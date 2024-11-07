#pragma once
#include "bits/stdc++.h"
#include "clsDate.h"

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

class clsInputValidate
{

public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		return clsDate::Is_Date_In_Period(Date, { &From, &To });
	}

	static int ReadIntNumber(string InvalidMessage = "Invalid Number : ")
	{

		long double Num;

		ci Num;

		while (cin.fail() || Num != floor(Num))
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			co InvalidMessage;
			ci Num;

		}

		return Num;

	}

	static ld ReadDblNumber(string Message, string InvalidMessage = "Invalid Number : ")
	{

		ld Num;

		co Message;
		ci Num;

		while (cin.fail())
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			co InvalidMessage;
			ci Num;

		}

		return Num;

	}

	static ld ReadPositiveDblNumber(string Message, string InvalidMessage = "Invalid Number : ")
	{

		ld Num;

		co Message;
		ci Num;

		while (cin.fail() || Num <= 0)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			co InvalidMessage;
			ci Num;

		}

		return Num;

	}

	static int ReadIntNumberBetween(int From, int To, string InvalidBetweenMessage = "Invalid Range", string InvalidMessage = "Invalid Number : ")
	{

		int Number;

		Number = ReadIntNumber(InvalidMessage);

		while (!IsNumberBetween(Number, From, To))
		{
			co InvalidBetweenMessage;
			Number = ReadIntNumber(InvalidMessage);
		}

		return Number;

	}

	static string ReadString(string Message)
	{

		string Result;

		co Message;

		getline(cin >> ws, Result);

		return Result;

	}

	static char ReadCharacter(string Message)
	{

		char Result;

		co Message;

		ci Result;

		return Result;

	}

	static ld ReadDblNumberBetween(ld From, ld To, string InvalidBetweenMessage = "Invalid Range", string InvalidMessage = "Invalid Number : ")
	{

		ld Number;

		Number = ReadDblNumber(InvalidMessage);

		while (Number < From || Number > To)
		{
			co InvalidBetweenMessage;
			Number = ReadDblNumber(InvalidMessage);
		}

		return Number;

	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::Is_Validate_Date(Date);
	}

	static bool ReadConfirm(string Message, string ErrorMessage = "Invalid : ")
	{

		char Answer = ' ';

		co Message;

		cin >> Answer;

		while ((toupper(Answer) != 'Y') && (toupper(Answer) != 'N'))
		{
			cout << ErrorMessage;
			cin >> Answer;
		}


		if (toupper(Answer) == 'Y')
			return true;

		return false;

	}

};