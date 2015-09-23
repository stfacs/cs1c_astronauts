#ifndef Item_H_
#define Item_H_

#include <string>

using namespace std;

class Item
{
public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/
	Item();  // Constructor
	~Item(); // Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/


	/*****************
	 **  ACCESSORS  **
	 *****************/
	string GetName() const;


private:
	string name;
	double price;

	/*****************
	 **  UTILITIES  **
	 *****************/

};


#endif /* Item_H_ */
