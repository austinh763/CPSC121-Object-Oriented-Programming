//Author: Connor Gresko and Austin Hoang
//CPSC 121 Lab 8
//<11/26/18> (Current Date)

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

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

	//Randomly generate the maximum health.
	inputNum = rand() % (3);

	maxHealth = 150 + (50 * inputNum);
	curHealth = maxHealth;

	//Randomly generate the critical hit percentage.
	inputNum = rand() % (3);

	critical = 5 + (5 * inputNum);

	//Randomly generate the evasion percentage.
	inputNum = rand() % (3);

	evasion = 5 + (5 * inputNum);

	//Randomly generate the minimum damage.
	inputNum = rand() % (7);

	dmgMin = 8 + inputNum;

	//Randomly generate the damage range.
	inputNum = rand() % (7);

	dmgRange = 16 + inputNum;
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
	
	//Checks if it's a critical strike. 
	if (critChance < critical)
	{
		std::cout << "CRITICAL STRIKE! ";
		damage *= 2;
	}
	
	//If it is a critical strike, apply the extra damage.
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
	if (evasionChance < evasion)
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
if (curHealth <= 0)
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

//A typedef for the gladiator vector.
typedef std::vector<Gladiator*> GladiatorPtrVector;

int main()
{
	//The gladiators in the red team.
	GladiatorPtrVector redTeam;

	//The gladiators in the blue team.
	GladiatorPtrVector blueTeam;

	//The input number for the user.
	int inputNum;

	//Checks if a valid input was entered.
	bool error;

	//The main loop.
	while (true)
	{
		do
		{
			error = false;

			//Prompt the user for input on the main menu.
			std::cout << "1. Add a Gladiator.\n";
			std::cout << "2. Take a turn.\n";
			std::cout << "3. Quit.\n:";

			std::cin >> inputNum;

			std::cin.ignore();

			switch (inputNum)
			{
			case 1:
			{
				std::cout << "Setting the stats for the red team gladiator..\n";
				Gladiator* pGladiator1 = new Gladiator();

				std::cout << "Setting the stats for the blue team gladiator..\n";
				Gladiator* pGladiator2 = new Gladiator();

				while (pGladiator2->name == pGladiator1->name) //Checks whether if the name of Gladiator 2 is the same as Gladiator 1
				{						//and asks the user to change it to avoid confusion.
									
					std::string newName; 			//The new name of gladiator 2.

					std::cout << "Please enter a different name for Gladiator 2..\n";
					std::getline(std::cin, newName);

					pGladiator2->name = newName;
				}

				std::cout << "Gladiator for red team Stats:\n\n";
				pGladiator1->display();

				std::cout << "Gladiator for blue team Stats:\n\n";
				pGladiator2->display();

				redTeam.push_back(pGladiator1);
				blueTeam.push_back(pGladiator2);

				std::cout << "\n\n";
			}
			break;
			case 2:
			{
				bool notEnoughGladiators = false;
				
				//Check to see if there is atleast 1 gladiator on each team.
				
				if (redTeam.size() == 0)	
				{
					std::cout << "Error: You need to add at least one gladiator to team red.\n\n";
					notEnoughGladiators = true;
				}

				if (blueTeam.size() == 0)
				{
					std::cout << "Error: You need to add at least one gladiator to team blue.\n\n";
					notEnoughGladiators = true;
				}

				if (!notEnoughGladiators)
				{
					//The currently selected red gladiator.
					Gladiator* pRedGladiator;

					//The currently selected blue gladiator.
					Gladiator* pBlueGladiator;

					//Checks which team is attacking.
					int teamSelect;

					//The index for the red team vector.
					int redTeamIndex;

					//The index for the blue team vector.
					int blueTeamIndex;

					//The size of the red team.
					unsigned int redTeamSize;

					//The size of the blue team.
					unsigned int blueTeamSize;

					teamSelect = rand() % 2;

					redTeamSize = redTeam.size();
					blueTeamSize = blueTeam.size();

					//Choose which team should attack.
					if (teamSelect == 0)
					{
						std::cout << "Red team attacks!\n";

						//Iterate through every gladiator in the red team and attack
						// random gladiators in the blue team.
						for (unsigned int i = 0; i < redTeamSize; i++)
						{
							if (blueTeamSize == 0)
							{
								break;
							}

							pRedGladiator = redTeam[i];

							blueTeamIndex = rand() % blueTeamSize;
							pBlueGladiator = blueTeam[blueTeamIndex];

							if (pBlueGladiator->takeDamage(pRedGladiator->rollDamage()))
							{
								std::cout << "Gladiator " << pRedGladiator->name <<
									" wins!\n\n";

								delete pBlueGladiator;

								//Look for the gladiator that was killed and remove it.
								for (unsigned int j = 0; j < blueTeamSize;)
								{
									if (blueTeam[j]->getCurHealth() < 1)
									{
										blueTeam.erase(blueTeam.begin() + j);
										blueTeamSize = blueTeam.size();
									}
									else
									{
										j++;
									}
								}
							}
						}
					}
					else
					{
						std::cout << "Blue team attacks!\n";

						//Iterate through every gladiator in the blue team and attack
						// random gladiators in the red team.
						for (unsigned int i = 0; i < blueTeamSize; i++)
						{
							if (redTeamSize == 0)
							{
								break;
							}

							pBlueGladiator = blueTeam[i];

							redTeamIndex = rand() % redTeamSize;
							pRedGladiator = redTeam[redTeamIndex];

							if (pRedGladiator->takeDamage(pBlueGladiator->rollDamage()))
							{
								std::cout << "Gladiator " << pBlueGladiator->name <<
									" wins!\n\n";

								delete pRedGladiator;

								//Look for the gladiator that was killed and remove it.
								for (unsigned int j = 0; j < redTeamSize;)
								{
									if (redTeam[j]->getCurHealth() < 1)
									{
										redTeam.erase(redTeam.begin() + j);
										redTeamSize = redTeam.size();
									}
									else
									{
										j++;
									}
								}
							}
						}
					}
				}
			}
				break;
			case 3:
				break;
			default:
				//Input invalidation.
				std::cout << "Error, enter 1, 2 or 3.\n\n" << std::endl; 
				error = true;
				break;
			}
		} while (error);

		if (inputNum == 3)
		{
			break;
		}
	}

	return 0;
}
