#!/bin/bash

list(){
    echo -n "리스트 할 디렉터리 입력: "
    read dir
    echo -----------------------------------------------
    echo $dir
    echo -----------------------------------------------
    ls -l $dir
    echo -----------------------------------------------
}
delete(){
    echo -n "삭제할 파일 이름 입력: "
    read file
    echo -----------------------------------------------
    if [ -f $file ]
    then
        rm -i $file
        echo "    $file 삭제 완료"
    elif [ -d $file ]
    then
        echo $file : 디렉터리입니다. 삭제 불가
    elif [ ! -e $file ]
    then
        echo 존재하지 않는 파일입니다.
    fi
    echo -----------------------------------------------
}
edit(){
    echo -n "편집할 파일 이름 입력: "
    read file
    gedit $file
}
show(){
    echo -n "파일 이름 입력: "
    read file
    echo -----------------------------------------------
    if [ ! -e $file ]
    then
        echo 해당 파일 없음
    elif [ -d $file ]
    then
        echo $file: 디렉터리입니다.
    elif [ -f $file ]
    then
        more $file
    fi
    echo -----------------------------------------------
}
echo -----------------------------------------------
echo 	나의 명령어 메뉴에 오신 것을 환영합니다.
echo -----------------------------------------------
cat << MENU
    1. 파일 리스트
    2. 파일 삭제
    3. 에디터 시작
    4. 파일 내용 보기
    5. 종료
MENU
let stop=0

while (( stop == 0 ))
do
    echo -n "메뉴 번호 입력: "
    read input
    case $input in
        "1") list;;
        "2") delete;;
        "3") edit;;
        "4") show;;
        "5") stop=1;;
        *) echo 잘못된 선택;;
    esac
done
