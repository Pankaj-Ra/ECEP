#!/bin/bash
#
# This simple script removes blank lines from a file
# No argument checking

clear

echo -n "Enter the filename tou want to delete the blank lines : "
read filename

sed -e '/^$/d' $filename
sed -i '/^$/d' $filename

# give the file name you want to remove the blank lines from this file
# -e - Means an editing command 
# -i - Edit insid in place
#'^' - Indicates the bigining of as line
#'$' - Ending of a line
#'d' - Indicates a delete command
