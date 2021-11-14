#!/bin/bash

echo "Enter a number"
read number

echo "Enter a power"
read power

res=1

for (( i = 1 ; i <= power ; i++ ))
do
     res=$(($res * $number))
done

echo "The Result = $res"
