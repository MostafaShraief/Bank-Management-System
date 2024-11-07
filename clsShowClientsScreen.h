#pragma once
#include "bits/stdc++.h"
#include "clsUserScreen.h"
#include "clsInputValidate.h"
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

class clsShowClientsScreen : protected clsUserScreen
{

private:
	
    static void _PrintClientRecordLine(clsBankClient& Client)
    {

        cout << "\t| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(30) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public:

    static void ShowClientList()
    {

        system("cls");

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "    Clients List";
        string SubTitle = "   (" + to_string(vClients.size()) + ") Clietnt(s)";

        clsUserScreen::_DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(10) << "PIN Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            co "\t\t\t\t\t\tNo Clients In The System..\n\t\t\t\t\tAdd Clients To Show Them.\n";
        }
        else
        {

            for (auto& C : vClients)
            {
                _PrintClientRecordLine(C);
                co endl;
            }

        }

        cout << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

    }

};