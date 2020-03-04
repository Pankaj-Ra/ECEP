#!/bin/bash

NUM1=5
NUM2=6

if [ ${NUM1} -eq ${NUM2} ]
then
	echo  "NUM1 is equal to NUM2"
elif [ ${NUM1} -gt ${NUM2} ]
then
	echo  "NUM1 is greater than NUM2"
else
	echo  "NUM1 is less than NUM2"
fi
