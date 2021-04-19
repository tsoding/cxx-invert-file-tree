CXXFLAGS=-Wall -Wextra -std=c++17 -pedantic

.PHONY: all
all: generator inverter

generator: generator.cpp
	$(CXX) $(CXXFLAGS) -o generator generator.cpp

inverter: inverter.cpp
	$(CXX) $(CXXFLAGS) -o inverter inverter.cpp
