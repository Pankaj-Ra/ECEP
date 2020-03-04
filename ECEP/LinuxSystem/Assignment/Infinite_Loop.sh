LOOP=1

while [ ${LOOP} -le 5 ] | 
do
        echo  "Looping : ${LOOP}"
        LOOP=$((${LOOP} + 1))
done
