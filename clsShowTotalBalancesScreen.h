#pragma once
#include "bits/stdc++.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
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

class clsShowTotalBalancesScreen : protected clsScreen
{

private:

    static void _PrintClientRow(clsBankClient& Client)
	{

        cout << "\t| " << setw(15) << left << Client.AccountNumber;
		cout << "\t\t| " << setw(20) << left << Client.FullName();
		cout << "\t\t\t| " << setw(12) << left << Client.AccountBalance;

	}

public:

    static void TotalBalances()
    {

        system("cls");

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "    Balances Menu";

        string SubTitle = "   (" + to_string(vClients.size()) + ") Clietnt(s)";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "\t\t| " << left << setw(20) << "Client Name";
        cout << "\t\t\t| " << left << setw(12) << "Balance";
        cout << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            co "\t\t\t\t\tNo Clients In The System..\n\t\t\t\t\tAdd Clients To Show Them.\n";
        }
        else
        {

            for (auto& C : vClients)
            {
                _PrintClientRow(C);
                co endl;
            }

        }

        cout << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        ld TotalBalances = clsBankClient::GetTotalBalances();

        co "\t\t\t\t\t\tTotal Balances = " o TotalBalances o endl;
        co "\t\t\t\t\t\t( " o clsUtility::NumberToText(TotalBalances) o " )\n";


    }

};