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
class clsMyQueue
{

private:

    int _Size = 0;

    T _Front;
    T _Back;

    class Node
    {

    public:

        T Value;
        Node* Next = nullptr;

    };

    Node* Head = NULL;

    Node* End = NULL;

    Node* Find(int Index)
    {

        if (Index >= _Size || Index < 0)
            return NULL;

        Node* Current = Head;

        while (Index--)
            Current = Current->Next;

        return Current;

    }

public:

    void push(T Value)
    {

        _Back = Value;

        Node* NewNode = new Node;

        NewNode->Value = Value;
        NewNode->Next = NULL;

        if (End != NULL)
            End->Next = NewNode;

        End = NewNode;

        if (Head == NULL)
            _Front = Value, Head = End;

        ++_Size;

    }

    void pop()
    {

        if (Head == NULL)
            return;

        Node* Temp = Head;

        Head = Head->Next;

        if (Head != NULL)
            _Front = Head->Value;
        else
            _Front = T(), _Back = T(), End = NULL;

        delete Temp;

        --_Size;

    }

    void clear()
    {

        _Front = T(), _Back = T(), _Size = 0, End = NULL;

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

    T fornt()
    {
        return _Front;
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

    void Reverse()
    {

        Node* Prev = NULL;

        Node* Current = NULL;

        End = Head;

        while (Head != NULL)
        {

            Current = Head->Next;

            Head->Next = Prev;

            Prev = Head;

            Head = Current;

        }

        Head = Prev;

        swap(_Front, _Back);

    }

    T GetItem(int Index)
    {

        Node* Current = Find(Index);

        if (Current == NULL)
            return T();

        return Current->Value;

    }

    bool UpdateItem(int Index, T Value)
    {

        Node* Current = Find(Index);

        if (Current == NULL)
            return 0;

        Current->Value = Value;

        _Front = Head->Value;

        _Back = End->Value;

        return 1;

    }

    bool InsertAfter(int Index, T Value)
    {

        Node* Current = Find(Index);

        if (Current == NULL)
            return 0;

        Node* NewNode = new Node;

        NewNode->Value = Value;

        NewNode->Next = Current->Next;

        Current->Next = NewNode;

        _Back = End->Value;

        ++_Size;

        return 1;

    }

    void InsertFront(T Value)
    {

        if (Head == NULL)
            _Back = Value;

        _Front = Value;

        Node* NewNode = new Node;

        NewNode->Value = Value;

        NewNode->Next = Head;

        Head = NewNode;

        ++_Size;

    }

    void InsertAtBack(T Value)
    {
        push(Value);
    }

};