#pragma once
#include "bits/stdc++.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUtility.h"

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

class clsShowTransferScreen : protected clsScreen
{

private:

	static void _PrintBalanceClientInfo(clsBankClient Client)
	{

		cout << "\n\t\t\t\t\tClient Card:";
		cout << "\n\t\t\t\t\t______________________________________";
		cout << "\n\t\t\t\t\tFull Name      : " << Client.FullName();
		cout << "\n\t\t\t\t\tAccount Number : " << Client.AccountNumber;
		cout << "\n\t\t\t\t\tBalance        : " << Client.AccountBalance;
		cout << "\n\t\t\t\t\t______________________________________\n";

	}

	static string _ReadDestinationAccountNumber(string SourceAccountNumber)
	{

		// This Function Gurantee That Source Account And Destination Account Not The Same 

		string DestinationAccountNumber = clsScreen::_ReadAccountNumber("\n\t\t\t\t\tInter Account Number You Want To\n\t\t\t\t\tTransfer To : ");

		while (DestinationAccountNumber == SourceAccountNumber)
		{

			cout << "\n\t\t\t\t\t______________________________________";
			co "\n\t\t\t\t\tCan Not Transfer To Same Account.";
			cout << "\n\t\t\t\t\t______________________________________\n";

			DestinationAccountNumber = clsScreen::_ReadAccountNumber("\n\t\t\t\t\tInter Valid Account Number You Want To\n\t\t\t\t\tTransfer To : ");

		}

		return DestinationAccountNumber;

	}

public:

	static void Transfer()
	{

		system("cls");

		string Title = "      Transfer";

		clsScreen::_DrawScreenHeader(Title); // Transfer Header

		string SourceAccountNumber = clsScreen::_ReadAccountNumber("\n\t\t\t\t\tInter Account Number You Want To\n\t\t\t\t\tTransfer From : ");

		clsBankClient SourceClientAccount = clsBankClient::Find(SourceAccountNumber); // Source Account

		_PrintBalanceClientInfo(SourceClientAccount);

		string DestinationAccountNumber = _ReadDestinationAccountNumber(SourceAccountNumber); // Destination Account

		clsBankClient DestinationClientAccount = clsBankClient::Find(DestinationAccountNumber);

		_PrintBalanceClientInfo(DestinationClientAccount);

		ld Amount = clsInputValidate::ReadPositiveDblNumber("\n\t\t\t\t\tInter Amount : ", "\n\t\t\t\t\tInvalid: "); // Read Amount

		bool Accept = clsInputValidate::ReadConfirm("\n\t\t\t\t\tAre You Sure You Want To\n\t\t\t\t\tComplete This Proccess Y/N? "); // Confrim Transfer

		if (Accept)
		{

			clsBankClient::enTransfer TransferResult = SourceClientAccount.Transfer(Amount, DestinationClientAccount, CurrentUser.UserName); // Transfer Operation
			
			// Check Transfer Result :
			switch (TransferResult)
			{

			case clsBankClient::eFailedNoMoneyEnough:
			{
				cout << "\n\t\t\t\t\t______________________________________";
				co "\n\t\t\t\t\tTransfer Failed.";
				co "\n\t\t\t\t\tAmount (" o Amount o ") Is Greater";
				co "\n\t\t\t\t\tThan Client Balance (" o SourceClientAccount.AccountBalance o ")";
				cout << "\n\t\t\t\t\t______________________________________\n";
				break;
			}
			case clsBankClient::eFailedSameAccount:
			{
				cout << "\n\t\t\t\t\t______________________________________";
				co "\n\t\t\t\t\tTransfer Failed.";
				co "\n\t\t\t\t\tCan Not Transfer To Same Account.";
				cout << "\n\t\t\t\t\t______________________________________\n";
				break;
			}
			case clsBankClient::eNotExist:
			{
				cout << "\n\t\t\t\t\t______________________________________";
				co "\n\t\t\t\t\tTransfer Failed.";
				co "\n\t\t\t\t\tCan Not Find Either Source Account\n\t\t\t\t\tOr Destination Account.";
				cout << "\n\t\t\t\t\t______________________________________\n";
				break;
			}
			case clsBankClient::eFaildNullAmount:
				cout << "\n\t\t\t\t\t______________________________________";
				co "\n\t\t\t\t\tTransfer Failed.";
				co "\n\t\t\t\t\tNo Thing To Transfer.";
				cout << "\n\t\t\t\t\t______________________________________\n";
				break;
			case clsBankClient::eSucceed:
			{

				co "\n\t\t\t\t\tTransferred Successfully.\n";

				_PrintBalanceClientInfo(SourceClientAccount);

				_PrintBalanceClientInfo(DestinationClientAccount);

				co "\n\t\t\t\t\tTransfer Amount : " o Amount o endl;

				break;

			}
			default:
				break;
			}

		}
		else
			co "\n\t\t\t\t\tTransfer Canceled.\n\n";

	}

};