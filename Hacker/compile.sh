#!/bin/bash
read NAME
read FILE
echo "g++ -Wall -o ${NAME} ${FILE}"
g++ -Wall -o ${NAME} ${FILE}
