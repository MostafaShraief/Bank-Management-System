#pragma once
#include "bits/stdc++.h"
#include "clsString.h"
#include "clsUtility.h"
#include "clsShowCurrencyList.h"
#include "clsShowFindCurrencyScreen.h"
#include "clsShowUpdateRate.h"
#include "clsScreen.h"
#include "clsShowCurrencyCalculator.h"

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

class clsShowCurrencyScreen : private clsScreen
{

private:

	static void _CurrencyListBody()
	{

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t    Currency Menu\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Currency List.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currencies Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "============================================\n";

	}

	enum enCurrencyOptions
	{
		eCurrencyList = 1, eFindCurrency,
		UpdateCurrency, eCurrenciesCalculator,
		eMainMenu
	};

	static enCurrencyOptions _ReadCurrencyMenuOption()
	{

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";

		short Option = clsInputValidate::ReadIntNumberBetween(1, 5, "\t\t\t\t     Please Inter Number Between 1 -> 5: ", "\t\t\t\t     Invalid: ");

		return enCurrencyOptions(Option);

	}

	static void _BackToCurrencyExchangeMenu()
	{

		cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Currency Exchange Menu...";

		system("pause>0");

		CurrencyListScreen();

	}

	static void _ShowCurrencyList()
	{
		clsShowCurrencyList::CurrencyList();
	}

	static void _ShowFindCurrency()
	{
		clsShowFindCurrencyScreen::FindCurrency();
	}

	static void _ShowUpdateCurrency()
	{
		clsShowUpdateRate::UpdateRate();
	}

	static void _ShowCurrencyCalculator()
	{
		clsShowCurrencyCalculator::CurrencyCalculator();
	}

	static void _PerformCurrencyMenuOptions(enCurrencyOptions Option)
	{

		switch (Option)
		{
		case clsShowCurrencyScreen::eCurrencyList:
			_ShowCurrencyList();
			_BackToCurrencyExchangeMenu();
			break;
		case clsShowCurrencyScreen::eFindCurrency:
			_ShowFindCurrency();
			_BackToCurrencyExchangeMenu();
			break;
		case clsShowCurrencyScreen::UpdateCurrency:
			_ShowUpdateCurrency();
			_BackToCurrencyExchangeMenu();
			break;
		case clsShowCurrencyScreen::eCurrenciesCalculator:
			_ShowCurrencyCalculator();
			_BackToCurrencyExchangeMenu();
			break;
		case clsShowCurrencyScreen::eMainMenu:
			break;
		default:
			break;
		}
	}

public:

	static void CurrencyListScreen()
	{

		system("cls");

		string Title = "Currency Exchange Menu";

		clsScreen::_DrawScreenHeader(Title);

		_CurrencyListBody();

		_PerformCurrencyMenuOptions(_ReadCurrencyMenuOption());

	}

};