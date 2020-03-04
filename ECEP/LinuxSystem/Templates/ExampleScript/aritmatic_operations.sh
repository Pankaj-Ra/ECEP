#!/bin/bash

clear

echo "Mathematical Expression"

echo  "Enter Two Operands & One Operator"
echo -n "Enter First Oparand : "
read NUM1
echo -n "Enter Second Oparand : "
read NUM2
echo -n "Enter the Operator : "
read OPERATION

RESULT=`echo ${NUM1} "${OPERATION}" ${NUM2} | bc`
echo "The $OPERATION of two Operands is : $RESULT "

# ${OPERATION} -> if u pass '*' it expands
# "${OPERATION}" -> It will pass as a string

RESULT=`expr ${NUM1} "${OPERATION}" ${NUM2}`
echo "The $OPERATION of two Operands is : $RESULT "

RESULT=$((${NUM1} ${OPERATION} ${NUM2}))
echo "The $OPERATION of two Operands is : $RESULT "
