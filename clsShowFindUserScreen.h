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

class clsShowFindUserScreen : protected clsUserScreen
{

public:


	static void FindUser()
	{

		system("cls");

		string Title = "      Find User";

		_DrawScreenHeader(Title);

		string UserName = clsInputValidate::ReadString("\n\t\t\t\t\tInter User Name : ");

		while (!clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate::ReadString("\n\t\t\t\t\tOps.. Not Exist,\n\t\t\t\t\tInter Valid User Name : ");
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			_Print(User);
		}
		else
		{
			co "\n\t\t\t\t\tUser Was Not Found";
		}

		co endl;

	}

};