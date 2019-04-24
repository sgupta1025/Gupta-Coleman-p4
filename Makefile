CC = g++
LFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
all: launcher tokeit

tokeit: tokeit.cpp
	$(CC) $(LFLAGS) -o tokeit tokeit.cpp

launcher: launcher.cpp
	$(CC) $(LFLAGS) -o launcher launcher.cpp
