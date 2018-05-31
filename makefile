game : src/*.cpp
	g++ -o game -Idep/GLFW/include -Idep/GLEW/include src/*.cpp -Ldep/GLFW/lib-mingw -Ldep/GLEW/lib/Release/Win32 -lmingw32 -lglew32s -lglfw3 -lopengl32 -lgdi32
