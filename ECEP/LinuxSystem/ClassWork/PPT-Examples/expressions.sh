#!/bin/bash

NUM1=5
NUM2=3

ADD=$((${NUM1} + ${NUM2}))
SUB=$((${NUM1} - ${NUM2}))
MUL=$((${NUM1} * ${NUM2}))
DIV=$((${NUM1} / ${NUM2}))
MOD=$((${NUM1} % ${NUM2}))

echo -e "Addition of two numbers is\t\t: ${ADD}"
echo -e "Substraction of two numbers is\t\t: ${SUB}"
echo -e "Multiplication of two numbers is\t: ${MUL}"
echo -e "Division of two numbers is\t\t: ${DIV}"
echo -e "Modulum of two numbers is\t\t: ${MOD}"
