CC = g++
CPFLAGS = -DHOMEGROWN
LPFLAGS = -pthread
CFLAGS = -mcx16 -O3 -std=c++17 -march=native -Wall $(CPFLAGS) 

all:	reduce

reduce:	reduce.cpp
	$(CC) $(CFLAGS) reduce.cpp -o reduce $(LPFLAGS)
	
clean:
	rm -f reduce
