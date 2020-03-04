echo "Rename Current Working Directory"
read NAME
echo -e "OLD Directory\t:$PWD" 
mv ${PWD} ${PWD}/../${NAME}
cd ../
cd ${NAME}
echo -e "NEW Directory\t:$PWD"
 

