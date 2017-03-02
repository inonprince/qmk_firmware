#!/bin/sh

flags=""
if [ ! -z $1 ]; then
	flags="MASTER=right"
fi
pwd
make ergodox-infinity-inonio $flags
if [ $? != 0 ]; then
    exit 1
fi
sudo make ergodox-infinity-inonio-dfu-util $flags
echo "Flashing $flags hand, Press enter key to continue"
read x

dfu-util --device 1c11:b007 -D .build/ergodox_infinity_inonio.bin
