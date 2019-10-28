CC = g++
CFLAGS = -mcx16 -O3 -std=c++17 -march=native -Wall -I../c++ $(CPFLAGS) 
CPFLAGS = -DHOMEGROWN
LPFLAGS = -pthread

all:	reduce

reduce:	reduce.cpp
	$(CC) $(CFLAGS) reduce.cpp -o reduce $(LFLAGS)
	
clean:
	rm -f reduce