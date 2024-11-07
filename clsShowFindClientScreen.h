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

class clsFindClientScreen : protected clsScreen
{

public:

	static void FindClient()
	{

		system("cls");

		string Title = "      Find Client";

		clsScreen::_DrawScreenHeader(Title);

		clsBankClient Client = clsBankClient::Find(clsScreen::_ReadAccountNumber());

		if (!Client.IsEmpty())
		{
			clsScreen::_Print(Client);
		}
		else
		{
			co "\n\t\t\t\t\tClient Was Not Found";
		}

		co endl;

	}

};