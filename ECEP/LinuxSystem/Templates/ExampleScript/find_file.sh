#!/bin/bash

if [ $# -eq 0 ] || [ $# -gt 2 ]
then
	echo "Usage: $0 <file to search> [ <where to search> ]"
	exit 1
fi

FILE="$1"

if [ $# -eq 2 ]
then
	DIR="$2"
else
	DIR=.
fi

FOUND_FILE=`find ${DIR} -name "${FILE}"`
if [ -f "${FOUND_FILE}" ]
then
	vi ${FOUND_FILE}
else
	echo "${FILE} not found in ${DIR}"
fi
