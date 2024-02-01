#include <iostream>
#include <ctime>

// Rock, Paper, Scissors, Lizard, Spock
// A game similar to rock, paper, scissors

// Scissors cuts Paper
// Paper covers rock
// Rock crushes scissors
// Scissors decapitates lizard
// Lizard poisons spock
// Spock smashes scissors
// Rock crushes lizard
// Lizard eats paper
// Paper Disproves spock
// Spock vaporizes rock

using namespace std;

int const MENU_OPTIONS = 3;
int const WEAPON_OPTIONS = 5;
string const WEAPON[] = { "ROCK", "PAPER", "SCISSORS", "LIZARD", "SPOCK" };

void displayTitle();
void displayRules();
void displayOptions();
void displayWeapons();
void playNewGame(string&, int&, int&, int&);
int askOption(string, int);
bool askYN(string);
int generateComputerSelect();
void clearScreen();
string play();
string battle(int, int);
char validateYN(char, string);
void displayScores(int, int, int);



int main()
{
	bool keepPlaying = true;
	bool again = true;
	int option;
	int playerScore = 0;
	int computerScore = 0;
	int ties = 0;
	string question;
	string winner;

	// Initialize random number generator
	srand((unsigned)time(0));

	displayScores(playerScore, computerScore, ties);
	displayTitle();

	cout << "WELCOME!" << endl << endl;

	displayRules();

	do {
		displayOptions();

		// Get user input to select from main options
		question = "Please select an option: ";
		option = askOption(question, MENU_OPTIONS);

		if (option == 1) // 1 - PLAY A GAME
		{
			do
			{
				playNewGame(winner, playerScore, computerScore, ties);

				if (winner == "player")
				{
					playerScore++;
					cout << "YOU WIN!" << endl;
				}
				else if (winner == "computer")
				{
					computerScore++;
					cout << "YOU LOSE!" << endl;
				}
				else
				{
					ties++;
					cout << "TIE!" << endl;
				}

				cout << endl;

				// Get user input for if they want to play another game
				question = "DO YOU WANT TO PLAY ANOTHER GAME? ";
				again = askYN(question);

			} while (again);

			clearScreen();
		}
		else if (option == 2) // 2 - DISPLAY RULES
		{
			clearScreen();

			displayRules();
		}
		else
		{
			question = "ARE YOU SURE YOU WANT TO EXIT? ";
			if (askYN(question))
			{
				keepPlaying = false;
			}
			else
			{
				clearScreen();
			}
		}
	} while (keepPlaying == true);

	cout << endl << "LIVE LONG AND PROSPER!" << endl;

	cout << endl;
	system("pause");
}



/// <summary>
/// Display the main title
/// </summary>
void displayTitle()
{
	cout << "ROCK, PAPER, SCISSORS, LIZARD, SPOCK" << endl;
	cout << "************************************" << endl << endl;
}



/// <summary>
/// Display the rules
/// </summary>
void displayRules()
{
	cout << "The rules are similar to how rock," << endl;
	cout << "paper, scissors works, but with the" << endl;
	cout << "addition of lizard and spock" << endl;
	cout << "Ways to win are:" << endl;
	cout << "\tScissors cuts Paper" << endl;
	cout << "\tPaper covers rock" << endl;
	cout << "\tRock crushes scissors" << endl;
	cout << "\tScissors decapitates lizard" << endl;
	cout << "\tLizard poisons spock" << endl;
	cout << "\tSpock smashes scissors" << endl;
	cout << "\tRock crushes lizard" << endl;
	cout << "\tLizard eats paper" << endl;
	cout << "\tPaper Disproves spock" << endl;
	cout << "\tSpock vaporizes rock" << endl << endl;
}



/// <summary>
/// Display the main options
/// </summary>
void displayOptions()
{
	cout << "MAIN OPTIONS" << endl;
	cout << "--------------------" << endl;
	cout << "1 - PLAY A GAME" << endl;
	cout << "2 - DISPLAY RULES" << endl;
	cout << "3 - EXIT" << endl << endl;
}



/// <summary>
/// Display the weapon options
/// </summary>
void displayWeapons()
{
	cout << "  WEAPONS" << endl;
	cout << "------------" << endl;
	cout << "1 - ROCK" << endl;
	cout << "2 - PAPER" << endl;
	cout << "3 - SCISSORS" << endl;
	cout << "4 - LIZARD" << endl;
	cout << "5 - SPOCK" << endl;
}



/// <summary>
/// Ask user to select option
/// Validate option
/// </summary>
/// <param name="numOptions"></param>
/// <param name="question"></param>
/// <returns>option</returns>
int askOption(string question, int numOptions)
{
	int option;
	cout << question;
	cin >> option;

	// Validate option
	while (option < 0 || option > numOptions || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "INVALID OPTION!" << endl;
		cout << question;
		cin >> option;
	}

	return option;
}



/// <summary>
/// Start a new game
/// </summary>
/// <returns>winner</returns>
void playNewGame(string& winner, int& playerScore, int& computerScore, int& ties)
{
	clearScreen();
	
	displayScores(playerScore, computerScore, ties);
	
	cout << "GOOD LUCK!" << endl << endl;

	displayWeapons();
	cout << endl;

	winner = play();
}



/// <summary>
/// Play a game
/// </summary>
/// <returns>winner</returns>
string play()
{
	int playerSelect, computerSelect;
	string question;

	// Get user input for weapon choice
	question = "Enter your weapon selection number: ";
	playerSelect = askOption(question, WEAPON_OPTIONS);

	// Make computers selection
	computerSelect = generateComputerSelect();

	cout << endl;
	cout << "You chose " << WEAPON[playerSelect] << endl;
	cout << "The computer chose " << WEAPON[computerSelect] << endl;

	return battle(playerSelect, computerSelect);
}



/// <summary>
/// Calculate the winner of the battle
/// </summary>
/// <param name="playerSelect"></param>
/// <param name="computerSelect"></param>
/// <returns>winner</returns>
string battle(int playerSelect, int computerSelect)
{
	string winner;

	if (
		(playerSelect == 0 && computerSelect == 2) || // Player = ROCK & Computer = SCISSORS
		(playerSelect == 0 && computerSelect == 3) || // Player = ROCK & Computer = LIZARD
		(playerSelect == 1 && computerSelect == 0) || // Player = PAPER & Computer = ROCK
		(playerSelect == 1 && computerSelect == 4) || // Player = PAPER & Computer = SPOCK
		(playerSelect == 2 && computerSelect == 1) || // Player = SCISSORS & Computer = PAPER
		(playerSelect == 2 && computerSelect == 3) || // Player = SCISSORS & Computer = LIZARD
		(playerSelect == 3 && computerSelect == 1) || // Player = LIZARD & Computer = PAPER
		(playerSelect == 3 && computerSelect == 4) || // Player = LIZARD & Computer = SPOCK
		(playerSelect == 4 && computerSelect == 0) || // Player = SPOCK & Computer = ROCK
		(playerSelect == 4 && computerSelect == 2)   // Player = SPOCK & Computer = SCISSORS
		)
	{
		winner = "player";
	}
	else if (playerSelect == computerSelect) // TIE
	{
		winner = "tie";
	}
	else
	{
		winner = "computer";
	}

	return winner;
}



/// <summary>
/// Generate random weapon choice
/// </summary>
/// <returns>Computers weapon selection</returns>
int generateComputerSelect()
{
	return rand() % WEAPON_OPTIONS;
}



/// <summary>
/// Clear console screen
/// </summary>
void clearScreen()
{
	cout << flush;
	system("CLS");
}



/// <summary>
/// Asks the user a yes or no question
/// Gets user input
/// </summary>
/// <param name="question"></param>
/// <returns>bool</returns>
bool askYN(string question)
{
	bool isYes = false;
	char answer;
	question += "(Y or N) ";

	cout << question;
	cin >> answer;
	answer = toupper(answer);
	answer = validateYN(answer, question);

	return answer == 'Y';
}



/// <summary>
/// Validates input is Y or N
/// </summary>
/// <param name="answer"></param>
/// <param name="question"></param>
/// <returns>Y or N</returns>
char validateYN(char answer, string question)
{
	while (answer != 'Y' && answer != 'N' || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "INVALID INPUT!" << endl;
		cout << question;
		cin >> answer;
	}
	return answer;
}



/// <summary>
/// Display Scores
/// </summary>
/// <param name="playerScore"></param>
/// <param name="computerScore"></param>
/// <param name="ties"></param>
void displayScores(int playerScore, int computerScore, int ties)
{
	cout << "PLAYER SCORE: " << playerScore << "   "
		<< "COMPUTER SCORE: " << computerScore << "   "
		<< "TIES: " << ties << endl << endl;
}