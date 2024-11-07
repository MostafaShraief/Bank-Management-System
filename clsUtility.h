#pragma once
#include "bits/stdc++.h"
#include "clsDate.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsUtility
{

private:

	static string _NumberToTextGenerator(ll Number)
	{

		if (Number < 0)
			return "Negative " + _NumberToTextGenerator(-1 * Number);

		if (Number == 0)
			return "";

		if (Number <= 9)
		{

			string Digit_1[10] = { "", "One", "Two", "Three", "Four", "Five",
								   "Six", "Seven", "Eight", "Nine" };

			return Digit_1[Number];

		}

		if (Number <= 19)
		{

			string Digit_2[10] = { "Ten", "Eleven", "Twelve", "Therteen", "Fourteen", "Fifteen",
								   "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

			return Digit_2[Number % 10];

		}

		if (Number <= 99)
		{

			string Digit_2[10] = { "", "", "Twenty", "Therty", "Fourty", "Fifty",
								   "Sixty", "Seventy", "Eighty", "Ninety" };

			return Digit_2[Number / 10] + " " + _NumberToTextGenerator(Number % 10);

		}

		if (Number <= 999)
		{

			return _NumberToTextGenerator(Number / 100) + " Hundred " + _NumberToTextGenerator(Number % 100);

		}

		if (Number <= 999999)
		{

			return _NumberToTextGenerator(Number / 1000) + " Thousand " + _NumberToTextGenerator(Number % 1000);

		}

		if (Number <= 999999999)
		{

			return _NumberToTextGenerator(Number / 1000000) + " Milion " + _NumberToTextGenerator(Number % 1000000);

		}

		if (Number <= 999999999)
		{

			return _NumberToTextGenerator(Number / 1000000) + " Milion " + _NumberToTextGenerator(Number % 1000000);

		}

		if (Number <= 999999999999)
		{

			return _NumberToTextGenerator(Number / 1000000000) + " Bilion " + _NumberToTextGenerator(Number % 1000000000);

		}

		if (Number <= 999999999999999)
		{

			return _NumberToTextGenerator(Number / 1000000000000) + " Trilion " + _NumberToTextGenerator(Number % 1000000000000);

		}

	}

public:

	enum enCharacterType { Number = 1, LowerCase, CapitalCase, MixCase, SpecailCase };

	static void Srand()
	{
		srand((int)time(NULL));
	}

	static int Random()
	{
		return rand();
	}

	static int RandomToFrom(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	static char GetRandomCharacter(enCharacterType CharacterType)
	{

		if (CharacterType == Number)
			return RandomToFrom('0', '9');
		else if (CharacterType == LowerCase)
			return RandomToFrom('a', 'z');
		else if (CharacterType == CapitalCase)
			return RandomToFrom('A', 'Z');
		else if (CharacterType == SpecailCase)
		{

			int Random = RandomToFrom(1, 2);

			if (Random == 1)
				return RandomToFrom('!', '0' - 1);
			else
				return RandomToFrom('9' + 1, 'A' - 1);

		}
		else
		{

			int Random = RandomToFrom(1, 4);

			if (Random == Number)
				return RandomToFrom('0', '9');
			else if (Random == LowerCase)
				return RandomToFrom('a', 'z');
			else if (Random == CapitalCase)
				return RandomToFrom('A', 'Z');
			else
			{

				Random = RandomToFrom(1, 2);

				if (Random == 1)
					return RandomToFrom('!', '0' - 1);
				else
					return RandomToFrom('9' + 1, 'A' - 1);

			}

		}

	}

	static string GenerateWord(enCharacterType WordFormat, int Length = 5)
	{

		string Result;
		
		for (int i = 0; i < Length; ++i)
		{
			Result += GetRandomCharacter(WordFormat);
		}

		return Result;

	}

	static string GenerateKey(enCharacterType KeyFormat, int Slots, int SingleSlotLength = 5)
	{

		string Result;

		for (int i = 0; i < Slots; ++i)
		{
			Result += GenerateWord(KeyFormat, SingleSlotLength) + '-';
		}

		Result.pop_back();

		return Result;

	}

	static void Swap(int& Change1, int& Change2)
	{

		int Temp = Change1;
		Change1 = Change2;
		Change2 = Temp;

	}

	static void Swap(double & Change1, double & Change2)
	{

		double  Temp = Change1;
		Change1 = Change2;
		Change2 = Temp;

	}

	static void Swap(string& Change1, string& Change2)
	{

		string  Temp = Change1;
		Change1 = Change2;
		Change2 = Temp;

	}

	static void Swap(clsDate& Change1, clsDate& Change2)
	{

		clsDate  Temp = Change1;
		Change1 = Change2;
		Change2 = Temp;

	}

	static void ShufleArray(int *Pointer, int Size)
	{
		
		for (int i = 0; i < Size; ++i)
			Swap(*(Pointer + RandomToFrom(0, Size - 1)), *(Pointer + RandomToFrom(0, Size - 1)));

	}

	static void ShufleArray(string* Pointer, int Size)
	{

		for (int i = 0; i < Size; ++i)
			Swap(*(Pointer + RandomToFrom(0, Size - 1)), *(Pointer + RandomToFrom(0, Size - 1)));

	}

	static void ShufleArray(int* Pointer, int Rows, int Columns)
	{

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Columns; ++j)
				Swap(*(Pointer + RandomToFrom(0, i * Columns + j)), *(Pointer + RandomToFrom(0, i * Columns + j)));

	}

	static void ShufleArray(string* Pointer, int Rows, int Columns)
	{

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Columns; ++j)
				Swap(*(Pointer + RandomToFrom(0, i * Columns + j)), *(Pointer + RandomToFrom(0, i * Columns + j)));

	}

	static void FillArrayWithRandomNumber(int *Pointer, int Length, int From, int To)
	{

		for (int i = 0; i < Length; ++i)
			*(Pointer + i) = RandomToFrom(From, To);

	}

	static void FillArrayWithRandomNumber(int* Pointer, int Rows, int Columns, int From, int To)
	{

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Columns; ++j)
				*(Pointer + i * Columns + j) = RandomToFrom(From, To);

	}

	static void FillArrayWithRandomWords(string* Pointer, int Size, enCharacterType Format, int Length = 5)
	{

		for (int i = 0; i < Size; ++i)
			*(Pointer + i) = GenerateWord(Format, Length);

	}

	static void FillArrayWithRandomWords(string* Pointer, int Rows, int Columns, enCharacterType Format, int Length = 5)
	{

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Columns; ++j)
				*(Pointer + i * Columns + j) = GenerateWord(Format, Length);

	}

	static void FillArrayWithRandomKeys(string* Pointer, int Size, enCharacterType Format, int Length = 5, int SingleSlotLength = 5)
	{

		for (int i = 0; i < Size; ++i)
			*(Pointer + i) = GenerateKey(Format, Length, SingleSlotLength);

	}

	static void FillArrayWithRandomKeys(string* Pointer, int Rows, int Columns, enCharacterType Format, int Length = 5, int SingleSlotLength = 5)
	{

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Columns; ++j)
				*(Pointer + i * Columns + j) = GenerateKey(Format, Length, SingleSlotLength);

	}

	static void PrintArray(int* Pointer, int Length)
	{

		for (int i = 0; i < Length; ++i)
			co Pointer[i] o " ";

		co endl;

	}

	static void PrintArray(string* Pointer, int Length)
	{

		for (int i = 0; i < Length; ++i)
			co Pointer[i] o " ";

		co endl;

	}

	static void PrintArray(int* Pointer, int Rows, int Columns)
	{


		for (int i = 0; i < Rows; ++i) {
			for (int j = 0; j < Columns; ++j) {
				std::cout << *(Pointer + i * Columns + j) << " ";
			}
			std::cout << endl;
		}

	}

	static void PrintArray(string* Pointer, int Rows, int Columns)
	{


		for (int i = 0; i < Rows; ++i) {
			for (int j = 0; j < Columns; ++j) {
				std::cout << *(Pointer + i * Columns + j) << " ";
			}
			std::cout << endl;
		}

	}

	static void Tabs(int Times)
	{

		for (int i = 0; i < Times; ++i)
			co '\t';

	}

	static string EncryptText(string Text, int EncryptionKey)
	{

		int _Length = Text.length();

		for (int i = 0; i < _Length; ++i)
			Text[i] += EncryptionKey;

		return Text;

	}

	static string DecryptText(string Text, int EncryptionKey)
	{

		int _Length = Text.length();

		for (int i = 0; i < _Length; ++i)
			Text[i] -= EncryptionKey;

		return Text;

	}

	static string NumberToText(ll Number)
	{

		if (Number == 0)
			return "Zero";
		else
			return _NumberToTextGenerator(Number);

	}

	static void SystemPause(string Message)
	{

		co Message;

		system("pause>0");

	}

	static void SystemPauseMiddle(string Message)
	{

		cout << endl o setw(37) << left << "" << Message;

		system("pause>0");


	}

	static vector <string> ExtractDataFromFile(string FileName, string FileFormat = ".txt")
	{

		fstream File;

		File.open(FileName + FileFormat, ios::in | ios::app);

		string Line;

		vector <string> vData;

		if (File.is_open())
		{

			while (getline(File, Line))
				vData.push_back(Line);

			File.close();

		}

		return vData;

	}

	static void WriteLineInFile(string Line, string FileName, string FileFormat = ".txt")
	{

		fstream File;

		File.open(FileName + FileFormat, ios::out | ios::app);

		vector <string> vData;

		if (File.is_open())
		{

			File o Line o endl;

			File.close();

		}

	}

};