![Overall](https://decomp.dev/MatBourgon/Gex64Decomp.svg?mode=shield)
![Game Code](https://decomp.dev/MatBourgon/Gex64Decomp.svg?mode=shield&category=game&color=%2349a343)
![Level Code](https://decomp.dev/MatBourgon/Gex64Decomp.svg?mode=shield&category=level&color=%23ab4f4f)
![SDK Code](https://decomp.dev/MatBourgon/Gex64Decomp.svg?mode=shield&category=sdk&color=%23292c47)

# Gex 64: Enter the Gecko

W.I.P. decompilation of Gex 64

## Prerequisites
### With Docker
* Docker
  
### Without Docker
* python3 & pip
* binutils-mips-linux-gnu

## Setup

1. Pull the docker image and run it: `docker run --name g64d -it matbourgon/gex64-decomp:latest`
    * You can re-attach to an existing container with this command: `docker attach -ia g64d`
2. Procure your legal ROM of Gex 64: Enter the Gecko (USA) and place it into the repo's root folder, and rename it to `gex64.z64`.
    * It must be a big endian rom in the z64 format. If you have a .n64 or other copy, it can be converted online.
    * If you have it locally, you can copy it into the docker container with the following command: `docker cp /path/to/file g64d://home/Gex64Decomp/gex64.z64`
3. Useful commands to get started:
    * `make clean` to clean the project and create any required files. Run this after changing the yaml file, and after moving a file from assembly to source.
    * `make split` to split the rom into assembly/binary files. Run this after cleaning.
    * `make build` to build the rom back up. Optionally, provide the parameter `-jX` where X is how many jobs to deploy to build. More jobs is better, but can slow down or freeze your computer. 8 is usually a good number. Compilation may still freeze, but Ctrl+C can break out of the command, and then you can re-run `make build` by itself to finish up any missing files.
    * `make diff` to diff the new rom file to the original rom. Before creating any pull requests, this must match.

## Contributing
Swap out `asm` segments in `gexenterthegecko.yaml` with `c`, and split again. Once a file is completed up to a certain point, you can create a Pull Request, as long as the diffing tool says the roms are matching after a clean build. For more information on how to process the files, visit [the Splat64 wiki](https://github.com/ethteck/splat/wiki/General-Workflow) and [decomp.me](https://decomp.me/).

The flags this build uses is generally just `-O2`, with `-g3` for temporary help on decomp.me (if you're getting extra `nop`s, remove it), and some files require -mips3 to compile, but most of the game compiles without it.

There is currently no naming scheme, but at the very least:
* Global functions should be named in PascalCase
* Enums follow a `EEnumType` form, and each entry follows a shorter `EET_EntryName`. See `TVTextData.h`.

After converting an assembly file to a C file in the yaml file, make sure to add it to either `mips1.source.txt` or `mips3.source.txt`, otherwise it won't compile and you'll get a linking error. You should always try `mips1.source.txt` first.

