#pragma once
#ifndef Member_h
#define Member_h
#include "SortListTemplate.h"
#include <string>

class Member
{
private:
	int membership_number;
	string first_name;
	string surname;
	int day;
	int month;
	int year;
	bool validate_member;

public:
	Member();
	Member(int membership_num, string f_name, string s_name, int a_day, int a_month, int a_year, bool vali_mem);
	int get_membership_number();
	string get_first_name();
	string get_surname();
	int get_day();
	int get_month();
	int get_year();
	bool check_current_membership();						//check the current membership status
	bool change_membership_status(bool validate);
	bool operator> (const Member& m2);
	//overloading operator> so that it can be used to detemine which member has a greater value in the split stage of quick sort, referring to Element[right] > pivot
	bool operator<= (const Member& m2);
	//overloading operator<= so that it can be used to detemine which member has a smaller value in the split stage of quick sort, referring to Element[left] <= pivot
};

#endif // !Member_h

