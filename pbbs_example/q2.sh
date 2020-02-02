#!/bin/bash


make clean && make
rm *.txt


declare -a algo=("reduce" "scan")

num_of_algo=${#algo[@]}

for len in {5000000..6000000..50000}
do
    for (( i=0; i<${num_of_algo}; i++ ));
    do
        res_file=res_${algo[$i]}.txt
        echo $res_file
        ./seq_${algo[$i]} $len &> $res_file
        for thread in {1..64..1}
        do
            echo $thread
            for n in {1..20..1}
            do
                export NUM_THREADS=${thread}
                ./${algo[$i]} $len >> $res_file
            done
        done
    done
done