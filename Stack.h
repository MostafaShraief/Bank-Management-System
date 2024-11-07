#pragma once
#include "bits/stdc++.h"
#include "Queue.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

template <class T>
class  clsStack : public clsQueue <T>
{

private:

	void front()
	{

	}

	void back()
	{

	}

public:

	void push(T Item)
	{
		clsQueue <T>::_MyList.InsertAtBeginning(Item);
	}

	T top()
	{
		return clsQueue <T>::front();
	}

	T bottom()
	{
		return clsQueue <T>::back();
	}

};