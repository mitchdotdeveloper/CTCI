CC = /Library/Developer/CommandLineTools/usr/bin/g++
CCFLAGS = -g -Wall -std=c++17
DEPS = arrayList.h
OBJ = main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS)

arrayList_exe: $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm *.o arrayList_exe
