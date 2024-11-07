#pragma once
#include "bits/stdc++.h"
#include "Global.h"
#include "clsDate.h"
#include "clsBankClient.h"

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

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t" << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t" << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        co "\n\t\t\t\t\tUser : " o CurrentUser.UserName;

        co "\n\t\t\t\t\tDate : " o clsDate::Local_Time_To_Date().Date_To_String() o endl o endl;

	}

    static void _Print(clsBankClient& Client)
    {

        cout << "\n\t\t\t\t\tClient Card:";
        cout << "\n\t\t\t\t\t______________________________________";
        cout << "\n\t\t\t\t\tFirst Name      : " << Client.FirstName;
        cout << "\n\t\t\t\t\tLastName       : " << Client.LastName;
        cout << "\n\t\t\t\t\tFull Name      : " << Client.FullName();
        cout << "\n\t\t\t\t\tEmail          : " << Client.Email;
        cout << "\n\t\t\t\t\tPhone          : " << Client.Phone;
        cout << "\n\t\t\t\t\tAccount Number : " << Client.AccountNumber;
        cout << "\n\t\t\t\t\tPassword       : " << Client.PinCode;
        cout << "\n\t\t\t\t\tBalance        : " << Client.AccountBalance;
        cout << "\n\t\t\t\t\t______________________________________\n";

    }

    static void _ReadClientInfo(clsBankClient& Client)
    {

        Client.FirstName = clsInputValidate::ReadString("\t\t\t\t\tEnter First Name : ");
        Client.LastName = clsInputValidate::ReadString("\t\t\t\t\tEnter Last Name : ");
        Client.Email = clsInputValidate::ReadString("\t\t\t\t\tEnter Email : ");
        Client.Phone = clsInputValidate::ReadString("\t\t\t\t\tEnter Phone Numebr : ");
        Client.PinCode = clsInputValidate::ReadString("\t\t\t\t\tEnter PIN Code : ");
        Client.AccountBalance = clsInputValidate::ReadDblNumber("\t\t\t\t\tEnter Account Balance : ", "\t\t\t\t\tInvalid: ");

    }

    static string _ReadAccountNumber(string Message = "\n\t\t\t\t\tInter Account Number : ")
    {

        string AccountNumber = clsInputValidate::ReadString(Message);

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tOps.. Not Exist,\n\t\t\t\t\tInter Valid Account Number : ");
        }

        return AccountNumber;

    }

};