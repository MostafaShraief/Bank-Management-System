#pragma once
#include "bits/stdc++.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowClientsScreen.h"
#include "ShowAddClientScreen.h"
#include "clsShowDeleteClientScreen.h"
#include "clsShowUpdateClientScreen.h"
#include "clsShowFindClientScreen.h"
#include "clsShowTransactionsScreen.h"
#include "clsShowManageUsers.h"
#include "Global.h"
#include "clsLogin.h"
#include "clsShowLoginRegisterScreen.h"
#include "clsShowCurrencyScreen.h"

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

class clsMainScreen : private clsScreen
{

private:

    enum enMainMenuOptions {
        eClientsList = 1, eAddClient, eDeleteClient,
        eUpdateClient, eFindClient, eTransactions,
        eManageUsers, eLoginRegister, eCurrencyExchange,
        eLogout
    };

    static enMainMenuOptions _ReadMainMenuOption()
    {

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";

        short Option = clsInputValidate::ReadIntNumberBetween(1, 10, "\t\t\t\t     Please Inter Number Between 1 -> 10: ", "\t\t\t\t     Invalid: ");

        return enMainMenuOptions(Option);

    }

    static void _BackToMainMenu()
    {

        cout << setw(37) << left << "" << "\n\t\t\t\t\tPress any key to go back to Main Menu...";

        system("pause>0");

        ShowMainMenu();

    }

    static void _ShowAllClientsScreen()
    {
        clsShowClientsScreen::ShowClientList();
    }

    static void _ShowAddNewClientScreen()
    {
        clsShowAddClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClient();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::FindClient();
    }

    static void _ShowTransactionsScreen()
    {
        clsShowTransactionsScreen::ShowTransactionsScreen();
    }

    static void _ShowManageUsersScreen()
    {
        clsShowManageUsersScreen::ShowManageUsersScreen();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsShowLoginRegisterScreen::LoginRegister();
    }

    static void _ShowEndScreen()
    {
        system("cls");
        CurrentUser = clsUser::Find("", "");
    }

    static void _ShowAccsssDeniedScreen()
    {

        system("cls");
        clsScreen::_DrawScreenHeader("   ACCESS DENIED", "Contact Admin To Give\n\t\t\t\t\t\t   You Permission");

    }

    static void _ShowCurrencyExchangeMenu()
    {
        clsShowCurrencyScreen::CurrencyListScreen();
    }

    static void _PerformMainMenuOptions(enMainMenuOptions Option)
    {

        if (!CurrentUser.CheckPermission(clsUser::enPermissions(Option)))
        {
            _ShowAccsssDeniedScreen();
            _BackToMainMenu();
            return;
        }

        switch (Option)
        {

        case clsMainScreen::eClientsList:
            _ShowAllClientsScreen();
            _BackToMainMenu();
            break;
        case clsMainScreen::eAddClient:
            _ShowAddNewClientScreen();
            _BackToMainMenu();
            break;
        case clsMainScreen::eDeleteClient:
            _ShowDeleteClientScreen();
            _BackToMainMenu();
            break;
        case clsMainScreen::eUpdateClient:
            _ShowUpdateClientScreen();
            _BackToMainMenu();
            break;
        case clsMainScreen::eFindClient:
            _ShowFindClientScreen();
            _BackToMainMenu();
            break;
        case clsMainScreen::eTransactions:
            _ShowTransactionsScreen();
            ShowMainMenu();
            break;
        case clsMainScreen::eManageUsers:
            _ShowManageUsersScreen();
            ShowMainMenu();
            break;
        case eLoginRegister:
            _ShowLoginRegisterScreen();
            _BackToMainMenu();
            break;
        case eCurrencyExchange:
            _ShowCurrencyExchangeMenu();
            ShowMainMenu();
            break;
        case clsMainScreen::eLogout:
            _ShowEndScreen();
            //clsLogin::Login();
            break;

        }
        
    }

public:

	static void ShowMainMenu()
	{

        system("cls");

		_DrawScreenHeader("       Main Menu");

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t       Main Menue\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerformMainMenuOptions(_ReadMainMenuOption());
		
	}

};