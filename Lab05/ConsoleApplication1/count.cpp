// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// C?u trúc c?a m?t node
struct NODE
{
    int info;
    NODE* pNext;
};
// C?u trúc c?a m?t DSLK
struct LIST
{
    NODE* pHead;
    NODE* pTail;
};

NODE* CreateNode(int x)
{
    NODE* p;
    p = new NODE;
    // if (p == NULL)
    //		exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void AddTail(LIST& L, int x)
{
    NODE* p = CreateNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void CreateList(LIST& L)
{

    int x;
    cin >> x;
    while (x != -1)
    {
        AddTail(L, x);
        cin >> x;
    }
}

int count_even(NODE* p)
{
    int count = 0;
    while (p!=NULL)
    {
        if (p->info%2==0)
        {
            count++;

        }
        p = p->pNext;
    }
    return count;

}


int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
