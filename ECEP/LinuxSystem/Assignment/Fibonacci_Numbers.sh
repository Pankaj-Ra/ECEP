echo "Enter the desired length of fibonacci series"
read N
echo "Greatest fibonacci No "
NUM1=0
NUM2=1
for (( i=2; i<N; i++ ))
do
	OUT_PUT=$((${NUM1} + ${NUM2}))
	NUM1=${NUM2}
	NUM2=${OUT_PUT}
done
echo ${OUT_PUT}
