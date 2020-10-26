all:
	clear && g++ Application.hpp DynamicStack.hpp Event.hpp Maze.hpp MazeSolver.hpp SLNode.hpp Window.hpp Position.hpp main.cpp -L./ -l420C35JOTP1 -lSDL2main -lSDL2 -o Tp1
run:
	./Tp1
