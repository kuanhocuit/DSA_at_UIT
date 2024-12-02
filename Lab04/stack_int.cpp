#include <iostream>
using namespace std;

struct Node
{
     int a;
     Node *pNext;
     Node() : a(0), pNext(NULL) {}
     Node(int x) : a(x), pNext(NULL) {}
     Node(int x, Node *p) : a(x), pNext(p) {}
};

struct List
{
     Node *pHead;
     Node *pTail;
     List() : pHead(NULL), pTail(NULL) {}
     List(Node *p1, Node *p2) : pHead(p1), pTail(p2) {}
};

struct stack
{
     List L;
     stack() : L(NULL, NULL) {}
     stack(List l) : L(l) {}
};

Node *CreateNode(int x)
{
     Node *p;
     p = new Node;
     // if (p == NULL)
     //		exit(1);

     p->a = x;
     p->pNext = NULL;
     return p;
}
void AddTail(List &L, int x)
{
     Node *p = CreateNode(x);
     if (L.pHead == NULL)
     {
          L.pHead = p;
          L.pTail = L.pHead;
     }
     else
     {
          L.pTail->pNext=p;
          L.pTail=p;
     }
}
void AddHead(List &L, int x)
{
     Node *p = CreateNode(x);
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

void CreateList(List &L)
{

     int x;
     cin >> x;
     while (x != -1)
     {
          AddTail(L, x);
          cin >> x;
     }
}

void PushS(stack &s, int &x)
{
     AddHead(s.L, x);
}
int TopS(stack &s)
{
     int x = s.L.pHead->a;
     return x;
}

void PopS(stack &s, int &x)
{
     Node *p;
     if (s.L.pHead != NULL)
     {
          x = s.L.pHead->a;
          p = s.L.pHead;                // Bước 1
          s.L.pHead = s.L.pHead->pNext; // Bước 2
          if (s.L.pHead == NULL)
               s.L.pTail = NULL;
          delete p; // Bước 3
     }
}

void Testing_Push_Pop_Top_Stack(stack &s)
{
     List L;
     CreateList(L);
     Node *p = L.pHead;
     cout << "output: ";
     while (L.pHead != NULL)
     {
          if (L.pHead->a != 0)
          {
               PushS(s, L.pHead->a);
          }
          else if(s.L.pHead!=NULL)
          {
               cout <<TopS(s)<<" ";
               PopS(s, L.pHead->a);
          }
          L.pHead=L.pHead->pNext;
     }
     cout << "\ntop: ";
     if(s.L.pHead!=NULL) cout<< TopS(s);
}

int main()
{
     stack s;

     Testing_Push_Pop_Top_Stack(s);
     return 0;
}
