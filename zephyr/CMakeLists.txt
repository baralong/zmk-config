if(CONFIG_ZMK_CONFIG_REBOOT_TO_BOOTLOADER_AFTER_RESET)
  zephyr_library()
  zephyr_library_sources(../src/reboot_to_bootloader.c)
endif()
