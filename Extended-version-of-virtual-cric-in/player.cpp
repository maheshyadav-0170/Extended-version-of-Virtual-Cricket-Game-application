/*
"player.cpp" is the source file to define
the attributes and methods declared in 'player.h' header-file
*/

#include "player.h"							//Including the header-file "player.h"


Player :: Player() {

	//Batsman attributes
	 runsScored=0;                          //'runsScore' 	- initially set to zero
	 ballsPlayed=0;                         //'ballsPlayed' - initially set to zero

	//Bowler attributes
	 ballsBowled=0;                         //'ballsBowled' - initially set to zero
	 runsGiven=0;                           //'runsGiven' 	- initially set to zero
	 wicketsTaken=0;                        //'wicketTaken' - initially set to zero
}


