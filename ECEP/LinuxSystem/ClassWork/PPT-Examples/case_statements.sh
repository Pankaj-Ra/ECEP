#!/bin/bash

echo “Enter a number \< 2:” 
read NUM

case ${NUM} in
	1) 
		echo "You entered One"
		;;
	2) echo "You entered Two" ;;
	*) echo "Obey my orders please"
		;;
esac
