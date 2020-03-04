#!/bin/bash

# Sum of given numbers

echo "Adding the given number"
echo -n "Enter the number : "
read NUM

SUM=0

while [ $NUM -gt 0 ]
do
	SD=`expr $NUM % 10`
	SUM=$((${SUM} + ${SD}))
	NUM=`expr ${NUM} / 10`
done

echo "The sum of the given number : $SUM"
