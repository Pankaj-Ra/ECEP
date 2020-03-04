#!/bin/bash

clear

ARGUMENTS=$#

if [ $ARGUMENTS -eq 0 ]
then
	echo "The sum is 0"
fi

if [ $ARGUMENTS -eq 1 ]
then
	echo "The sum is $1"
fi

if [ $ARGUMENTS -ge 2 ]
then
	COUNT=1
	while [ $COUNT -le $ARGUMENTS ]
	do
	#	COUNT1=$[$COUNT]
	#	echo $COUNT1
		echo "first arguments is $[$COUNT]"
	#	COUNT1=$(($COUNT + 1)) ((COUNT++))
	#	echo "second arguments is $[COUNT=$(($COUNT + 1))]"
	#	sum=$(($[ $COUNT ] + $[ $COUNT + 1]))
		COUNT=$(($COUNT + 1))
	#	sum=${sum}+${COUNT1}
	done
	#echo "The sum is $sum"
fi

exit 0
