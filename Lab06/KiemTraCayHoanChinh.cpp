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

void CreateEmptyTree(TREE &T)
{
    T = NULL;
}

TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE; // cấp phát vùng nhớ động
    p->key = x; // gán trường dữ liệu của node = x
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

bool IsCompleteBST(TREE &T)
{
    if (T == NULL)
        return true;

    queue<TREE> q;
    q.push(T);
    bool foundNull = false;

    while (!q.empty())
    {
        TREE node = q.front();
        q.pop();

        if (node)
        {
            if (foundNull) return false; // Nếu đã gặp nút trống trước đó thì cây không hoàn chỉnh
            q.push(node->pLeft);
            q.push(node->pRight);
        }
        else
        {
            foundNull = true; // Đánh dấu đã gặp nút trống
        }
    }

    return true;
}

int main()
{
    TREE T; // hay: TNODE* T;
    T = NULL; // Khởi tạo cây T rỗng, or: CreateEmptyTree(T)
    CreateTree(T);
    if (T == NULL)
        cout << "Empty Tree." << endl;
    else
        cout << boolalpha << IsCompleteBST(T) << endl;

    return 0;
}
