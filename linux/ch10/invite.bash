#!/bin/bash
invitee=(lee kim choi)
for person in ${invitee[*]}
do
    echo "초대의 글: 오늘 저녁 식사 모임에 초대합니다."
    echo $person"께"
done
