
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
bool isSorted(NODE *p)
{
     bool check = false;
     while (p != NULL and p->pNext != NULL)
     {
          if (p->info > p->pNext->info)
               return false;
          if (p->info < p->pNext->info)
          {
               check = true;
          }
          p = p->pNext;
     }
     return check;
}

int main()
{
     LIST *L = new LIST;

     CreateEmptyList(*L);
     CreateList(*L);

     cout << boolalpha << isSorted(L->pHead);

     return 0;
}
