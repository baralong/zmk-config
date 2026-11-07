# ZMK keyboard configurations

This repository contains ZMK configuration and build files for the keyboards
listed below. Each keyboard should have its own section in this index, with a
link to its documentation and keymap details.

## Keymaps

### Bad Wings

See the [Bad Wings README](./boards/shields/bad_wings/readme.md) for its
hardware details, keymap overview, build targets, and firmware artifacts.

### Add another keymap

Add a section here for each additional keyboard or keymap. Include a short
description, a link to its keymap documentation, and links or instructions for
its build artifacts.

## Build process

[`build.yaml`](./build.yaml) defines the firmware targets that the ZMK
reusable user-config workflow builds. The project manifest in
[`config/west.yml`](./config/west.yml) identifies ZMK and the additional
modules used by the configurations.

The GitHub Actions workflow in
[`.github/workflows/build.yml`](./.github/workflows/build.yml) runs on pushes,
pull requests, and manual dispatch. For builds that can write to this
repository, it downloads the generated firmware and commits updated artifacts
under [`artifacts/`](./artifacts/).

An optional local build task using `act` and Docker is available in
[`.vscode/tasks.json`](./.vscode/tasks.json). 
