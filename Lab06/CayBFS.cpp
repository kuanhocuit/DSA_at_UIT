#include <iostream>
#include <queue>
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

void PrintTreeBFS(TREE T)
{
     if (T == NULL)
     {
          cout << "Empty Tree.";
          return;
     }

     queue<TNODE *> q;
     q.push(T);

     while (!q.empty())
     {
          TNODE *node = q.front();
          q.pop();
          cout << node->key << " ";

          if (node->pLeft != NULL)
               q.push(node->pLeft);
          if (node->pRight != NULL)
               q.push(node->pRight);
     }
}

int main()
{
     TREE T; // hay: TNODE* T;
     T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
     CreateTree(T);
     PrintTreeBFS(T);
     return 0;
}