#pragma once
#include "bits/stdc++.h"

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
class clsDynamicArray
{

protected:

	int _Size = 0;

	T* Temp;

public:

	T* DArray;

	clsDynamicArray(int SIZE = 0)
	{

		_Size = (SIZE > 0 ? SIZE : 0);

		DArray = new T[_Size];
		
	}

	~clsDynamicArray()
	{
		delete[] DArray;
	}

	void PrintList()
	{

		for (int i = 0; i < _Size; ++i)
			co DArray[i] o " ";

		co endl;

	}

	bool SetItem(int Index, T Value)
	{

		if (Index >= _Size || Index < 0)
			return 0;

		DArray[Index] = Value;

		return 1;

	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

	void Resize(int NewSize)
	{

		if (NewSize < 0 || NewSize == _Size)
			return;

		Temp = new T[NewSize];

		int MinSize = min(_Size, NewSize);

		for (int i = 0; i < MinSize; ++i)
			Temp[i] = DArray[i];

		delete[] DArray;

		DArray = Temp;

		_Size = NewSize;

	}

	void Clear()
	{

		delete[] DArray;

		DArray = NULL;

		_Size = 0;

	}

	T GetItem(int Index)
	{

		if (Index >= _Size || Index < 0)
			return T();

		return DArray[Index];

	}

	T Front()
	{
		return GetItem(0);
	}

	T Back()
	{
		return GetItem(_Size - 1);
	}

	void Reverse()
	{

		Temp = new T[_Size];

		for (int i = 0; i < _Size; ++i)
			Temp[_Size - i - 1] = DArray[i];

		delete[] DArray;

		DArray = Temp;

	}

	bool DeleteItemAt(int Index)
	{

		if (Index >= _Size || Index < 0)
			return 0;

		Temp = new T[_Size - 1];

		for (int i = 0; i < Index; ++i)
			Temp[i] = DArray[i];

		for (int i = Index + 1; i < _Size; ++i)
			Temp[i - 1] = DArray[i];

		delete[] DArray;

		DArray = Temp;

		--_Size;

		return 1;

	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{

		for (int i = 0; i < _Size; ++i)
		{
			if (DArray[i] == Value)
				return i;
		}

		return -1;

	}

	bool DeleteItem(T Value)
	{

		int Index = Find(Value);

		if (Index == -1)
			return 0;

		DeleteItemAt(Index);

		return 1;

	}

	bool InsertAt(int Index, T Value)
	{

		if (Index > _Size || Index < 0)
			return 0;

		Temp = new T[_Size + 1];

		for (int i = 0; i < Index; ++i)
			Temp[i] = DArray[i];

		Temp[Index] = Value;

		for (int i = Index; i < _Size; ++i)
			Temp[i + 1] = DArray[i];

		delete[] DArray;

		DArray = Temp;

		++_Size;

		return 1;
		
	}

	bool InsertAtBeginning(T Value)
	{
		return InsertAt(0, Value);
	}

	bool InsertBefore(int Index, T Value)
	{
		return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}

};