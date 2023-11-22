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
	@echo "Running the program..."
	@time ./$(EXECUTABLE)  # Measure execution time

profile: $(EXECUTABLE)
	@echo "Profiling the program..."
	@g++ -o $(EXECUTABLE)_profiled -pg $(SOURCES) $(CXXFLAGS)
	@./$(EXECUTABLE)_profiled
	@gprof -b ./$(EXECUTABLE)_profiled | grep -A100 "time\s\+seconds" | grep -v "time\s\+seconds" | sort -k2 -n -r > profile_results.txt
	@rm -f $(EXECUTABLE)_profiled gmon.out
	@echo "Profiling results stored in profile_results.txt"

memory: $(EXECUTABLE)
	@echo "Checking memory usage..."
	@valgrind ./$(EXECUTABLE)  # Check memory usage

thread_monitor: $(EXECUTABLE)
	@echo "Monitoring threads..."
	@htop -p "$(EXECUTABLE)"


.PHONY: all clean run profile memory thread_monitor


.PHONY: all clean run profile memory thread_monitor
