FILE=$1
if [ -z "$FILE" ]
then
    FILE=main
fi
gcc -g -fsanitize=address src/*.c main/$FILE.c -I include