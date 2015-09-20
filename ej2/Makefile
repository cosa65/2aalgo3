CC=g++
CFLAGS= -O0 -ggdb -lm -std=c++11
CWFLAGS=-Wall -Wextra -pedantic -O0 -ggdb -lm -std=c++11
SOURCE=ej2.cpp
TARGET=ej2

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp 

clean:
	rm -f *.o
	rm -f $(TARGET)

full: $(SOURCE)
	$(CC) $(CWFLAGS) -o $(TARGET) $(TARGET).cpp 
