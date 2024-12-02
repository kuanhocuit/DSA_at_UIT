
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
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


void Partition(LIST &L, LIST &L1, NODE *&pv, LIST &L2)
{
     if(L.pHead!=NULL)
     pv= L.pHead;

     while (L.pHead->pNext!=NULL)
     {
          L.pHead=L.pHead->pNext;
          if (L.pHead->info<= pv->info)
          {
               AddTail(L1, L.pHead->info);
          }
          else AddTail(L2,L.pHead->info);  
     }
     L.pHead =NULL;
     
}

void PrintList( LIST &l)
{
    if (l.pHead== NULL)
    {
     cout<<"Empty List.";
    }
    else 
    {
     NODE* p=l.pHead;
          while (p!=NULL)
          {
               cout<<p->info<<" ";
               p=p->pNext;
          }
    }
    cout<<endl;
}

int main() {
    LIST L, L1, L2;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateList(L);

	if(L.pHead==NULL) {
		cout << "Empty List.";
		return 0;
	}

	Partition(L, L1, pivot, L2);

	cout << pivot->info << endl;
	PrintList(L1);
	PrintList(L2);
	PrintList(L);

    return 0;
}
