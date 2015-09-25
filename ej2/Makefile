CC=g++
CFLAGS= -O0 -ggdb -lm -std=c++11
CWFLAGS=-Wall -Wextra -pedantic -O0 -ggdb -lm -std=c++11
SOURCE=ej2.cpp
TARGET=ej2

all: $(SOURCE)
	$(CC) $(CWFLAGS) -o $(TARGET) $(TARGET).cpp 

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp 

clean:
	rm -f *.o
	rm -f $(TARGET)

run: $(SOURCE)
	$(CC) $(CWFLAGS) -o $(TARGET) $(TARGET).cpp 
	./$(TARGET) tests/Tp2Ej2.in tests/Tp2Ej2.out