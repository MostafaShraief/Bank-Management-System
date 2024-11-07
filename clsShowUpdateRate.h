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

class clsShowUpdateRate : protected clsScreen
{

private:

	static clsCurrency FindByCode()
	{

		string CurrencyCode = clsInputValidate::ReadString("\n\t\t\t\t\tInter Currency Code : ");

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			co "\n\t\t\t\t\tOps.. Currency Not Found";

			CurrencyCode = clsInputValidate::ReadString("\n\t\t\t\t\tInter Valid Currency Code : ");

		}

		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);


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

	static void UpdateRate()
	{

		system("cls");

		string Title = "Update Currency Rate";

		clsScreen::_DrawScreenHeader(Title);

		clsCurrency Currency = FindByCode();

		_Print(Currency);

		bool Accept = clsInputValidate::ReadConfirm("\n\t\t\t\t\tAre You Sure You Want To Update\n\t\t\t\t\tThis Currency Y/N? ", "\n\t\t\t\t\tInvalid : ");

		if (Accept)
		{

			ld NewRate = clsInputValidate::ReadPositiveDblNumber("\n\t\t\t\t\tInter New Rate : ", "\n\t\t\t\t\tInvalid : ");

			Currency.SetRate(NewRate);

			if (Currency.Save() == clsCurrency::eSuccessful)
			{

				co "\n\t\t\t\t\tSaved Successfully";

				_Print(Currency);

			}
			else
				co "\n\t\t\t\t\tSaved Failed";

		}
		else
		{
			co "\n\t\t\t\t\tUpdate Canceled";
		}

	}
};