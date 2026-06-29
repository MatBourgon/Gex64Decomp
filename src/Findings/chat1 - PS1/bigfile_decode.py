#!/usr/bin/env python3
"""
BIGFILE.DAT decoder for Gex 2: Enter the Gecko (SLUS-00598)
Usage: python3 bigfile_decode.py <raw_disc.car> [output_dir]
Disc image must be raw 2352-byte/sector CD-XA format.
"""
import struct, sys, os, re

SECTOR=2352; DATA_OFF=24; DATA_LEN=2048
BF_LBA=268;  BF_SIZE=70_731_776

def read_at(f, bf_byte_off, n):
    s=bf_byte_off//DATA_LEN; ofs=bf_byte_off%DATA_LEN
    buf=b""
    for i in range((ofs+n+DATA_LEN-1)//DATA_LEN):
        f.seek((BF_LBA+s+i)*SECTOR+DATA_OFF); buf+=f.read(DATA_LEN)
    return buf[ofs:ofs+n]

def classify(magic, size, f1):
    if magic[:4]==b'map7':                       return "arg",   ".arg"
    if magic[2:7]==b'DNSaC':                     return "audio", ".dnsc"
    if magic[:2]==b'\xa8\xaa':                   return "geom",  ".geom"
    if magic[0]==0x20 and magic[2]==0x10 and magic[3]==0x00: return "level",".lev"
    if magic[3]==0x00 and magic[4:8]==b'\x00'*4 and size>300000: return "vram",".vram"
    if size<100000 and f1<0x10000:               return "meta",  ".meta"
    return "bin", ".bin"

def decode(disc_path, outdir="bigfile_out"):
    os.makedirs(outdir, exist_ok=True)
    with open(disc_path,"rb") as f:
        toc=read_at(f,0,0x1800)
        n_res  = struct.unpack_from("<I",toc,0)[0]
        cksum  = struct.unpack_from("<I",toc,4)[0]
        n_maps = struct.unpack_from("<I",toc,8)[0]
        print(f"BIGFILE: n_resources={n_res}  n_maps={n_maps}  checksum=0x{cksum:08X}")

        entries=[]
        for i in range(n_res):
            b=16+i*16
            entries.append((struct.unpack_from("<I",toc,b)[0],
                            struct.unpack_from("<I",toc,b+4)[0],
                            struct.unpack_from("<I",toc,b+8)[0],
                            struct.unpack_from("<I",toc,b+12)[0]))

        valid=sorted([(i,e) for i,e in enumerate(entries) if 0<e[0]<BF_SIZE],
                     key=lambda x:x[1][0])
        sized=[]
        for rank,(i,(off,f1,f2,f3)) in enumerate(valid):
            nxt=valid[rank+1][1][0] if rank+1<len(valid) else BF_SIZE
            sized.append((i,off,nxt-off,f1,f2,f3))

        extracted=0
        for i,off,size,f1,f2,f3 in sized:
            if size==0 or size>15_000_000: continue
            magic=read_at(f,off,min(16,size))
            ftype,ext=classify(magic,size,f1)
            fname=f"entry_{i:03d}_0x{off:08X}_{size}{ext}"
            data=read_at(f,off,size)
            with open(os.path.join(outdir,fname),"wb") as out: out.write(data)
            extracted+=1
            print(f"  [{i:3d}] {ftype:<6} 0x{off:08X}  {size//1024:6}KB  {fname}")
        print(f"\nExtracted {extracted} files to {outdir}/")

        # Write manifest including hash-addressed entries
        with open(os.path.join(outdir,"MANIFEST.txt"),"w") as mf:
            mf.write(f"BIGFILE.DAT  n_resources={n_res}  n_maps={n_maps}  checksum=0x{cksum:08X}\n\n")
            mf.write("DIRECT-OFFSET ENTRIES (byte offset within BIGFILE):\n")
            mf.write(f"{'idx':>4}  {'offset':>10}  {'size_KB':>8}  {'type':<6}  {'f1_crc':>10}  {'f3':>10}\n")
            for i,off,size,f1,f2,f3 in sized:
                if size==0: continue
                magic=read_at(f,off,min(8,size))
                ftype,_=classify(magic,size,f1)
                mf.write(f"{i:4d}  0x{off:08X}  {size//1024:8}  {ftype:<6}  0x{f1:08X}  0x{f3:08X}\n")
            mf.write("\nHASH-ADDRESSED ENTRIES (f0 = content hash, not byte offset):\n")
            mf.write("These 60 entries contain the 26 per-mission configs + other resources.\n")
            mf.write(f"{'idx':>4}  {'f0_hash':>10}  {'f1':>10}  {'f3':>10}\n")
            for i,(f0,f1,f2,f3) in enumerate(entries):
                if f0>=BF_SIZE:
                    mf.write(f"{i:4d}  0x{f0:08X}  0x{f1:08X}  0x{f3:08X}\n")

if __name__=="__main__":
    if len(sys.argv)<2:
        print(__doc__); sys.exit(1)
    decode(sys.argv[1], sys.argv[2] if len(sys.argv)>2 else "bigfile_out")
