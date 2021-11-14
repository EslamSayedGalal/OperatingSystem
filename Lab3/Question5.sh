#!/bin/bash

echo "Enter Positive Number Only : "

read number
flag=0

if [ $number -eq 1 ]
then
   echo "$number is not a prime number."
else
    for ((i=2; i<=number/2; i++))
    do
      if [ $((number%i)) -eq 0 ]
      then
        echo "$number is not a prime number."
        exit
      fi
    done
    echo "$number is a prime number." 
fi    
