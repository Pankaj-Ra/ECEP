#!/bin/bash
A=( q w e r t y u i o p a s d f g h j k l z x c v b n m )
B=( Q W E R T Y U I O P A S D F G H J K L Z X C V B N M )
C=( 7 4 1 8 5 2 9 6 3 0 9 8 7 4 5 6 3 2 1 0 8 6 4 1 2 9 )
#D=( % @ # ^ % ^ @ * # * ? ^ * # % @ ? % @ * ^ # @ ^ * # )
TYPE=( ${A[@]} ${B[@]} ${C[@]} )
echo "Random Password Generated"
for (( i=0; i<8; i++ ))
do
VALUES=$(( $RANDOM % 67 ))
CODE=${TYPE[$VALUES]}

echo -n "${CODE}"
done
echo
