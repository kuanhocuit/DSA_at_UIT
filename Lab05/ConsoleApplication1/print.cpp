

#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};
// Cấu trúc của một DSLK
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    // if (p == NULL)
    //		exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void AddTail(LIST &L, int x)
{
    NODE *p = CreateNode(x);
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

void CreateList(LIST &L)
{

    int x;
    cin >> x;
    while (x != -1)
    {
        AddTail(L, x);
        cin >> x;
    }
}

void Print_Middle(LIST &L)
{
    if (L.pHead == NULL)
        cout << "Empty List";
    else 
    {
        NODE *slow = L.pHead;
        NODE *fast = L.pHead;
        while (fast->pNext != NULL && fast->pNext->pNext != NULL)
        {
            slow = slow->pNext;
            fast = fast->pNext->pNext;
        }
        cout << slow->info;
    }
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    Print_Middle(L);

    return 0;
}
