#!/bin/bash

# Check if exactly 1 argument is passed
if [ $# -ne 1 ]; then
  echo "Error: Please provide exactly one number."
  exit 1
fi

# Read the input number from command line argument
num=$1

# Check if the number is less than or equal to 1 (not a prime number)
if [ "$num" -le 1 ]; then
  echo "$num is not a prime number."
  exit 0
fi

# Check for divisibility from 2 to the square root of the number
for ((i=2; i<=$(echo "sqrt($num)" | bc); i++)); do
  if [ $((num % i)) -eq 0 ]; then
    echo "$num is not a prime number."
    exit 0
  fi
done

# If no divisors were found, it's a prime number
echo "$num is a prime number."
