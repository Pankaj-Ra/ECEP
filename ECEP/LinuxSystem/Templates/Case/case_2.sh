#!/bin/bash

echo "Enter an element between 0 - 10 (excluded)"
echo -n "Enter a number: "
read X

if [ -n $X ]
then
	case $X in
		Emx) echo Value of x is One.;;
		emx) echo Value of x is Two.;;
		eMx) echo Value of x is Three.;;
		EMx) echo Value of x is Four.;;
		EMX) echo Value of x is Five.;;
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
