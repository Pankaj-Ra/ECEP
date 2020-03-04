echo "Enter The Directory Name And Specify Path"
echo
read PTH
echo
echo -en "Present Permissions for the Directory:\t"
ls -l $PTH
chmod go-rwx $PTH/*
echo
echo -en "New Permissions for the Directory:\t"
ls -l $PTH
