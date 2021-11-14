#!/bin/bash

echo "Enter Numbers Of Seconds ? "

read seconds


hour=$((seconds/3600))
minute=$((seconds%3600/60))
second=$((seconds%60))
echo "$hour:$minute:$second"


#OR

printf '%d:%d:%d\n' $((seconds/3600)) $((seconds%3600/60)) $((seconds%60))


