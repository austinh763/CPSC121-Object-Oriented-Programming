//Austin Hoang
//CPSC 121 Lab 3
//09/30/2018

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Declaring void functions.

void drawTriangleSizeUp(int size, bool pointingUp) {
	int choice9 = 0;
	cout << "Would you like to display on screen(1) or on a file(2)?: ";
	cin >> choice9;
	if (choice9 == 1)
	{
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		{
			cout << endl;
		}
	}
}
	if (choice9 == 2)
	{
		ofstream cout("myshape.txt");
		for (int i = 0; i <= size; i++)
		{
			for (int j = 0; j < i; j++) {
				cout << "*";
			}
			{
				cout << endl;
			}
		}
	}
}

void drawTriangleSizeDown(int size, bool pointingDown) {
	int choice10 = 0;
	cout << "Would you like to display on screen(1) or on file(2)?: ";
	cin >> choice10;
	if (choice10 == 1)
	{
	for (int i = size; i >= 0; i--)
	{
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		{
			cout << endl;
		}
	}
}
	if (choice10 == 2)
	{
		ofstream cout ("myshape.txt");
			for (int i = size; i >= 0; i--)
			{
				for (int j = 0; j < i; j++) {
					cout << "*";
				}
				{
					cout << endl;
				}
			}
		}
	}

void drawTriangleWordUp(string word, bool PointingUp) {
	int length = word.length();
	int choice7 = 0;
	cout << "Would you like to display this on screen(1) or on a file(2)?: ";
	cin >> choice7;
	if (choice7 == 1)
	{
		for (int i = 0; i <= length; i++) {
			for (int j = 0; j < i; j++) {
				cout << word[j];
			}
			{
				cout << endl;
			}
		}
	}
	if (choice7 == 2)
	{
		ofstream cout("myshape.txt");
		for (int i = 0; i <= length; i++) {
			for (int j = 0; j < i; j++) {
				cout << word[j];
			}
			{
				cout << endl;
			}
		}
	}
}

void drawTriangleWordDown(string word, bool pointingDown) {
	int length = word.length();
	int choice8 = 0;
	cout << "Would you like to display this on screen(1) or on file(2)?: ";
	cin >> choice8;
	if (choice8 == 1)
	{
		for (int i = length; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				cout << word[j];
			}
			{
				cout << endl;
			}
		}
	}
	if (choice8 == 2)
	{
		ofstream cout("myshape.txt");
		for (int i = length; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				cout << word[j];
			}
			{
				cout << endl;
			}
		}
	}
}

void drawRectangle(int width, int height) {
	int choice3 = 0;
	cout << "Would you like to display this on screen(1) or on a file(2)? ";
	cin >> choice3;
	if (choice3 == 1)
	{
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << "*";
			}
			{
				cout << endl;
			}
		}
	}
	if (choice3 == 2)
	{
		ofstream cout("myshape.txt");
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << "*";
			}
			{
				cout << endl;
			}
		}
	}
}

void drawRectangle(string word, int height) {
	int length = word.length();
	int choice4 = 0;
	cout << "Would you like to display this on screen(1) or on a file(2)? ";
	cin >> choice4;
	if (choice4 == 1) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j <= length; j++) {
				cout << word[j];
			}
			{
				cout << endl;
			}
		}
	}

	if (choice4 == 2) {
		ofstream cout("myshape.txt");
		for (int i = 0; i < height; i++) {
			for (int j = 0; j <= length; j++) {
				cout << word[j];
			}
			{
				cout << endl;
			}
		}
	}
}

//Start of main() body and declaring variables for it.

int main() {
	int height = 0;
	int width = 0;
	int size = 0;
	string word = "";

	int choice1 = 0;
	int choice2 = 0;
	int choice11 = 0;
	int choice5 = 0;
	int choice6 = 0;
	int again = 0;

//Start of the actual program

	do

	{
		cout << "Would you like to draw a rectangle(1) or a triangle?(2):";
		cin >> choice1;
				while (choice1 != 1 && choice1 != 2) //Input invalidation
				{
					cout << "Not an acceptable choice. Please enter 1 or 2.: ";
					cin >> choice1;
				}


		if (choice1 == 1) //Asking user for desired rectangle.
		{
		cout << "Do you want to draw a rectangle using letters(1) or a width(2)? ";
		cin >> choice2;
					while (choice2 != 1 && choice2 != 2) //Input inval.
					{
						cout << "Please enter 1 or 2 for your choice: ";
						cin >> choice2;
					}
				}


		if (choice2 == 1)	//Worded rectangle.
		{
			int height = 0;
			cout << "Please enter a height: ";
			cin >> height;
			cin.ignore();
			cout << "Enter the word: ";
			getline(cin, word);
			drawRectangle(word, height);
		}
		if (choice2 == 2) //Standard rectangle with asterisks.
		{
			cout << "Please enter a height: ";
			cin >> height;
			cout << "please enter a width: ";
			cin >> width;
			drawRectangle(width, height);
    		}


		if (choice1 == 2) //Asking user for their desired triangle.
		{
			cout << "Do you want a triangle with words(1) or size(2)? ";
			cin >> choice5;
				while (choice5 != 1 && choice5 != 2) //input inval.
				{
					cout << "Not acceptable, word(1) or size(2): ";
					cin >> choice5;
				}
			}

		if (choice5 == 1) //Asking user if they want triangle up or down.
		{
			cout << "do you want the triangle pointing up(1) or down(2)? ";
			cin >> choice6;
				while (choice6 != 1 && choice6 != 2) //Input inval.
				{
					cout << "Not acceptable. Up(1) or down(2)?: ";
					cin >> choice6;
				}
			}

			if (choice6 == 1) //For worded triangle pointing up.
			{
				cout << "Please enter a word: ";
				cin.ignore();
				getline(cin, word);
				drawTriangleWordUp(word, true);
			}
			if (choice6 == 2) //For worded triangle pointing down.
			{
				cout << "Please enter a word: ";
				cin.ignore();
				getline(cin, word);
				drawTriangleWordDown(word, true);
			}
		if (choice5 == 2) //For standard triangle using asterisks.
		{
			cout << "Please enter the size of desired triangle: ";
			cin >> size;
			cout << "Pointing up(1) or down(2)? ";
			cin >> choice11;
			while (choice11 != 1 && choice11 != 2) {
				cout << "Not acceptable. Up(1) or down(2)?: ";
				cin >> choice11;
			}
			if (choice11 == 1)
			{
				drawTriangleSizeUp(size, true);
			}
			if (choice11 == 2)
			{
				drawTriangleSizeDown(size, true);

			}
		}
		cout << "Do you want to run again? Yes(1) or no(2)"; //Asking user to either
		cin >> again;																				//end program or repeat.

			while (again != 1 && again != 2)
			{
				cout << "Please enter a valid response. Yes(1) or No(2)";
				cin >> again;
			}

	} while (again == 1);

	return 0;
}
