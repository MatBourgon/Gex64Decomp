
BUILD_DIR = build
ASMSOURCES := $(shell find asm -not \( -path asm/nonmatchings -prune \) -name "*.s")
ASMOBJECTS := $(addprefix $(BUILD_DIR)/, $(patsubst %.s, %.o, $(ASMSOURCES)))

MIPS1SOURCES := $(shell cat mips1.source.txt)
MIPS1OBJECTS := $(addprefix $(BUILD_DIR)/, $(patsubst %.c, %.o, $(MIPS1SOURCES)))
MIPS3SOURCES := $(shell cat mips3.source.txt)
MIPS3OBJECTS := $(addprefix $(BUILD_DIR)/, $(patsubst %.c, %.o, $(MIPS3SOURCES)))
COBJECTS := $(MIPS1OBJECTS) $(MIPS3OBJECTS)

AS = mips-linux-gnu-as
OBJCOPY = mips-linux-gnu-objcopy
COMMONFLAGS = -mabi=32 -mfp32 -mgp32 -Iinclude
ASFLAGS = -mtune=vr4300 -march=vr4300 -no-pad-sections -mips3 -G0 $(COMMONFLAGS)
CC = tools/gcc
CDEFINES = -DNUM_LEVELS=32 -DF3DEX_GBI=1 -D_LANGUAGE_C
CFLAGS = -nostdinc -c -O2 -G0 $(CDEFINES) $(COMMONFLAGS) -Btools/
LD = mips-linux-gnu-ld

default: all

all: clean split build diff

$(ASMOBJECTS): $(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

$(MIPS1OBJECTS): $(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -mips1 $< -o $@

$(MIPS3OBJECTS): $(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -mips3 $< -o $@

rom.elf: $(ASMOBJECTS) $(COBJECTS)
	$(info Linking elf file...)
	@$(LD) -Map gexenterthegecko.map $(ASMOBJECTS) $(COBJECTS) -T gexenterthegecko.ld -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -o $@

split:
	python3 -m splat split gexenterthegecko.yaml

rom.z64: rom.elf
	$(OBJCOPY) -O binary --pad-to 0x1000000 rom.elf rom.z64

build: rom.z64

diff:
	python3 diffcheck.py

clean:
	rm -rf build/
	rm -rf asm/
	rm -rf assets/
	rm -f rom.elf
	rm -f rom.z64
	mkdir -p build/asm/data
	mkdir -p build/asm/ultralib
	mkdir -p build/asm/rmon
	mkdir -p build/asm/os
	mkdir -p build/asm/libc
	mkdir -p build/src
	mkdir -p build/src/ultralib
	mkdir -p build/src/libc
	mkdir -p build/src/rmon
	mkdir -p build/src/sched
	mkdir -p build/src/gu
	mkdir -p build/src/audio
	mkdir -p build/src/io
	mkdir -p build/src/os
	mkdir -p build/src/host
	mkdir -p build/src/debug

cleanc:
	rm -rf build/src/*.o

.PHONY: all clean default split build diff
