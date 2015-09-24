#include "MemberList.h"

/**************************************************************************
* Constructor MemberList
*__________________________________________________________________________
* This function is a constructor that initializes value to MemberList.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  only initialize values.
**************************************************************************/
MemberList::MemberList()
{
	head = NULL;
	tail = NULL;
	memberCount = 0;
};

/**************************************************************************
* Deconstructor ~MemberList
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
MemberList::~MemberList()
{
	MemberNode *delPtr;

	delPtr = head;

	while(!IsEmpty())
	{
		head = delPtr -> next;
		delete delPtr->storeMember;
		delete delPtr;
		delPtr = head;
	}
};

/**************************************************************************
* Method AddMember: Class MemberList
*__________________________________________________________________________
* This method will add a new Member object into a node and will add that
* node to a doubly-linked list in alphabetical order. It also increments
* the memberCount.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  newMember : a new Member object
* POST-CONDITIONS
*  Will add a new Member to a doubly-linked list
**************************************************************************/
void MemberList::AddMember(Member *newMember) // PROC - a new sheep object
{
	MemberNode *memPtr;
	MemberNode *searchPtr;
	bool      found;

	memberCount++;

	//ASSIGN - create an empty list and a new node and point the prev & next
	//		   to null
	memPtr = new MemberNode;
	memPtr -> storeMember = newMember;
	memPtr -> prev = NULL;
	memPtr -> next = NULL;

	//if the list is empty, add to the top
	if(IsEmpty())
	{
		head = memPtr;
		tail = memPtr;
	}
	//If the name needs to go first, add to the top
	else if(head->storeMember->GetName() > memPtr->storeMember->GetName())
	{

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
		//		  alphabetical order only if !found and searchPtr->next != NULL
		while(searchPtr->next != NULL && !found)
		{
			if(searchPtr->next->storeMember->GetName()
			    > memPtr->storeMember->GetName())
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

		//If the you exit the while loop w/out adding a node, this adds the node
		// to the end of the list:

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
* Method RemoveSheep: Class MemberList
*__________________________________________________________________________
* This method  will search the linked list for the Member specified, and
* then it will remove said Member node from the link list (if found).
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  remMember : the Member's name to remove
* POST-CONDITIONS
*  Will remove a node from a list
**************************************************************************/
void MemberList::RemoveMember(string remMember)
{
	MemberNode *searchPtr;   // PROC - a pointer that points to sheep wanted
	bool		found;	   // PROC - whether a sheep was found or not

	found   = false;
	searchPtr = head;

	// PROC - performs a sequential search that searches for a sheep that
	//		  needs to be removed
	while(!found && searchPtr != NULL)
	{
		if (searchPtr -> storeMember -> GetName() == remMember)
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
		delete searchPtr->storeMember;
		delete searchPtr;
		memberCount--;
	}
	else
	{
		cout << endl << "There is no member with that name!" << endl;
	}
}

/**************************************************************************
* Method ClearList: Class MemberList
*__________________________________________________________________________
* This method will go through the entire link list and delete every node.
* Returns -> nothing
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will recreate an empty link list
**************************************************************************/
void MemberList::ClearList()
{
	MemberNode *delPtr;  // PROC - a pointer

	delPtr = head;

	if(memberCount > 0)
	{
		cout << endl << "Clearing the Member:" << endl;

		while(!IsEmpty())
		{
			cout << "removing " << delPtr->storeMember->GetName() << "...\n";

			head = delPtr -> next;
			delete delPtr->storeMember;
			delete delPtr;
			delPtr = head;
		}

		cout << "The list has been cleared!" << endl;

		//Reinitialize the memberCount to 0 and the tail to NULL
		memberCount = 0;
		tail = NULL;
	}
	else
	{
		cout << endl << "The list is already empty!" << endl;
	}
}

void MemberList::CreateList(string inFileName)
{
	ifstream inFile;
	string memberName;
	int memberNumber;
	bool bIsMemberExecutive;
	string memberType;
	string memberDate;
	string testString;

	Member *newMember;

	inFile.open(inFileName.c_str());

	while (!inFile.eof())
	{
		getline(inFile, memberName);
		inFile >> memberNumber;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(inFile, testString);
		if (testString == "Executive")
		{
			bIsMemberExecutive = true;
		}

		getline(inFile, memberDate);

		newMember = new Member(memberName, memberNumber);

		AddMember(newMember);
	}
}

string MemberList::OutputList() const
{
	MemberNode *listPtr;
	ostringstream output;

	listPtr = head;

	while(listPtr != NULL)
	{
		output << listPtr->storeMember->GetName() << endl;
		listPtr = listPtr->next;
	}


	return output.str();
}

/**************************************************************************
* Method IsEmtpy: Class MemberList
*__________________________________________________________________________
* This method will return a bool determining if the list is empty
* Returns -> a bool determining if the list is empty
*__________________________________________________________________________
* PRE-CONDITIONS
*  none
* POST-CONDITIONS
*  Will return a bool determining if the list is empty
**************************************************************************/
bool MemberList::IsEmpty() const
{
	return head == NULL;
}

/******************************************************************************
 * Below is all of the linked list code that Steve worked on
 ******************************************************************************/

//class Member {
//public:
//	string name;
//	int number;
//	bool bIsExecutive;
//	string date;
//	Member *next;
//};
//
//class Executive : public Member {
//public:
//	Executive() {
//		rebate = 0.0;
//	};
//	~Executive() {};
//	float rebate;
//private:
//
//};
//
//class MemberList {
//public:
//	MemberList()
//	{
//		head = NULL;
//	}
//	void addMember(string memberName, int memberNumber, bool bIsMemberExecutive, string memberDate) {
//		if (bIsMemberExecutive) {
//			Member* MemberPtr = new Member();
//		}
//		else
//		{
//			Member* MemberPtr = new Executive();
//		}
//		Member* MemberPtr = new Member();
//		MemberPtr->name = memberName;
//		MemberPtr->number = memberNumber;
//		MemberPtr->bIsExecutive = bIsMemberExecutive;
//		MemberPtr->date = memberDate;
//		MemberPtr->next = head;
//		head = MemberPtr;
//	}
//
//	void CreateList() {
//		ifstream inFile;
//		inFile.open("InputFile.txt");
//		string memberName;
//		int memberNumber;
//		bool bIsMemberExecutive = false;
//		string memberType;
//		string memberDate;
//		string testString;
//
//		while (!inFile.eof())
//		{
//			getline(inFile, memberName);
//			inFile >> memberNumber;
//			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
//
//			getline(inFile, testString);
//			if (testString == "Executive")
//			{
//				bIsMemberExecutive = true;
//			}
//
//			getline(inFile, memberDate);
//			addMember(memberName, memberNumber, bIsMemberExecutive, memberDate);
//		}
//	}
//
//	void OutputList()
//	{
//		Member* MemberPtr;
//		void* ExecutivePtr;
//		MemberPtr = head;
//
//		while (MemberPtr != NULL)
//		{
//			cout << MemberPtr->name << "\n";
//			cout << MemberPtr->number << "\n";
//			if (MemberPtr->bIsExecutive)
//			{
//				cout << "Executive\n";
//			}
//			else {
//				cout << "Regular\n";
//			}
//			cout << MemberPtr->date << "\n";
//
//			// Traverse the list by setting pointer to the next element in the head
//			MemberPtr = MemberPtr->next;
//		}
//
//		// Delete pointer as it is no longer needed
//		delete MemberPtr;
//	}
//
//private:
//	Member *head;
//};
