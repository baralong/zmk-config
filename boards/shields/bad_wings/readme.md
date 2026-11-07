# Bad Wings

Bad Wings is a split, 5x3+3 unibody (36 key) keyboard built around the Seeed XIAO
BLE and a Cirque Pinnacle trackpad.

Hardware designed by [hazles-garage bad-wings v1]
(https://github.com/hazels-garage/bad-wings/tree/master/v1) details of my 
process in the [build notes](./build-notes/readme.md). I chose bad-wings v1 
because it supports bluetooth. 

The end result is a compact keyboard that's only 22mm thick, 240mm wide, and
110m deep. The touch pad can be handy and it supports 5 bluetooth profiles. I
can switch between my work and personal laptops, and my phone with a key press.
One thing to note: it maintains a connection to all paired devices, the switch
is just a change of where it sends the codes. 

I've also included support for recording key presses for playback stored in
either temporary or persistent storage.


## Keymap

The default keymap is in [`bad_wings.keymap`](./bad_wings.keymap). It defines
the Base, Numbers, Symbols, Navigation, Function, MacroBluetooth, Mouse, and
Scroll layers, along with tap/hold behaviors, combos, and dynamic macros.

My general approach is QWERTY with home row mods, I also have some convenience 
adjacent key, so 1 finger chords. With the placement of the number layer 
directly below shift I can hit the shifted numbers with just 2 fingers, I
don't use the symbols layer much. That might change when I start doing more
coding again. This wasn't actually planned, but works well

The physical layout and matrix are described in
[`bad_wings.overlay`](./bad_wings.overlay) and
[`bad_wings-layouts.dtsi`](./bad_wings-layouts.dtsi). The shield settings,
including trackpad, ZMK Studio, and dynamic-macro options, are in
[`bad_wings.conf`](./bad_wings.conf).

## Firmware artifacts

The compiled UF2 files are kept in the repository's
[`artifacts/`](../../../artifacts/) directory:

| File | Purpose |
| --- | --- |
| `bad_wings raw_hid_adapter-xiao_ble__zmk-zmk.uf2` | Main Bad Wings firmware for the XIAO BLE, including the keyboard keymap, trackpad support, ZMK Studio support, and Raw HID adapter. |
| `settings_reset-xiao_ble__zmk-zmk.uf2` | Temporary settings-reset firmware. It erases ZMK settings and reboots the XIAO BLE into its UF2 bootloader so the main firmware can be installed again. I created this artefact because the reset button on the XIAO is a pain to hit with the case on|

Use the main image for normal operation. Use the settings-reset image only when
you need to clear stored ZMK settings; after it reboots to the bootloader, flash
the main image.

## Build targets and reset behavior

[`build.yaml`](../../../build.yaml) defines two builds for `xiao_ble//zmk`:

- The Bad Wings shield with the Studio USB/UART snippet and Raw HID adapter.
- ZMK's `settings_reset` shield with the bootloader-reboot option enabled.

The reset build uses [`src/reboot_to_bootloader.c`](../../../src/reboot_to_bootloader.c).
After settings are erased, it requests a warm reboot into the bootloader when
supported, with a fallback reset value for the Adafruit nRF52 UF2 bootloader.

The GitHub Actions workflow builds these targets and commits updated firmware
files to `artifacts/` when the event and repository permissions allow it.
