
build : robot.cpp rotation.o ../catPng.o
	g++ $^ -I ../  -lGL -lGLU -lglut `libpng-config --ldflags` -o robot

debug : robot.cpp rotation.o
	g++ $^ -g -I ../  -lGL -lGLU -lglut -o robot

rotation.o : rotation.cpp
	g++ -c rotation.cpp
