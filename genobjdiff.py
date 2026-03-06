import json

if __name__ == '__main__':
    filejson = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "units": [],
        "progress_categories": [
            {
                "id": "game",
                "name": "Game"
            },
            {
                "id": "sdk",
                "name": "SDK"
            },
            {
                "id": "level",
                "name": "Levels"
            }
        ]
    }

    unlinkedfiles = {
        "game": [
            "D6F0",
            "DC40",
            "F3D0",
            "FCB0",
            "103F0",
            "10640",
            "10F50",
            "12720",
            "12D70",
            "161C0",
            "19BD0",
            "1A6A0",
            "1BA60",
            "1F5F0",
            "2BA70",
            "2C440",
            "2D6E0",
            "2F310",
            "30630",
            "30C90",
            "30E70",
            "32D70",
            "345E0",
            "368B0",
            "3AF50",
            "3BAA0",
            "3C190",
            "3D2B0",
            "3EAA0",
            "405D0",
            "4F810",
            "56340",
            "63860",
            "67080",
            "6AB50",
            "6B0D0",
            "6B5F0",
        ],
        "sdk": [
            # technically done, but needs to be moved out into proper files. [hasm]
            "os/invaldcache",
            "os/invalicache",
            "os/writebackdcache",
            "os/writebackdcacheall",

            "libc/bzero",
            "os/exceptasm",
            "os/getsr",
            "os/interrupt",
            "os/probetlb",
            "os/setintmask",
            "os/setfpccsr",
            "os/setsr",
            "os/maptlbrdb",
            "libc/bcopy",
            "os/getcause",
            "os/getcount",
            "os/setcompare",
            "ultralib/NotImplemented",
            "divdi",
            "udivdi",
            "umoddi",
        ]
    }

    filelist = {
        "game": [
            "_4a780",
            "_42bd0",
            "_1050",
            "_31960",
            "1A6A0"
        ],
        "level": [
            "aztec_code",
            "circuit_code",
            "final_code",
            "gexzil_code",
            "gillig_code",
            "horror_code",
            "intro_code",
            "kungfu_code",
            "logo_code",
            "looney_code",
            "map_code",
            "mooshu_code",
            "nypd_code",
            "prehst_code",
            "rezop_code",
            "rta_code",
            "scifi_code",
            "spy_code"
        ],
        "sdk": [
            "audio/auxbus",
            "audio/copy",
            "audio/drvrnew",
            "audio/env",
            "audio/filter",
            "audio/heapalloc",
            "audio/heapinit",
            "audio/load",
            "audio/mainbus",
            "audio/resample",
            "audio/reverb",
            "audio/save",
            "audio/sl",
            "audio/synaddplayer",
            "audio/synallocfx",
            "audio/syndelete",
            "audio/synsetfxmix",
            "audio/synsetpan",
            "audio/synsetpitch",
            "audio/synsetvol",
            "audio/synstartvoice",
            "audio/synstopvoice",
            "audio/synthesizer",

            "debug/kdebugserver",

            "gu/cosf",
            "gu/mtxcatf",
            "gu/mtxutil",
            "gu/perspective",
            "gu/sinf",

            "host/readhost",

            "io/ai",
            "io/aigetlen",
            "io/aisetfreq",
            "io/aisetnextbuf",
            "io/cartrominit",
            "io/contpfs",
            "io/contramread",
            "io/contramwrite",
            "io/contreaddata",
            "io/controller",
            "io/contsetch",
            "io/crc",
            "io/devmgr",
            "io/dp",
            "io/dpsetnextbuf",
            "io/epidma",
            "io/epirawdma",
            "io/epirawread",
            "io/epirawwrite",
            "io/leodiskinit",
            "io/leointerrupt",
            "io/pfsallocatefile",
            "io/pfschecker",
            "io/pfsdeletefile",
            "io/pfsfilestate",
            "io/pfsfreeblocks",
            "io/pfsgetstatus",
            "io/pfsinitpak",
            "io/pfsisplug",
            "io/pfsnumfiles",
            "io/pfsreadwritefile",
            "io/pfsrepairid",
            "io/pfssearchfile",
            "io/pidma",
            "io/pigetcmdq",
            "io/pirawdma",
            "io/pirawread",
            "io/si",
            "io/siacs",
            "io/sirawdma",
            "io/sirawread",
            "io/sirawwrite",
            "io/sp",
            "io/spgetstat",
            "io/sprawdma",
            "io/sprawread",
            "io/sprawwrite",
            "io/spsetpc",
            "io/spsetstat",
            "io/sptask",
            "io/sptaskyield",
            "io/sptaskyielded",
            "io/vi",
            "io/viblack",
            "io/vigetcurrframebuf",
            "io/vigetnextframebuf",
            "io/vimgr",
            "io/visetevent",
            "io/visetmode",
            "io/visetspecial",
            "io/viswapbuf",
            "io/viswapcontext",

            "libc/ldiv",
            "libc/sprintf",
            "libc/string",
            "libc/xldtob",
            "libc/xlitob",
            "libc/xprintf",

            "os/createmesgqueue",
            "os/createthread",
            "os/destroythread",
            "os/getactivequeue",
            "os/getthreadpri",
            "os/gettime",
            "os/initialize",
            "os/initrdb",
            "os/jammesg",
            "os/rdbsend",
            "os/recvmesg",
            "os/resetglobalintmask",
            "os/sendmesg",
            "os/seteventmesg",
            "os/setglobalintmask",
            "os/setthreadpri",
            "os/startthread",
            "os/stopthread",
            "os/thread",
            "os/timerintr",
            "os/virtualtophysical",
            "os/yieldthread",

            "rmon/rmonbrk",
            "rmon/rmoncmds",
            "rmon/rmonmain",
            "rmon/rmonmem",
            "rmon/rmonmisc",
            "rmon/rmonrcp",
            "rmon/rmonregs",
            "rmon/rmonsio",
            "rmon/rmontask",

            "sched/sched",

            "zlib",
        ]
    }

    for (cat, l) in filelist.items():
        for name in l:
            filejson["units"].append({
                "name": name,
                "target_path": f"build/asm/{name}.o",
                "base_path": f"build/src/{name}.o",
                "metadata": {
                    "progress_categories": [cat]
                }
            })

    

    for (cat, l) in unlinkedfiles.items():
        for name in l:
            filejson["units"].append({
                "name": name,
                "target_path": f"build/asm/{name}.o",
                "base_path": None,
                "metadata": {
                    "progress_categories": [cat]
                }
            })
    
    with open("objdiff.json", "w") as f:
        json.dump(filejson, f)