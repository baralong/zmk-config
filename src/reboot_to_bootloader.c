#include <zephyr/init.h>
#include <zephyr/sys/reboot.h>

/* Magic value understood by the Adafruit nRF52 UF2 bootloader (DFU_MAGIC_UF2_RESET). */
#define RST_BOOTLOADER 0x57

/* Runs after the settings reset (ZMK_SETTINGS_RESET_ON_START) has erased the settings. */
static int reboot_to_bootloader(void) {
    sys_reboot(RST_BOOTLOADER);
    return 0;
}

SYS_INIT(reboot_to_bootloader, APPLICATION, 99);
