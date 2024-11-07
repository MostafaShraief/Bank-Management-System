#pragma once
#include "bits/stdc++.h"
#include "clsString.h"
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsShowCurrencyList.h"

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

class clsShowFindCurrencyScreen : protected clsScreen
{

private:

	enum enFindChoice {eCountry = 1, eCode};

	static enFindChoice _CurrencyFindChoice()
	{

		co "\n\t\t\t\t\tDo You Want Search By :\n\t\t\t\t\t[1] Country / [2] Currency Code : ";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "\n\t\t\t\t\Inter Number Between 1 -> 2 : ", "\n\t\t\t\t\Invalid : ");

		return enFindChoice(Choice);

	}

	static clsCurrency FindByCode()
	{

		string CurrencyCode = clsInputValidate::ReadString("\n\t\t\t\t\tInter Currency Code : ");

		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

		return Currency;

	}

	static clsCurrency FindByCountry()
	{

		string CountryName = clsInputValidate::ReadString("\n\t\t\t\t\tInter Country Name : ");

		clsCurrency Currency = clsCurrency::FindByCountryName(CountryName);

		return Currency;

	}

	static void _Print(clsCurrency Currency)
	{

		cout << "\n\t\t\t\t\tCurrency Card:";
		cout << "\n\t\t\t\t\t______________________________________";
		cout << "\n\t\t\t\t\tCountry Name  : " << Currency.CountryName();
		cout << "\n\t\t\t\t\tCurrency Code : " << Currency.CurrencyCode();
		cout << "\n\t\t\t\t\tCurrency Name : " << Currency.CurrencyName();
		cout << "\n\t\t\t\t\tRate           : " << Currency.Rate();
		cout << "\n\t\t\t\t\t______________________________________\n";

	}

public:

	static void FindCurrency()
	{

		system("cls");

		string Title = "  Find Currency";

		clsScreen::_DrawScreenHeader(Title);

		enFindChoice Choice = _CurrencyFindChoice();

		clsCurrency Currency = clsCurrency::FindByCurrencyCode("");

		if (Choice == eCountry)
			Currency = FindByCountry();
		else if (Choice == eCode)
			Currency = FindByCode();

		if (Currency.IsEmpty())
			co "\n\t\t\t\t\tCurrency Not Found";
		else
		{

			co "\n\t\t\t\t\tCurrency Found";

			_Print(Currency);

		}

	}

};