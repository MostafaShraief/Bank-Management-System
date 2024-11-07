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

class clsShowDepositeScreen : protected clsScreen
{

public:

	static void Deposite()
	{

		system("cls");

		string Title = "       Deposite";

		_DrawScreenHeader(Title);

		clsBankClient Client = clsBankClient::Find(clsScreen::_ReadAccountNumber());

		_Print(Client);

		ld Amount = clsInputValidate::ReadPositiveDblNumber("\n\t\t\t\t\tInter Amount: ", "\n\t\t\t\t\tInvalid: ");

		char Accept = clsInputValidate::ReadCharacter("\n\t\t\t\t\tAre You Sure You Want To Deposite To\n\t\t\t\t\tThis Client Y/N ? ");

		cout << "\t\t\t\t\t______________________________________\n";

		if (toupper(Accept) == 'Y')
		{

			Client.Deposit(Amount);

			co "\n\t\t\t\t\tDeposite Successfully.";

			co "\n\t\t\t\t\tNew Balance: " o Client.AccountBalance o endl o endl;

		}
		else
		{
			co "\n\t\t\t\t\tDeposite Canceled.\n\n";
		}

	}

};