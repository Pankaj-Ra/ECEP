echo "1-Current logged user"
echo
echo $USER
echo
echo "2-Shell Directory"
echo
echo $SHELL
echo
echo "3-Home Directory"
echo
echo $HOME
echo
echo "4-Current working directory"
echo
echo $PWD
echo
echo "5-Show all available shells in system"
echo
cat /etc/shells
echo
echo "6-OS name  and Version"
echo
echo $MDV_MENU_STYLE
echo $KDE_SESSION_VERSION
echo
echo "Number Of Users Logged On"
echo
who
echo
echo "Hard Disk Info"
echo
df -h
echo
echo "CPU Info"
echo
lsCPU
echo
echo "Memory Info"
echo
cat /proc/meminfo
echo
echo "File Sys Info"
mount
echo
echo "Current Running Process"
echo
ps -ef
