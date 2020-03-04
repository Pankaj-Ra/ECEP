#!/bin/bash

function sum()
{
  	x=`expr $1 + $2`
	echo $x
}		
   
 y=`sum 5 3`
 echo "The sum of 5 and 3 is $y"
 echo "The sum of 6 and 2 is `sum 6 2`"	
 echo "The sum of 10 and 2 is `sum 10 2`"
