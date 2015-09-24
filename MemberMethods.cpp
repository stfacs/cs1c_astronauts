#include "Member.h"

Member::Member()
{
	idNum = 0;
	totalMoneySpent = 0;
	totalPurchases = 0;
}

Member::Member(string newName,
		   	   unsigned int newIdNum)
{
	name = newName;
	idNum = newIdNum;
	totalMoneySpent = 0;
	totalPurchases = 0;
}

Member::~Member()
{

}

string Member::GetName() const
{
	return name;
}
