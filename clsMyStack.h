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
class clsMyStack
{

private:

	int _Size = 0;

    T _Top;
    T _Back;

    class Node
    {

    public:

        T Value;
        Node* Next = nullptr;

    };

    Node* Head = NULL;

public:

    void push(T Value)
    {

        if (Head == NULL)
            _Back = Value;

        _Top = Value;

        Node* NewNode = new Node;

        NewNode->Value = Value;

        NewNode->Next = Head;

        Head = NewNode;

        ++_Size;

    }

    void pop()
    {

        if (Head == NULL)
            return;

        Node* Temp = Head;

        Head = Head->Next;

        if (Head != NULL)
            _Top = Head->Value;
        else
            _Top = T(), _Back = T();

        delete Temp;

        --_Size;

    }

    void clear()
    {

        _Top = T(), _Back = T(), _Size = 0;

        Node* Temp = NULL;

        while (Head != NULL)
        {

            Temp = Head;

            Head = Head->Next;

            delete Temp;

        }

    }

    int size()
    {
        return _Size;
    }

    T top()
    {
        return _Top;
    }

    T back()
    {
        return _Back;
    }

    void Print()
    {

        Node* Current = Head;

        while (Current != NULL)
        {

            co Current->Value o " ";

            Current = Current->Next;

        }

    }

};