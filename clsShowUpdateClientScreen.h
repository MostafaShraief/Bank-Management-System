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

class clsUpdateClientScreen : protected clsScreen
{

public:

    static void UpdateClient()
    {

        system("cls");

        string Title = "      Update Client";

        clsScreen::_DrawScreenHeader(Title);

        clsBankClient Client = clsBankClient::Find(clsScreen::_ReadAccountNumber());

        _Print(Client);

        co "\n\t\t\t\t\tUpdate Client Info :";
        cout << "\n\t\t\t\t\t___________________\n\n";

        _ReadClientInfo(Client);

        cout << "\n\t\t\t\t\t___________________\n\n";

        if (Client.Save() == clsBankClient::SavedSucceed)
        {
            co "\n\t\t\t\t\tSaved Successfully :)\n";
            _Print(Client);
        }
        else
            co "\n\t\t\t\t\tSorry.. Went Wrong, Unsaved Issue.\n";

    }

};