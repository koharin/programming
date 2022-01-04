#!/bin/bash
if [ $# -eq 0 ]
then
    echo 사용법 : $0 파일
    exit 1
else
    file=$1 #띄어쓰기 주의!
fi
if [ -f $file ] && [ -w $file ]
then
    uptime > $file
fi
