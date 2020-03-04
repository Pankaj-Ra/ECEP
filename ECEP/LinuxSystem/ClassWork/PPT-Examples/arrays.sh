#!/bin/bash

declare -a LINUX_DISTROS=('Debian' 'Redhat' 'Ubuntu' 'Suse' 'Fedora');

echo -e "Number of elements in the array\t\t\t: ${#LINUX_DISTROS[@]}"
echo -e "Printing elements of array in one shot\t\t: ${LINUX_DISTROS[@]}"
echo -e "Printing elements of array in one shot\t\t: ${LINUX_DISTROS[*]}" 
echo -ne "Printing elements of array in using a loop\t: " 
for ((i = 0; i < ${#LINUX_DISTROS[@]}; i++))
do
	echo -n ${LINUX_DISTROS[$i]} 
done

echo
