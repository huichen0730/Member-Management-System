#include "pch.h"
#include "Member.h"

//constructor
Member::Member() {}

Member::Member(int membership_num, string f_name, string s_name, int a_day, int a_month, int a_year, bool vali_mem) :
	membership_number(membership_num), first_name(f_name), surname(s_name), day(a_day), month(a_month), year(a_year), validate_member(vali_mem) {}

int Member::get_membership_number()
{
	return membership_number;
}

string Member::get_first_name()
{
	return first_name;
}

string Member::get_surname()
{
	return surname;
}

int Member::get_day()
{
	return day;
}

int Member::get_month()
{
	return month;
}

int Member::get_year()
{
	return year;
}

bool Member::check_current_membership()
{
	return validate_member;
}

bool Member::change_membership_status(bool validate)
{
	validate_member = validate;
	return true;			//the operation has completed when return true;
}

//overloading operator> so that it can be used to detemine which member has a greater value in the split stage of quick sort, referring to Element[right] > pivot
bool Member::operator> (const Member& m2)
{
	if (year > m2.year)
		return true;
	else if (year < m2.year)
		return false;
	else								//that means year1 = year2, so need to compare month1 to month2 to see which one is greater
	{
		if (month > m2.month)
			return true;
		else if (month < m2.month)
			return false;
		else						//that means year1= year2 and also month1 = month2, now need to compare day1 to day2 to see which one is greater
		{
			if (day > m2.day)
				return true;
			else if (day < m2.day)
				return false;
			else					//if member1 and member2 have exact same join date, then need to compare which surname has greater value. 
			{						//The value of name increases in alphabetical order.  E.g. Helena has greater value than Cassie
				if (surname > m2.surname)
					return true;
				else if (surname < m2.surname)
					return false;
				else			//if date and surname are all the same, then compare which first name has greater value. 
				{
					if (first_name > m2.first_name)
						return true;
					else if (first_name < m2.first_name)
						return false;
				}
			}
		}
	}
}

//overloading operator<= so that it can be used to detemine which member has a smaller value in the split stage of quick sort, referring to Element[left] <= pivot
//This applies the opposite logic of operator> function;
bool Member::operator<= (const Member& m2)
{
	if (year <= m2.year)
		return true;
	else if (year > m2.year)
		return false;
	else
	{
		if (month <= m2.month)
			return true;
		else if (month > m2.month)
			return false;
		else
		{
			if (day <= m2.day)
				return true;
			else if (day > m2.day)
				return false;
			else
			{
				if (surname <= m2.surname)
					return true;
				else if (surname > m2.surname)
					return false;
				else
				{
					if (first_name <= m2.first_name)
						return true;
					else if (first_name > m2.first_name)
						return false;
				}
			}
		}
	}
}