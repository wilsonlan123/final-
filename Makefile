# Makefile for building the application

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++11  # Enable C++11 standard

# Object files
NumMonster.o: NumMonster.cpp NumMonster.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Guess_Your_Luck.o: Guess_Your_Luck.cpp Guess_Your_Luck.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

tictactoe.o: tictactoe.cpp tictactoe.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Guess_Your_Luck.h NumMonster.h tictactoe.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linking the final executable
main: NumMonster.o Guess_Your_Luck.o tictactoe.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up command
clean: 
	rm -f main main.o Guess_Your_Luck.o NumMonster.o tictactoe.o

# Mark 'clean' as a phony target
.PHONY: clean
