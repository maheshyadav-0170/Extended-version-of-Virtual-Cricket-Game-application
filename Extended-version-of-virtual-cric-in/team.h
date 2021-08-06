/*
"team.h" - header file where Team attributes and methods are declared
*/

#include<vector>
#include "player.h"					//Including the header-file "player.h"

class Team {

	public:

		Team();					//'Team();'			- Constructor

		std :: string name;			//'name'  			- To store the name of the team

		int totalRunsScored;			//'totalRunsScored' - To store the total runs scored by a team during batting
		int totalWicketLost;			//'totalWicketLost'	- To store the total wicket lost by a team during batting
		int totalBallBowled;			//'totalBallsBowled'- To store the total balls bowled by a bowling team

		std :: vector<Player> players; 	//vector<Player> player - To store the list of Player of team

};
