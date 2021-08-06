/*
"game.h" - header file where Game attributes and methods are declared
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include<unistd.h>
#include "team.h"

class Game {

	public:
		Game();					//'Game();			- Constructor

		Team teamA, teamB;			//Creating teamA and teamB objects of Team Class
		int playersPerTeam;			//'playersPerTeam'	- To store max no. of players in one team
		int maxPlayers;				//'maxPlayers'		- To store the max players in the match
		int maxBallsInInng;			//'maxBallsInInng'	- To store the no. of balls delivery in an innings
		std :: string players[20];

		Team *battingTeam, *bowlingTeam;
		Player *bowler1, *bowler2, *onStrike, *runner;

		bool isFirstInnings;

        	void welcomeUser();
        	void enter();
        	void displayPlayersList();
        	int getIntegerInput();
        	void selectPlayers();
        	void showTeamPlayers();
        	void toss();
        	void tossChoice(Team);
        	int getRunsScored();
        	void startFirstInnings();
        	bool validateSelectedPlayer(int);
        	void playInnings();
        	void bat();
        	void bat2();
        	bool validateInningsScore();
        	void startSecondInnings();
        	void winner();
        	void summary();
};
