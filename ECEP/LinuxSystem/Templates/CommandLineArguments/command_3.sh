#!/bin/sh

if [ $# -lt 2 ]
then 
	echo "$0 error: you must supply atleast one argument"
else
	for ARG in $@
	do
		echo "I found the argument $ARG"
	done
fi
