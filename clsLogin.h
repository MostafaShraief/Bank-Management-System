#pragma once
#include "bits/stdc++.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

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

class clsLogin : protected clsScreen
{

	static void _SystemLockedScreen()
	{

		system("cls");

		clsScreen::_DrawScreenHeader("   SYSTEM LOCKED\n", "System Locked Due to\n\t\t\t\t\t\t   Many Attempts");

		cout << setw(37) << left << "" << "\n\t\t\t\t\t  ( Press any key to Close Screen )";

		system("pause>0");

	}

	static bool _Login()
	{

		short CountLock = 3;

		string UserName, Password;

		bool TryAgain = false;

		do
		{

			if (TryAgain)
				co "\n\t\t\t\t\tInvalid User Name Or Password..\n\t\t\t\t\tYou Have (" o CountLock o ") Trial(s).\n";

			UserName = clsInputValidate::ReadString("\n\t\t\t\t\tUser Name : ");

			Password = clsInputValidate::ReadString("\n\t\t\t\t\tPassword : ");

			CurrentUser = clsUser::Find(UserName, Password);

			TryAgain = CurrentUser.IsEmpty();

		} while (TryAgain && --CountLock > 0);

		if (CountLock)
		{

			CurrentUser.LoginLog();

			clsMainScreen::ShowMainMenu();

			return 1;

		}

		_SystemLockedScreen();

		return 0;

	}

public:

	static bool LoginScreen()
	{

		system("cls");

		clsScreen::_DrawScreenHeader("    Login");

		return _Login();

	}

};