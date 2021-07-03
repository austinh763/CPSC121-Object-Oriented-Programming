#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

//Setting up functions.

string getInput() {
  string userInput = "";
  cout  << "Enter string: ";
  getline (cin, userInput);
  return userInput;
}

string printBetween (int a, int b, int step = 1) {
  string printBetween1 = "";
  if (a < b)
  {
    for (int i = a; i <= b; i++)
    {
      cout << i;
    }
  }
  else if (b < a)
  {
    for (int i = b; i <= a; i++)
    {
      cout << i;
    }
  }
  return printBetween1;
}


string nonalnum_removed(string input)
{
  for (int i = 0; i < input.length(); i++)
  {
      if(!isalnum(input[i]))
      {
        input[i] = '\0';
      }
    }
  return input;
}

string alphabet_numberified(string input)
{
  string alphabet_numberified1 = "";
  for(int i = 0; i < input.length(); i++)
  {
    if(isalpha(input[i]))
    {
      int j = input[i];
      alphabet_numberified1 += to_string(j);
    }
    else
      {
      alphabet_numberified1 += input[i];
      }
    }
    return alphabet_numberified1;
}

int sumDigits(string digitString)
{
  int sum = 0;
  for(int i=0; i < digitString.length(); i++)
  {
    if(!isdigit(digitString[i]))
    {
      cout << digitString[i] << "could not be summed" << endl;
    }
    else
    {
      int j = digitString[i];
      sum += j;
    }
  }
  return sum;
}

void saveString(string savedStr)
{
  ofstream myfile;
  myfile.open("HoangAlab4.txt");
  myfile << savedStr;
  myfile.close();

}

//Initializing variables for main().

int main () {
  string word = "word";
  string savedStr = "";
  string digitString = "";
  string userInput = "";
  string input = "";
  int choice = 0;
  int again = 0;

//start of the do-while loop; actual program.

  do

{

  cout << "current string: " << word << endl;       //introducing user choices
  cout << "Select a choice" << endl;                //and displaying arbitrary
  cout << "1. string_getInput" << endl;             //string.
  cout << "2. string_printBetween" << endl;
  cout << "3. string nonalnum_removed" << endl;
  cout << "4. string_alphabetnumberified" << endl;
  cout << "5. int sumDigits" << endl;
  cout << "6. void saveString" << endl;
  cout << "Please enter 1 - 6" << endl;
  cin >> choice;
  cin.ignore();


  if (choice == 1)    //Asking user for thir input and setting that as current
  {                   //string.
    getInput();
    word = getInput();
    cout << word << endl;
  }

  else if (choice == 2) //Printing numbers between 2 numbers by user.
  {
    int a = 0;
    int b = 0;
    cout << "Enter number for a: ";
    cin >> a;
    cin.ignore();
    cout << "Enter number for b: ";
    cin >> b;
    cin.ignore();
    printBetween(a,b);
    word = printBetween(a,b);
    cout << word << endl;
  }
  else if (choice == 3) //Removing non alphanumeric numbers from inputted user
  {                     //string.
    cout << "Enter string: ";
    cin.ignore();
    getline(cin, input);
    nonalnum_removed(input);
    word = nonalnum_removed(input);
    cout << word << endl;

  }
  else if (choice == 4) //Converting alphabetic characters to character code.
  {
    cout << "Enter string: ";
    getline(cin, input);
    alphabet_numberified(input);
    word = alphabet_numberified(input);
    cout << word << endl;
  }
  else if (choice == 5) //Reads user string input as digit and sums them up.
  {
    cout << "Enter string: ";
    cin >> digitString;
    sumDigits(digitString);
    word = sumDigits(digitString);
    cout << word << endl;
  }
  else if (choice == 6) //Outputs current string into a file.
  {
    savedStr = word;
    saveString(word);
  }
  cout << "Do you want to run again? Yes(1) or no(2): "; //Asking user to run again
  cin >> again;                                       //or not.

  			while (again != 1 && again != 2) //Input invalidation.
  			{
  				cout << "Please enter a valid response. Yes(1) or No(2): ";
  				cin >> again;
  			}

  	} while (again == 1);

  	return 0;
}
