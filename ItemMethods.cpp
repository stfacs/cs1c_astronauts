#include "Item.h"

Item::Item()
{
	price = 0;
}

Item::~Item()
{

}

string Item::GetName() const
{
	return name;
}
