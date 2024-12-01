BUILD_DIR = build
ASMSOURCES := $(shell find asm -name *.s)
ASMDIRS := $(sort $(dir $(ASMSOURCES)))
ASMOBJECTS := $(addprefix $(BUILD_DIR)/, $(patsubst %.s, %.o, $(ASMSOURCES)))

CROSS = mips-linux-gnu-
AS = $(CROSS)as
OBJCOPY = $(CROSS)objcopy
ASFLAGS = -march=vr4300 -mtune=vr4300 -Iinclude -no-pad-sections

LD = $(CROSS)ld

default: all

all: clean split rom.z64

vpath %.s $(ASMDIRS)

$(ASMOBJECTS): $(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

rom.elf: $(ASMOBJECTS)
	$(LD) -Map gexenterthegecko.map $(ASMOBJECTS) -T gexenterthegecko.ld -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -o $@ > log.txt

split:
	cmd.exe /c splat split gexenterthegecko.yaml

rom.z64: rom.elf
	$(OBJCOPY) -O binary --pad-to 0x1000000 rom.elf rom.z64

build: rom.z64

diff:
	cmd.exe /c py diffcheck.py

clean:
	rm -rf build/
	rm -rf asm/
	rm -rf assets/
	rm -f rom.elf
	rm -f rom.z64
	mkdir -p build/asm/data

.PHONY: all clean default split build diff

# mips64-elf-gcc.exe -O2 -g3 -I../include -mabi=32 -mgp32 -mfp32 -nostdinc -fno-PIC -G 0 -mips2 -c ../src/_3eaa0.c -o ../_3eaa0.o