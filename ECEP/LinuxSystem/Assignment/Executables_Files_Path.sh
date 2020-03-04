IFS=:
for d in $PATH
do
echo 
echo -en "Number of Executable files in:\t"
echo $d | cut -d":" -f1
echo
echo $d | cut -d":" -f1 | find -perm -u+x | wc -l
done
