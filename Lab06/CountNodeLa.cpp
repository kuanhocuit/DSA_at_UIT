
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
// count leaf in tree
void CountLeaf(TREE &T, int &count)
{
     if (T == NULL)
          return;
     if (T->pLeft == NULL && T->pRight == NULL)
     {
          count += 1;
          return;
     }
     CountLeaf(T->pLeft, count);
     CountLeaf(T->pRight, count);
}

int main()
{
     TREE T;   // hay: TNODE* T;
     T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
     CreateTree(T);

     int count = 0;
     CountLeaf(T, count);
     cout << count;
     return 0;
}
