/*
"player.h" -  header file where Player attributes are declared
*/

#include <string>


class Player {

	public:

		Player();				//'Player();'	- Constructor

		//Batsman attributes
		std :: string name;			//'name'  		- To store the name of the player
		int id;					//'id' 			- assigned to each player
		int runsScored;				//'runsScore' 	- to store runs scored by the player
		int ballsPlayed;			//'ballsPlayed' - to store the number of balls a player has player


		//Bowler attributes
		int ballsBowled;			//'ballsBowled' - to store the number of balls a player has thrown
		int runsGiven;				//'runs given' 	- to store how many runs does bowler gave in an over
		int wicketsTaken;			//'wicketsTaken'- to store number of wickets taken by the bowler
};
