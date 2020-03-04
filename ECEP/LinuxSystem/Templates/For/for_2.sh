#!/bin/bash

echo -n "Enter a number : "
read X

let SUM=0

for ((i = 1 ; $i < $X ; i = $i + 1)) 
do
	let SUM=$SUM+$i
done

echo The sum of the first $X natural numbers is: $SUM
