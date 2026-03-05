
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
CDEFINES = -DNUM_LEVELS=32 -DF3DEX_GBI=1 -D_LANGUAGE_C -DINCLUDE_ASM_USE_MACRO_INC
CFLAGS = -nostdinc -c -O2 -G0 $(CDEFINES) $(COMMONFLAGS) -Btools/
LD = mips-linux-gnu-ld

ALLSOURCES := $(patsubst %.s, %.o, $(ASMSOURCES)) $(patsubst %.c, %.o, $(MIPS1SOURCES) $(MIPS3SOURCES))
BUILDTREE := $(addprefix $(BUILD_DIR)/, $(ALLSOURCES))

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

build: makedirs rom.z64

buildobjdiff: makedirs $(ASMOBJECTS) $(COBJECTS)

splitobjdiff:
	python3 -m splat split gexenterthegecko.yaml --make-full-disasm-for-code

generatediffjson:
	python3 genobjdiff.py

report: clean splitobjdiff buildobjdiff generatediffjson
	tools/objdiff report generate -o build/report.json

diff:
	python3 diffcheck.py

clean:
	rm -rf build/
	rm -rf asm/
	rm -rf assets/
	rm -f rom.elf
	rm -f rom.z64

makedirs:
	$(shell mkdir -p $(dir $(BUILDTREE)))

cleanc:
	rm -rf build/src/*.o

.PHONY: all clean default split build diff
