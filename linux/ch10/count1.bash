#!/bin/bash
if [ $# -eq 0 ]
then
    dir="." #명령줄 인수 안 줬으면 현재 디렉터리 대상
else
    dir=$1
fi
if [ -d $dir ]
then
    echo -n $dir 내의 파일과 서브디렉터리 개수:
    ls $dir | wc -l
else
    echo $dir : 디렉터리 아님
fi
