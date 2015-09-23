#ifndef ItemList_H_
#define ItemList_H_

#include <string>
#include "Item.h"

using namespace std;

class ItemList
{
public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/
	ItemList();  // Constructor
	~ItemList(); // Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/
	void AddItem(Item *newItem);
	void RemoveItem(string remItem);
	void ClearList();


	/*****************
	 **  ACCESSORS  **
	 *****************/
	string OutputList() const;



private:
	struct ItemNode{ Item *myItem;
					 ItemNode *prev;
					 ItemNode *next;
					};

	ItemNode *head;
	ItemNode *tail;
	unsigned int itemCount;

	/*****************
	 **  UTILITIES  **
	 *****************/
	bool IsEmpty() const;

};

#endif /* ItemList_H_ */
