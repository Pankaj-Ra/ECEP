#!/bin/bash

echo "You have executed" ${0}

STRING1="Welcome"
NUM=2
STRING2="Scripting World :)"

echo "You used 2 variables in you script and they are"
echo ${STRING1} ${NUM} ${STRING2}

echo "You have passed" ${#} "variables" "and they are"
echo ${@}
