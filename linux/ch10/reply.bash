#!/bin/bash

echo -n 계속하시겠습니까?
read reply
if [ $reply == "예" ]
then
    echo 계속합니다
else
    echo 중지합니다
fi
