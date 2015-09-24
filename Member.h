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

	Member(string newName,
		   unsigned int newIdNum);

	~Member(); // Deconstructor

	/****************
	 **  MUTATORS  **
	 ****************/

	/*****************
	 **  ACCESSORS  **
	 *****************/
	string GetName() const;

	private:
		string 		 name;
		unsigned int idNum;
		double  	 totalMoneySpent;
		unsigned int totalPurchases;


	/*****************
	 **  UTILITIES  **
	 *****************/
};

#endif /* Member_H_ */
