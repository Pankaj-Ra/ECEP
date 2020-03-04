echo "Enter Directory Names"
read NAME
ARRAY=( $NAME )
for (( i=0; i<${#ARRAY[@]}; i++ ))
do
echo
echo -e "Contents of Directory:${ARRAY[$i]}"
ls $PWD/Test_dir/${ARRAY[$i]}/
done

