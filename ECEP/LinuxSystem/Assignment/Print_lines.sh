echo "Enter the File name"
read F
echo "Show output from line no"
read NUM1
echo "To the end of the line"
read NUM2
NUM=1
LINES=$((${NUM2} - ${NUM1}))
OUT_PUT=$((${LINES} + ${NUM}))
echo
echo
echo "Following are the selected lines"
echo
echo
head -${NUM2} ${F} | tail -${OUT_PUT} 


