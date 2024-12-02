
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
void RNL(TREE &T)
{
    if (T)
    {
        RNL(T->pLeft);
        cout << T->key << " ";
        RNL(T->pRight);
    }
}
void PrintTree(TREE T)
{
    if (T == NULL)
        cout << "Empty List.";
    else
        RNL(T);
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
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}
