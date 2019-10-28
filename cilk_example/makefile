CC = g++
CFLAGS = -O2 -I../c++ -mcx16 -march=native -DCILK -fcilkplus -std=c++11

all:	reduce scan

reduce:	reduce.cpp
	$(CC) $(CFLAGS) -DNDEBUG reduce.cpp -o reduce
	
scan:	scan.cpp
	$(CC) $(CFLAGS) -DNDEBUG scan.cpp -o scan

	
clean:
	rm -f reduce scan