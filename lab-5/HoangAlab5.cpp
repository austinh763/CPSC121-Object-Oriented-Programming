//Author: Austin Hoang
//CPSC 121 Lab 5
//<11/02/2018>
#include <iostream>
using namespace std;

//Declaring global constant for array size.

const int size = 5;

//Setting up functions

void Sum(int arrayUser[], int &result) {
  for (int i = 0; i < size; i++)
  {
    result = result + arrayUser[i];
  }
}

double mean(int arrayUser[]) {
  int result;

  Sum(arrayUser, result);

  return static_cast<double>(result)/size;
}

void display(int arrayUser[]) {
  for (int i = 0; i < size; i++)
  {
    cout << arrayUser[i] <<" ";
  }
}

void sequencing(int arrayUser[]) {
  for (int i = 0; i < 4; i++)
  {
    cout << arrayUser[i+1] - arrayUser[i] <<" ";
  }
}

int search(int arrayUser[], int numElems, int value) {
  int index = 0;
  int position = -1;
  bool found = false;

  while (index < numElems && !found)
  {
    if (arrayUser[index] == value)
    {
      found = true;
      position = index;
    }
    index++;
  }
  return position;
}


void sort(int arrayUser[], int size) {
  bool swap;
  int temp;

  do
  {
    swap = false;
    for (int i = 0; i < (size - 1); i++)
    {
      if (arrayUser[i] > arrayUser[i+1])
      {
        temp = arrayUser[i];
        arrayUser[i] = arrayUser[i+1];
        arrayUser[i+1] = temp;
        swap = true;
      }
    }
  } while (swap);
}

void showSortedArray(const int arrayUser[], int size) {
  for (int i = 0; i < size; i++)
  {
    cout << arrayUser[i] << " ";
    cout << endl;
  }
}

void edit(int arrayUser[]) {
  for(int i = 0; i < size; i++)
  {
    cout << "Re-enter integer variable " << i+1 << " : ";
    cin >> arrayUser[i];
  }
}

//Setting up variables in int main.

int main () {
  int choice = 0;
  int arrayUser[size];
  int value = 0;
  int result = 0;
  double r = 0;
  int s = 0;

//Asking user to input values.
  
  for(int i=0; i < size; i++)
  {
  cout << "Enter integer" << i+1 << " : ";
  cin >> arrayUser[i];
}

//While loop in order to have user loop back to step 2.
  
  while(true)
  {

    cout << "\n\n1. Sum" << endl;
    cout << "2. Mean" << endl;
    cout << "3. Display" << endl;
    cout << "4. Sequencing" << endl;
    cout << "5. Search" << endl;
    cout << "6. Sort" << endl;
    cout << "7. Edit" << endl;
    cout << "8. Exit" << endl;
    cout << "Select a choice 1-8: ";
    cin >> choice;

  if (choice == 1)
  {
    Sum(arrayUser, result);
    cout << "\nThe sum of the array is: " << result;
  }
  else if (choice == 2)
  {
    r=mean(arrayUser);

    cout << "\nThe mean is: " << r << endl;

  }
  else if (choice == 3)
  {
    display(arrayUser);
  }
  else if (choice == 4)
  {
    sequencing(arrayUser);
  }
  else if (choice == 5)
  {
    cout << "Enter a value you would like to find: ";
    cin >> value;
    s = search(arrayUser, size, value);
    if(s == -1)
    {
      cout << "\nNot found" << endl;
    }
    else
    {
      cout << "\nFound " << arrayUser[s] << endl;
    }
  }
  else if (choice == 6)
  {
    sort(arrayUser, size);
    cout << "The sorted values are:\n";
    showSortedArray(arrayUser, size);
  }
  else if (choice == 7)
  {
    edit(arrayUser);
  }
  else if (choice == 8)
  {
    return 0;
  }

}

}
