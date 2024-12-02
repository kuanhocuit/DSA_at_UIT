
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;


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

int SumNode(TREE T)
{
     int sum =0;
     if (T)
     {
          sum+= T->key;
          sum+= SumNode(T->pLeft);
          sum+= SumNode(T->pRight);
     }
     return sum;
     
}
 
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << SumNode(T);
	return 0;
}

