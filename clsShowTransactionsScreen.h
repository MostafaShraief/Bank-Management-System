#pragma once
#include "bits/stdc++.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsShowDepositeScreen.h"
#include "clsShowWithdrawScreen.h";
#include "clsShowTotalBalancesScreen.h"
#include "clsShowTransferScreen.h"
#include "clsShowTransferRegisterScreen.h"

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

class clsShowTransactionsScreen : protected clsScreen
{

private:

	enum _enTransactionsOptions
	{
		eDeposite =1, eWithdraw,
		eTotalBalances, eTransfer,
		eTransferLog, eMainMenu
	};

	static _enTransactionsOptions _ReadTransactionsOptions()
	{

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

		short Option = clsInputValidate::ReadIntNumberBetween(1, 6, "\t\t\t\t     Please Inter Number Between 1 -> 6: ", "\t\t\t\t     Invalid: ");

		return _enTransactionsOptions(Option);

	}

	static void _BackToTransactionsMenu()
	{

		cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Transaction Menu...";

		system("pause>0");

		ShowTransactionsScreen();

	}

	static void _ShowDepositeScreen()
	{
		clsShowDepositeScreen::Deposite();
	}

	static void _ShowWithdrawScreen()
	{
		clsShowWithdrawScreen::Withdraw();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsShowTotalBalancesScreen::TotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsShowTransferScreen::Transfer();
	}

	static void _ShowTransferLogScreen()
	{
		clsShowTransferRegisterScreen::TransferRegister();
	}

	static void _PerformTransactionsOptions(_enTransactionsOptions Option)
	{

		switch (Option)
		{

		case clsShowTransactionsScreen::eDeposite:
			_ShowDepositeScreen();
			_BackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::eWithdraw:
			_ShowWithdrawScreen();
			_BackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::eTotalBalances:
			_ShowTotalBalancesScreen();
			_BackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::eTransfer:
			_ShowTransferScreen();
			_BackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::eTransferLog:
			_ShowTransferLogScreen();
			_BackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::eMainMenu:
			break;

		}
	}

public:

	static void ShowTransactionsScreen()
	{

		system("cls");

		string Title = "   Transactions Menu";

		clsScreen::_DrawScreenHeader(Title);

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t   Transactions Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposite.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Logs.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformTransactionsOptions(_ReadTransactionsOptions());

	}

};