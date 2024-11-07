#pragma once
#include "bits/stdc++.h"
#include "StackArr.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsMyString
{

private:

	clsStackArr <string> _Undo;

	clsStackArr <string> _Redo;

	string _Value;

public:

	string GetValue()
	{
		return _Value;
	}

	void SetValue(string Value)
	{

		_Undo.push(_Value);

		_Value = Value;

		_Redo.clear();

	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void Undo()
	{
		if (!_Undo.empty())
		{

			_Redo.push(_Value);

			_Value = _Undo.top();

			_Undo.pop();

		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{

			_Undo.push(_Value);

			_Value = _Redo.top();

			_Redo.pop();

		}
	}

};