#!/bin/bash 
file='tag.txt'

while read line 
do
    b=$(docker run --rm $line cat /etc/shadow | grep root)
    echo "$line : $b" >> output.txt
    if [ $(docker images -aq | wc -l) -ge 8 ] ; then
        docker rmi -f `docker images -aq`
    fi
done < $file


