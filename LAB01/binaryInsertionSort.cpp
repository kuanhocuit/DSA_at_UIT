
#include <iostream>
#define MAXN 60000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// Function to sort an array a[] of size 'n'
void binary_insertion_sort(int a[], int n) {
    int i, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

      int t=0;k=j;  
    while(t<=k)
    {
        int g=(t+k)/2;
        if(a[g]==selected){
            k=i;break;
        }
        if(a[g]<selected)
        {
            t=g+1;
        }
        else k=g-1;
        
    }
    //write your code here

    for(int l=n;l>k;l--)a[l]=a[l-1];
        a[j+1] = selected;
    }
}
bool is_decending(int A[], int N) {
    for (int i = 0; i < N-1; i++)
        if(A[i]<A[i+1]) return false;
    return true;
}
void XuatMang(int A[], const int &N) {
    // std::cout << is_decending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << "\n";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    binary_insertion_sort(a, n);

    XuatMang(a, n);

    return 0;
}
