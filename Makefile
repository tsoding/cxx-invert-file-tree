CXXFLAGS=-Wall -Wextra -std=c++17 -pedantic
LIBS=-lstdc++fs

.PHONY: all
all: generator inverter

generator: generator.cpp fruits.hpp fruits.cpp
	$(CXX) $(CXXFLAGS) -o generator generator.cpp fruits.cpp $(LIBS)

inverter: inverter.cpp
	$(CXX) $(CXXFLAGS) -o inverter inverter.cpp $(LIBS)
