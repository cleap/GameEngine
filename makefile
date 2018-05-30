game : src/*.cpp
	g++ -o game -Idep/GLFW/include src/*.cpp -Ldep/GLFW/lib-mingw -lmingw32 -lglfw3 -lopengl32 -lgdi32
