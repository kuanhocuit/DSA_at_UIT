
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

int Height(TREE T)
{
     if (T == NULL)
     {
          return -1;
     }
     int leftHeight = Height(T->pLeft);
     int rightHeight = Height(T->pRight);
     return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int main()
{
     TREE T;   // hay: TNODE* T;
     T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
     CreateTree(T);
     if (T == NULL)
          cout << "Empty Tree.";
     else
          cout << Height(T);
     return 0;
}
