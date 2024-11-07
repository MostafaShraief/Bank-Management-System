#pragma once
#include "bits/stdc++.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"
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

class clsUserScreen : protected clsScreen
{

private:

    static void _AskPermissions(clsUser& User)
    {

        if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Full Access Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
            User.SetPermissions(clsUser::eFullAccess);

        if (User.Permissions != -1)
        {

            User.NullPermissions();

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tShow Clients List Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eClientsList);

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tAdd Clients Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eAddClient);

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tDelete Clients Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eDeleteClient);

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tUpdate Clients Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eUpdateClient);

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tFind Clients Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eFindClient);

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tTransactions Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eTransactions);

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tManage Users Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eManageUsers);

            if (clsInputValidate::ReadConfirm("\n\t\t\t\t\tDo You Want Give Access To\n\t\t\t\t\tLogin Register Y/N? ", "\n\t\t\t\t\tInvalid Procedure: "))
                User.SetPermissions(clsUser::eRegisterLogs);

        }

    }

protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        clsScreen::_DrawScreenHeader(Title, SubTitle);
    }

    static void _Print(clsUser& User)
    {

        cout << "\n\t\t\t\t\tUser Card:";
        cout << "\n\t\t\t\t\t______________________________________";
        cout << "\n\t\t\t\t\tFirstName   : " << User.FirstName;
        cout << "\n\t\t\t\t\tLastName    : " << User.LastName;
        cout << "\n\t\t\t\t\tFull Name   : " << User.FullName();
        cout << "\n\t\t\t\t\tEmail       : " << User.Email;
        cout << "\n\t\t\t\t\tPhone       : " << User.Phone;
        cout << "\n\t\t\t\t\tUser Name   : " << User.UserName;
        cout << "\n\t\t\t\t\tPassword    : " << User.Password;
        cout << "\n\t\t\t\t\tPermissions : " << User.Permissions;
        cout << "\n\t\t\t\t\t______________________________________\n";

    }

    static void _ReadUserInfo(clsUser& User)
    {

        User.FirstName = clsInputValidate::ReadString("\t\t\t\t\tEnter First Name : ");
        User.LastName = clsInputValidate::ReadString("\t\t\t\t\tEnter Last Name : ");
        User.Email = clsInputValidate::ReadString("\t\t\t\t\tEnter Email : ");
        User.Phone = clsInputValidate::ReadString("\t\t\t\t\tEnter Phone Numebr : ");
        User.Password = clsInputValidate::ReadString("\t\t\t\t\tEnter Password : ");
        _AskPermissions(User);

    }

};