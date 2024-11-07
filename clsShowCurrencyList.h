#pragma once
#include "bits/stdc++.h"
#include "clsString.h"
#include "clsUtility.h"
#include "clsCurrency.h"
#include "clsScreen.h"

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

class clsShowCurrencyList : protected clsScreen
{

	static void _PrintTableHeader()
	{

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country Name";
		cout << "| " << left << setw(15) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(8) << "Rate";

	}

	static void _PrintRowCurrency(clsCurrency& Currency)
	{

		cout << "\t| " << setw(30) << left << Currency.CountryName();
		cout << "| " << setw(15) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(8) << left << Currency.Rate();

	}

public:

	static void CurrencyList()
	{

		system("cls");

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "  Currency List";

		string SubTitle = "(" + to_string(vCurrencies.size()) + ") Currencies";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		_PrintTableHeader();

		cout << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vCurrencies.size() > 0)
		{
			for (auto& Currency : vCurrencies)
			{
				_PrintRowCurrency(Currency);
				co endl;
			}
		}
		else
			co "\n\t\t\t\t\t No In The System Currencies";

		cout << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

	}

};