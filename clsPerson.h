#pragma once
#include "bits/stdc++.h"
#include "clsString.h"

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

class clsPerson
{

private:
	
	string _FirstName, _LastName, _Email, _Phone;

public:


	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
	{

		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = PhoneNumber;

	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	string GetLastName()
	{
		return _LastName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string GetEmail()
	{
		return _Email;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	string GetPhone()
	{
		return _Phone;
	}

	void SetPhone(string PhoneNumber)
	{
		_Phone = PhoneNumber;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	//void _PrintClientRow()
	//{
	//	cout << "\nInfo:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName: " << _FirstName;
	//	cout << "\nLastName : " << _LastName;
	//	cout << "\nFull Name: " << FullName();
	//	cout << "\nEmail    : " << _Email;
	//	cout << "\nPhone    : " << _Phone;
	//	cout << "\n___________________\n";

	//}

};