#!/bin/bash
# array_3.sh: More fun with arrays.
#
clear

# Element 0   1   2     3    4    5
ARRAY=(zero one two three four five)

echo ${ARRAY[0]}       #  zero
echo ${ARRAY:0}        #  zero
                       #  Parameter expansion of first element,
                       #  + starting at position # 0 (1st character).
echo ${ARRAY:1}        #  ero
                       #  Parameter expansion of first element,
                       #  + starting at position # 1 (2nd character).
echo "--------------"
echo ${#ARRAY[0]}      #  4
                       #  Length of first ELEMent of array.
echo ${#ARRAY}         #  4
                       #  Length of first element of array.
                       #  (Alternate notation)
echo ${#ARRAY[1]}      #  3
                       #  Length of second element of array.
                       #  arrays in Bash have zero-based indexing.
echo ${#ARRAY[*]}      #  6
                       #  Number of elements in arraY.
echo ${#ARRAY[@]}      #  6
                       #  Number of elements in array.
echo "--------------"

ARRAY2=([0]="first element" [1]="second element" [3]="fourth element")

# Quoting permits embedding whitespace within individual array elements.
echo " The ${ARRAY2[0]}"	# first element
echo " The ${ARRAY2[1]}"	# second element
echo " The ${ARRAY2[2]}"	#
							# Skipped in initialization, and therefore null.
echo " The ${ARRAY2[3]}"    # fourth element
echo " The lenght of ${ARRAY2[0]} ${#ARRAY2[0]}"			# 13     (length of first element)
echo " The number of elements in the ARRAY ${#ARRAY2[*]}"   # 3      (number of elements in array)
exit
