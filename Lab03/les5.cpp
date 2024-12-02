
#include <iostream>
using namespace std;

// Cấu trúc của một node
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

void Join(LIST &L, LIST &L1, NODE *&pivot, LIST &L2)
{
     while (L1.pHead!= NULL)
     {
          AddTail(L,L1.pHead->info);
          L1.pHead=L1.pHead->pNext;
     }
     AddTail(L,pivot->info);
     while (L2.pHead!= NULL)
     {
          AddTail(L,L2.pHead->info);
          L2.pHead=L2.pHead->pNext;
     }

}

void PrintList(LIST &l)
{
     NODE *p = l.pHead;
     while (p != NULL)
     {
          cout << p->info << " ";
          p = p->pNext;
     }
}

int main()
{
     LIST L, L1, L2;

     int x;
     NODE *pivot;

     CreateEmptyList(L);
     CreateEmptyList(L1);
     CreateEmptyList(L2);

     CreateList(L1);
     cin >> x;
     pivot = CreateNode(x);
     CreateList(L2);

     Join(L, L1, pivot, L2);
     PrintList(L);

     return 0;
}
