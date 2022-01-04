#!/bin/bash
#파일의 사용권한과 이름 출력
if [ $# -eq 0 ]
then
    echo 사용법 : $0 파일
fi

echo 접근권한	    파일이름
while [ $# -gt 0 ]
do
    file=$1
    if [ -f $file ]
    then
        fileinfo=`ls -l $file`
        perm=`echo $fileinfo | cut -d' ' -f1`
        echo $perm $file
    fi
    shift
done
