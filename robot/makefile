
build : robot.cpp rotation.o state.o
	g++ $^ -I ../  -lGL -lGLU -lglut -o robot

debug : robot.cpp rotation.o state.o
	g++ $^ -g -I ../  -lGL -lGLU -lglut -o robot

rotation.o : rotation.cpp
	g++ -c rotation.cpp

state.o : state.cpp state.h
	g++ -c state.cpp
