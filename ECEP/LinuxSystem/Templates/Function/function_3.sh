#!/bin/bash

clear

function check() 
{
	if [ -e "./$1" ]
	then
		echo "Succeeded"
		return 0
	else
		echo "Failed"
		return 1
	fi
}

echo -n "Enter the name of a file: "
read X

if check $X
then
	echo $X exists!
else
	echo $X does not exists!
fi
