#include <iostream>
#include <queue>
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

bool compareQueues(queue<TREE> q1, queue<TREE> q2) {
    // Kiểm tra nếu kích thước của hai hàng đợi không bằng nhau
    if (q1.size() != q2.size()) {
        return false;
    }

    // So sánh từng phần tử của hai hàng đợi
    while (!q1.empty() && !q2.empty()) {
        if (q1.front()->key != q2.front()->key) {
            return false; // Nếu phát hiện phần tử không bằng nhau
        }
        q1.pop();
        q2.pop();
    }

    // Nếu tất cả phần tử đều bằng nhau
    return true;
}

// find x in tree
bool searchNode(TREE &T, int x, TREE &result)
{
    if (!T)
        return false;
    if (T->key == x)
    {
        result = T;
        return true;
    }
    if (x < T->key)
        return searchNode(T->pLeft, x, result);
    else
        return searchNode(T->pRight, x, result);
}

bool isSubtree(TREE S, TREE T)
{
    if (S == NULL) return true;
    if (T == NULL) return false;

    TREE subtreeRoot = NULL;
    if (searchNode(T, S->key, subtreeRoot) == false) return false;

    queue<TREE> qs, qt;
    qs.push(S);
    qt.push(subtreeRoot);

    while (!qs.empty() && !qt.empty())
    {
        TREE sNode = qs.front();
        qs.pop();
        TREE tNode = qt.front();
        qt.pop();

        if (sNode->key != tNode->key)
            return false;

        if (sNode->pLeft != NULL)
            qs.push(sNode->pLeft);
        if (sNode->pRight != NULL)
            qs.push(sNode->pRight);

        if (tNode->pLeft != NULL)
            qt.push(tNode->pLeft);
        if (tNode->pRight != NULL)
            qt.push(tNode->pRight);
    }

    return qs.empty() && qt.empty();
}

int main() {
    TNODE* S = NULL;
    TNODE* T = NULL;

    CreateTree(S);
    CreateTree(T);

    cout << boolalpha << isSubtree(S, T);

    return 0;
}
