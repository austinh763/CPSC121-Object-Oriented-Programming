//Author: Connor Gresko and Austin Hoang
//CPSC 121 Lab 6
//<11/05/18>

#include <iostream>
#include <string>

//Used for calculating numbers using different operations.
struct Calculator 
{
	//The first value is simply a large integer variable. This is also where the answer to an equation is stored.
	//The second value is a POINTER to a large integer. We will be able to use it similarly after syntax differences.
	//To use it, we will need to assign it memory space (using a variables address or, ideally, with the "new" keyword)
	long long LHValue;

	//If the user provides only the = operator, the previous RHValue and operator will be used
	long long* RHValue;

	//Indicates which operator was last used, in case one isn't provided
	char lastOperator;
};

//Parses the input string and performs the calculation.
// Parameters:
// @calc: The calculator used to perform the computations.
// @inputChars: The input chars string that is being parsed.
void PerformCalculation(Calculator* calc, std::string inputChars);

void PerformCalculation(Calculator* calc, std::string inputChars)
{
	//The current char being parsed from the input string.
	char curChar;

	//Checks if the operator has already been found.
	bool foundOperator = false;

	//Checks if the operation is valid.
	bool validOperation = false;

	//Checks if an error has occured in the parsing for loop.
	bool errorFound = false;

	//The current number string of the current number being parsed.
	std::string numberStr = "";

	//Only parse the string if it isn't equals.
	if (inputChars[0] != '=')
	{
		//Parse the input string for getting the l and r values, and the operator value.
		for (unsigned int i = 0; i < inputChars.size(); i++)
		{
			curChar = inputChars[i];

			//Checking if a character was entered.
			if (!isdigit(curChar))
			{
				//Get the operator value, if it exists.
				switch (curChar)
				{
				case '+':
				case '-':
				case '*':
				case '/':
					calc->lastOperator = curChar;

					foundOperator = true;
					break;
				case ' ':
					break;
				default:
					std::cout << "Error: You must enter numbers or an operator (+ - * /).\n";
					errorFound = true;
					break;
				}
			}

			//Checks if an error was found. If so, exit the for loop.
			if (errorFound)
			{
				break;
			}

			//If the operator wasn't already found, get the l value. Otherwise,
			// get the r value.
			if (!foundOperator)
			{
				if (isdigit(curChar))
				{
					do
					{
						numberStr += curChar;

						++i;

						if (i < inputChars.size())
						{
							curChar = inputChars[i];
						}

					} while (isdigit(curChar) && i < inputChars.size());

					--i;

					calc->LHValue = std::stoll(numberStr.c_str());
				}
			}
			else
			{
				if (isdigit(curChar))
				{
					numberStr = "";

					if (calc->RHValue == nullptr)
					{
						calc->RHValue = new long long;
					}

					do
					{
						numberStr += curChar;

						++i;

						if (i < inputChars.size())
						{
							curChar = inputChars[i];
						}

					} while (isdigit(curChar) && i < inputChars.size());

					*calc->RHValue = std::stoll(numberStr.c_str());

					validOperation = true;
				}
			}
		}
	}
	else
	{
		validOperation = true;
	}

	//Perform the actual calculation, and store the result in 
	// LHValue.
	if (validOperation)
	{
		switch (calc->lastOperator)
		{
		case '+':
			calc->LHValue += *calc->RHValue;
			std::cout << "Result: " << calc->LHValue << "\n";
			break;
		case '-':
			calc->LHValue -= *calc->RHValue;
			std::cout << "Result: " << calc->LHValue << "\n";
			break;
		case '*':
			calc->LHValue *= *calc->RHValue;
			std::cout << "Result: " << calc->LHValue << "\n";
			break;
		case '/':
			if (*calc->RHValue != 0)
			{
				calc->LHValue /= *calc->RHValue;
				std::cout << "Result: " << calc->LHValue << "\n";
			}
			else
			{
				std::cout << "Error: Cannot divide by zero!\n";
			}
			break;
		default:
			break;
		}
	}
	else
	{
		std::cout << "Error: The equation isn't valid. You at least need "
			<< "one operator and an r value.\n";
	}
}


int main()
{
	//The calculator being used.
	Calculator calculator;
	calculator.LHValue = 0;
	calculator.RHValue = nullptr;
	calculator.lastOperator = '+';
	
	//The input string from the user.
	std::string inputChars;

	//Checks if quitting the program.
	bool quit = false;

	//Checks if the input is valid.
	bool validInput = true;

	do
	{
		do
		{
			validInput = true;

			//Prompt the user for input.
			std::cout << "Please insert a command for the calculator: ";
			std::getline(std::cin, inputChars);

			if (inputChars.size() < 1)
			{
				validInput = false;
				std::cout << "Error, enter at least 1 character into the input stream.\n";
			}
		} while (!validInput);

	if (inputChars.compare("q") == 0)
	{
		quit = true;
	}
	else
	{
		PerformCalculation(&calculator, inputChars);
	}
		

	} while (!quit);

	//don't forget to delete the r value to prevent a memory leak.
	if (calculator.RHValue != nullptr)
	{
		delete calculator.RHValue;
	}

	return 0;
}
