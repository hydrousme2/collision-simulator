CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=bin/%.o)
EXECUTABLE = bin/collision_simulation

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $@ 

bin/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	@rm -rf bin/*

run: $(EXECUTABLE)
	@$(EXECUTABLE)
