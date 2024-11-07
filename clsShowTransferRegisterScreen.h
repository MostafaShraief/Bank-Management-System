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

class clsShowTransferRegisterScreen : protected clsScreen
{

private:

	static void _PrintTransferRegisterListHeader()
	{

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(9) << "s.Acct";
		cout << "| " << left << setw(9) << "d.Acct";
		cout << "| " << left << setw(9) << "Amount";
		cout << "| " << left << setw(11) << "s.Balance";
		cout << "| " << left << setw(11) << "d.Balance";
		cout << "| " << left << setw(12) << "User";

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

	}

	static void _PrintLogRow(clsUser::stTransferRegisterLog Log)
	{

		cout << "\t| " << setw(30) << left << Log.DateTime;
		cout << "| " << setw(9) << left << Log.SourceAccountNumber;
		cout << "| " << setw(9) << left << Log.DestinationAccountNumber;
		cout << "| " << setw(9) << left << Log.Amount;
		cout << "| " << setw(11) << left << Log.SourceAccountBalance;
		cout << "| " << setw(11) << left << Log.DestinationAccountBalance;
		cout << "| " << setw(12) << left << Log.UserName;

	}

public:

	static void TransferRegister()
	{

		system("cls");

		vector <clsUser::stTransferRegisterLog> vLogs = clsUser::GetstTransferRegisterLogs();

		string Title = " Transfer Register List";

		string Subtitle = "    (" + to_string(vLogs.size()) + ") Log(s)";

		clsScreen::_DrawScreenHeader(Title, Subtitle);

		_PrintTransferRegisterListHeader();

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
			co "\t\t\t\t\t\tNo Transfer Logs In The System..\n";
		}

		cout << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

	}

};