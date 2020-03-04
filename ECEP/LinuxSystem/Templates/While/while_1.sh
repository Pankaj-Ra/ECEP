#!/bin/sh

UNIT="x"

while [ "$STRING" != "xxxxxx" ]
do
	STRING=${STRING}${UNIT}
        sleep 1
	echo "string not yet complete: ($STRING)"
done

echo "Done and sting is $STRING"
