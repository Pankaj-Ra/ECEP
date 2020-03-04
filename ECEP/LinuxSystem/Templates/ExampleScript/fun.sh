echo $1

echo "created a function"
echo $?

display()
{
	echo $#
	echo $@
	return 100
}

FUN_CALL=`display 10 200 `
RET_VAL=$?

echo $RET_VAL
echo $FUN_CALL
