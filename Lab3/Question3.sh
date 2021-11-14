#!/bin/bash

echo "enter your gross salary"

read salary

if [ $salary -ge 2000 ]
then
    sal=$(($salary-($salary*15/100)))
    
elif [ $salary -lt 2000 -a $salary -ge 1000 ]
then
    sal=$(($salary-($salary*10/100)))
    
else
    sal=$(($salary))
fi

echo "$sal"
