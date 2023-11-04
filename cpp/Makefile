CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=bin/%.o)
EXECUTABLE = bin/collision_simulation

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $@ -lpthread

bin/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -lpthread

clean:
	@rm -rf bin/*

run: $(EXECUTABLE)
	@$(EXECUTABLE)
