#pragma once
#ifndef Member_Manager_h
#define Member_Manager_h
#include "Member.h"

class MemberManager
{
private:
	int size;
	Member* members;			//a dynamic allocated member array
	int count_member;			//count how many members have been added into the array;

public:
	MemberManager(int array_size);
	~MemberManager();
	bool Full() const;
	bool Add(const Member& new_member);
	bool Disable_membership(const int& mem_num);
	void Sort_list() const;
	bool Compare_date(int d, int m, int y, Member member);
	bool Set_filter_print(int d, int m, int y);
	void Print_list(int x) const;
};

#endif // !Member_Manager_h

