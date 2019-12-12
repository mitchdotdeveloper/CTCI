# CC = /Library/Developer/CommandLineTools/usr/bin/g++
# CCFLAGS = -g -Wall
# DEPS = main.h
# OBJ = main.o menu.o fileRead.o addRecord.o delRecord.o showRecord.o saveRecord.o bubbleSort.o merge.o splitList.o listSort.o
#
# %.o: %.cpp $(DEPS)
# 	$(CC) -c -o $@ $< $(CCFLAGS)
#
# linkedList_exe: $(OBJ)
# 	g++ -o $@ $^ $(CCFLAGS)
#
# clean:
# 	rm *.o linkedList_exe
CC = /Library/Developer/CommandLineTools/usr/bin/g++
CCFLAGS = -g -Wall
DEPS = main.h
OBJ = main.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

test_exe: $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm *.o test_exe
