//Author: Connor Gresko and Austin Hoang
//CPSC 121 Lab 9
//<12/14/18> (Current Date)

#include <iostream>
#include "LinkedList.h"

int main()
{
	//The primary linked list used for testing.
	LinkedList<int> mylist;

	//Output the starting size.
	std::cout << "Starting size: " << mylist.size() << std::endl;

	//Insert items into the list, sorted from smallest to largest.
	mylist.insertItemSorted(4);
	mylist.insertItemSorted(3);
	mylist.insertItemSorted(5);

	//Display the linked list.
	mylist.display();

	//Display the recursive sum.
	std::cout << "The recursive sum of the elements in the list is: " <<
			mylist.startRecursiveFunction() << std::endl;

	//Output the current size of the linked list.
	std::cout << "Size after insertion: " << mylist.size() << std::endl;

	//Remove the element 4 from the linked list.
	mylist.remove(4);

	//Output the current size of the linked list.
	std::cout << "Size after deletion: " << mylist.size() << std::endl;

	//Output the items found.
	std::cout << "1 for item found: " << mylist.findValue(3) << std::endl;
	std::cout << "0 for item missing: " << mylist.findValue(4) << std::endl;

	return 0;
}
