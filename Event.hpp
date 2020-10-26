#include <SDL2/SDL.h>

class Event {
private:
	static SDL_Event sdlEvent;

public:
    static unsigned int getType();
    static unsigned int getWindowId();
    static unsigned char getWindowEvent();
    static int poll();
};
