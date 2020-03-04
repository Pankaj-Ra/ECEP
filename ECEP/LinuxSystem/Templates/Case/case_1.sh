#!/bin/bash

echo "Enter an element between 0 - 10 (excluded)"
echo -n "Enter a number: "
read X

if [ -n $X ]
then
	case $X in
		1) echo Value of x is One.;;
		2) echo Value of x is Two.;;
		3) echo Value of x is Three.;;
		4) echo Value of x is Four.;;
		5) echo Value of x is Five.;;
		6) echo Value of x is Six.;;
		7) echo Value of x is Seven.;;
		8) echo Value of x is Eight.;;
		9) echo Value of x is Nine.;;
		0 | 10) echo wrong number.;;
		*) echo Please follow the instructions;;
	esac
else
	echo Enter the correct element
fi
