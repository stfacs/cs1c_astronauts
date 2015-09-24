#include "ProjectHeader.h"

int main()
{
	MemberList storeMembers;

	storeMembers.CreateList("Members.txt");
	cout << storeMembers.OutputList();


	return 0;
}
