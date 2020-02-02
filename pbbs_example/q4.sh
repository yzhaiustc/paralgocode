#!/bin/bash


make clean && make

len=5000000
res_file=q4.txt
rm $res_file

./seq_reduce $len >> $res_file
for k in {1..15..1}
do
        n=2
        let threshold=( $n**$k )
        echo $threshold
        thread=16
            echo $thread
            for n in {1..5..1}
            do
                export NUM_THREADS=${thread}
                ./thres_reduce $len $threshold >> $res_file
            done
done
