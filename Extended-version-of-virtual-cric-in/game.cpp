/*
"game.h" - header file where Game attributes and methods are defined
*/


#include "game.h"

using namespace std;

Game :: Game() {

	 playersPerTeam=8;                      //'playersPerTeam'	- max players per team is 8
	 maxPlayers=20;                         //'maxPlayers'		- no of players in match is 20
	 maxBallsInInng=12;                     //'maxBallsInInng'	- max balls per innings is 12


	 //Initializing Players name

	 players[0]  = "MS Dhoni        ";
	 players[1]  = "Suresh Raina    ";
	 players[2]  = "Ambati Rayudu   ";
	 players[3]  = "N Jagadeesan    ";
	 players[4]  = "Faf Du Plessis  ";
	 players[5]  = "Ruturaj Gaikwad ";
	 players[6]  = "Sam Curran      ";
	 players[7]  = "Ravi Jadeja     ";
	 players[8]  = "Dwayne Bravo    ";
	 players[9]  = "Virat kohli     ";
	 players[10] = "Shardul Thakur  ";
	 players[11] = "Karn Sharma     ";
	 players[12] = "Imran Tahir     ";
	 players[13] = "Deepak Chahar   ";
	 players[14] = "Lungi Ngidi     ";
	 players[15] = "Mitchell Santner";
	 players[16] = "Hardik Pandya   ";
	 players[17] = "Krunal Pandya   ";
	 players[18] = "Rohith Sharma   ";
	 players[19] = "Ishan kishan    ";

	 isFirstInnings = false;                    //Initially 'isFirstInnings' will be set to zero

	 teamA.name = "Team-A";                     //Setting name for Team A and Team B
	 teamB.name = "Team-B";
}


void Game :: welcomeUser() {                       //Defining the 'welcomeUser' function

	cout<<endl<<endl<<"\t\t\t\t";
	cout<<"====================================================="<<endl;
	cout<<"\t\t\t\t";
	cout<<"------------------------CRIC-IN----------------------"<<endl;
	cout<<"\t\t\t\t";
	cout<<"====================================================="<<endl<<endl;
	cout<<endl;

	usleep(1000000);                             //Pausing the program execution using usleep() function

	cout<<"\t\t\t\t";
	cout<<"------------------BASIC INSTRUCTIONS-----------------"<<endl<<endl;
    usleep(250000);
	//Displaying Basic instructions of the game

	cout<<"\t\t\t\t";
	cout<<"1) Create two teams(Team-A and Team-B each of 8 Players)"<<endl;
	cout<<"\t\t\t\t   from a pool of given 20 Players."<<endl<<endl;
    usleep(250000);

	cout<<"\t\t\t\t";
	cout<<"2) Lead the toss and decide the choice of play."<<endl<<endl;
    usleep(250000);

	cout<<"\t\t\t\t";
	cout<<"3) Each innings will be of 12 balls."<<endl;

	cout<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl<<endl;

    cout<<"\t\t\t\t";
    cout<<"          Press Enter to start the game...";

    enter();
}



void Game :: enter() {

    char temp;
    cin.get(temp);
}



void Game :: displayPlayersList() {

    cout<<"\n\t\t\t\t\t";
    cout<<" Press enter to display players....";
    enter();

    cout<<"\n\n\t\t\t\t\t";
    cout<<"    Displaying Players list..."<<endl;
    usleep(500000);

	cout<<endl<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"\t\t\t\t";
	cout<<"                   List of Players                   "<<endl;
	cout<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl<<endl;

	for(int i=0;i<maxPlayers;i++)                   //Executing iterations for 20 times, maxPlayers=20;
	{
		cout<<"\t\t\t\t\t\t";
        cout<<"["<<i<<"]"<<"\t";
        cout<<players[i]<<endl;
	}

}



int Game :: getIntegerInput() {                     //To get only integer input from the user

	int n;

	while (!(cin >> n))
	{

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\t\t\t\t*****Invalid input! Please try again with valid input:*****"<<endl;		//Print appropriate msg if user enter other than interger
	}

    return n;
}



bool Game :: validateSelectedPlayer(int index) {

	int n;
	vector<Player> players;

	players = teamA.players;
	n = players.size();

	for(int i = 0; i < n; i++)
	{
		if(players[i].id == index)
		{
			return false;
		}
	}

	players = teamB.players;
	n = players.size();

	for (int i = 0; i < n; i++)
	{
		if (players[i].id == index)
		{
			return false;
		}
	}

	return true;
}



void Game :: selectPlayers() {                      //To select Players for Team-A and Team-B

    cout<<"\n\t\t\t\t\t";
    cout<<"   Press Enter to Create teams... ";
    enter();

	cout<<endl<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"\t\t\t\t";
	cout<<"              Create Team-A and Team-B               "<<endl;
	cout<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl<<endl;


	for(int i=0;i<playersPerTeam;i++)								//Selecting Team A players
	{

		TeamAPlayersSelection:				 						//goto label

		cout<<"\t\t\t\t\t";
		cout<<"Select Player "<<i+1<<" for Team-A - ";

		int indexOfPlayerA = getIntegerInput();						//Taking index of the Player using "getIntegerInput()" function

		if( indexOfPlayerA < 0 || indexOfPlayerA > maxPlayers) 		//Checks if User enter index other than the displayed
		{
			cout<<"\n\t\t\t\t";
			cout<<"Please select players from a given set of pool!!!"<<endl;
			goto TeamAPlayersSelection;
		}
		else if(!(validateSelectedPlayer(indexOfPlayerA)))			//Checks if User enters Index Twice
		{
			cout<<"\n\t\t\t\t";
			cout<<"The Players has been already selected!!! Select another Player"<<endl;
			goto TeamAPlayersSelection;
		}
		else
		{
			Player TeamAPlayer;										//Creating TeamAPlayer object of Class Player
			TeamAPlayer.id = indexOfPlayerA;						//Initializing the player id
			TeamAPlayer.name = players[indexOfPlayerA];
			teamA.players.push_back(TeamAPlayer);
		}


		TeamBPlayersSelection:	                             	   //goto Label

		cout<<"\t\t\t\t\t";
		cout<<"Select Player "<<i+1<<" for Team-B - ";

		int indexOfPlayerB = getIntegerInput();						//Taking index of the Player using "getIntegerInput()" function

		if( indexOfPlayerB < 0 || indexOfPlayerB > maxPlayers)		//Checks if User enter index other than the displayed
			{
				cout<<"\n\t\t\t\t";
				cout<<"Please select players from a given set of pool!!!"<<endl;
				goto TeamBPlayersSelection;
			}

		else if(!(validateSelectedPlayer(indexOfPlayerB)))			//Checks if User enters Index Twice
			{
				cout<<"\n\t\t\t\t";
				cout<<"The Players has been already selected!!! Select another Player"<<endl;
				goto TeamBPlayersSelection;
			}

		else
			{
				Player TeamBPlayer;									//Creating TeamBPlayer object of Class Player
				TeamBPlayer.id = indexOfPlayerB;
				TeamBPlayer.name = players[indexOfPlayerB];
				teamB.players.push_back(TeamBPlayer);
			}
	}

}



void Game :: showTeamPlayers() {

    vector<Player> TeamAPlayer = teamA.players;
    vector<Player> TeamBPlayer = teamB.players;

    cout<<"\n\n\t\t\t\t\t"<<"Displaying Team-A and Team-B players..."<<endl<<endl;
    usleep(500000);

	cout<<endl<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"\t\t\t\t";
	cout<<"                List of Team Players                 "<<endl;
	cout<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl<<endl;

    cout<<"\t\t\t\t";
    cout<<"Team-A Players squad             Team-B Players squad"<<endl;
    cout<<"\t\t\t\t";
	cout<<"-----------------------------------------------------"<<endl<<endl;

    for(int i=0;i<playersPerTeam;i++)
	{

		cout << "\t\t\t\t" << "[" << i << "] "<<TeamAPlayer[i].name<<"               "<<"[" << i << "] "<<TeamBPlayer[i].name<<endl;
	}

}



void Game :: toss() {

    cout<<"\n\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t";
    cout<<"                      Lets Toss                        "<<endl;
    cout<<"\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"        Tossing the Coin...";   usleep(1000000);
    cout<<endl;

    srand(time(NULL));
    int randomValueForToss = rand()%2;         							 //Gives either 0 or 1

    switch(randomValueForToss)
    {
        case 0:
        cout<<"\n\t\t\t\t\t";
        cout<<"Team-A won the toss, congratulations!!!";
        tossChoice(teamA);
        break;

        case 1:
        cout<<"\n\n\t\t\t\t";
        cout<<"Team-B won the toss, congratulations!!!"<<endl;
        tossChoice(teamB);
        break;
    }
}



void Game :: tossChoice(Team tossWinnerTeam) {
        cout<<"\n\n\t\t\t\t";
    	cout<<"Enter 1 to bat or 2 to bowl first. "<<endl;
    	cout<<"\t\t\t\t";
       	cout<<"1. Bat"<<endl;
       	cout<<"\t\t\t\t";
        cout<<"2. Bowl"<<endl;

        cout<<"\n\t\t\t\twhat's your choice - ";

	    int tossInput = getIntegerInput();             //Taking only integer input

    	cin.ignore(numeric_limits<streamsize>::max(),'\n');

    	switch (tossInput)
    	{
            case 1:
		    cout<<"\n\t\t\t\t\t"<<tossWinnerTeam.name<<" won the toss and elected to bat first"<<endl<<endl;

		    if (tossWinnerTeam.name.compare("Team-A") == 0)
	            {
			        battingTeam = &teamA;
			        bowlingTeam = &teamB;
		        }
		    else
		        {
			        battingTeam = &teamB;
			        bowlingTeam = &teamA;
		        }
            break;

		    case 2:
			cout<<"\n\t\t\t\t\t"<<tossWinnerTeam.name<<" won the toss and choose to bowl first"<<endl<<endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0)
			    {
					bowlingTeam = &teamA;
					battingTeam = &teamB;
		    	}
		    	else
		    	{
					bowlingTeam = &teamB;
					battingTeam = &teamA;
			    }
			break;

		default:
			cout<<"\n\t\t\t\t\t"<<"Invalid input. Please try again:"<<endl<<endl;
			tossChoice(tossWinnerTeam);              //Again calling the function to opt bat or bowl
			break;
   	    }

}



void Game :: startFirstInnings() {

    cout<<"\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t";
    cout<<"                      First Innings                    "<<endl;
    cout<<"\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl;

    isFirstInnings=true;
    bowler1 = &bowlingTeam->players[0];
	bowler2 = &bowlingTeam->players[1];

	onStrike= &battingTeam->players[0];
	runner= &battingTeam->players[1];

    cout<<"\n\t\t\t\t";
	cout<<"Batting Team - "<<battingTeam->name<<" - "<<"Opening batsmen"<<endl;

    cout<<"\t\t\t\t";
    cout<<"1. "<<onStrike->name<<endl<<"\t\t\t\t"<<"2. "<<runner->name<<endl;


    cout<<"\n\t\t\t\t";
    cout<<"Bowling Team - "<<bowlingTeam->name<<" - "<<"Bowlers "<<endl;

    cout<<"\t\t\t\t";
    cout<<"1. "<<bowler1->name<<endl<<"\t\t\t\t"<<"2. "<<bowler2->name<<endl;

	playInnings();

}



void Game :: startSecondInnings() {

    isFirstInnings=false;

    cout<<"\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t";
    cout<<"                     Second Innings                    "<<endl;
    cout<<"\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl;

    bowler1 = &battingTeam->players[0];
	bowler2 = &battingTeam->players[1];

	onStrike = &bowlingTeam->players[0];
	runner = &bowlingTeam->players[1];

    cout<<"\n\t\t\t\t";
	cout<<"Batting Team - "<<battingTeam->name<<" - "<<"Opening batsmen"<<endl;

    cout<<"\t\t\t\t";
    cout<<"1. "<<onStrike->name<<endl<<"\t\t\t\t"<<"2. "<<runner->name<<endl;


    cout<<"\n\t\t\t\t";
    cout<<"Bowling Team - "<<bowlingTeam->name<<"      -     "<<"Bowlers "<<endl;

    cout<<"\t\t\t\t";
    cout<<"1. "<<bowler1->name<<endl<<"\t\t\t\t"<<"2. "<<bowler2->name<<endl;

    playInnings();

}



void Game :: playInnings() {

    for(int i=0;i<maxBallsInInng;i++)
    {
        char temp;
        cout<<"\n\t\t\t";
        cout<<"Press Enter to bowl..";
        if(i==0)
            if(isFirstInnings)
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get(temp);
        cout<<"\n\t\t\t";
        cout<<"Bowling..."<<endl;
        usleep(500000);
        if(isFirstInnings)
            bat();
        else
            bat2();

        if(!validateInningsScore())
        {
            break;
        }
    }

}



int Game :: getRunsScored()
{
    Runssss:
	int Runs;

	srand(time(NULL));
	Runs = rand()%7;
    if(Runs==5)
    {
        goto Runssss;
    }
    else{
        return Runs;
    }
}



void Game :: bat() {

    srand(time(NULL));

    int runsScored = getRunsScored();

    battingTeam->totalRunsScored += runsScored;
    bowlingTeam->totalBallBowled++;

    if(bowlingTeam->totalBallBowled<6)
    {
        bowler1->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<<bowler1->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;

            onStrike->runsScored += runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven += runsScored;
            battingTeam->totalWicketLost++;
            bowler1->wicketsTaken++;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;


            int index=battingTeam->totalWicketLost;
            index++;
            onStrike=&battingTeam->players[index];
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";

            cout<<bowler1->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored += runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven += runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;
        }
        else
        {
            cout<<"\t\t\t";

            cout<<bowler1->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }

    }
    else if(bowlingTeam->totalBallBowled==6)
    {
        bowler1->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<<bowler1->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;
            battingTeam->totalWicketLost++;
            bowler1->wicketsTaken++;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            int index=battingTeam->totalWicketLost;
            index++;
            onStrike=&battingTeam->players[index];

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";

            cout<<bowler1->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;
            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else
        {
            cout<<"\t\t\t";
            cout<<bowler1->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

        }
    }
    else if(bowlingTeam->totalBallBowled>6 && bowlingTeam->totalBallBowled!=12)
    {
        bowler2->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<< bowler2->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;


            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;
            battingTeam->totalWicketLost++;
            bowler2->wicketsTaken++;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            int index=battingTeam->totalWicketLost;
            index++;
            onStrike=&battingTeam->players[index];
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";
            cout<< bowler2->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;
        }
        else
        {
            cout<<"\t\t\t";
            cout<<bowler2->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
    }
    else if(bowlingTeam->totalBallBowled==12)
    {
        bowler2->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<<bowler2->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;
            battingTeam->totalWicketLost++;
            bowler2->wicketsTaken++;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            int index=battingTeam->totalWicketLost;
            index++;
            onStrike=&battingTeam->players[index];

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";

            cout<<bowler2->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else
        {
            cout<<"\t\t\t";
            cout<<bowler2->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;
        }
    }
}




bool Game::validateInningsScore()
{
    if(isFirstInnings)
    {
        if(battingTeam->totalWicketLost == playersPerTeam || bowlingTeam->totalBallBowled == maxBallsInInng)
        {
                cout<<"\t\t\t\t";
                cout<<"-------------------------------------------------------"<<endl;
                cout<<"\t\t\t\t";
                cout<<"                   First Innings Ends                  "<<endl;
                cout<<"\t\t\t\t";
                cout<<"-------------------------------------------------------"<<endl<<endl;

                cout<<"\t\t\t\t";
                cout<<battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalWicketLost<< " ("<<bowlingTeam->totalBallBowled<<")"<<endl;
                cout<<"\t\t\t\t";
                cout<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored+1<<" runs to win the match. "<<endl<<endl<<endl;
                return false;
        }
    }
    else
    {
        if(bowlingTeam->totalWicketLost == playersPerTeam || battingTeam->totalBallBowled == maxBallsInInng || bowlingTeam->totalRunsScored>battingTeam->totalRunsScored)
        {
                cout<<"\t\t\t\t";
                cout<<"-------------------------------------------------------"<<endl;
                cout<<"\t\t\t\t";
                cout<<"                  Second Innings Ends                  "<<endl;
                cout<<"\t\t\t\t";
                cout<<"-------------------------------------------------------"<<endl<<endl;
            return false;
        }
    }
    return true;
}

void Game::bat2()
{
    srand(time(NULL));
    int runsScored=getRunsScored();

    bowlingTeam->totalRunsScored+=runsScored;
    battingTeam->totalBallBowled++;

    if(battingTeam->totalBallBowled<6)
    {
        bowler1->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<<bowler1->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;
            bowlingTeam->totalWicketLost++;
            bowler1->wicketsTaken++;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<<bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            int index=bowlingTeam->totalWicketLost;
            index++;
            onStrike=&bowlingTeam->players[index];
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";
            cout<<bowler1->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<<bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;
        }
        else
        {

            cout<<"\t\t\t";
            cout<<bowler1->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;
            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<<bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }

    }
    else if(battingTeam->totalBallBowled==6)
    {
        bowler1->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<<bowler1->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;
            bowlingTeam->totalWicketLost++;
            bowler1->wicketsTaken++;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            int index=bowlingTeam->totalWicketLost;
            index++;
            onStrike=&bowlingTeam->players[index];

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";
            cout<<bowler1->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;
            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else
        {
            cout<<"\t\t\t";
            cout<<bowler1->name<<" to       "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler1->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler1->name<<" "<<bowler1->ballsBowled<<" - "<<bowler1->runsGiven<<" - "<<bowler1->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

        }
    }
    else if(battingTeam->totalBallBowled >6 && battingTeam->totalBallBowled !=12)
    {
        bowler2->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<<bowler2->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;
            bowlingTeam->totalWicketLost++;
            bowler2->wicketsTaken++;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            int index=bowlingTeam->totalWicketLost;
            index++;
            onStrike=&bowlingTeam->players[index];
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";
            cout<<bowler2->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;
        }
        else
        {
            cout<<"\t\t\t";
            cout<<bowler2->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
    }
    else
    {
        bowler2->ballsBowled++;
        if(runsScored==0)
        {
            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

            cout<<"\n\t\t\t";
            cout<<bowler2->name<<" to      "<<onStrike->name<<" OUT!"<<endl;

            cout<<"\t\t\t";
            cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;
            bowlingTeam->totalWicketLost++;
            bowler2->wicketsTaken++;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            int index=bowlingTeam->totalWicketLost;
            index++;
            onStrike=&bowlingTeam->players[index];

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else if(runsScored%2==0)
        {
            cout<<"\t\t\t";
            cout<<bowler2->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<< bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

            Player Temp = *onStrike;
            *onStrike = *runner;
            *runner = Temp;
        }
        else
        {
            cout<<"\t\t\t";
            cout<<bowler2->name<<" to      "<<onStrike->name<<" - "<<runsScored<<" runs!"<<endl<<endl;

            onStrike->runsScored+=runsScored;
            onStrike->ballsPlayed++;
            bowler2->runsGiven+=runsScored;

            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t";
            cout<<"\t "<<bowlingTeam->name<<"  "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<") | "<<onStrike->name<<" "<<onStrike->runsScored<<" ("<<onStrike->ballsPlayed<<") \t"<<bowler2->name<<" "<<bowler2->ballsBowled<<" - "<<bowler2->runsGiven<<" - "<<bowler2->wicketsTaken<<endl;
            cout<<"\t\t\t";
            cout<<"--------------------------------------------------------------------------"<<endl<<endl<<endl;

        }
    }
}



void Game::winner()
{
    cout<<"\n\t\t\t\t";
    cout<<"Winning Team is..."<<endl<<endl;
    usleep(1000000);
    cout<<endl;
    if(bowlingTeam->totalRunsScored>battingTeam->totalRunsScored)
    {
        cout<<"\t\t\t\t";
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        cout<<"\n\t\t\t\t";
        cout<< bowlingTeam->name<<" won the match by "<<playersPerTeam - bowlingTeam->totalWicketLost<<" wickets!!"<<endl;
        cout<<"\n\t\t\t\t";
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl<<endl;
    }
    else if(bowlingTeam->totalRunsScored<battingTeam->totalRunsScored)
    {
        cout<<"\t\t\t\t";
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        cout<<"\n\t\t\t\t";
        cout<<battingTeam->name<<" won the match by "<<battingTeam->totalRunsScored - bowlingTeam->totalRunsScored<<" runs!!"<<endl;
        cout<<"\n\t\t\t\t";
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl<<endl;
    }
}



void Game::summary()
{
    usleep(2000000);
    cout<<"\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t";
    cout<<"                       Match Ends                      "<<endl;
    cout<<"\t\t\t\t";
    cout<<"-------------------------------------------------------"<<endl<<endl;


    usleep(1000000);
    cout<<"\t\t\t\t";
    cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<"-"<<battingTeam->totalWicketLost<<" ("<<bowlingTeam->totalBallBowled<<")"<<endl;

    cout<<"\t\t\t\t";
    cout<<"========================================================="<<endl;

    cout<<"\t\t\t\t";
    cout<<"| PLAYER\t\t\tBATTING\t\tBOWLING\t|"<<endl;


    for(int i=0;i<playersPerTeam;i++)
    {
    	cout<<"\t\t\t\t";
        cout<<"|-------------------------------------------------------|"<<endl;
        cout<<"\t\t\t\t";
        cout<<"| ["<<i<<"] "<<battingTeam->players[i].name<<"\t\t"<<battingTeam->players[i].runsScored<<"("<<battingTeam->players[i].ballsPlayed<<")\t\t"<<battingTeam->players[i].ballsBowled<<"-"<<battingTeam->players[i].runsGiven<<"-"<<battingTeam->players[i].wicketsTaken<<"\t|"<<endl;
    }

    cout<<"\t\t\t\t";
    cout<<"========================================================="<<endl<<endl;

    cout<<"\t\t\t\t";
    cout<<bowlingTeam->name<<" "<<bowlingTeam->totalRunsScored<<"-"<<bowlingTeam->totalWicketLost<<" ("<<battingTeam->totalBallBowled<<")"<<endl;
    cout<<"\t\t\t\t";

    cout<<"========================================================="<<endl;
    cout<<"\t\t\t\t";

    cout<<"| PLAYER\t\tBATTING\t\tBOWLING\t|"<<endl;


    for(int i=0;i<playersPerTeam;i++)
    {
    	cout<<"\t\t\t\t";
        cout<<"|-------------------------------------------------------|"<<endl;
        cout<<"\t\t\t\t";
        cout<<"| ["<<i<<"] "<<bowlingTeam->players[i].name<<"\t\t"<<bowlingTeam->players[i].runsScored<<"("<<bowlingTeam->players[i].ballsPlayed<<")\t\t"<<bowlingTeam->players[i].ballsBowled<<"-"<<bowlingTeam->players[i].runsGiven<<"-"<<bowlingTeam->players[i].wicketsTaken<<"\t|"<<endl;
    }
    cout<<"\t\t\t\t";
    cout<<"========================================================="<<endl;
}



