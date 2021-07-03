//Author: Austin Hoang
//CPSC 121 Lab 1
//8/27/2018
#include <iostream>
using namespace std;

int main() {

	//setting variables up for input, output, and values of each type of cent
	int cents = 0;
	int cents_Total = 0;
	int cents_Dime = 0;
	int cents_Nickel = 0;
	int cents_Penny = 0;
	int cents_Quarter = 0;

	int quarter = 25;
	int dime = 10;
	int nickel = 5;
	int penny = 1;

	//asking for input
	cout << "Please enter the number of cents you have." << endl;
	cin >> cents;

	//calculations
	cents_Quarter = cents / quarter;
	cents = cents % quarter;
	cents_Dime = cents / dime;
	cents = cents % dime;
	cents_Nickel = cents / nickel;
	cents = cents % nickel;
	cents_Penny = cents / penny;


	cents_Total = cents_Quarter + cents_Dime + cents_Nickel + cents_Penny;

	//displaying total number of coins
	cout << "Quarters: " << cents_Quarter << endl;
	cout << "Dimes: " << cents_Dime << endl;
	cout << "Nickels: " << cents_Nickel << endl;
	cout << "Pennies: " << cents_Penny << endl;
	cout << "You have a total of " << cents_Total << " coins" << endl;

	
	return 0;

}

	
