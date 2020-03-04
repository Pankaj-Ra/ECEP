#!/bin/bash

# Example for the if-then-elif-else

if [ 'whoami' = "root" ]
then 
	echo "You are the superuser!!"
elif [ "$USER" = "root" ]
then
	echo "You might be super user"
elif [ `id -u` -gt 10000 ]
then 
	echo "You can pay to be the superuser ;)"
else
	echo "You are still an ordinary dude"
fi
