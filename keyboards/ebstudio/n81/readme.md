# EBStudio

![ebstudio logo](https://portrait.gitee.com/uploads/avatars/user/3363/10089555_ebstudio_1637910625.png!avatar100)

The N81 is the hotswap PCB for the EBStudio N81 wireless keyboard, a seventy-percent high-end keyboard.

* Maintainer: [EBStudio](https://gitee.com/ebstudio)
* Hardware Supported: N81 wireless PCB (proto and final rev)

Make example for this keyboard (after setting up your build environment):
```
make ebstudio/n81:via
```

Flashing example for this keyboard (By Ardunio as an ISP on macOS):
```
make ebstudio/n81:via:flash
```

Enter Bootloader for this keyboard:
```
Press Fn + Del (for default keymap setting)
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
