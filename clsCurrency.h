#pragma once
#include "bits/stdc++.h"
#include "clsString.h"
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

class clsCurrency
{

private:

	enum _enMode { eEmptyMode, eUpdateMode };

	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	ld _Rate;
	_enMode _Mode;

	static clsCurrency _ConvertRecordToclsCurrency(string Line, string Seperator = "#//#")
	{

		vector <string> vData = clsString::Split(Line, Seperator);
		
		clsCurrency Currency = _GetNewEmptyObject();

		Currency._Mode = eUpdateMode;
		Currency._CountryName = vData[0];
		Currency._CurrencyCode = vData[1];
		Currency._CurrencyName = vData[2];
		Currency._Rate = stod(vData[3]);

		return Currency;

	}

	static string _ConvertclsCurrencyToRecord(clsCurrency& Currency, string Seperator = "#//#")
	{

		string Line;

		Line = Currency._CountryName + Seperator;
		Line += Currency._CurrencyCode + Seperator;
		Line += Currency._CurrencyName + Seperator;
		Line += to_string(Currency._Rate) + Seperator;

		return Line;

	}

	static vector <clsCurrency> _ExtractCurrenciesFromFile(string FileName = "Currencies")
	{

		vector <string> vData = clsUtility::ExtractDataFromFile(FileName);

		vector <clsCurrency> vCurrencies;

		for (auto& Record : vData)
		{

			clsCurrency Currency = _ConvertRecordToclsCurrency(Record);

			vCurrencies.push_back(Currency);

		}

		return vCurrencies;

	}

	static clsCurrency _GetNewEmptyObject()
	{
		return {eEmptyMode, "", "", "", 0 };
	}

	void _SaveDataToFile(vector <clsCurrency>& vCurrencies, string FileName = "Currencies")
	{

		fstream File;

		File.open(FileName + ".txt", ios::out);

		if (File.is_open())
		{

			for (auto& Currency : vCurrencies)
			{

				string Record = _ConvertclsCurrencyToRecord(Currency);

				File o Record o endl;

			}

			File.close();

		}

	}

	void _Update()
	{

		string CountryName = clsString::Upper_All_Letters_Of_String(_CountryName);

		vector <clsCurrency> vCurrencies = _ExtractCurrenciesFromFile();

		for (auto& Currency : vCurrencies)
		{

			string CurrencyNameOfFile = clsString::Upper_All_Letters_Of_String(Currency.CountryName());

			if (CountryName == CurrencyNameOfFile)
			{
				Currency = *this;
				break;
			}

		}

		_SaveDataToFile(vCurrencies);

	}

public:

	clsCurrency(_enMode Mode, string CountryName, string CurrencyCode, string CurrencyName, ld CurrencyValue)
	{
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = CurrencyValue;
	}

	bool IsEmpty()
	{
		return (_Mode == eEmptyMode);
	}

	string CountryName()
	{
		return _CountryName;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	ld Rate()
	{
		return _Rate;
	}

	void SetRate(ld NewRate)
	{
		_Rate = NewRate;
	}

	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{

		CurrencyCode = clsString::Upper_All_Letters_Of_String(CurrencyCode);

		vector <clsCurrency> vCurrencies = _ExtractCurrenciesFromFile();

		for (auto& Currency : vCurrencies)
		{

			string CurrencyCodeOfFile = clsString::Upper_All_Letters_Of_String(Currency.CurrencyCode());

			if (CurrencyCode == CurrencyCodeOfFile)
				return Currency;

		}

		return _GetNewEmptyObject();

	}

	static clsCurrency FindByCountryName(string CountryName)
	{

		CountryName = clsString::Upper_All_Letters_Of_String(CountryName);

		vector <clsCurrency> vCurrencies = _ExtractCurrenciesFromFile();

		for (auto& Currency : vCurrencies)
		{

			string CountryNameOfFile = clsString::Upper_All_Letters_Of_String(Currency.CountryName());

			if (CountryName == CountryNameOfFile)
				return Currency;

		}

		return _GetNewEmptyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{

		clsCurrency Currency = FindByCurrencyCode(CurrencyCode);

		return (!Currency.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _ExtractCurrenciesFromFile();
	}

	enum enSaveResult { eSuccessful, eFailed };

	enSaveResult Save()
	{
		
		if (Rate() > 0 && IsCurrencyExist(CurrencyCode()))
		{
			_Update();
			return eSuccessful;
		}

		return eFailed;

	}

	ld ConvertToUSD(ld Amount)
	{
		return Amount / Rate();
	}

	ld ConvertToOtherCurrency(ld Amount, clsCurrency Currency2)
	{

		ld AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
			return AmountInUSD;


		return AmountInUSD * Currency2.Rate();

	}


};