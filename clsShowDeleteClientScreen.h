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

class clsDeleteClientScreen : protected clsScreen
{

public:

    static void DeleteClient()
    {

        system("cls");

        string Title = "      Delete Client";

        clsScreen::_DrawScreenHeader(Title);

        clsBankClient Client = clsBankClient::Find(clsScreen::_ReadAccountNumber());

        _Print(Client);

        char Accept = clsInputValidate::ReadCharacter("\n\t\t\t\t\tAre You Sure You Want To Delete\n\t\t\t\t\tThis Client Y/N ? ");

        cout << "\n\t\t\t\t\t___________________\n";

        if (toupper(Accept) == 'Y')
        {

            if (Client.DeleteClient())
            {
                co "\n\t\t\t\t\tDeleted Successfully.\n\n";
            }
            else
            {
                co "\n\t\t\t\t\tFailed To Delete Client.\n\n";
            }

        }

    }

};