#include<iostream>
#include<iomanip>
#include<time.h>
#include<Windows.h>

using namespace std;

//defining ANSI codes for colored text 
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BG_YELLOW "\033[43m"
#define BG_CYAN "\033[46m"
#define BG_BLUE "\033[44m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"


struct horse {
	int speed;
	int endurance;
	int position;
	int fatigue;
};

//making array of horse names globally accessible
string names[8] = { "Jonathan", "Joseph","Jotaro", "Josuke", "Giorno", "Jolyne", "Johnny", "Jodio" };

//randomly generating obstacles 
int log_fence_pos = rand() % 145 + 100;
int water_trench = rand() % 145 + 50;
int zigzag_track = rand() % 145 + 50;
int ditch = rand() % 80 + 65;


//function headers
void welcome(string* names);
void movehorse(horse* horses);
void applyfatigue(horse* horses);
void apply_obstacles(horse* horses, int* log_fence_pos, int* water_trench, int* zigzag_track, int* ditch);
void print_race_status(horse* horses, string* names);

int main()
{

	welcome(names);
	horse horses[8];
	srand(time(0));


	//assigning attributes to horses
	for (int i = 0; i < 8; i++)
	{
		horses[i].speed = rand() % 100 + 50;
		horses[i].endurance = rand() % 100 + 20;
		horses[i].position = 0;
		horses[i].fatigue = 1;

	}
	//setting winning variable to false initially 
	bool race_won = false;
	//setting var to -1, so it can be compared with later
	int horse_win = -1;
	//while loop to move horses until one reaches the finish line
	while (race_won != true) {

		movehorse(horses);
		// loop to run until a horse has reached the position of 150 or higher, and checks while horse made it there first
		for (int i = 0; i < 8; i++)
		{
			if (horses[i].position >= 150) {
				if (horse_win == -1 || horses[i].position > horses[horse_win].position) {
					horse_win = i;
				}

			}
		}
		//displaying the horse that won
		if (horse_win != -1) {
			Sleep(300);
			cout << endl;
			cout << YELLOW << "*" << setw(34) << setfill('-') << "*" << RESET;
			cout << CYAN << ITALIC << "\n " << names[horse_win] << " is the winner!" << endl << RESET;
			cout << YELLOW << "*" << setw(34) << setfill('-') << "*" << RESET;

			race_won = true;
			break;
		}
	}

}

void welcome(string* names)
{

	cout << YELLOW << "*" << setw(34) << setfill('-') << "*" << RESET;
	cout << CYAN << ITALIC << "\nWelcome to horse racing simulation! " << RESET << endl;
	cout << YELLOW << "*" << setw(34) << setfill('-') << "*" << endl;
	Sleep(500);

	cout << CYAN << "\nOur main contestants are:\n " << RESET << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << YELLOW << "* " << RESET;
		cout << CYAN << names[i] << RESET << endl;
		Sleep(500);
	}
	cout << endl;
	cout << YELLOW << "*" << setw(34) << setfill('-') << "*" << RESET;
	cout << CYAN << "\nPlacing obstacles..";
	Sleep(700);
	cout << "\nPreparing horses..";
	Sleep(700);
	cout << "\n3..";
	Sleep(1000);
	cout << "\n2..";
	Sleep(1000);
	cout << "\n1..";
	Sleep(1000);
	cout << "\nGO!! " << YELLOW << "~*" << RESET;
	Sleep(700);

}

void movehorse(horse* horses)
{
	//formula used to calculate position of the horse depending on speed, fatigue and endurance
	for (int i = 0; i < 8; i++)
	{
		horses[i].position = horses[i].position + ((horses[i].speed - horses[i].fatigue) / 5) + (horses[i].endurance / 4);
	}
	//applying obstacles and increasing fatigue levels
	apply_obstacles(horses, &log_fence_pos, &water_trench, &zigzag_track, &ditch);
	applyfatigue(horses);
}

void applyfatigue(horse* horses)
{
	//formula used to calculate fatigue of the horse
	for (int i = 0; i < 8; i++)
	{
		horses[i].fatigue = (horses[i].fatigue + horses[i].endurance / 20) + horses[i].speed / 6;
	}
	//printing the status of the race after increased fatigue levels for every iteration
	print_race_status(horses, names);
}

void apply_obstacles(horse* horses, int* log_fence_pos, int* water_trench, int* zigzag_track, int* ditch)
{
	//variable ti be assigned with either 2 or 1, which represent either loss in speed, or gain in fatigue
	int fatigue_or_speed = rand() % 2 + 1;

	//if position of horse is equal to that of the obstacle, speed or fatigue are affected accordingly
	for (int i = 0; i < 8; i++)
	{
		if (horses[i].position == *log_fence_pos)
		{
			if (fatigue_or_speed == 1)
			{
				horses[i].speed = horses[i].speed - 25;
				cout << UNDERLINE << "\nAfter encountering a log fence, " << names[i] << " slowed down" << RESET;
			}
			else
			{
				horses[i].fatigue = horses[i].fatigue + 20;
				cout << UNDERLINE << "\nAfter encountering a log fence, " << names[i] << " became exhausted" << RESET;

			}
		}
		else if (horses[i].position == *water_trench)
		{
			if (fatigue_or_speed == 1)
			{
				horses[i].speed = horses[i].speed - 20;
				cout << UNDERLINE << "\nAfter encountering a water trench, " << names[i] << " slowed down" << RESET;

			}
			else
			{
				horses[i].fatigue = horses[i].fatigue + 20;
				cout << UNDERLINE << "\nAfter encountering a water trench, " << names[i] << " became exhausted" << RESET;

			}
		}
		else if (horses[i].position == *zigzag_track)
		{
			if (fatigue_or_speed == 1)
			{
				horses[i].speed = horses[i].speed - 20;
				cout << UNDERLINE << "\nAfter encountering a zig-zag track, " << names[i] << " slowed down" << RESET;

			}
			else
			{
				horses[i].fatigue = horses[i].fatigue + 25;
				cout << UNDERLINE << "\nAfter encountering a zig-zag track, " << names[i] << " became exhausted" << RESET;

			}
		}
		else if (horses[i].position == *ditch)
		{
			if (fatigue_or_speed == 1)
			{
				horses[i].speed = horses[i].speed - 20;
				cout << UNDERLINE << "\nAfter encountering a ditch, " << names[i] << " slowed down" << RESET;

			}
			else
			{
				horses[i].fatigue = horses[i].fatigue + 25;
				cout << UNDERLINE << "\nAfter encountering a ditch, " << names[i] << " became exhausted" << RESET;

			}
		}

	}
}

void print_race_status(horse* horses, string* names)
{

	Sleep(1000);
	cout << endl << endl;
	cout << BG_BLUE << YELLOW << "\nRACE STATUS: " << RESET << endl;
	Sleep(500);
	//loop to display status of the race after every iteration 
	for (int i = 0; i < 8; i++)
	{
		cout << UNDERLINE << CYAN << names[i] << YELLOW " - Position: " << horses[i].position << " , Fatigue: " << horses[i].fatigue << RESET << endl;
		Sleep(500);

	}

}