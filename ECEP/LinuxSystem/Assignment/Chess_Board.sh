echo -e -n "\e[0m\n" " "
for (( i=0; i<8; i++ ))
do
REM=$(( ${i} % 2 ))
for ((k=0; k<2; k++))
do
for (( j=0; j<4; j++ ))
do
if [ $REM -eq 0 ]
then
echo -e -n "\e[40m" " "
echo -e -n "\e[40m" " "
echo -e -n "\033[47m" " "
echo -e -n "\033[47m" " "
else
echo -e -n "\033[47m" " "
echo -e -n "\033[47m" " "
echo -e -n "\e[40m" " "
echo -e -n "\e[40m" " "
fi
done
echo -e -n "\e[0m\n" " "
done
done
echo
