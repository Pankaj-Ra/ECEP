ARRAY=`cut -f1 -d":" /etc/passwd` 
LONGEST=""
for i in ${ARRAY}
do
	if [ ${#LONGEST} -lt ${#i} ]
	then
		LONGEST=${i}
	fi
done
echo -e  "Longest user name\t ${LONGEST}"
for i in ${ARRAY}
do
	if [ ${#ARRAY[0]} -gt ${#i} ]
	then
		ARRAY[0]=${i}
	fi
done
echo -e  "Shortest user name\t ${ARRAY[0]}"
