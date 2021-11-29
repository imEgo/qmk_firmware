# EBStudio

![ebstudio logo](https://portrait.gitee.com/uploads/avatars/user/3363/10089555_ebstudio_1637910625.png!avatar100)

A RGB controller for keyboards.

* Maintainer: [EBStudio](https://gitee.com/ebstudio)
* Hardware Supported: N81 wireless PCB (proto and final rev)

Make example for this keyboard (after setting up your build environment):
```
make ebstudio/n81_rgb:rev02
```

Flashing example for this keyboard (By Ardunio as an ISP on macOS):
```
avrdude -c avrisp -P /dev/tty.usbmodem14501 -b 19200 -p m328p -v -e -U flash:w:ebstudio_n81_rgb_rev02.hex:i -U lfuse:w:0xff:m -U hfuse:w:0xd9:m -U efuse:w:0xfc:m
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
