#!/bin/bash

STRING=(Hello how are you)

echo ${STRING[@]}
echo ${STRING[*]}
echo $STRING
echo ${STRING[0]}
echo ${STRING[1]}
echo ${#STRING[@]}
