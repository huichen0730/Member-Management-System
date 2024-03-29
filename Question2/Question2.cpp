#include "pch.h"
#include "MemberManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

void show_menu();
int check_input(int input, string input_name);
int check_input(int input, int small_range, int large_range, string input_name);

int main()
{
	cout << "* --------------------------------------------- *" << endl;
	cout << "*    " << "< Welcome to Member Management System> " << "    *" << endl;
	cout << "* --------------------------------------------- *" << endl;
	cout << endl << "Please specify how many people maximum can join the society. " << endl;
	int max_size;
	cin >> max_size;
	max_size = check_input(max_size, "number to specify the maximum number");
	MemberManager member_list(max_size);

	bool keep_looping;
	do
	{
		show_menu();
		keep_looping = 1;
		int choice;
		cout << endl << "Choose the operation you want to perform: " << endl << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{	//add a member record 
			if (member_list.Full())
				cout << "Sorry the number of members in the society has reached its maximum. You cannot add any more record." << endl;
			else
			{
				cout << "Please enter 4 digit membership number." << endl;
				//maximum 4 digit as the society has no more than 10000 member and membership number starts from 0000 to 9999
				int member_num;
				cin >> member_num;
				member_num = check_input(member_num, 0, 10000, "four digit membership number");

				string f_name;
				cout << "Now enter this member's first name." << endl;
				cin >> f_name;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Now enter this member's surname." << endl;
				string surname;
				cin >> surname;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				int day, month, year;
				cout << "Now enter the day that the member joined the society." << endl;
				cin >> day;
				day = check_input(day, 1, 31, "day");
				cout << "Now enter the month that the member joined the society." << endl;
				cin >> month;
				month = check_input(month, 1, 12, "month");
				cout << "Now enter the year that the member joined the society." << endl;
				cin >> year;
				year = check_input(year, 1, 2020, "year");

				bool validate_member;
				cout << "Is this person still a member of the society? Enter 1 for Yes, 0 for No." << endl;
				cin >> validate_member;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please try again with proper input. Enter 1 for Yes, 0 for No. " << endl;
					cin >> validate_member;
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				Member a_member(member_num, f_name, surname, day, month, year, validate_member);			//create a member object to store all this information
				member_list.Add(a_member);																							//Then put this member object into the member_list array
				cout << "The details of this member has been added successfully into the system." << endl;
				cout << endl;
			}
			break;
		}
		case 2:
		{	//show a list of member details, only print out validate members
			member_list.Sort_list();

			cout << "Please enter the current date (day, month, year)." << endl;
			int cur_day, cur_month, cur_year;
			cin >> cur_day >> cur_month >> cur_year;

			while (cur_day < 0 || cur_day > 31 || cur_month < 0 || cur_month > 12 || cur_year < 0 || cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a proper date (day, month, year) that the member joined the society." << endl;
				cin >> cur_day >> cur_month >> cur_year;
			}
			cout << endl << endl;

			cout << "Long-standing members at " << setfill('0') << setw(2) << cur_day << "/" << setfill('0') << setw(2) << cur_month << "/" << setfill('0') << setw(4) << cur_year << ": " << endl << endl;
			if (!member_list.Set_filter_print(cur_day, cur_month, cur_year))
				cout << "There is no member who has joined the society for more than 10 years compared with the current date." << endl;
			break;
		}
		case 3:
		{	//disable one's membership
			cout << "Please enter a membership number to mark that person's membership as not current." << endl;
			int mem_num;
			cin >> mem_num;
			mem_num = check_input(mem_num, 0, 10000, "four digit membership number");
			if (member_list.Disable_membership(mem_num))
				cout << "This person's membership is not current anymore." << endl;
			else
				cout << "Sorry the system didn't find anyone to mark as non-current member with the membership number you have entered." << endl;
			break;
		}
		case 4:
		{ // quit the program
			keep_looping = 0;
			cout << "Thank you for using the program." << endl;
			break;
		}
		default:
		{ //handling any unexpected input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, the system cannot recognise your choice. Try again!" << endl;
			break;
		}
		}
	} while (keep_looping);

	return 0;
}

void show_menu()
{
	cout << endl << endl;
	cout << "* --------------------------------------------- *" << endl;
	cout << "*    " << "< Welcome to Member Management System> " << "    *" << endl;
	cout << "*  \t\t\t" << "Menu" << "\t\t        *" << endl;
	cout << "* " << "Press 1 to enter details of a member" << "\t\t*" << endl;
	cout << "* " << "Press 2 to show a list of member details" << "\t*" << endl;
	cout << "* " << "Press 3 to disable one's membership" << "\t\t*" << endl;
	cout << "* " << "Press 4 to quit the program" << " \t\t\t*" << endl;
	cout << "* --------------------------------------------- *" << endl << endl;
}

int check_input(int input, string input_name)
{
	while (input <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a proper " << input_name << "." << endl;
		cin >> input;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

int check_input(int input, int small_range, int large_range, string input_name)
{
	while (input < small_range || input > large_range || cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, Please enter a proper " << input_name << "." << endl;
		cin >> input;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}