CC = g++
CFLAGS = -O2 -I../c++ -mcx16 -march=native -fcilkplus -std=c++11

all:	reduce

reduce:	reduce.cpp
	$(CC) $(CFLAGS) -DNDEBUG reduce.cpp -o reduce
	
clean:
	rm -f reduce