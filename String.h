#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <forward_list>
#include <map>
#include <iomanip>

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i]
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void Print_Spaces(short Times)
{

    for (short _ = 0; _ < Times; ++_)
        co " ";

}

void Print_UnderScore(int Times, bool New_Line = 0)
{

    for (short _ = 0; _ < Times; ++_)
        co "_";

    if (New_Line)
        co endl;

}

void Print(string Message)
{

    if (Message != "")
        co Message o endl;

}

short ReadValidate_and_PosNumber(string Message = "")
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

short ReadValidateNumber(string Message = "")
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

struct StringInfo
{

    int length = 0;
    int Count_Lower_Letters = 0;
    int Count_Upper_Letters = 0;

};

void Print_String(string & St, string Message = "")
{

    co Message;
    getline(cin >> ws, St);

}

void Print_String(char Letter, string Message = "")
{

    co Message;
    co Letter;

}

void First_Letter_Of_Each_Word(string St)
{

    int siz = size(St); bool Is_First_Letter = true;

    for (int i = 0; i < siz; ++i)
    {

        if (St[i] != ' ' && Is_First_Letter)
            co St[i] o endl;

        Is_First_Letter = (St[i] == ' ') ? true : false;

    }

}

void Upper_First_Letter_Of_Each_Word(string & St)
{

    int Length = St.length(); bool Is_First_Letter = true;

    for (int i = 0; i < Length; ++i)
    {

        if (Is_First_Letter)
            St[i] = toupper(St[i]);

        Is_First_Letter = (St[i] == ' ') ? true : false;

    }

}

void Lower_First_Letter_Of_Each_Word(string & St)
{

    int Length = St.length(); bool Is_First_Letter = true;

    for (int i = 0; i < Length; ++i)
    {

        if (Is_First_Letter)
            St[i] = tolower(St[i]);

        Is_First_Letter = (St[i] == ' ') ? true : false;

    }

}

void Upper_All_Letters_Of_String(string & St)
{

    int length = St.length();

    for (int i = 0; i < length; ++i)
    {

        St[i] = toupper(St[i]);

    }

}

void Lower_All_Letters_Of_String(string & St)
{

    int length = St.length();

    for (int i = 0; i < length; ++i)
    {

        St[i] = tolower(St[i]);

    }

}

char Invert_Case_Letter(char Letter)
{

    return (isupper(Letter)) ? tolower(Letter) : toupper(Letter);

}

string Invert_Case_Letters(string St)
{

    int length = St.length();

    for (int i = 0; i < length; ++i)
    {

        St[i] = Invert_Case_Letter(St[i]);

    }

    return St;

}

bool Check_IsUpper(char Letter)
{

    return isupper(Letter) && isalpha(Letter) ? true : false;

}

StringInfo StrInfo(string St)
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

void Print_Each_Word_In_New_Line(string St)
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

void Print_Each_Word_In_New_Line_V2(string St)
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

int Count_Words(string St)
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

vector <string> Split(string St, string Del = " ", bool Senstive = 1, bool Dont_Ignore_Empty_Strings = 0)
{

    vector <string> vString;

    string temp, S2 = "";
    short Pos;

    if (!Senstive)
    {

        for (char c : St)
            S2 += tolower(c);
        for (char& c : Del)
            c = tolower(c);

    }
    else
        S2 = St;

    while ((Pos = S2.find(Del)) != S2.npos)
    {

        temp = S2.substr(0, Pos);

        if (temp != "" || Dont_Ignore_Empty_Strings)
            vString.push_back(temp);

        S2.erase(0, Pos + Del.length());

    }

    if (S2 != "")
        vString.push_back(S2);

    return vString;

}

string Trim_Left(string St)
{

    int len = St.length();

    for (int i = 0; i < len; ++i)
    {

        if (St[i] != ' ')
            return St.substr(i);

    }

    return "";

}

string Trim_Right(string St)
{

    int len = St.length();

    for (int i = len - 1; i >= 0; --i)
    {

        if (St[i] != ' ')
            return St.substr(0, i + 1);

    }

    return "";

}

string Trim(string St)
{

    return Trim_Left(Trim_Right(St));

}

string Join_string(vector <string> vSt, string Sep = " ", bool Delete_Last_Sep = 1)
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

string reverse_Words(string St, string Sep = " ")
{

    string Result = "";
    vector <string> vSt = Split(St);

    for (auto it = vSt.rbegin(); it != vSt.rend(); ++it)
        Result += *it + Sep;

    return Result.substr(0, Result.length() - Sep.length());

}

string Replace_Words(string S1, string Del, string Replace, bool Sensitive = 1)
{

    return Join_string(Split(" " + S1, Del, Sensitive), Replace, 0).substr(1);

}

string Replace(string st, string old_word, string new_word)
{

    int pos;

    while ((pos = st.find(old_word)) != st.npos)
    {

        st.replace(pos, old_word.length(), new_word);

    }

    return st;

}

string Remove_Punctuations(string S1)
{

    string S2 = "";

    for (char& c : S1)
    {
        if (!ispunct(c))
            S2 += c;
    }

    return S2;

}
