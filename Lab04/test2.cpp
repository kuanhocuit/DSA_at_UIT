#include <iostream>
#include <string.h>

using namespace std;

// Cấu trúc của một node
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
    if (p == nullptr) {
        cout << "Khong du bo nho";
        return nullptr;
    }
    p->info = x;
    p->pNext = nullptr;
    return p;
}

void CreateEmptyList(LIST &L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}

void AddTail(LIST &L, int x) {
    NODE* p = CreateNode(x);
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = p;
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

int get_nth_node_from_head(NODE* pHead, int k) {
    int count = 1;
    NODE* p = pHead;
    while (p != nullptr) {
        if (count == k) {
            return p->info;
        }
        count++;
        p = p->pNext;
    }
    return -1; // Không tìm thấy node ở vị trí thứ k
}

int main() {
    LIST L;
    int k;
    CreateEmptyList(L);
    CreateList(L);

    cin >> k;
    cout << get_nth_node_from_head(L.pHead, k);

    return 0;
}
