
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


void CreateEmptyList(LIST &L)
{
     L.pHead = NULL;
     L.pTail = NULL;
}


int count_even(NODE *p)
{
     int count=0;
     while (p!=NULL)
     {
          if(p->info%2==0)count++;
          p=p->pNext;
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

