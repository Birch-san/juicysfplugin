#!/usr/bin/env bash
# https://stackoverflow.com/a/67217015/5257399
cd /

echo $1

FILE=`wget -O - -o /dev/null $URL | sed -n 's/.*href="\([^"]*\).*/\1/p' | grep -E ^$1 | egrep -v '.sig$' | sort | tail -1f`

echo $FILE

if [[ $FILE == *.zst ]] # * is used for pattern matching
then
  wget -qO- $URL/$FILE | tar -I zstd -xvf - -C /
elif [[ $FILE == *.xz ]]
then
  wget -qO- $URL/$FILE | tar xJvf - -C /
else
  echo "$FILE is not extracted"
fi
