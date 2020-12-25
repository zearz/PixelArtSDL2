#include <iostream>
#include "Game.hpp"

/*
//g++ src/main.cpp -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
int main(int argc, char **argv)
{
    Game game(608,608);
    while(game.launched != false)
    {
        game.Event();
        game.Update();
        game.Render(255,255,255);
    }
    game.~Game(); // Quitte l'éditeur puis efface la mémoire allouée
    
    return EXIT_SUCCESS;
}
*/
int main(int argc, char **argv)
{
    Game game(800,608);
    while(game.launched != false)
    {
        game.Event();
        game.Update();
        game.Render(255,255,255);
    }
    game.~Game(); // Quitte l'éditeur puis efface la mémoire allouée
    
    return EXIT_SUCCESS;
}

// g++ src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2