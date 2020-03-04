#!/bin/bash
#
# This script will do the following using sed command
#  1) Removing 
#  2) Replacing
#  3) Writing
#  4) Printing

clear
echo "Select the following option : "
echo 
echo "    1) Replacing "
echo "    2) Deleting "
echo "    3) Writing "
echo "    4) Printing "
read OPTION
echo -n "Enter the FILE name to do this operation : "
read FILE

if [ $OPTION == 1 ]
then
	echo -n "Enter the string to replace by which : "
	read STRING_1
	echo -n "Enter the string to replace by $STRING_1 : "
	read STRING_2
	sed -e 's/${STRING_1}/${STRING_2}/g' $FILE
elif [ $OPTION == 2 ]
then
	echo  "Enter the option : "
	echo  "   1) Deleting the string "
	echo  "   2) Deleting the single line "
	echo  "   3) Deleting the line from one line to another line "
	echo  "   4) Deleting the last line from a given file $FILE : "
		if [ $delete == 1 ]
		then 
			echo -n "Enter the string to delete : "
			read STRING_3
			sed -i 's/$STRING_3/ /g' $FILE
		elif [ $delete == 2 ]
		then
			echo -n "Enter the line number to delete : "
			read line
			sed -i '${line}d' $FILE
		elif [ $delete == 3 ]
		then
			echo -n "Enter the starting line number to delete : "
			read line
			echo -n "Enter the ending line number to delete : "
			read line2
			sed -i '${line},${line2}d' $FILE
		else
			echo "Deleting the last line from a file $FILE "
			sed "$d" $FILE
		fi
			
elif [ $OPTION == 3 ]
then
	echo  "Select the option to perform : "
	echo  "Enter the line number to write : "
	read WRITE_STRING
	
else
	echo " Select the option : "
	echo "        1) Printing the hole file "
	echo "        2) Printing the specified line number "
	echo "        3) Printing from one line to another line "
	read OPTION_PRINT
	if [ $OPTION_PRINT == 1 ]
	then
		sed -e ' ' $FILE 
	elif [ $OPTION_PRINT == 2 ]
	then
		echo -n " Enter the line number to print : "
		read PRINT_LINE
		sed -n '{$PRINT_LINE}p' $FILE
	else
		echo -n " Enter the first line number to print : "
		read PRINT_LINE_1
		echo -n " Enter the second line number to print : "
		read PRINT_LINE_2
		sed -n '{$PRINT_LINE},{$PRINT_LINE_2}p' $FILE
	fi
fi	
