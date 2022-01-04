#!/bin/bash
if [ $# -eq 0 ]
then
    echo "사용법: trash [-pl] 파일이름*"
    exit 1
else
    file=$1
fi
if [ $file == "-p" ]
then
    cd ~/linux/ch10/trash
    for f in *
    do
        rm -i $f
    done
elif [ $file == "-l" ]
then
    cd ~/linux/ch10/trash
    ls -l

else
    mv ~/linux/ch10/$file ~/linux/ch10/trash
fi
