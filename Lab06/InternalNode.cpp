
#include <iostream>
using namespace std;

struct TNODE
{
     int key;
     TNODE *pLeft;
     TNODE *pRight;
};
typedef TNODE *TREE;

TNODE *CreateNodeTree(int x)
{
     TNODE *p = new TNODE;
     p->key = x;
     p->pLeft = NULL;
     p->pRight = NULL;
     return p;
}

void InsertNode(TREE &T, int x)
{
     if (T == NULL)
     {
          T = CreateNodeTree(x);
     }
     else
     {
          if (x < T->key)
          {
               InsertNode(T->pLeft, x);
          }
          else if (x > T->key)
          {
               InsertNode(T->pRight, x);
          }
     }
}
void CreateTree(TREE &T)
{
     int value;
     while (true)
     {
          cin >> value;
          if (value == -1)
               break;
          InsertNode(T, value);
     }
}
int SumInternalNode(TREE &T)
{
     if (!T)
     {
          return 0;
     }
     int sum = 0; // Check if the current node is an internal node
     if (T->pLeft != NULL || T->pRight != NULL)
     {
          sum += T->key;
     } 
     sum += SumInternalNode(T->pLeft);
     sum += SumInternalNode(T->pRight);
     return sum;
}
int main()
{
     TREE T;   // hay: TNODE* T;
     T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
     CreateTree(T);

     cout << SumInternalNode(T);
     return 0;
}
