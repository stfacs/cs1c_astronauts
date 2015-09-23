#ifndef MemberList_H_
#define MemberList_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Member.h"

using namespace std;

class MemberList
{
public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/
	MemberList();  // Constructor
	~MemberList(); // Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/
	void AddMember(Member *newMember);
	void RemoveMember(string remMember);
	void ClearList();


	/*****************
	 **  ACCESSORS  **
	 *****************/
	string OutputList() const;



private:
	struct MemberNode{ Member *storeMember;
					   MemberNode *prev;
					   MemberNode *next;
					 };

	MemberNode *head;
	MemberNode *tail;
	unsigned int memberCount;

	/*****************
	 **  UTILITIES  **
	 *****************/
	bool IsEmpty() const;

};


#endif /* MemberList_H_ */
