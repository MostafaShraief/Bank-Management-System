#pragma once
#include "bits/stdc++.h"
#include "clsUserScreen.h"
#include "clsInputValidate.h"
#include "clsShowUsersListScreen.h"
#include "clsShowAddUserScreen.h"
#include "clsShowDeleteUser.h"
#include "clsShowFindUserScreen.h"
#include "clsShowUpdateUserScreen.h"

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

class clsShowManageUsersScreen : protected clsUserScreen
{

private:

	enum _enManageUsersOptions
	{
		eListUsers = 1, eAddUser,
		eDeleteUser, UpdateUser,
		eFindUser, eMainMenu
	};

	static _enManageUsersOptions _ReadMangeUsersOption()
	{

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

		short Option = clsInputValidate::ReadIntNumberBetween(1, 6, "\t\t\t\t     Please Inter Number Between 1 -> 6: ", "\t\t\t\t     Invalid: ");

		return _enManageUsersOptions(Option);

	}

	static void _BackToManageUsersMenu()
	{

		cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Manage Users Menu...";

		system("pause>0");

		ShowManageUsersScreen();

	}

	static void _ShowUsersListScreen()
	{
		clsShowUsersListScreen::UsersList();
	}

	static void _ShowAddUserScreen()
	{
		clsShowAddUserScreen::AddNewUser();
	}

	static void _ShowDeleteUserScreen()
	{
		clsShowDeleteUser::DeleteUser();
	}

	static void _ShowUpdateUserScreen()
	{
		clsShowUpdateUserScreen::UpdateUser();
	}

	static void _ShowFindUserScreen()
	{
		clsShowFindUserScreen::FindUser();
	}

	static void _PerformMangeUsersOption(_enManageUsersOptions Option)
	{

		switch (Option)
		{
		case clsShowManageUsersScreen::eListUsers:
			_ShowUsersListScreen();
			_BackToManageUsersMenu();
			break;
		case clsShowManageUsersScreen::eAddUser:
			_ShowAddUserScreen();
			_BackToManageUsersMenu();
			break;
		case clsShowManageUsersScreen::eDeleteUser:
			_ShowDeleteUserScreen();
			_BackToManageUsersMenu();
			break;
		case clsShowManageUsersScreen::UpdateUser:
			_ShowUpdateUserScreen();
			_BackToManageUsersMenu();
			break;
		case clsShowManageUsersScreen::eFindUser:
			_ShowFindUserScreen();
			_BackToManageUsersMenu();
			break;
		case clsShowManageUsersScreen::eMainMenu:
			break;
		}

	}

public:

	static void ShowManageUsersScreen()
	{
		
		system("cls");

		string Title = "    Manage Users Menu";

		clsUserScreen::_DrawScreenHeader(Title);

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t   Manage Users Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformMangeUsersOption(_ReadMangeUsersOption());

	}

};