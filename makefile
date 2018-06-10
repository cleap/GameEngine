game : src/*.cpp
	g++ -Wall -std=c++11 -o game -Idep/GLFW/include -Idep/GLEW/include src/*.cpp -Ldep/GLFW/lib-mingw -Ldep/GLEW/lib/Release/Win32 -lmingw32 -lglew32s -lglfw3 -lopengl32 -lgdi32
