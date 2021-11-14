#!/bin/bash

echo "Enter a Number : "
read Num
g=$Num

sum=0
count=0
revers=0

while [ $g -gt 0 ]
do
revers=$(( $revers * 10))
temp=$(( $g % 10))
revers=$(( $revers + $temp))
g=$(( $g / 10))
done


while [ $Num -gt 0 ]
do
	# get Remainder
	k=$(( $Num % 10 ))

	# get next digit
	Num=$(( $Num / 10 ))

	# calculate sum of
	# digit
	sum=$(( $sum + $k ))
	((count++))
done

echo "number is $revers"
echo "sum of digits of $g is : $sum"
printf "average of digits of $g is : "
echo "scale=2; $sum/$count" | bc



