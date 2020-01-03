CC = /Library/Developer/CommandLineTools/usr/bin/g++
CCFLAGS = -g -Wall -std=c++17
DEPS = hashTable.h
OBJ = main.o hashTable.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS)

hashTable_exe: $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm *.o hashTable_exe
