#!/bin/bash

# Check if the number is passed as an argument
if [ -z "$1" ]; then
    echo "Error: No input provided. Please enter a number."
    exit 1
fi

# Input number from command line argument
num=$1

# Check if the input is a valid number
if ! [[ "$num" =~ ^[0-9]+$ ]]; then
    echo "Error: Please enter a valid positive integer."
    exit 1
fi

# Reverse the number
reverse=0
while [ $num -gt 0 ]; do
    digit=$((num % 10))         # Extract the last digit
    reverse=$((reverse * 10 + digit)) # Build the reversed number
    num=$((num / 10))           # Remove the last digit from the original number
done

# Print the reversed number
echo "Reversed number: $reverse"


  chomod -x shell.c
  ./shell (values)
  
