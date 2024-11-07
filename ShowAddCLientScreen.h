#pragma once
#include "bits/stdc++.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
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

class clsShowAddClientScreen : protected clsScreen
{

public:

    static void AddNewClient()
    {

        system("cls");

        string Title = "      Add Client";

        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tInter Account Number : ");

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tOps.. Already Exist,\n\t\t\t\t\tInter Valid Account Number : ");
        }

        co "\n\t\t\t\t\tAdd New Client :";
        cout << "\n\t\t\t\t\t___________________\n\n";

        clsBankClient Client = clsBankClient::AddNewClientObject(AccountNumber);

        _ReadClientInfo(Client);

        cout << "\n\t\t\t\t\t___________________\n\n";

        if (Client.Save() == clsBankClient::SavedSucceed)
        {

            co "\t\t\t\t\tSaved Successfully :)\n";

            _Print(Client);

        }
        else if (clsBankClient::FailedToSave)
            co "\t\t\t\t\tSorry.. Somthing Went Wrong,\n\t\t\t\t\tUnsaved Issue.\n";
        else if (clsBankClient::FailedToSaveAlreeadyAccNumExist)
            co "\t\t\t\t\tSorry.. Failed To Save Due To Account\n\t\t\t\t\tNumber Already Exist.\n";

        co endl;

    }

};