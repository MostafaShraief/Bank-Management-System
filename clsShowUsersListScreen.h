#pragma once
#include "bits/stdc++.h"
#include "clsUserScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define ld long double
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsShowUsersListScreen : protected clsUserScreen
{

private:

	static void _PrintUsersListHeader()
	{

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

	}

	static void _PrintUserRow(clsUser User)
	{
		
		cout << "\t| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(30) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;

	}

public:

	static void UsersList()
	{

		system("cls");

		string Title, SubTitle;

		vector <clsUser> vUsers = clsUser::GetUsersList();

		Title = "    Users List", SubTitle = "    (" + to_string(vUsers.size()) + ") User(s)";

		clsUserScreen::_DrawScreenHeader(Title, SubTitle);

		_PrintUsersListHeader();

		if (vUsers.size() > 0)
			for (auto& User : vUsers)
				_PrintUserRow(User), co endl;
		else
		{
			co "\t\t\t\t\t\tNo Users In The System..\n\t\t\t\t\t\tAdd Users To Show Them.\n";
		}

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

	}

};