#pragma once
#include "bits/stdc++.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsUserScreen.h"

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

class clsShowUpdateUserScreen : protected clsUserScreen
{

public:

    static void UpdateUser()
    {

        system("cls");

        string Title = "      Update User";

        _DrawScreenHeader(Title);

        string UserName = clsInputValidate::ReadString("\n\t\t\t\t\tInter User Name : ");

        while (!clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("\n\t\t\t\t\tOps.. Not Exist,\n\t\t\t\t\tInter Valid User Name : ");
        }

        clsUser User = clsUser::Find(UserName);

        _Print(User);

        co "\n\t\t\t\t\tUpdate User Info :";
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        _ReadUserInfo(User);

        cout << "\n\t\t\t\t\t______________________________________\n\n";

        if (User.Save() == clsUser::SavedSucceed)
        {
            co "\n\t\t\t\t\tSaved Successfully :)\n";
            _Print(User);
        }
        else
            co "\n\t\t\t\t\tSorry.. Went Wrong, Unsaved Issue.\n";

    }

};