# Makefile for Nostalgia Bytes C++ Games

CXX = g++
CXXFLAGS = -Wall -std=c++17
BIN_DIR = bin
GAMES_DIR = games

# Add new games here as you add their code
GAMES = snake car_race egg_basket

# Default target
all: $(GAMES)

snake:
	$(CXX) $(CXXFLAGS) $(GAMES_DIR)/snake/*.cpp -o $(BIN_DIR)/snake

car_race:
	$(CXX) $(CXXFLAGS) $(GAMES_DIR)/car_race/*.cpp -o $(BIN_DIR)/car_race

egg_basket:
	$(CXX) $(CXXFLAGS) $(GAMES_DIR)/egg_basket/*.cpp -o $(BIN_DIR)/egg_basket

clean:
	rm -f $(BIN_DIR)/*

.PHONY: all clean snake car_race egg_basket
