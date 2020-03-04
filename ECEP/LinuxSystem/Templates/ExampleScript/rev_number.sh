#!/bin/bash
# Reversing the given number

echo "Reversing the Given Number"
echo -n "Enter the number : "
read NUM

echo $NUM

while [ $NUM -gt 0 ]
do
	TEMP=$(($NUM % 10))
	NUM=$(($NUM / 10))
	REVERSED_NUM=$((TEMP + REVERSED_NUM * 10))
done

echo "The Reverse of given number is : $REVERSED_NUM "
