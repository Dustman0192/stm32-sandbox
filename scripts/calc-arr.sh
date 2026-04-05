#! /usr/bin/bash

freq=$(($1*1*10**6))
prescaler=$2
desired=$3

echo "Input Frequency: " $freq "Hz"
echo "Prescaler: " $((prescaler))
echo "Desired Frequency: " $desired "Hz"

autoreload=$((($freq / $prescaler) / $desired))

echo "Results"
echo "======="
echo "Prescaler " $(($prescaler - 1))
echo "Autoreload: " $(($autoreload - 1))
