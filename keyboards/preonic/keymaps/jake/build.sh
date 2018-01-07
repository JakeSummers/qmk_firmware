#!/bin/bash
set -e

figlet 'Build QMK Firmware'
cd ~/repos/qmk_firmware
make preonic:jake

figlet 'Erase Board'
sudo dfu-programmer atmega32u4 erase --force

figlet 'Flash Board'
sudo dfu-programmer atmega32u4 flash /home/jsummers/repos/qmk_firmware/preonic_rev2_jake.hex 

figlet 'DONE'
