#!/bin/sh

if [ `whoami` = "root" ]
then
	echo "you are the superuser"
else
	echo "you are $USER"
fi
