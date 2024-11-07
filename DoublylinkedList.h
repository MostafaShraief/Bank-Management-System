#pragma once
#include "bits/stdc++.h"
#include "clsUtility.h"

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
class clsDblLinkedList
{

public:

    class Node;

private:

    static void InsertAtBeginning(Node*& Head, T Value)
    {

        Node* NewNode = new Node;

        NewNode->Value = Value;

        NewNode->Next = NULL;

        NewNode->Prev = NULL;

        if (Head != NULL)
            Head->Prev = NewNode, NewNode->Next = Head;

        Head = NewNode;

    }

    static void PrintNodesAccendingOrder(Node* Head)
    {

        while (Head != NULL)
        {
            co Head->Value o " ";
            Head = Head->Next;
        }

    }

    static void PrintList(Node* head)
    {

        cout << "NULL <--> ";
        while (head != NULL) {
            cout << head->Value << " <--> ";
            head = head->Next;
        }
        cout << "NULL";

    }

    static Node* Find(Node* Head, T Value)
    {

        while (Head != NULL)
        {

            if (Head->Value == Value)
                return Head;

            Head = Head->Next;

        }

        return NULL;

    }

    static void InsertAtEnd(Node*& Head, T Value)
    {

        Node* NewNode = new Node;

        NewNode->Value = Value;
        NewNode->Next = NULL;
        NewNode->Prev = NULL;

        if (Head == NULL)
        {
            Head = NewNode;
            return;
        }

        if (Head->Next == NULL)
        {

            Head->Next = NewNode;

            NewNode->Prev = Head;

            return;

        }

        Node* CurrentNode = Head;

        while (CurrentNode->Next != NULL)
            CurrentNode = CurrentNode->Next;

        CurrentNode->Next = NewNode;

        NewNode->Prev = CurrentNode;

    }

    static void DeleteFirstNode(Node*& Head)
    {

        if (Head == NULL)
            return;

        Node* Current = Head;

        if (Head->Prev == NULL)
        {

            Head = Head->Next;

            if (Head != NULL)
                Head->Prev = NULL;

            delete Current;

            return;

        }

    }

    static void DeleteLastNode(Node*& Head)
    {

        if (Head == NULL)
            return;

        Node* Current = Head;

        if (Head->Next == NULL)
        {

            Head = NULL;

            delete Current;

            return;

        }

        while (Current->Next != NULL)
            Current = Current->Next;

        Current->Prev->Next = NULL;

        delete Current;

    }

protected:

    int _Size = 0;

public:

    class Node
    {

    public:

        T Value;
        Node* Next;
        Node* Prev;

    };

    Node* Head = NULL;

    void InsertAtBeginning(T Value)
    {
        InsertAtBeginning(Head, Value);
        ++_Size;
    }

    void PrintNodesAccendingOrder()
    {
        PrintNodesAccendingOrder(Head);
    }

    static void PrintNodesDeccendingOrder(Node* Head)
    {

        if (Head == NULL)
            return;

        while (Head->Next != NULL)
            Head = Head->Next;

        while (Head != NULL)
        {
            co Head->Value o " ";
            Head = Head->Prev;
        }

    }

    void PrintNodesDeccendingOrder()
    {
        PrintNodesDeccendingOrder(Head);
    }

    static void PrintNodeDetails(Node* head)
    {

        if (head->Prev != NULL)
            cout << head->Prev->Value;
        else
            cout << "NULL";

        cout << " <--> " << head->Value << " <--> ";

        if (head->Next != NULL)
            cout << head->Next->Value << "\n";
        else
            cout << "NULL";

    }

    void PrintNodeDetails()
    {
        PrintNodeDetails(Head);
    }

    static void PrintListDetails(Node* Head)
    {

        while (Head != NULL)
        {
            PrintNodeDetails(Head);
            Head = Head->Next;
        }

    }

    void PrintListDetails()
    {
        PrintListDetails(Head);
    }

    void PrintList()
    {
        PrintList(Head);
    }

    Node* Find(T Value)
    {
        return Find(Head, Value);
    }

    void InsertAfter(Node* Head, T Value)
    {

        if (Head == NULL)
            return;

        Node* NewNode = new Node;

        NewNode->Value = Value;

        NewNode->Next = Head->Next;

        if (NewNode->Next != NULL)
            NewNode->Next->Prev = NewNode;

        NewNode->Prev = Head;

        Head->Next = NewNode;

        ++_Size;

    }

    void InsertAfter(T Value)
    {
        InsertAfter(Head, Value);
        ++_Size;
    }

    void InsertAtEnd(T Value)
    {
        InsertAtEnd(Head, Value);
        ++_Size;
    }

    /*static void DeleteNode(Node*& Head, T Value)
    {

        if (Head == NULL)
            return;

        Node* Current = Head;

        if (Head->Value == Value)
        {

            Head = Head->Next;

            if (Head != NULL)
                Head->Prev = NULL;

            delete Current;

            return;

        }

        while (Current != NULL)
        {

            if (Current->Value == Value)
            {

                Current->Prev->Next = Current->Next;

                if (Current->Next != NULL)
                    Current->Next->Prev = Current->Prev;

                delete Current;

                return;

            }

            Current = Current->Next;

        }

    }

    void DeleteNode(T Value)
    {
        void DeleteNode(Head, Value);
    }*/

    void DeleteNode(Node*& Head)
    {

        if (Head == NULL)
            return;

        if (Head->Prev != NULL)
            Head->Prev->Next = Head->Next;

        if (Head->Next != NULL)
            Head->Next->Prev = Head->Prev;

        delete Head;

        --_Size;

    }

    void DeleteFirstNode()
    {

        if (Head == NULL)
            return;

        DeleteFirstNode(Head);

        --_Size;

    }

    void DeleteLastNode()
    {

        if (Head == NULL)
            return;

        DeleteLastNode(Head);

        --_Size;

    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return Head == NULL;
    }

    void Clear()
    {

        _Size = 0;

        while (Head != NULL)
        {

            Node* Current = Head;

            Head = Head->Next;

            delete Current;

        }

    }

    void Reverse()
    {

        Node* Current = Head;

        Node* Temp = NULL;

        while (Current != NULL)
        {

            Temp = Current->Prev;

            Current->Prev = Current->Next;

            Current->Next = Temp;

            Current = Current->Prev;

        }
        
        if (Temp != NULL)
            Head = Temp->Prev;

    }

    Node* GetNode(int Index)
    {

        if (Index >= _Size || Index < 0)
            return NULL;

        Node* Current = Head;

        ++Index;

        while (--Index > 0)
            Current = Current->Next;

        return Current;

    }

    T GetItem(int Index)
    {

        Node* Current = GetNode(Index);

        if (Current == NULL)
            return NULL;

        return Current->Value;

    }

    bool UpdateItem(int Index, T Value)
    {

        Node* Current = GetNode(Index);

        if (Current != NULL)
        {
            Current->Value = Value;
            return true;
        }

        return false;

    }

    bool InsertAfter(int Index, T Value)
    {

        Node* Current = GetNode(Index);

        if (Current != NULL)
        {
            InsertAfter(Current, Value);
            return true;
        }

        return false;

    }

};