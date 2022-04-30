#!/bin/sh

read N

rem=$((N%2))

if [ "$rem" -eq 1 ]; then
    echo Weird
elif [ "$N" -le 5 ] && [ "$N" -ge 2 ]; then
    echo "Not Weird"
elif [ "$N" -le 20 ] && [ "$N" -ge 6 ]; then
    echo "Weird"
elif [ "$N" -gt 20 ]; then
    echo "Not Weird"
fi