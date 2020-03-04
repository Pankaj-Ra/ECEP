#!/bin/sh

RESPONSE="n" 

while [ "$RESPONSE" != y ] 
do  							
	echo -n "Enter option: " 
	read OPTION 
	echo -n "You entered $OPTION | Is this correct? (y/n): " 
	read RESPONSE 
done 
