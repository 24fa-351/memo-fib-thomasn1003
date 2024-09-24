#!/bin/bash

gcc fib.c -o fib

echo "Nth Value,method,result,real_time,user_time,sys_time" > results.csv

for method in i r
do
    for num in {0..100} 
    do

        result=$(./fib $num $method)


        TIMEFORMAT='%R %U %S'
        exec_time=$( { time ./fib $num $method > /dev/null; } 2>&1 )
        read real_time user_time sys_time <<< $exec_time

        
        echo "$num,$method,$result,$real_time,$user_time,$sys_time" >> results.csv
    done
done