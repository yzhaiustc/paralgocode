CC = g++
CPFLAGS = -DHOMEGROWN
LPFLAGS = -pthread
CFLAGS = -mcx16 -O3 -std=c++11 -march=native -Wall $(CPFLAGS) 

all:	reduce seq_reduce seq_scan scan qsort thres_reduce

reduce:	reduce.cpp
	$(CC) $(CFLAGS) reduce.cpp -o reduce $(LPFLAGS)


thres_reduce:	granularity_reduce.cpp
	$(CC) $(CFLAGS) granularity_reduce.cpp -o thres_reduce $(LPFLAGS)

seq_reduce:	seq_reduce.cpp
	$(CC) $(CFLAGS) seq_reduce.cpp -o seq_reduce $(LPFLAGS)

seq_scan: seq_scan.cpp scan.h
	$(CC) $(CFLAGS) seq_scan.cpp -o seq_scan $(LPFLAGS)

scan: scan.cpp scan.h
	$(CC) $(CFLAGS) scan.cpp -o scan $(LPFLAGS)
	
qsort:	quicksort.cpp qsort.h
	$(CC) $(CFLAGS) quicksort.cpp -o qsort $(LPFLAGS)

clean:
	rm -f reduce scan qsort
