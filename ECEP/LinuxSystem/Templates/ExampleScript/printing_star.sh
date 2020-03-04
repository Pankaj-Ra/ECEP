#!/bin/bash
#
# This program is to print the " * " depends on user input
#

echo -n "Enter the number : "
read MAX_NO

clear

for (( i=1; i<=$MAX_NO; i++ ))
do
	for (( s=$MAX_NO; s>=i; s-- ))
	do
		echo  " "
	done
	for (( j=1; j<=i; j++ ))
	do
		echo -n "*"
	done
	echo  " "
done
