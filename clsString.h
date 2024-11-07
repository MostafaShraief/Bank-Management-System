#pragma once
#include "bits/stdc++.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsString
{

private:

	string Value;

public:

	clsString(string Value)
	{
		this->Value = Value;
	}

	struct StringInfo
	{

		int length = 0;
		int Count_Lower_Letters = 0;
		int Count_Upper_Letters = 0;

	};

	string Get_Value()
	{
		return Value;
	}

	void Set_Value(string Value)
	{
		this->Value = Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	static string Op_Number_To_Text(ll Number)
	{

		if (Number < 0)
			return "Negative " + Op_Number_To_Text(-1 * Number);

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

			return Digit_2[Number / 10] + " " + Op_Number_To_Text(Number % 10);

		}

		if (Number <= 999)
		{

			return Op_Number_To_Text(Number / 100) + " Hundred " + Op_Number_To_Text(Number % 100);

		}

		if (Number <= 999999)
		{

			return Op_Number_To_Text(Number / 1000) + " Thousand " + Op_Number_To_Text(Number % 1000);

		}

		if (Number <= 999999999)
		{

			return Op_Number_To_Text(Number / 1000000) + " Milion " + Op_Number_To_Text(Number % 1000000);

		}

		if (Number <= 999999999)
		{

			return Op_Number_To_Text(Number / 1000000) + " Milion " + Op_Number_To_Text(Number % 1000000);

		}

		if (Number <= 999999999999)
		{

			return Op_Number_To_Text(Number / 1000000000) + " Bilion " + Op_Number_To_Text(Number % 1000000000);

		}

		if (Number <= 999999999999999)
		{

			return Op_Number_To_Text(Number / 1000000000000) + " Trilion " + Op_Number_To_Text(Number % 1000000000000);

		}

	}

	static string Number_To_Text(ll Number)
	{

		if (Number == 0)
			return "Zero";
		else
			return Op_Number_To_Text(Number);

	}

	static int Count_Words(string St)
	{

		int cnt = 0;

		string temp;
		short Pos;

		while ((Pos = St.find(" ")) != St.npos)
		{

			if (*St.begin() != ' ')
				++cnt;

			St.erase(0, Pos + 1);

		}

		if (St != "")
			++cnt;

		return cnt;

	}

	int Count_Words()
	{
		return Count_Words(Value);
	}

	static vector <string> Split(string St, string Seperator, bool Senstive = 1, bool Ignore_Empty_Strings = 1)
	{

		vector <string> vString;

		string temp, S2 = "";
		short Pos;

		if (Seperator == "")
			return {St};

		if (!Senstive)
		{

			for (char c : St)
				S2 += tolower(c);
			for (char& c : Seperator)
				c = tolower(c);

		}
		else
			S2 = St;

		while ((Pos = S2.find(Seperator)) != S2.npos)
		{

			temp = S2.substr(0, Pos);

			if (temp != "" || !Ignore_Empty_Strings)
				vString.push_back(temp);

			S2.erase(0, Pos + Seperator.length());

		}

		if (S2 != "")
			vString.push_back(S2);

		return vString;

	}

	vector <string> Split(string Seperator = " ")
	{
		return Split(Value, Seperator);
	}
	
	static string Trim_Left(string St)
	{

		int len = St.length();

		for (int i = 0; i < len; ++i)
		{

			if (St[i] != ' ')
				return St.substr(i);

		}

		return "";

	}

	void Trim_Left()
	{
		Value = Trim_Left(Value);
	}

	static string Trim_Right(string St)
	{

		int len = St.length();

		for (int i = len - 1; i >= 0; --i)
		{

			if (St[i] != ' ')
				return St.substr(0, i + 1);

		}

		return "";

	}

	void Trim_Right()
	{
		Value = Trim_Right(Value);
	}

	static string Trim(string St)
	{

		return Trim_Left(Trim_Right(St));

	}

	void Trim()
	{
		Value = Trim(Value);
	}

	static string Join_string(vector <string> vSt, string Sep = " ", bool Delete_Last_Sep = 1)
	{

		string result = "";

		for (auto& x : vSt)
		{
			result += x + Sep;
		}

		if (Delete_Last_Sep)
			result.erase(result.end() - Sep.length(), result.end());

		return result;

	}

	static string reverse_Words(string St, string Sep)
	{

		string Result = "";
		vector <string> vSt = Split(St, Sep);

		for (auto it = vSt.rbegin(); it != vSt.rend(); ++it)
			Result += *it + Sep;

		return Result.substr(0, Result.length() - Sep.length());

	}

	void reverse_Words(string Seperator)
	{
		Value = reverse_Words(Value, Seperator);
	}
	
	static string Replace_Words(string S1, string Sepertor, string ReplaceWith, bool Sensitive = 1)
	{

		return Join_string(Split(" " + S1, Sepertor, Sensitive), ReplaceWith, 0).substr(1);

	}

	void Replace_Words(string Sepertor, string ReplaceWith, bool Sensitive = 1)
	{
		Value = Replace_Words(Value, Sepertor, ReplaceWith, Sensitive);
	}
	
	static string Replace(string st, string old_word, string new_word)
	{

		int pos;

		while ((pos = st.find(old_word)) != st.npos)
		{

			st.replace(pos, old_word.length(), new_word);

		}

		return st;

	}

	void Replace(string old_word, string new_word)
	{
		Value = Replace(Value, old_word, new_word);
	}
	
	static string Remove_Punctuations(string S1)
	{

		string S2 = "";

		for (char& c : S1)
		{
			if (!ispunct(c))
				S2 += c;
		}

		return S2;

	}

	void Remove_Punctuations()
	{
		Value = Remove_Punctuations(Value);
	}

	static void Print_Spaces(short Times)
	{

		for (short _ = 0; _ < Times; ++_)
			co " ";

	}
	
	static void Print_UnderScore(int Times, bool New_Line = 0)
	{

		for (short _ = 0; _ < Times; ++_)
			co "_";

		if (New_Line)
			co endl;

	}
	
	static void Print(string Message)
	{

		if (Message != "")
			co Message o endl;

	}
	
	static short ReadValidate_and_PosNumber(string Message = "")
	{

		short Num;

		co Message;
		ci Num;

		while (cin.fail() || Num < 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			Print("Not Valid, Please Try Again : ");
			ci Num;
		}

		return Num;

	}
	
	static short ReadValidateNumber(string Message = "")
	{

		short Num;

		co Message;
		ci Num;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			Print("Not Valid, Please Try Again:");
			ci Num;
		}

		return Num;

	}

	static void Print_String(string& St, string Message = "")
	{

		co Message;
		getline(cin >> ws, St);

	}
	
	static void Print_String(char Letter, string Message = "")
	{

		co Message;
		co Letter;

	}
	
	static void First_Letter_Of_Each_Word(string St)
	{

		int siz = size(St); bool Is_First_Letter = true;

		for (int i = 0; i < siz; ++i)
		{

			if (St[i] != ' ' && Is_First_Letter)
				co St[i] o endl;

			Is_First_Letter = (St[i] == ' ') ? true : false;

		}

	}
	
	static void Upper_First_Letter_Of_Each_Word(string& St)
	{

		int Length = St.length(); bool Is_First_Letter = true;

		for (int i = 0; i < Length; ++i)
		{

			if (Is_First_Letter)
				St[i] = toupper(St[i]);

			Is_First_Letter = (St[i] == ' ') ? true : false;

		}

	}

	void Upper_First_Letter_Of_Each_Word()
	{
		Upper_First_Letter_Of_Each_Word(Value);
	}

	static void Lower_First_Letter_Of_Each_Word(string& St)
	{

		int Length = St.length(); bool Is_First_Letter = true;

		for (int i = 0; i < Length; ++i)
		{

			if (Is_First_Letter)
				St[i] = tolower(St[i]);

			Is_First_Letter = (St[i] == ' ') ? true : false;

		}

	}

	void Lower_First_Letter_Of_Each_Word()
	{
		Lower_First_Letter_Of_Each_Word(Value);
	}
	
	static string Upper_All_Letters_Of_String(string St)
	{

		int length = St.length();

		for (int i = 0; i < length; ++i)
		{

			St[i] = toupper(St[i]);

		}

		return St;

	}

	void Upper_All_Letters_Of_String()
	{
		Upper_All_Letters_Of_String(Value);
	}
	
	static void Lower_All_Letters_Of_String(string& St)
	{

		int length = St.length();

		for (int i = 0; i < length; ++i)
		{

			St[i] = tolower(St[i]);

		}

	}

	void Lower_All_Letters_Of_String()
	{
		Lower_All_Letters_Of_String(Value);
	}
	
	static char Invert_Case_Letter(char Letter)
	{

		return (isupper(Letter)) ? tolower(Letter) : toupper(Letter);

	}
	
	static string Invert_Case_Letters(string St)
	{

		int length = St.length();

		for (int i = 0; i < length; ++i)
		{

			St[i] = Invert_Case_Letter(St[i]);

		}

		return St;

	}

	void Invert_Case_Letters()
	{
		Value = Invert_Case_Letters(Value);
	}
	
	static bool Check_IsUpper(char Letter)
	{

		return isupper(Letter) && isalpha(Letter) ? true : false;

	}

	static StringInfo StrInfo(string St)
	{

		StringInfo Info;

		Info.length = St.length();

		for (int i = 0; i < Info.length; ++i)
		{

			if (isalpha(St[i]))
				Check_IsUpper(St[i]) ? ++Info.Count_Upper_Letters : ++Info.Count_Lower_Letters;

		}

		return Info;

	}

	StringInfo StrInfo()
	{
		return StrInfo(Value);
	}
	
	static void Print_Each_Word_In_New_Line(string St)
	{

		int Length = St.length();

		for (int i = 0; i < Length; ++i)
		{
			if (St[i] != ' ')
			{

				do
				{

					co St[i];
					++i;

				} while (i < Length && St[i] != ' ');

				co endl;

			}
		}

	}

	void Print_Each_Word_In_New_Line()
	{
		Print_Each_Word_In_New_Line(Value);
	}
	
	static void Print_Each_Word_In_New_Line_V2(string St)
	{

		string temp;
		short Pos;

		while ((Pos = St.find(" ")) != St.npos)
		{

			temp = St.substr(0, Pos);

			if (temp != "")
				co temp o endl;

			St.erase(0, Pos + 1);

		}

		if (St != "")
			co St o endl;

	}

	void Print_Each_Word_In_New_Line_V2()
	{
		Print_Each_Word_In_New_Line_V2(Value);
	}

	int Length(string S1)
	{
		return S1.length();
	}

	int Length()
	{
		return Length(Value);
	}

	static string EncryptText(string Text, int EncryptionKey1 = 1, int EncryptionKey2 = 2, int EncryptionKey3 = 3)
	{

		for (int i = 0; i < Text.length(); ++i)
		{

			if (i % 3 == 0)
				Text[i] += EncryptionKey1;
			else if (i % 3 == 1)
				Text[i] -= EncryptionKey2;
			else
				Text[i] += EncryptionKey3;

		}

		return Text;

	}

	static string DecryptText(string Text, int EncryptionKey1 = 1, int EncryptionKey2 = 2, int EncryptionKey3 = 3)
	{

		for (int i = 0; i < Text.length(); ++i)
		{

			if (i % 3 == 0)
				Text[i] -= EncryptionKey1;
			else if (i % 3 == 1)
				Text[i] += EncryptionKey2;
			else
				Text[i] -= EncryptionKey3;

		}

		return Text;

	}

};