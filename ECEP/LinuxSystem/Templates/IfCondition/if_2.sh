#!/bin/bash

# Move the command line arg files to Backup directory.

BACKUP_DIR=$HOME/BackupFiles 

if [ $# -eq 0 ] # check for command line arguments
then
	echo  "Usage: $0 <files to backup>"
	exit 1
fi

echo $#

if [ ! -d ${BACKUP_DIR} ]
then
	mkdir  ${BACKUP_DIR}
fi

echo "The following files will be saved in the Backup directory:"
echo $*

for FILES in $* # loop through all command line arguments
do
	if [ -f $FILES ]
	then
		cp $FILES ${BACKUP_DIR}
		chmod 400 ${BACKUP_DIR}/$FILES
	fi
done

ls -l  ${BACKUP_DIR}
