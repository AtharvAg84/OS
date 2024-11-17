#!/bin/bash

# Check if the number of command-line arguments is 1
if [ $# -eq 0 ]; then
  echo "Error: No input provided. Please provide a number."
  exit 1
fi

# Get the number of terms to display
n=$1

# Validate if the input is a valid positive integer
if ! [[ "$n" =~ ^[0-9]+$ ]] || [ "$n" -lt 1 ]; then
  echo "Error: Please enter a valid positive integer."
  exit 1
fi

# Function to print Fibonacci series
fibonacci() {
  a=0
  b=1
  echo -n "Fibonacci series: "
  for (( i=0; i<n; i++ )); do
    echo -n "$a "
    # Update the values for the next Fibonacci number
    fn=$((a + b))
    a=$b
    b=$fn
  done
  echo
}

# Call the function to print Fibonacci series
fibonacci
