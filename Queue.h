#pragma once
#include "bits/stdc++.h"
#include "clsSingleLinkedList.h"

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
class clsQueue
{

protected:

    clsSingleLinkedList <T> _MyList;
	
public:

    void push(T Value)
    {
        _MyList.InsertAtBack(Value);
    }

    void pop()
    {
        _MyList.DeleteFirstNode();
    }

    void clear()
    {
        _MyList.clear();
    }

    int size()
    {
        return _MyList.size();
    }

    T front()
    {
        return _MyList.fornt();
    }

    T back()
    {
        return _MyList.back();
    }

    bool empty()
    {
        return _MyList.IsEmpty();
    }

    void Print()
    {
        _MyList.PrintNodes();
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    T GetItem(int Index)
    {
        return _MyList.GetItem(Index);
    }

    bool UpdateItem(int Index, T Value)
    {
        return _MyList.UpdateItem(Index, Value);
    }

    bool InsertAfter(int Index, T Value)
    {
        return _MyList.InsertAfter(Index, Value);
    }

    void InsertFront(T Value)
    {
        _MyList.InsertAtBeginning(Value);
    }

    void InsertAtBack(T Value)
    {
        push(Value);
    }

};