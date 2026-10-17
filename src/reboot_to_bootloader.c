#include <zephyr/init.h>
#include <zephyr/sys/reboot.h>

#if IS_ENABLED(CONFIG_RETENTION_BOOT_MODE)
#include <zephyr/retention/bootmode.h>
#endif

/* Runs after the settings reset (ZMK_SETTINGS_RESET_ON_START) has erased the settings. */
static int reboot_to_bootloader(void) {
#if IS_ENABLED(CONFIG_RETENTION_BOOT_MODE)
    if (bootmode_set(BOOT_MODE_TYPE_BOOTLOADER) < 0) {
        return 0;
    }
    sys_reboot(SYS_REBOOT_WARM);
#else
    /* Magic value understood by the Adafruit nRF52 UF2 bootloader (DFU_MAGIC_UF2_RESET). */
    sys_reboot(0x57);
#endif
    return 0;
}

SYS_INIT(reboot_to_bootloader, APPLICATION, 99);
