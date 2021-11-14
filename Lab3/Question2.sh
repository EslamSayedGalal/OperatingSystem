#!/bin/bash

echo "enter a temperature in degrees Celsius"

read Celsius

Fahrenheit=$(((Celsius*9/5)+32))

echo "$Fahrenheit"
