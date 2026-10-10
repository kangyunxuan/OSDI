ARMGNU ?= aarch64-linux-gnu

CC      := $(ARMGNU)-gcc
LD      := $(ARMGNU)-ld
OBJCOPY := $(ARMGNU)-objcopy

BUILD_DIR = build
SRC_DIR = src

CFLAGS = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -mgeneral-regs-only
ASFLAGS = -Iinclude

C_FILES   := $(wildcard $(SRC_DIR)/*.c)
ASM_FILES := $(wildcard *.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:%.S=$(BUILD_DIR)/%_s.o)

DEPFILES = $(OBJ_FILES:.o=.d)

all: $(BUILD_DIR)/kernel8.img

#start obj
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@
	
$(BUILD_DIR)/%_s.o: %.S
	mkdir -p $(@D)
	$(CC) $(ASFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/kernel8.elf: linker.ld $(OBJ_FILES)
	$(ARMGNU)-ld -T linker.ld -o $@ $(OBJ_FILES)

$(BUILD_DIR)/kernel8.img: $(BUILD_DIR)/kernel8.elf
	$(ARMGNU)-objcopy -O binary $< $@

run: $(BUILD_DIR)/kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel $< \
		-serial null -serial stdio -display none

debug: $(BUILD_DIR)/kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel $< -display none -S -s

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPFILES)

# $@ = cur target
# $< = cur dependency
# $(@D) 是目標所在目錄
# -c：只編譯成目的檔（.o），不進行連結。
# -o 檔名：指定輸出檔案的名稱與路徑。