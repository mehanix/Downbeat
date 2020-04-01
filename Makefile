CC = g++
CFLAGS = -Wall -g -c

.PHONY: build
build:downbeat

downbeat: 
	g++ -g -o downbeat.out main.cpp src/*.cpp -I./include -lsfml-system -lsfml-graphics -lsfml-window

