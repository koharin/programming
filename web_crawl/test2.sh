#!/bin/bash 
file='tag.txt'

while read line 
do
    b=$(docker run --rm $line cat /etc/shadow | grep root)
    docker run -d --name container $line 
    docker cp container:/etc/shadow .
    a=$(cat shadow | grep root)
    echo "$line : $b  $a" >> output.txt
    rm shadow
    docker rm -f `docker ps -aq`
    if [ $(docker images -aq | wc -l) -ge 6 ] ; then
        docker rmi -f `docker images -aq`
    fi
done < $file


