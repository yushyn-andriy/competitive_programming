#!/bin/bash
for i in {1..1000}
do
   python3 create_expression.py > input.txt
   a=$(cat input.txt | python3 -c 'print(eval(input()))')
   b=$(cat input.txt | python3 ca.py)
    if [ $a != $b ]
    then
        cat input.txt > "fail_$i.txt"
    fi

   echo "Test $i..."
done

