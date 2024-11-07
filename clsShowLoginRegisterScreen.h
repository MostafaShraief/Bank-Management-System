#pragma once
#include "bits/stdc++.h"
#include "clsScreen.h"
#include "clsString.h"
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

class clsShowLoginRegisterScreen : protected clsScreen
{

private:

	static void _PrintLoginRegisterListHeader()
	{

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(30) << "User Name";
		cout << "| " << left << setw(30) << "Password";
		cout << "| " << left << setw(12) << "Permissions";

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

	}

	static void _PrintLogRow(clsUser::stLoginRegisterLogs Log)
	{

		cout << "\t| " << setw(30) << left << Log.DateTime;
		cout << "| " << setw(30) << left << Log.UserName;
		cout << "| " << setw(30) << left << Log.Password;
		cout << "| " << setw(12) << left << Log.Permissions;

	}

public:

	static void LoginRegister()
	{

		system("cls");

		vector <clsUser::stLoginRegisterLogs> vLogs = clsUser::GetstRegisterLogs();

		string Title = " Login Register List";

		string Subtitle = "    (" + to_string(vLogs.size()) + ") Log(s)";

		clsScreen::_DrawScreenHeader(Title, Subtitle);

		_PrintLoginRegisterListHeader();

		if (vLogs.size() > 0)
		{

			for (auto& Log : vLogs)
			{
				_PrintLogRow(Log);
				co endl;
			}

		}
		else
		{
			co "\t\t\t\t\t\tNo Logs In The System..\n";
		}

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

	}

};