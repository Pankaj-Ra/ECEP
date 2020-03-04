#!/bin/bash 

clear

function quit() 
{
	echo $1 echo $2
	echo Quiting out from the function
	exit

}  

function e 
{
	echo $1 
}  

e Hello
e World
quit Hello World

echo foo 
