#!/bin/bash

# Check if exactly 3 arguments are passed
if [ $# -ne 3 ]; then
  echo "Error: Please provide exactly three numbers."
  exit 1
fi

# Read the input numbers from command line arguments
num1=$1
num2=$2
num3=$3

# Compare the numbers
if [ "$num1" -eq "$num2" ] && [ "$num2" -eq "$num3" ]; then
  echo "The three numbers are equal."
else
  echo "The three numbers are not equal."
fi
