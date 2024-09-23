#!/bin/bash

gcc fib.c -o fib

echo "Nth Value,method,real_time,user_time,sys_time" > results.csv

for method in i r
do
    for num in {0..60} 
    do

        ./fib $num $method > /dev/null

        TIMEFORMAT='%R %U %S'
        exec_time=$( { time ./fib $num $method > /dev/null; } 2>&1 )
        read real_time user_time sys_time <<< $exec_time

        
        echo "$num,$method,$real_time,$user_time,$sys_time" >> results.csv
    done
done