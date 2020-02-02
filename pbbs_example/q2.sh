#!/bin/bash


make clean && make
rm *.txt

len=5000000

declare -a algo=("reduce" "scan")

num_of_algo=${#algo[@]}

for (( i=0; i<${num_of_algo}; i++ ));
do
    res_file=res_${algo[$i]}.txt
    ./seq_${algo[$i]} $len &> $res_file
    for thread in {1..8..1}
    do
        for n in {1..20..1}
        do
            export NUM_THREADS=${thread}
            ./${algo[$i]} $len >> $res_file
        done
    done
  
done