build : texture 

texture : texture.cpp ../catPng.o
	g++ -I../ $^ -lGL -lGLU -lglut `libpng-config --ldflags` -o texture

../catPng.o : 
	g++ -c catPng.cpp -o catPng.o
