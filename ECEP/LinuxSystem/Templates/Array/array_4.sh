#!/bin/bash

ARRAY=(1 4 hello)
echo "Num of elements are ${#ARRAY[@]}"
echo ${ARRAY[@]}

ARRAY[5]=1010
echo ${ARRAY[@]}
echo ${ARRAY[2]:2}
