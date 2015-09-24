#include "Date.h"

				/******************************
				** CONSTRUCTOR & DESTRUCTOR **
				******************************/
/**************************************************************
* Date ();
* 	Constructor; Initialize class attributes to current date
* 	Parameters: none
* 	Return: none
***************************************************************/
Date::Date()
{
	time_t now;
	tm *currentTime;

	now = time(NULL);
	currentTime = localtime(&now);

	dateYear  = 1900 + currentTime -> tm_year;
	dateMonth = 1 + currentTime -> tm_mon;
	dateDay   = currentTime -> tm_mday;
}

/**************************************************************
* Date(unsigned short year,
	   unsigned short month,
	   unsigned short day);
* 	Constructor; Initialize class attributes to current date
* 	Parameters: year, month, day
* 	Return: none
***************************************************************/
Date::Date(unsigned short year,
		   unsigned short month,
	       unsigned short day)
{
	if (ValidateDate(year, month, day))
	{
		dateYear = year;
		dateMonth = month;
		dateDay = day;
	}
	else
	{
		cout << "Date was not set - Invalid Input\n\n";
	}

}

/**************************************************************
* ~Date ();
*	Destructor; does not perform any specific function
* 	Parameters: none
* 	Return: none
***************************************************************/
Date::~Date()
{

}

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
void Date::SetDate(unsigned short year,
		           unsigned short month,
		           unsigned short day)
{
	if (ValidateDate(year, month, day))
	{
		dateYear = year;
		dateMonth = month;
		dateDay = day;
	}
	else
	{
		cout << "Date was not set - Invalid Input\n\n";
	}
}

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
void Date::GetDate(unsigned short &year,
				   unsigned short &month,
				   unsigned short &day) const
{
	year  = dateYear;
	month = dateMonth;
	day   = dateDay;
}

/**************************************************************
* unsigned short GetYear() const;
*	Accessor; gets Month
* 	Parameters: none
* 	Return: Month
***************************************************************/
unsigned short Date::GetYear()  const
{
	return dateYear;
}

/**************************************************************
* unsigned short GetMonth() const;
*	Accessor; gets Month
* 	Parameters: none
* 	Return: Month
***************************************************************/
unsigned short Date::GetMonth() const
{
	return dateMonth;
}

/**************************************************************
* unsigned short GetDay() const;
*	Accessor; gets Day
* 	Parameters: none
* 	Return: Day
***************************************************************/
unsigned short Date::GetDay()   const
{
	return dateDay;
}

/**************************************************************
* string DisplayDate() const;
*	Accessor; displays date in MM/DD/YYYY format
* 	Parameters: none
* 	Return: date as string
***************************************************************/
string Date::Display() const
{
	ostringstream out;

	out << right;

	//Outputs the month
	if(dateMonth < 10)
	{
		out << "0" << dateMonth << "/";
	}
	else
	{
		out << dateMonth << "/";
	}

	//Outputs the day
	if(dateDay < 10)
	{
		out << "0" << dateDay << "/";
	}
	else
	{
		out << dateDay << "/";
	}

	out << dateYear;

	return out.str();
}

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
unsigned short Date::GetDaysInMonth(unsigned short year,
									unsigned short month) const
{
	unsigned short daysInMonth;

	daysInMonth = 0;

	if (month == 1  || month == 3  || month == 5  || month == 7  ||
		month == 8  || month == 10 || month == 12)
	{
		daysInMonth = 31;
	}
	else if (month == 4  || month == 6  ||
			 month == 9  || month == 11)
	{
		daysInMonth = 30;
	}
	else if(month == 2)
	{
		if(IsLeapYear(year))
		{
			daysInMonth = 29;
		}
		else
		{
			daysInMonth = 28;
		}
	}

	return daysInMonth;
}

/**************************************************************
* IsLeapYear(unsigned short year) const
*	Accessor; check whether or not indicated year is a leap year
* 	Parameters: year
* 	Return: bool indiating leap year or not
***************************************************************/
bool Date::IsLeapYear(unsigned short year) const
{
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

						/*************
						 * VALIDATES *
						 *************/
/**************************************************************
* bool ValidateYear(unsigned short year) const;
*	Accessor; validates the year
* 	Parameters: year
* 	Return: bool indicating valid year or not
***************************************************************/
bool Date::ValidateYear(unsigned short year) const
{
	unsigned short currentYear;
	time_t now;
	tm *currentTime;

	now = time(NULL);
	currentTime = localtime(&now);

	currentYear  = 1900 + currentTime -> tm_year;

	return (year >= 1900 && year <= currentYear);
}

/**************************************************************
* bool ValidateMonth(unsigned short month) const;
*	Accessor; validates the month
* 	Parameters: month
* 	Return: bool indicating valid month or not
***************************************************************/
bool Date::ValidateMonth(unsigned short month) const
{
	return (month >= 1 && month <= 12);
}

/**************************************************************
* bool ValidateDay(unsigned short year,
				   unsigned short month,
				   unsigned short day) const;
*	Accessor; validates the day
* 	Parameters: year, month, day
* 	Return: bool indicating valid day or not
***************************************************************/
bool Date::ValidateDay(unsigned short year,
					   unsigned short month,
					   unsigned short day) const
{
	return (day >= 1 && day <= GetDaysInMonth(year, month));
}

/**************************************************************
* bool ValidateDate(unsigned short year,
				   unsigned short month,
				   unsigned short day) const;
*	Accessor; validates the passed in date against current day
* 	Parameters: year, month, day
* 	Return: bool indicating valid date or not
***************************************************************/
bool Date::ValidateDate(unsigned short year,
					 	unsigned short month,
					 	unsigned short day) const
{
	bool valid;
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;

	time_t now;
	tm *currentTime;

    valid = false;
	now = time(NULL);
	currentTime = localtime(&now);

	currentYear  = 1900 + currentTime -> tm_year;
	currentMonth = 1 + currentTime -> tm_mon;
	currentDay   = currentTime -> tm_mday;

	if (ValidateYear (year)  &&
		ValidateMonth(month) &&
		ValidateDay  (year, month, day))
	{
		if (year == currentYear)
		{
			if (month == currentMonth)
			{
				if (day <= currentDay)
				{
					valid = true;
				}
			}
			else if (month < currentMonth)
			{
				valid = true;
			}
		}
		else if (year < currentYear)
		{
			valid = true;
		}
	}

	return valid;
}

/**************************************************************
* unsigned short GetDaysSince(unsigned short year,
*				    		  unsigned short month,
*				    		  unsigned short day) const;
*	Accessor; determines the amount of days that have passsed
*			  since the date passed in
* 	Parameters: fromYear, fromMonth, fromDay
* 	Return: the number of days that have passed
***************************************************************/
unsigned short Date::GetDaysSince(unsigned short fromYear,
								  unsigned short fromMonth,
								  unsigned short fromDay) const
{
	unsigned short daysSince;
	unsigned short loopMonth;
	unsigned short loopYear;
	daysSince = 0;

	if(ValidateDate(fromYear, fromMonth, fromDay))
	{
		if (fromYear == dateYear)
		{
			if (fromMonth == dateMonth)
			{
				if (fromDay <= dateDay)
				{
					daysSince = dateDay - fromDay;
				}
			}
			else if (fromMonth < dateMonth)
			{
				//Adds the days left in the fromMonth to daysSince
				daysSince += (GetDaysInMonth(fromYear, fromMonth) - fromDay);

				//Adds the days in all the in-between months
				for(loopMonth = fromMonth + 1; loopMonth < dateMonth; loopMonth++)
				{
					daysSince += GetDaysInMonth(fromYear, loopMonth);
				}

				//Adds the days in the current month
				daysSince += dateDay;
			}
		}
		else if (fromYear < dateYear)
		{
			//Adds the days left in the fromMonth to daysSince
			daysSince += (GetDaysInMonth(fromYear, fromMonth) - fromDay);

			//Adds the days left in the year
			for(loopMonth = fromMonth + 1; loopMonth <= 12; loopMonth++)
			{
				daysSince += GetDaysInMonth(fromYear, loopMonth);
			}

			//Adds the days from all the in-between years
			for(loopYear = fromYear + 1; loopYear < dateYear; loopYear++)
			{
				for(loopMonth = 1; loopMonth <= 12; loopMonth++)
				{
					daysSince += GetDaysInMonth(fromYear, loopMonth);
				}
			}

			//Adds the days from the current year
			for(loopMonth = 1; loopMonth < dateMonth; loopMonth++)
			{
				daysSince += GetDaysInMonth(fromYear, loopMonth);
			}
		}
	}

	return daysSince;
}

/**************************************************************
* unsigned short GetMonthsSince(unsigned short year,
*				    		    unsigned short month,
*				    		    unsigned short day) const;
*	Accessor; determines the amount of months that have passsed
*			  since the date passed in
* 	Parameters: fromYear, fromMonth, fromDay
* 	Return: the number of months that have passed
***************************************************************/
unsigned short Date::GetMonthsSince(unsigned short currentYear,
									unsigned short currentMonth,
									unsigned short currentDay) const
{
	unsigned short monthsSince;
	monthsSince = 0;

	//If it's a valid date
	if(ValidateDate(currentYear, currentMonth, currentDay))
	{
		monthsSince = (currentMonth + ((currentYear - dateYear) * 12) - dateMonth);

		if(dateDay > currentDay)
		{
			monthsSince--;
		}
	}

	return monthsSince;
}

/**************************************************************
* unsigned short GetMonthsSince(unsigned short year,
*				    		    unsigned short month,
*				    		    unsigned short day) const;
*	Accessor; determines the amount of months that have passsed
*			  since the date passed in
* 	Parameters: fromYear, fromMonth, fromDay
* 	Return: the number of months that have passed
***************************************************************/
unsigned short Date::GetMonthsSince(Date currentDate) const
{
	unsigned short monthsSince;
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;

	currentDate.GetDate(currentYear, currentMonth, currentDay);
	monthsSince = 0;

	//If it's a valid date
	if(ValidateDate(currentYear, currentMonth, currentDay))
	{
		monthsSince = (currentMonth + ((currentYear - dateYear) * 12) - dateMonth);

		if(dateDay > currentDay)
		{
			monthsSince--;
		}
	}
	else
	{
		cout << "Date is not valid!";
	}

	return monthsSince;
}

/**************************************************************
* unsigned short GetMonthsSince() const;
*	Accessor; determines the amount of months that have passsed
*			  since the date passed in
* 	Parameters: fromYear, fromMonth, fromDay
* 	Return: the number of months that have passed
***************************************************************/
unsigned short Date::MonthsSince() const
{
	time_t now;
	tm *currentTime;
	unsigned short monthsSince;

	now = time(NULL);
	currentTime = localtime(&now);
	monthsSince = 0;

	monthsSince = (currentTime->tm_mon + ((currentTime->tm_year - dateYear) * 12) - dateMonth);

	if(dateDay > currentTime->tm_mday)
	{
		monthsSince--;
	}

	return monthsSince;
}
