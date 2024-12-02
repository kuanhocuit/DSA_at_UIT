#include <iostream>
using namespace std;

struct TNODE
{
     int key;
     TNODE *pLeft;
     TNODE *pRight;
};
typedef TNODE *TREE;

void CreateEmptyTree(TREE &T)
{
     T = NULL;
}

TNODE *CreateTNode(int x)
{
     TNODE *p = new TNODE; // cấp phát vùng nhớ động
     p->key = x;           // gán trường dữ liệu của node = x
     p->pLeft = NULL;
     p->pRight = NULL;
     return p;
}

int Insert(TREE &T, TNODE *p)
{
     if (T)
     {
          if (T->key == p->key)
               return 0;
          if (T->key > p->key)
               return Insert(T->pLeft, p);
          return Insert(T->pRight, p);
     }
     T = p;
     return 1;
}

void CreateTree(TREE &T)
{
     int x;
     do
     {
          cin >> x;
          if (x == -1)
               break;
          if (x < 1000) // Kiểm tra giá trị nhỏ hơn 1000
               Insert(T, CreateTNode(x));
     } while (true);
}

void FindParent(TREE T, int x)
{
     if (!T)
     {
          cout << "Empty Tree." << endl;
          return;
     }
     if (T->key == x)
     {
          cout << x << " has no parent." << endl;
          return;
     }
     if ((T->pLeft != NULL && T->pLeft->key == x) || (T->pRight != NULL && T->pRight->key == x))
     {
          cout << T->key << " is parent of " << x << ".";
          return;
     }
     if (x < T->key)
     {
          if (T->pLeft != NULL)
               FindParent(T->pLeft, x);
          else
               cout << "Not found " << x << ".";
     }
     else
     {
          if (T->pRight != NULL)
               FindParent(T->pRight, x);
          else
               cout << "Not found " << x << ".";
     }
}

int main()
{
     TREE T;   // hay: TNODE* T;
     T = NULL; // Khởi tạo cây T rỗng, or: CreateEmptyTree(T)
     CreateTree(T);

     int x;
     cin >> x;

     FindParent(T, x);

     return 0;
}
