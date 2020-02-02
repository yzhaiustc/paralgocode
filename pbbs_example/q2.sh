#!/bin/bash


make clean && make
rm *.txt

len=5000000

declare -a algo=("reduce" "scan")

num_of_algo=${#algo[@]}

for (( i=0; i<${num_of_algo}; i++ ));
do
    res_file=res_${algo[$i]}.txt
    echo $res_file
    ./seq_${algo[$i]} $len &> $res_file
    for thread in {1..64..1}
    do
        for n in {1..10..1}
        do
            export NUM_THREADS=${thread}
            echo $NUM_THREADS
            ./${algo[$i]} $len >> $res_file
        done
    done
  
done