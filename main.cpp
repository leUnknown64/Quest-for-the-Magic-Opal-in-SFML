#include "src/Game.h"

int main(){
    // Init Game Engine
    std::srand(time(NULL));
    Game game;

    // Game loop
    while(game.getWindowIsOpen()){
        // Update
        game.update();

        // Render
        game.render();
    }

    return 0;
}
