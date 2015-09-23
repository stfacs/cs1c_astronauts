#include "ItemList.h"

/**************************************************************************
* Constructor ItemList
*__________________________________________________________________________
* This function is a constructor that initializes value to ItemList.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
ItemList::ItemList()
{
	head = NULL;
	tail = NULL;
	itemCount = 0;
};

/**************************************************************************
* Deconstructor ~ItemList
*__________________________________________________________________________
* This function is a deconstructor that loops through and de-allocates all
* nodes in the list
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Loops through and de-allocates all nodes in the list
**************************************************************************/
ItemList::~ItemList()
{
	ItemNode *delPtr;

	delPtr = head;

	while(!IsEmpty())
	{
		head = delPtr -> next;
		delete delPtr->myItem;
		delete delPtr;
		delPtr = head;
	}
};

/**************************************************************************
* Method AddItem: Class ItemList
*__________________________________________________________________________
* This method will add a new Item object into a node and will add that
* node to a doubly-linked list in alphabetical order. It also increments
* the itemCount.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newItem : a new Item object
* POST-CONDITIONS
*  Will add a new Item to a doubly-linked list
**************************************************************************/
void ItemList::AddItem(Item *newItem) // PROC - a new sheep object
{
	ItemNode *memPtr;
	ItemNode *searchPtr;
	bool      found;

	itemCount++;

	//ASSIGN - create an empty list and a new node and point the prev & next
	//		   to null
	memPtr = new ItemNode;
	memPtr -> myItem = newItem;
	memPtr -> prev = NULL;
	memPtr -> next = NULL;

	if(IsEmpty()) //if the list is empty, add to the top
	{
		head = memPtr;
		tail = memPtr;
	}
	else if(head->myItem->GetName() > memPtr->myItem->GetName())
	{
		//If the name needs to go first, add to the top
		memPtr -> next = head; //points next to head
		memPtr -> prev = NULL; //points prev to null
		head -> prev   = memPtr;
		head = memPtr;
	}
	else
	{
		searchPtr = head;
		found = false;

		// PROC - will keep searching the list and rearranging nodes in
		//		  alphabetical order only if !found and searchPtr != NULL
		while(searchPtr->next != NULL && !found)
		{
			if(searchPtr->next->myItem->GetName()
			    > memPtr->myItem->GetName())
			{
				found = true;
				memPtr->next = searchPtr->next;
				memPtr->prev = searchPtr;
				searchPtr->next->prev = memPtr;
				searchPtr->next = memPtr;
			}
			else
			{
				searchPtr = searchPtr->next;
			}
		}

		//If the loop exits w/out adding the node it adds to the end
		if(!found)
		{
			memPtr->next = NULL;
			memPtr->prev = searchPtr;
			searchPtr->next = memPtr;
			tail = memPtr;
		}
	}
}

/**************************************************************************
* Method RemoveSheep: Class ItemList
*__________________________________________________________________________
* This method  will search the linked list for the Item specified, and
* then it will remove said Item node from the link list (if found).
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  remItem : the Item's name to remove
* POST-CONDITIONS
*  Will remove a node from a list
**************************************************************************/
void ItemList::RemoveItem(string remItem)
{
	ItemNode *searchPtr;   // PROC - a pointer that points to sheep wanted
	bool		found;	   // PROC - whether a sheep was found or not

	found   = false;
	searchPtr = head;

	// PROC - performs a sequential search that searches for a sheep that
	//		  needs to be removed
	while(!found && searchPtr != NULL)
	{
		if (searchPtr -> myItem -> GetName() == remItem)
		{
			found = true;
		}
		else
		{
			searchPtr = searchPtr -> next;
		}
	}

	// PROC - will remove a node from a list only if srchPtr isn't at NULL
	if(searchPtr != NULL)
	{
		if(searchPtr == head)
		{
			//Will remove from the front
			head = searchPtr -> next;
			searchPtr -> prev = NULL;
		}
		else if(searchPtr == tail)
		{
			//Will remove from the tail
			searchPtr -> prev -> next = NULL;
			tail = searchPtr -> prev;
		}
		else
		{
			//Will remove in the middle of two nodes
			searchPtr -> prev -> next = searchPtr -> next;
			searchPtr -> next -> prev = searchPtr ->prev;
		}
		delete searchPtr->myItem;
		delete searchPtr;
		itemCount--;
	}
	else
	{
//		cout << endl << "There is no item with that name!" << endl;
	}
}

/**************************************************************************
* Method ClearList: Class ItemList
*__________________________________________________________________________
* This method will go through the entire link list and delete every node.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will recreate an empty link list
**************************************************************************/
void ItemList::ClearList()
{
	ItemNode *delPtr;  // PROC - a pointer

	delPtr = head;

	if(itemCount > 0)
	{
//		cout << endl << "Clearing the Item:" << endl;

		while(!IsEmpty())
		{
//			cout << "removing " << delPtr->myItem->GetName() << "...\n";

			head = delPtr -> next;
			delete delPtr->myItem;
			delete delPtr;
			delPtr = head;
		}

//		cout << "The list has been cleared!" << endl;

		//Reinitialize the itemCount to 0 and the tail to NULL
		itemCount = 0;
		tail = NULL;
	}
	else
	{
//		cout << endl << "The list is already empty!" << endl;
	}
}


/**************************************************************************
* Method IsEmtpy: Class ItemList
*__________________________________________________________________________
* This method will return a bool determining if the list is empty
* Returns -> a bool determining if the list is empty
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will return a bool determining if the list is empty
**************************************************************************/
bool ItemList::IsEmpty() const
{
	return head == NULL;
}
