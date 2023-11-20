CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=bin/%.o)
EXECUTABLE = bin/collision_simulation

all: $(EXECUTABLE)
	@echo "$(EXECUTABLE) built."

$(EXECUTABLE): $(OBJECTS)
	@echo "Linking Objects ..."
	@$(CXX) $(CXXFLAGS) $^ -o $@ 

bin/%.o: src/%.cpp
	@mkdir -p bin
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	@rm -rf bin

run: $(EXECUTABLE)
	@$(EXECUTABLE)
