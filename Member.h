#ifndef Member_H_
#define Member_H_

#include <string>

using namespace std;

class Member
{
	public:
	/*********************************
	 ** CONSTRUCTOR & DECONSTRUCTOR **
	 *********************************/
	Member();  // Constructor
	~Member(); // Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/

	/*****************
	 **  ACCESSORS  **
	 *****************/
	string GetName() const;

	private:
		string 	name;
		int 	idNum;

	/*****************
	 **  UTILITIES  **
	 *****************/
};

#endif /* Member_H_ */
