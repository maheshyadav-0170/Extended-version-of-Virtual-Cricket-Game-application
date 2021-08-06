/*
=================================================================
 Name        : virtual-cricket-game-application.cpp
 Author      : Mahesh Yadav G
 Program Name: Programming with C and C++
 Project Name: CRIC-IN application (The C & C++ Coding Challenge)
 Description : Building a virtual cricket game CRIC-IN using C++
==================================================================
*/


#include "game.h"

using namespace std;


int main()
{
    Game game;

    game.welcomeUser();

    game.displayPlayersList();

    game.selectPlayers();

    game.showTeamPlayers();

    game.toss();

    game.startFirstInnings();

    game.startSecondInnings();

    game.winner();

    game.summary();

    return 0;
}
