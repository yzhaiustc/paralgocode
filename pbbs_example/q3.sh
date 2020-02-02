#!/bin/bash


make clean && make

len=5000000
res_file=q3.txt
rm $res_file

for k in {1..15..1}
do
        n=2
        let threshold=( $n**$k )
        ./seq_reduce $len >> $res_file
        echo $threshold
        for thread in {1..64..1}
        do
            echo $thread
            for n in {1..5..1}
            do
                export NUM_THREADS=${thread}
                ./thres_reduce $len $threshold >> $res_file
            done
        done

done