#include <iostream>
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

// Hàm tạo node mới
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == nullptr) {
        cout << "Không đủ bộ nhớ";
        return nullptr;
    }
    p->info = x;
    p->pNext = nullptr;
    return p;
}

// Hàm khởi tạo danh sách rỗng
void CreateEmptyList(LIST &L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}

// Hàm thêm node vào cuối danh sách
void AddTail(LIST &L, int x) {
    NODE* p = CreateNode(x);
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

// Hàm tạo danh sách
void CreateList(LIST &L) {
    int x;
    cin >> x;
    while (x != -1) {
        AddTail(L, x);
        cin >> x;
    }
}

// Hàm nối L1 - node *pivot - ds L2 thành L
void Join(LIST &L, LIST &L1, NODE *pivot, LIST &L2) {
    CreateEmptyList(L);
    NODE *p = L1.pHead;
    // Nối L1 vào L
    while (p != nullptr) {
        AddTail(L, p->info);
        p = p->pNext;
    }
    // Thêm pivot vào L
    AddTail(L, pivot->info);
    // Nối L2 vào L
    p = L2.pHead;
    while (p != nullptr) {
        AddTail(L, p->info);
        p = p->pNext;
    }
    // Làm rỗng L1 và L2
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}

// Hàm in danh sách
void PrintList(const LIST &L) {
    NODE *p = L.pHead;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

int main() {
    LIST L, L1, L2;

    int x;
    NODE *pivot;

    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList(L1);
    cin >> x;
    pivot = CreateNode(x);
    CreateList(L2);

    Join(L, L1, pivot, L2);
    PrintList(L);

    return 0;
}
