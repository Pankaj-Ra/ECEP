#!/bin/bash

echo -n "Enter a number: "
read NUM

let SUM=0; let I=1

while [ $I -le $NUM ]
do
	SUM=`expr $SUM + $I`
	I=$((${I} + 1))
done

echo "The sum of the first $NUM numbers is: $SUM"
