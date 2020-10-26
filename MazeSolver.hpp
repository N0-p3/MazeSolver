#include "./Window.hpp"
#include "./DynamicStack.hpp"
#include "./Position.hpp"

class MazeSolver : public Window {
private:
	Maze* maze;
	// TODO : Declarations.
	Stack<Position*> myStack;

public:
	MazeSolver(Maze* maze) {
		this->maze = maze;
		// TODO : Instanciations.
		for (int x = 0; x < 53; x++)
			for (int y = 0; y < 53; y++)
				if (maze->getSquare(x, y) == Square::ENTRY) {
					myStack.push(new Position(x,y));
					setDirections();
				}
	}

	~MazeSolver() {
		// TODO : Liberations.
		delete maze;
	}

	void onUpdate() {
		int dir = -1;
		// TODO : Avancer d'un pas.
		switch (myStack.top()->getDirectionCount()) {
			case 0:
				// TODO : pop until multiple choice
				while(!(myStack.top()->getDirectionCount()))
					myStack.pop();
			break;
			case 1:
				// TODO : fucking go
				for (int i = 0; i < 4; i++)
					if (myStack.top()->directions[i] == true)
						dir = i;
			break;
			case 2:
			case 3:
			case 4:
				// TODO : choose a random path and fucking go
				// 				Affecter dir a random
			break;
		}
		switch (dir) {
			// mettre direction que je vais emprunter a faux
			// se deplacer (nouvelle instance et empiler)
			// determiner les direction possible
			// mettre a faux d'ou je viens
			case Position::NORTH:
				myStack.top()->directions[Position::NORTH] == false;
				myStack.push(new Position(myStack.top()->x, myStack.top()->y - 1));
				setDirections();
				myStack.top()->directions[Position::SOUTH] = false;
			break;
			case Position::EAST:
				myStack.top()->directions[Position::EAST] == false;
				myStack.push(new Position(myStack.top()->x + 1, myStack.top()->y));
				setDirections();
				myStack.top()->directions[Position::WEST] = false;
			break;
			case Position::SOUTH:
				myStack.top()->directions[Position::SOUTH] == false;
				myStack.push(new Position(myStack.top()->x , myStack.top()->y + 1));
				setDirections();
				myStack.top()->directions[Position::NORTH] = false;
			break;
			case Position::WEST:
				myStack.top()->directions[Position::WEST] == false;
				myStack.push(new Position(myStack.top()->x - 1, myStack.top()->y));
				setDirections();
				myStack.top()->directions[Position::EAST] = false;
			break;
		}
	}

	void onRefresh() {
		// TODO : Afficher le labyrinthe.
		for (int x = 0; x < 53; x++)
			for (int y = 0; y < 53; y++)
				drawSquare(maze->getSquare(x, y), x, y);
		// TODO : Afficher le chemin parcouru.
		drawSquare(Square::PATH, myStack.top()->x, myStack.top()->y);
	}

	void setDirections() {
		// TODO : Update possible directions
		myStack.top()->directions[Position::EAST] = maze->getSquare(myStack.top()->x + 1, myStack.top()->y) != Square::WALL;
		myStack.top()->directions[Position::WEST] = maze->getSquare(myStack.top()->x - 1, myStack.top()->y) != Square::WALL;
		myStack.top()->directions[Position::SOUTH] = maze->getSquare(myStack.top()->x, myStack.top()->y + 1) != Square::WALL;
		myStack.top()->directions[Position::NORTH] = maze->getSquare(myStack.top()->x, myStack.top()->y - 1) != Square::WALL;
	}
};
