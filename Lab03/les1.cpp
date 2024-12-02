

#include <iostream>
using namespace std;

#define MAX 10000
struct NODE
{
     int inf;
     NODE *pNext;
};

struct LIST
{
     NODE *pHead;
     NODE *pTail;
};

void CreateEmptyList(LIST &L)
{
     L.pHead = NULL;
     L.pTail = NULL;
}

NODE *CreateNode(int x)
{
     NODE *p;
     p = new NODE;
     if (p == NULL)
          exit(1);
     p->inf = x;
     p->pNext = NULL;
     return p;
}

void AddHead(LIST &L, int x)
{
     NODE *p = CreateNode(x);
     if (L.pHead == NULL)
     {
          L.pHead = p;
          L.pTail = L.pHead;
     }
     else
     {
          p->pNext = L.pHead;
          L.pHead = p;
     }
}

void CreateList(LIST &L)
{
     int x = -1;
     do
     {
          AddHead(L, x);
          cin >> x;
     } while (x != -1);
}

int length(LIST &L)
{
     int count = -1;
     NODE *p = L.pHead;
     while (p != NULL)
     {
          count++;
          p = p->pNext;
     }
     return count;
}

int main()
{
     LIST L;
     CreateEmptyList(L);

     CreateList(L);

     cout << length(L);

     return 0;
}
