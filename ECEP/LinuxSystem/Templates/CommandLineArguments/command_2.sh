#!/bin/sh

if [ $# -lt 2 ]
then 
	echo "$0 error: you must supply two arguments i.e your name and native"
else
	echo "My name is $1 and I came from $2"
fi
