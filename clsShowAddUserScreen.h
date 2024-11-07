#pragma once
#include "bits/stdc++.h"
#include "clsUserScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

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

class clsShowAddUserScreen : protected clsUserScreen
{

private:

public:

    static void AddNewUser()
    {

        system("cls");

        string Title = "      Add User";

        clsUserScreen::_DrawScreenHeader(Title);

        string UserName = clsInputValidate::ReadString("\n\t\t\t\t\tInter User Name : ");

        while (clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("\n\t\t\t\t\tOps.. Already User Name Exist,\n\t\t\t\t\tInter Valid User Name : ");
        }

        co "\n\t\t\t\t\tAdd New User :";
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        clsUser User = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(User);

        cout << "\n\t\t\t\t\t______________________________________\n\n";

        if (User.Save() == clsUser::SavedSucceed)
        {

            co "\t\t\t\t\tSaved Successfully :)\n";

            _Print(User);

        }
        else if (clsUser::FailedToSave)
            co "\t\t\t\t\tSorry.. Somthing Went Wrong,\n\t\t\t\t\tUnsaved Issue.\n";
        else if (clsUser::FailedToSaveAlreeadyUserNameExist)
            co "\t\t\t\t\tSorry.. Failed To Save Due To User\n\t\t\t\t\tName Already Exist.\n";

        co endl;

    }

};