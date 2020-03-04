#!/bin/bash

# This is the program that prints what are the arguments u passed to the script
clear
if [ $# != 2 ]
then
	echo "Usage : Pass 3 arguments"
	exit 0
fi
echo " This will the Arguments u have been passed to this script : "
echo " The total number of arguments u passed is : $# "
echo " The name of the script 					 : $0 "
echo " The first Argument is  					 : $1 "
echo " The second Argument is 					 : $2 "
echo " Then all the Arguments 					 : $@ "
echo " Then all the Arguments 					 : $* "
