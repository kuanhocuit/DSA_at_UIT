#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};

// Cấu trúc của một DSLK
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddTail(LIST &L, int x) {
    NODE* p = CreateNode(x);
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void CreateList(LIST &L) {
    int x;
    cin >> x;
    while (x != -1) {
        AddTail(L, x);
        cin >> x;
    }
}

void RemoveHead(LIST &L) {
    if (L.pHead != NULL) {
        NODE* p = L.pHead;
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL) { // Kiểm tra nếu danh sách rỗng sau khi xóa phần tử đầu tiên
            L.pTail = NULL;
        }
        delete p;
    }
}

void PrintList(LIST L) {
    if (L.pHead == NULL) {
        cout << "Empty List.";
    } else {
        NODE* p = L.pHead;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
    cout << endl;
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    RemoveHead(L);
    PrintList(L);

    return 0;
}
