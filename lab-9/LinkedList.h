#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//Eric May
//CS 121 Fall 18
//Declares a linked list that can hold a variable amount of items

#include <iostream>

//The node class for the linked list.
template <class T>
struct Node
{
	//The data stored in the node.
	T data;

	//The next node that this node points to.
	Node* next = nullptr;
};

//The linked list class. Used to store data into nodes.
template <class T>
class LinkedList
{
private:
	//Points to the entry point for our linked list
	Node<T>* head;

	//Part of extra credit
	int recursiveSum(Node<T>* h = nullptr)
	{
		int sum = 0;

		if(h->next != nullptr)
		{
			sum = recursiveSum(h->next);
		}

		return sum += h->data;
	}

public:
	//Constructor initializes values upon declaration
	LinkedList()
	{
		head = nullptr;
	}

	//Deconstructor frees up any dynamic memory space granted to this class
	~LinkedList()
	{

	}

	//Returns the number of nodes that are contained in the linked list. USEFUL IN OTHER MEMBER FUNCTIONS.
	int size()
	{
		//The number of nodes in the list.
		int count = 0;

		if (head == nullptr)
		{
			count = 0;
		}
		else
		{
			//The cursor for iterating through the linked list.
			Node<T>* pCursor = head;

			count = 1;

			//If the next node isn't nullptr, we are not at the end of the list, and so we count the next node.
			while (pCursor->next != nullptr)
			{
				++count;
				pCursor = pCursor->next;
			}
		}

		return count;
	}

	//Displays all values in the list in order, starting from the head
	void display()
	{
		//The cursor for iterating through the linked list.
		Node<T>* pCursor = head;

		while (pCursor != nullptr)
		{
			std::cout << pCursor->data << ", ";
			pCursor = pCursor->next;
		}

		std::cout << std::endl;
	}

	//Inserts a node containing the argument into the linked list, fulfilling ascending order
	void insertItemSorted(T data)
	{
		//The new node being created.
		Node<T>* node = new Node<T>();
		node->data = data;

		if (head == nullptr)
		{
			head = node;
		}
		else
		{
			//The cursor reading the linked list.
			Node<T>* pCursor = head;

			//The previous node that was examined by the cursor.
			Node<T>* pPrevNode = pCursor;

			//Iterate through every node and find where to insert the node.
			while (pCursor != nullptr)
			{
				//If the current node data is larger than the current data, insert the node before the current node.
				if (pCursor->data > data)
				{
					node->next = pCursor;

					if (pPrevNode == head && pCursor == head)
					{
						head = node;
					}
					else
					{
						pPrevNode->next = node;
					}

					break;
				}

				pPrevNode = pCursor;
				pCursor = pCursor->next;

				//If the last node is found, insert the new node at the end of
				//the list.
				if (pCursor == nullptr)
				{
					pPrevNode->next = node;
				}
			}
		}
	}

	//Returns whether the linked list contains the provided value or not
	bool findValue(T data)
	{
		//The cursor reading the linked list.
		Node<T>* pCursor = head;

		//Checks if the node was found
		bool found = false;

		//Iterate through every node and find where to insert the node.
		while (pCursor != nullptr)
		{
			if(pCursor->data == data)
			{
				found = true;
				break;
			}

			pCursor = pCursor->next;
		}

		return found;
	}

	//If a node is found containing the value passed as an argument, it will be
	// safely removed from the LL.
	void remove(T data)
	{
		//The cursor reading the linked list.
		Node<T>* pCursor = head;

		//The previous node that was examined by the cursor.
		Node<T>* pPrevNode = pCursor;

		//Iterate through every node and find where to insert the node.
		while (pCursor != nullptr)
		{
			if(pCursor != pPrevNode && pCursor->data == data)
			{
				pPrevNode->next = pCursor->next;
				delete pCursor;
				break;
			}
			else if(pCursor == pPrevNode && pCursor->data == data)
			{
				head = pCursor->next;
				delete pCursor;
				break;
			}

			pCursor = pCursor->next;
		}
	}

	int startRecursiveFunction()
	{
		return recursiveSum(head);
	}
};

#endif /* LINKEDLIST_H_ */
