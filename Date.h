#ifndef L_18_DATE_H_
#define L_18_DATE_H_

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/****************************************************************
* CLASS Date
* 	This class represents a date. It manages three attributes:
* 		year, month, day
***************************************************************/
class Date
{
	public:
		/****************************
		 * Constructor & Destructor *
		 ****************************/
		Date();

		Date(unsigned short year,
			 unsigned short month,
			 unsigned short day);

		~Date();

		/*************
		 * Mutators  *
		 *************/
		// Uses private utility methods
		void SetDate(unsigned short year,
					 unsigned short month,
					 unsigned short day);

		/*************
		 * Accessors *
		 *************/
		void GetDate(unsigned short &year,
					 unsigned short &month,
					 unsigned short &day) const;

		unsigned short GetYear()  const;
		unsigned short GetMonth() const;
		unsigned short GetDay()   const;
		unsigned short GetDaysSince(unsigned short fromYear,
									unsigned short fromMonth,
									unsigned short fromDay) const;
		unsigned short GetMonthsSince(unsigned short fromYear,
									  unsigned short fromMonth,
									  unsigned short fromDay) const;
		unsigned short GetMonthsSince(Date currentDate) const;
		unsigned short MonthsSince() const;

		// Displays in MM/DD/YYYY format
		string Display() const;

	private:
		/*************
		 * UTILITIES *
		 *************/
		unsigned short GetDaysInMonth(unsigned short year,
									  unsigned short month) const;

		bool IsLeapYear(unsigned short year) const;

		/*************
		 * VALIDATES *
		 *************/

		// Validates the year is between 1900 and the current year
		bool ValidateYear(unsigned short year) const;

		// Validates the month
		bool ValidateMonth(unsigned short month) const;

		// Checks if a day is valid taking leap year into consideration
		bool ValidateDay(unsigned short year,
					 	 unsigned short month,
					 	 unsigned short day) const;

		// Uses methods above to validate a given date
		// (checks against current day)
		bool ValidateDate(unsigned short year,
					 	  unsigned short month,
					 	  unsigned short day) const;

		/*************
		 * ATTRIBUTES *
		 *************/
		unsigned short dateYear;
		unsigned short dateMonth;
		unsigned short dateDay;
};

				/******************************
				** CONSTRUCTOR & DESTRUCTOR **
				******************************/
/**************************************************************
* Date ();
* 	Constructor; Initialize class attributes to current date
* 	Parameters: none
* 	Return: none
***************************************************************/

/**************************************************************
* Date(unsigned short year,
	   unsigned short month,
	   unsigned short day);
* 	Constructor; Initialize class attributes to current date
* 	Parameters: year, month, day
* 	Return: none
***************************************************************/

/**************************************************************
* ~Date ();
*	Destructor; does not perform any specific function
* 	Parameters: none
* 	Return: none
***************************************************************/

					/*************
					 * Mutators  *
					 *************/
/**************************************************************
* void SetDate(unsigned short year,
*			   unsigned short month,
*			   unsigned short day);
*	Mutators; Sets animals name
* 	Parameters: year, month, day
* 	Return: None
***************************************************************/

					/*************
					 * Accessors *
					 *************/
/**************************************************************
* void GetDate(unsigned short &year,
*			   unsigned short &month,
*			   unsigned short &day) const;
*	Accessor; gets year, month, day
* 	Parameters: year, month, day
* 	Return: year, month, day
***************************************************************/

/**************************************************************
* unsigned short GetYear() const;
*	Accessor; gets Month
* 	Parameters: none
* 	Return: Month
***************************************************************/

/**************************************************************
* unsigned short GetMonth() const;
*	Accessor; gets Month
* 	Parameters: none
* 	Return: Month
***************************************************************/

/**************************************************************
* unsigned short GetDay() const;
*	Accessor; gets Day
* 	Parameters: none
* 	Return: Day
***************************************************************/

/**************************************************************
* string DisplayDate() const;
*	Accessor; displays date in MM/DD/YYYY format
* 	Parameters: none
* 	Return: date as string
***************************************************************/

						/*************
						 * UTILITIES *
						 *************/
/**************************************************************
* unsigned short GetDaysInMonth(unsigned short year,
								unsigned short month) const;
*	Accessor; gets days in indicated month
* 	Parameters: year, month
* 	Return: days in the month
***************************************************************/

/**************************************************************
* IsLeapYear(unsigned short year) const
*	Accessor; check whether or not indicated year is a leap year
* 	Parameters: year
* 	Return: bool indiating leap year or not
***************************************************************/

						/*************
						 * VALIDATES *
						 *************/
/**************************************************************
* bool ValidateYear(unsigned short year) const;
*	Accessor; validates the year
* 	Parameters: year
* 	Return: bool indicating valid year or not
***************************************************************/

/**************************************************************
* bool ValidateMonth(unsigned short month) const;
*	Accessor; validates the month
* 	Parameters: month
* 	Return: bool indicating valid month or not
***************************************************************/

/**************************************************************
* bool ValidateDay(unsigned short year,
				   unsigned short month,
				   unsigned short day) const;
*	Accessor; validates the day
* 	Parameters: year, month, day
* 	Return: bool indicating valid day or not
***************************************************************/
/**************************************************************
* bool ValidateDate(unsigned short year,
				   unsigned short month,
				   unsigned short day) const;
*	Accessor; validates the passed in date against current day
* 	Parameters: year, month, day
* 	Return: bool indicating valid date or not
***************************************************************/

#endif /* L_18_DATE_H_ */
