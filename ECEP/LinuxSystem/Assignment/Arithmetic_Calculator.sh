echo "Chose Operation and enter assigned No. 1 Addition
                                       2 Substraction
			    	       3 Division
				       4 Multiplication
			     	       5 Modulum"
read Operation									
ADD=1
SUB=2
DIV=3
MUL=4
MOD=5
echo "Enter Number One"
read NUM1
echo "Enter Number Two"
read NUM2
if [ ${Operation} -eq ${ADD} ]
then
	ADD=$((${NUM1} + ${NUM2}))
	echo -e "Addition\t${ADD}"
elif [ ${Operation} -eq ${SUB} ]
then
	SUB=$((${NUM1} - ${NUM2}))
	echo -e "Substraction\t${SUB}"
elif [ ${Operation} -eq ${DIV} ]
then
	DIV=$((${NUM1} / ${NUM2}))
	echo -e "Division\t${DIV}"
elif [ ${Operation} -eq ${MUL} ]
then
	MUL=$((${NUM1} * ${NUM2}))
	echo -e "Multiplication\t${MUL}"
else
	MOD=$((${NUM1} % ${NUM2}))
	echo -e "Modulum\t${MOD}"
fi



