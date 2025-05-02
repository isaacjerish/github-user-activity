CXX     := g++
CXXFLAGS:= -Wall -Wextra -Wpedantic -std=c++17 -g
TARGET  := github-user-activity
SRC     := main.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o