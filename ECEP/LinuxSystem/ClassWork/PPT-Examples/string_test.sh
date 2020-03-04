#!/bin/bash

echo “Enter the first string” 
read STR1
echo “Enter the second string” 
read STR2

if [ -z ${STR1} ]; then
	echo "First string is empty"
else
	echo "First string is not empty"
fi
if [ -n ${STR2} ]; then
 	echo "First string is not empty"
else
	echo "First string is empty"
fi
if [ ${STR1} = ${STR2} ]; then
	echo "Both string are equal"
else
	echo "Both string are not equal"
fi
