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

class clsShowDeleteUser : clsUserScreen
{

public:

    static void DeleteUser()
    {

        system("cls");

        string Title = "      Delete User";

        clsUserScreen::_DrawScreenHeader(Title);

        string UserName = clsInputValidate::ReadString("\n\t\t\t\t\tInter User Name : ");

        while (!clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("\n\t\t\t\t\tOps.. Not Exist,\n\t\t\t\t\tInter Valid User Name : ");
        }

        clsUser User = clsUser::Find(UserName);

        _Print(User);

        char Accept = clsInputValidate::ReadCharacter("\n\t\t\t\t\tAre You Sure You Want To Delete\n\t\t\t\t\tThis User Y/N ? ");

        cout << "\t\t\t\t\t______________________________________\n";

        if (toupper(Accept) == 'Y')
        {

            if (User.DeleteUser())
            {
                co "\n\t\t\t\t\tDeleted Successfully.\n\n";
            }
            else
            {
                co "\n\t\t\t\t\tFailed To Delete User.\n\n";
            }

        }

    }

};