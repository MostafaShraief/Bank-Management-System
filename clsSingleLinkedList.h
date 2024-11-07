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
class clsSingleLinkedList
{

protected:

    class Node
    {

    public:

        int Value;

        Node* Next;

    };

    Node* Head = NULL;
    Node* End = NULL;

    T _Front;
    T _Back;

    int _Size = 0;

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

    void PrintNodes()
    {

        Node* Current = Head;

        while (Current != NULL)
        {

            co Current->Value o " ";

            Current = Current->Next;

        }

        co endl;

    }

    void InsertAtBeginning(Node*& Head, T Value)
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

    void InsertAtBeginning(T Value)
    {


        Node* NewNode = new Node;

        NewNode->Value = Value;

        NewNode->Next = Head;

        if (Head == NULL)
            _Back = Value, End = NewNode;

        _Front = Value;

        Head = NewNode;

        ++_Size;

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

        if (End == Current)
            End = NewNode;

        _Back = End->Value;

        ++_Size;

        return 1;

    }

    /*void InsertNodeAtEnd(Node*& Head, int Value)
    {

        Node* NewNode = new Node;

        NewNode->Value = Value;

        NewNode->Next = NULL;

        if (Head == NULL)
        {
            Head = NewNode;
            return;
        }

        Node* LastNode = Head;

        while (LastNode->Next != NULL)
            LastNode = LastNode->Next;

        LastNode->Next = NewNode;

        ++_Size;

    }*/

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

    void DeleteNode(Node*& Head, int Value)
    {

        if (Head == NULL)
            return;

        Node* Current = Head;

        Node* Previous = Head;

        if (Head->Value == Value)
        {

            Head = Head->Next;

            delete Current;

            return;

        }

        Current = Head->Next;

        while (Current != NULL)
        {

            if (Current->Value == Value)
            {

                Previous->Next = Current->Next;

                delete Current;

                return;

            }

            Previous = Current;

            Current = Current->Next;

        }


    }

    void DeleteFirstNode()
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

    //void DeleteLastNode(Node*& Head)
    //{

    //    if (Head == NULL)
    //        return;

    //    Node* Temp = Head;

    //    Head = Head->Next;

    //    if (Head != NULL)
    //        _Front = Head->Value;
    //    else
    //        _Front = T(), _Back = T();

    //    delete Temp;

    //    --_Size;

    //}

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

    Node* GetNode(int Index)
    {

        if (Index >= _Size || Index < 0)
            return NULL;

        Node* Current = Head;

        while (Index--)
            Current = Current->Next;

        return Current;

    }

    T GetItem(int Index)
    {

        Node* Current = Find(Index);

        if (Current == NULL)
            return T();

        return Current->Value;

    }

    bool IsEmpty()
    {
        return Head == NULL;
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

};
