build : texture lf2

texture : texture.cpp ../catPng.o
	g++ -I../ $^ -lGL -lGLU -lglut `libpng-config --ldflags` -o $@

lf2 : lf2.cpp ../catPng.o
	g++ -g -I../ $^ -lGL -lGLU -lglut `libpng-config --ldflags` -o $@

../catPng.o : 
	g++ -c ../catPng.cpp -o ../catPng.o
