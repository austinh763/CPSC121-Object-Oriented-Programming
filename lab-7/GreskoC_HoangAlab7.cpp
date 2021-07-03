//Author: Connor Gresko and Austin Hoang
//CPSC 121 Lab 7
//<11/15/18> (Current Date)

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//Fighter in the ring
class Gladiator
{
private:
	int dmgMin,//The lowest amount of damage a gladiator can inflict with a successful attack
		dmgRange,//The most damage ABOVE Minimum Damage that the gladiator can inflict with a single, non-critical hit
		evasion, //The % chance (0-100) that the gladiator will completely avoid incoming damage when defending
		critical,//The % chance (0-100) that the gladiator will inflict twice (2x) the rolled damage when attacking the opponent (known as a crit)
		maxHealth,//The amount of HP a gladiator will start each fight with
		curHealth;//The amount of HP a gladiator has left before they have died and lost the fight
public:
	//How the gladiator is referenced to the user, provided somehow in the constructor
	std::string name;

	//Called upon creation; prevent any uninitialized values from being available
	Gladiator();//Constructor
				//Use this to obtain all information on our gladiators, including their name.
				//Confirmation of the created gladiator is permitted but NOT required.

	//Calculates a damage roll based on dmgMin, dmgRange, and crit
	//This would be a good place to display a crit notification
	int rollDamage();

	//Displays gladiator's stats, in one or two lines so it's pleasing in a list
	void display();//you're responsible for defining this function

	//Hint: Evasion should be calculated here
	bool takeDamage(int dmgAmt);//Returns whether the gladiator was killed by the damage or not

	//Getters:
	//Accessor for health
	int getCurHealth();
};

//Methods for the Gladiator class.

Gladiator::Gladiator()
{
	//The input number.
	unsigned int inputNum;

	//Checks if an error input has occured.
	bool error = false;

	//Prompt the user for the name.
	std::cout << "Please choose a name for the gladiator\n:";

	std::getline(std::cin, name);

	//Prompt the user for the maximum health.
	std::cout << "Please choose the maximum health. Enter numbers 1-3.\n"
			" Options:\n"
			"  <1>: 150\n"
			"  <2>: 200\n"
			"  <3>: 250\n"
			":";

	do
	{
		error = false;

		std::cin >> inputNum;

		switch(inputNum)
		{
		case 1 : maxHealth = 150;
			break;
		case 2 : maxHealth = 200;
			break;
		case 3 : maxHealth = 250;
			break;
		default:
			std::cout << "Error: Please enter a number between 1 and 3.\n:";
			error = true;
		}
	}while(error);

	curHealth = maxHealth;

	//Prompt the user for the critical hit percentage.
	std::cout << "\nPlease choose the critical hit percentage. Enter numbers 1-3.\n"
			" Options:\n"
			"  <1>: 5%\n"
			"  <2>: 10%\n"
			"  <3>: 15%\n"
			":";

	do
	{
		error = false;

		std::cin >> inputNum;

		switch(inputNum)
		{
		case 1 : critical = 5;
			break;
		case 2 : critical = 10;
			break;
		case 3 : critical = 15;
			break;
		default:
			std::cout << "Error: Please enter a number between 1 and 3.\n:";
			error = true;
		}
	}while(error);

	//Prompt the user for the evasion percentage.
	std::cout << "\nPlease choose the evasion percentage. Enter numbers 1-3.\n"
			" Options:\n"
			"  <1>: 5%\n"
			"  <2>: 10%\n"
			"  <3>: 15%\n"
			":";

	do
	{
		error = false;

		std::cin >> inputNum;

		switch(inputNum)
		{
		case 1 : evasion = 5;
			break;
		case 2 : evasion = 10;
			break;
		case 3 : evasion = 15;
			break;
		default:
			std::cout << "Error: Please enter a number between 1 and 3.\n:";
			error = true;
		}
	}while(error);

	//Prompt the user for the minimum damage.
	std::cout << "\nPlease choose the minimum damage. Enter numbers 1-7.\n"
			" Options:\n"
			"  <1>: 8\n"
			"  <2>: 9\n"
			"  <3>: 10\n"
			"  <4>: 11\n"
			"  <5>: 12\n"
			"  <6>: 13\n"
			"  <7>: 14\n"
			":";

	do
	{
		error = false;

		std::cin >> inputNum;

		switch(inputNum)
		{
		case 1 : dmgMin = 8;
			break;
		case 2 : dmgMin = 9;
			break;
		case 3 : dmgMin = 10;
			break;
		case 4 : dmgMin = 11;
			break;
		case 5 : dmgMin = 12;
			break;
		case 6 : dmgMin = 13;
			break;
		case 7 : dmgMin = 14;
			break;
		default:
			std::cout << "Error: Please enter a number between 1 and 7.\n:";
			error = true;
		}
	}while(error);

	//Prompt the user for the damage range.
	std::cout << "\nPlease choose the damage range. Enter numbers 1-7.\n"
			" Options:\n"
			"  <1>: 16\n"
			"  <2>: 17\n"
			"  <3>: 18\n"
			"  <4>: 19\n"
			"  <5>: 20\n"
			"  <6>: 21\n"
			"  <7>: 22\n"
			":";

	do
	{
		error = false;

		std::cin >> inputNum;

		switch(inputNum)
		{
		case 1 : dmgRange = 16;
			break;
		case 2 : dmgRange = 17;
			break;
		case 3 : dmgRange = 18;
			break;
		case 4 : dmgRange = 19;
			break;
		case 5 : dmgRange = 20;
			break;
		case 6 : dmgRange = 21;
			break;
		case 7 : dmgRange = 22;
			break;
		default:
			std::cout << "Error: Please enter a number between 1 and 7.\n:";
			error = true;
		}
	}while(error);

	std::cin.ignore();
}

void Gladiator::display()
{
	//Display the current stats of the current gladiator.
	std::cout << "STATS:";
	std::cout << "\n--Name: " << name;
	std::cout << "\n--Maximum Health: " << maxHealth;
	std::cout << "\n--Current Health: " << curHealth;
	std::cout << "\n--Critical Hit %: " << critical;
	std::cout << "\n--Evasion %: " << evasion;
	std::cout << "\n--Minimum Damage: " << dmgMin;
	std::cout << "\n--Damage Range: " << dmgRange;
	std::cout << "\n";
}

int Gladiator::rollDamage()
{
	//The damage occured.
	int damage;

	//The critical hit chance.
	int critChance;

	damage = rand() % (dmgRange + 1) + dmgMin;

	critChance = rand() % 100;

	if(critChance < critical)
	{
		std::cout << "CRITICAL STRIKE! ";
		damage *= 2;
	}

	std::cout << name << " swung their sword to deal " << damage <<
			" damage..\n";

	return damage;
}

bool Gladiator::takeDamage(int dmgAmt)
{
	//Checks if the gladiator was killed.
	bool killed;

	//The evasion chance.
	int evasionChance;

	evasionChance = rand() % 100;

	//Check if evading. If so, do not apply the damage.
	if(evasionChance < evasion)
	{
		std::cout << "The attack missed gladiator " << name << "!\n\n";

		killed = false;
	}
	else
	{
		//Apply the damage.
		curHealth -= dmgAmt;

		std::cout << "Gladiator " << name << " took the hit!\n";

		//Check if dead. If so, tell the player that the gladiator is killed.
		if(curHealth <= 0)
		{
			std::cout << "Gladiator " << name << " was defeated!\n\n";
			killed = true;
		}
		else
		{
			std::cout << "Gladiator " << name << " has " << curHealth <<
					" health remaining!\n\n";
			killed = false;
		}
	}

	return killed;
}

//Getters:

//Most simple function, so it's defined here to show syntax you'll be using
int Gladiator::getCurHealth()
{
	return curHealth;
}

//The main function.
int main()
{
	//The two gladiators that will be dynamically allocated to decide when to
	// call the constructor.
	Gladiator* pGladiator1;
	Gladiator* pGladiator2;

	//Setting the random seed for the time.
	srand(time(0));

	//Checks if the player is exiting.
	bool exiting;

	//The input character.
	char inputChar;

	//Prompt the user to enter information for two gladiators.
	std::cout << "Gladiator battle! You will choose stats for two gladiators\n";
	std::cout << "that will fight one another.\n\n";

	do
	{
		std::cout << "Setting the stats for the first gladiator..\n";
		pGladiator1 = new Gladiator();

		std::cout << "Setting the stats for the second gladiator..\n";
		pGladiator2 = new Gladiator();
		
		  while(pGladiator2->name == pGladiator1->name) //Checks whether if the name of Gladiator 2 is the same as Gladiator 1
   		 {						//and asks the user to change it to avoid confusion.
     			
			std::string newName;			//New name of gladiator 2.

			std::cout << "Please enter a different name for Gladiator 2..\n";
			std::getline(std::cin, newName);

			pGladiator2->name = newName;
   		 }
		
		std::cout << "Gladiator 1 Stats:\n\n";
		pGladiator1->display();

		std::cout << "Gladiator 2 Stats:\n\n";
		pGladiator2->display();

		std::cout << "The battle will commence! Press ENTER to start!\n:";
		std::cin.get();

		//The game loop.
		while(true)
		{
			if(pGladiator2->takeDamage(pGladiator1->rollDamage()))
			{
				std::cout << "Gladiator " << pGladiator1->name <<
						" wins!\n\n";
				break;
			}

			if(pGladiator1->takeDamage(pGladiator2->rollDamage()))
			{
				std::cout << "Gladiator " << pGladiator2->name <<
						" wins!\n\n";
				break;
			}
		}

		delete pGladiator1;
		delete pGladiator2;

		//Prompt the user to either play again or exit.
		std::cout << "Would you like to play again? y or n?\n:";

		//Checks if the user entered the right input.
		bool error;

		do
		{
			error = false;

			std::cin >> inputChar;
			std::cin.ignore();

			switch(inputChar)
			{
			case 'y' :
			case 'Y' :
				exiting = false;
				break;
			case 'n' :
			case 'N' :
				exiting = true;
				break;
			default:
				std::cout << "Please enter either y or n.\n:";
				error = true;
			}
		}while(error);

	}while(!exiting);

	return 0;
}
