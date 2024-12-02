
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
void AddTail(LIST &L, NODE *p)
{
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

void CreateEmptyList(LIST &L)
{
     L.pHead = NULL;
     L.pTail = NULL;
}
void CreateList(LIST &L)
{
     NODE *p;
     int x, n;
     cin >> n; // Số lượng phần tử của danh sách
     while (n-- > 0)
     {
          cin >> x;
          p = CreateNode(x);
          AddTail(L, p);
     }
}

// 6 3 2 4

int length(NODE *p)
{
     int i = 0;
     while (p)
     {
          i++;
          p = p->pNext;
     }
     return i;
}

void PrintList(NODE *p)
{
     if (p == NULL)
          cout << "Empty List.";
     else
     {
          // cout << boolalpha << is_ascending(p) << endl;
          cout <<"a"<< length(p) << endl;
          while (p)
          {
               cout << p->info << " ";
               p = p->pNext;
          }
     }
}

NODE *SeparateHead(LIST &L)
{
     NODE *p = L.pHead;
     if (p == NULL)
          return NULL;
     L.pHead = L.pHead->pNext;
     if (L.pHead == NULL)
          L.pTail = NULL;
     p->pNext = NULL;
     return p;
}

void Partition(LIST &L, LIST &L1, LIST &L2, NODE *&pivot)
{
     NODE *p;
     if (L.pHead == NULL)
          return;
     pivot = SeparateHead(L);
     while (L.pHead != NULL)
     {
          p = SeparateHead(L);
          if (p->info <= pivot->info)
               AddTail(L1, p);
          else
               AddTail(L2, p);
     }
}

void Join(LIST &L1, LIST &L2, LIST &L3, NODE *pivot)
{
     NODE *p;
     while (L2.pHead != NULL)
     {
          p = SeparateHead(L2);
          AddTail(L1, p);
     }
     AddTail(L1, pivot);
     while (L3.pHead != NULL)
     {
          p = SeparateHead(L3);
          AddTail(L1, p);
     }
}

void QuickSort(LIST &L)
{
     LIST L1, L2;
     CreateEmptyList(L1);
     CreateEmptyList(L2);
     NODE *pivot;
     Partition(L, L1, L2, pivot);
     if (L1.pHead != L1.pTail)
          QuickSort(L1);
     if (L2.pHead != L2.pTail)
          QuickSort(L2);
     Join(L, L1, L2, pivot);
}

int main()
{
     LIST L;
     CreateEmptyList(L);

     CreateList(L);
     QuickSort(L);
     PrintList(L.pHead);

     return 0;
}