echo "Select Operation: 1-SCP 2-SSH"
read NUM
if [ $NUM -eq 1 ]
then
echo "SCP-Mention FileName And UserName@IpAddress With Path"
read NUM
FILE1=( $NUM )
echo ${FILE1[0]}
echo ${FILE1[1]}
echo ${FILE1[2]}
scp -r ${PWD}/${FILE1[0]} ${FILE1[1]}:${FILE1[2]}/ 
else
echo "SSH-Mention UserName@ipAddress"
read FILE2
cd 
ssh ${FILE2}
fi
