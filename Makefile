CC = g++
CFLAGS = -Wall -g -c

.PHONY: build
build:downbeat

downbeat: 
	g++ -g -o ./bin/downbeat.out main.cpp src/*.cpp src/GUI/*.cpp -I./include -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wfatal-errors -w -std=c++2a

run:
	./bin/downbeat.out