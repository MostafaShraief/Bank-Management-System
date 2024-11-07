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

class clsShowCurrencyCalculator : protected clsScreen
{

	static clsCurrency _FindByCode(string ToFrom)
	{

		string CurrencyCode = clsInputValidate::ReadString("\n\t\t\t\t\tInter Currency" + ToFrom + " Code : ");

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			co "\n\t\t\t\t\tOps.. Currency Not Found";

			CurrencyCode = clsInputValidate::ReadString("\n\t\t\t\t\tInter Valid Currency Code : ");

		}

		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);


		return Currency;

	}

	static void _PrintCurrencyCard(clsCurrency& Currency)
	{

		cout << "\n\t\t\t\t\tCurrency Card:";
		cout << "\n\t\t\t\t\t______________________________________";
		cout << "\n\t\t\t\t\tCountry Name  : " << Currency.CountryName();
		cout << "\n\t\t\t\t\tCurrency Code : " << Currency.CurrencyCode();
		cout << "\n\t\t\t\t\tCurrency Name : " << Currency.CurrencyName();
		cout << "\n\t\t\t\t\tRate           : " << Currency.Rate();
		cout << "\n\t\t\t\t\t______________________________________\n";

	}

	static void _PrintCalculationResult(clsCurrency& FromCurrency, clsCurrency& ToCurrency, ld Amount)
	{

		ld AmountInUSD = FromCurrency.ConvertToUSD(Amount);

		co "\n\t\t\t\t\tConvert From :\n";

		_PrintCurrencyCard(FromCurrency);

		co "\n\t\t\t\t\t" o Amount o " " o FromCurrency.CurrencyCode() o
			" = " o AmountInUSD o " USD";

		if (ToCurrency.CurrencyCode() != "USD")
		{

			ld AmountInToCurrency = FromCurrency.ConvertToOtherCurrency(Amount, ToCurrency);

			co "\n\t\t\t\t\tConvert To :\n";

			_PrintCurrencyCard(ToCurrency);

			co "\n\t\t\t\t\t" o Amount o " " o FromCurrency.CurrencyCode() o
				" = " o AmountInToCurrency o " " o ToCurrency.CurrencyCode() o endl;

		}


	}

public:

	static void CurrencyCalculator()
	{
		
		system("cls");

		string Title = "Currency Calculator";

		clsScreen::_DrawScreenHeader(Title);

		clsCurrency FromCurrency = _FindByCode("1");

		clsCurrency ToCurrency = _FindByCode("2");

		ld Amount = clsInputValidate::ReadPositiveDblNumber("\n\t\t\t\t\tInter Amount : ", "\n\t\t\t\t\tInvalid : ");

		_PrintCalculationResult(FromCurrency, ToCurrency, Amount);

	}

};