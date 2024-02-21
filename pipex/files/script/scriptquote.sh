#!/bin/bash

# Initialize our own variables
output_file=""
verbose=0

# Parse command line options
while getopts "o:v" opt; do
  case ${opt} in
    o)
      output_file=$OPTARG
      ;;
    v)
      verbose=1
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

# Print the values of the variables
echo "output_file = ${output_file}"
echo "verbose = ${verbose}"
