#include "Member.h"

Member::Member()
{
	idNum = 0;
}

Member::~Member()
{

}

string Member::GetName() const
{
	return name;
}
