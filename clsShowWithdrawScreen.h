#pragma once
#include "bits/stdc++.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

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

class clsShowWithdrawScreen : protected clsScreen
{

public:

	static void Withdraw()
	{

		system("cls");

		string Title = "       Withdraw";

		_DrawScreenHeader(Title);

		clsBankClient Client = clsBankClient::Find(clsScreen::_ReadAccountNumber());

		_Print(Client);

		ld Amount = clsInputValidate::ReadPositiveDblNumber("\n\t\t\t\t\tInter Amount: ", "\n\t\t\t\t\tInvalid: ");

		char Accept = clsInputValidate::ReadCharacter("\n\t\t\t\t\tAre You Sure You Want To Withdraw From\n\t\t\t\t\tThis Client Y/N ? ");

		cout << "\t\t\t\t\t______________________________________\n";

		if (toupper(Accept) == 'Y')
		{

			if (Client.WithDraw(Amount))
			{

				co "\n\t\t\t\t\tWithdrawed Successfully.";
				co "\n\t\t\t\t\tNew Balance: " o Client.AccountBalance o endl o endl;

			}
			else
			{

				co "\n\t\t\t\t\tWithdraw Failed.";
				co "\n\t\t\t\t\tAmount (" o Amount o ") Is Greater";
				co "\n\t\t\t\t\tThan Client Balance (" o Client.AccountBalance o ")\n\n";

			}


		}
		else
		{
			co "\n\t\t\t\t\tWithdraw Canceled.\n\n";
		}

	}

};