#include "pch.h"
#include "MemberManager.h"
#include <iomanip>

//constructor
MemberManager::MemberManager(int array_size) : size(array_size), members(new Member[size]), count_member(-1) {}

//destructor
MemberManager::~MemberManager()
{
	delete[] members;
}

//test if the array is already full
bool MemberManager::Full() const
{
	return (count_member == size - 1) ? true : false;
}


//add a member record into the array
bool MemberManager::Add(const Member& new_member)
{
	if (Full())
		return false;
	else
	{
		count_member++;
		members[count_member] = new_member;
		return true;
	}
}

bool MemberManager::Disable_membership(const int& mem_num)
{
	int a = 0;
	while ((mem_num != members[a].get_membership_number()) && a <= count_member)
	{
		a++;
	}
	if (mem_num == members[a].get_membership_number())
	{
		members[a].change_membership_status(false);
		return true;														//return true means the operation has completed													
	}
	else
		return false;										//array exhaust and no such membership number has been found
}

void MemberManager::Sort_list() const
{
	Sortlist<Member> members_to_sort(count_member + 1);			 //creates a sortlist object with the current size of members array
	members_to_sort.SetArray(members);								//copies all the value from members array to the sort list array
	members_to_sort.Quicksort();										   //sorts the array into increasing order based on the logic from overloaded operator > and operator <=
	members_to_sort.GetArray(members);						   	  //puts all the sorted value back to members array
}


bool MemberManager::Compare_date(int d, int m, int y, Member member)
{
	if (member.get_year() > y)
		return true;
	else if (member.get_year() < y)
		return false;
	if (member.get_month() > m)
		return true;
	else if (member.get_month() < m)
		return false;
	if (member.get_day() > d)
		return true;
	else
		return false;
}

bool MemberManager::Set_filter_print(int d, int m, int y)
{
	int largest_year_range = y;

	//find what is the largest year range to start printing out the list of members, e.g. 70, 60, 50 or 40 years
	while (!Compare_date(d, m, largest_year_range, members[0]))
	{
		largest_year_range -= 10;
	}

	bool printMember = false;
	int index = 0;

	for (int year = largest_year_range; year < y - 10 && index <= count_member; year += 10)
	{
		bool print_title = false;

		//print out all the members fitting in the largest 10-year range first and then move down to next 10-year range
		while (Compare_date(d, m, year, members[index]) && !Compare_date(d, m, year + 10, members[index]))
		{
			if (!print_title)
			{
				// print title
				cout << y - year - 10 << " years+" << endl;
				cout << "Mem No.\t\tDate Joined\t\t\tName" << endl;
				print_title = true;										//the title row for each one 10-year period will only print out once
			}

			if (members[index].check_current_membership())		//only print out those are validate members
			{
				//print member
				Print_list(index);
			}
			index++;
			printMember = true;
		}
	}
	return printMember;			//return true if there are members been more than 10 years in the society; return false when there is no member been more than 10 years at all.
}

void MemberManager::Print_list(int x) const
{
	cout << setfill('0') << setw(4) << members[x].get_membership_number() << "\t\t" << setfill('0') << setw(2) << members[x].get_day() << "/"
		<< setfill('0') << setw(2) << members[x].get_month() << "/" << setfill('0') << setw(4) << members[x].get_year()
		<< "\t\t\t" << members[x].get_first_name() << " " << members[x].get_surname() << endl;
}