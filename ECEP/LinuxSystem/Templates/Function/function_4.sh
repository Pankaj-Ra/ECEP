#!/bin/sh

function sum() 
{
	SUM=`expr $1 + $2`
	echo $SUM
}

echo "The sum of 4 and 7 is `sum 4 7`" 
