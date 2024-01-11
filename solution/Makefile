CXX = g++
TARGET = process_trades
OBJ = main.o process.o stock.o

CXXFLAGS = -c -Wall

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGET)