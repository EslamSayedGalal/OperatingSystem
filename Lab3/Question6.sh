#!/bin/bash

echo "Enter Positive Number : "

read number
sum=0
counter=0

while [ $number -ne 0 ]
do
  if [ $number -lt 0 ]
  then
     printf "Error,"
  else
      sum=$(($sum+$number))  
      ((counter++))
  fi
  printf "Enter a positive integer : \n"
  read number
done


if [ $counter -gt 0 ]
then
   echo "scale=2; $sum/$counter" | bc
else
   echo "No AVERAGE"
fi   
