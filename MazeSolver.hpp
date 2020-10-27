#include <time.h>
#include "./Window.hpp"
#include "./DynamicStack.hpp"
#include "./Position.hpp"

class MazeSolver : public Window {
private:
	Maze* maze;
	Stack<Position*> myStack;

public:
	MazeSolver(Maze* maze) {
		this->maze = maze;
		srand(time(NULL));
		for (int x = 0; x < 53; x++)
			for (int y = 0; y < 53; y++)
				if (maze->getSquare(x, y) == Square::ENTRY) {
					myStack.push(new Position(x,y));
					setDirections();
				}
	}

	~MazeSolver() {
		while (myStack.size()) {
			delete myStack.top();
			myStack.pop();
		}
		delete maze;
	}

	void onUpdate() {
		int dir = -1;
		if (!myStack.top()->getDirectionCount()) {
			if (maze->getSquare(myStack.top()->x, myStack.top()->y) != Square::EXIT)
				myStack.pop();
		}
		else if(myStack.top()->getDirectionCount() == 1) {
			for (int i = 0; i < 4; i++)
				if (myStack.top()->directions[i])
					dir = i;
		}
		else
			while (!(myStack.top()->directions[(dir = rand() % 4)]));

		switch (dir) {
			case Position::NORTH:
				myStack.top()->directions[Position::NORTH] = false;
				myStack.push(new Position(myStack.top()->x, myStack.top()->y - 1));
				setDirections();
				myStack.top()->directions[Position::SOUTH] = false;
			break;
			case Position::EAST:
				myStack.top()->directions[Position::EAST] = false;
				myStack.push(new Position(myStack.top()->x + 1, myStack.top()->y));
				setDirections();
				myStack.top()->directions[Position::WEST] = false;
			break;
			case Position::SOUTH:
				myStack.top()->directions[Position::SOUTH] = false;
				myStack.push(new Position(myStack.top()->x, myStack.top()->y + 1));
				setDirections();
				myStack.top()->directions[Position::NORTH] = false;
			break;
			case Position::WEST:
				myStack.top()->directions[Position::WEST] = false;
				myStack.push(new Position(myStack.top()->x - 1, myStack.top()->y));
				setDirections();
				myStack.top()->directions[Position::EAST] = false;
			break;
		}
	}

	void onRefresh() {
		for (int x = 0; x < 53; x++)
			for (int y = 0; y < 53; y++)
				drawSquare(maze->getSquare(x, y), x, y);
		drawSquare(Square::PATH, myStack.top()->x, myStack.top()->y);
	}

	void setDirections() {
		myStack.top()->directions[Position::EAST] = maze->getSquare(myStack.top()->x + 1, myStack.top()->y) != Square::WALL;
		myStack.top()->directions[Position::WEST] = maze->getSquare(myStack.top()->x - 1, myStack.top()->y) != Square::WALL;
		myStack.top()->directions[Position::SOUTH] = maze->getSquare(myStack.top()->x, myStack.top()->y + 1) != Square::WALL;
		myStack.top()->directions[Position::NORTH] = maze->getSquare(myStack.top()->x, myStack.top()->y - 1) != Square::WALL;
	}
};
