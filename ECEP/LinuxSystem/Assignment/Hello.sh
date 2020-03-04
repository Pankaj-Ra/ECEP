TIME=`date +%k`
if [ $TIME -ge 9 -a $TIME -lt 12 ]
then
echo "Good Morning"
elif [ $TIME -ge 12 -a $TIME -lt 14 ]
then
echo "Lunch Break"
elif [ $TIME -ge 14 -a $TIME -lt 17 ]
then
echo "Good Afternoon"
elif [ $TIME -ge 17 -a $TIME -lt 21 ]
then
echo "Good Evening"
elif [ $TIME -ge 21 -a $TIME -lt 9 ]
then
echo "Good Night"
fi
echo "Pankaj Rangta"


