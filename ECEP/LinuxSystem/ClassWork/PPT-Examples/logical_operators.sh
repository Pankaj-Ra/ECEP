#!/bin/bash

echo “Enter the first number A” 
read A
echo “Enter the second number B ” 
read B
echo “Enter the third number C ” 
read C

if [ ${A} -gt ${B} -a ${A} -gt ${C} ]; then
   	echo "A is the greatest of all"
elif [ ${B} -gt ${A} -a ${B} -gt ${C} ]; then
   	echo "B is the greatest of all"
elif [ ${C} -gt ${A} -a ${C} -gt ${B} ]; then
   	echo "C is the greatest of all"
else
   	echo "Invalid Input"
fi
