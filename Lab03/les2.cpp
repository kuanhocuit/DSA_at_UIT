
#include <iostream>
#include <cstdlib>
#include <ctime>
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
     int n;
     cin >> n;
     int x;
     while (n)
     {
          cin >> x;
          AddTail(L, x);
          n--;
     }
}

NODE *SeparateHead(LIST &L)
{
     NODE *p;
     p = L.pHead;
     return p;
}

void PrintList(NODE *p)
{
     if (p == NULL or p->pNext == NULL)
          cout << "Empty List.";
     else
     {
          while (p->pNext != NULL)
          {
               cout << p->pNext->info << " ";
               p = p->pNext;
          }
     }
}

int main()
{
     LIST L;
     CreateEmptyList(L);

     CreateList(L);
     NODE *p = SeparateHead(L);
     if (p != NULL)
          cout << p->info << endl;
     PrintList(L.pHead);

     return 0;
}
