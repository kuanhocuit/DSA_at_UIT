
#include <iostream>
#define MAXN 30000

void NhapMang(int A[], int &N)
{
     std::cin >> N;
     for (int i = 0; i < N; i++)
          std::cin >> A[i];
}

void insertionSort_sort_decending(int a[], int n)
{
     for (int i = 1; i < n; i++)
     {
          int x = a[i];
          int vt = i - 1;
          while (vt >= 0 and a[vt] > x)
          {
               a[vt + 1] = a[vt];
               vt--;
          }
          a[vt+1] = x;
     }
}

void XuatMang(int A[], const int &N)
{
     std::cout << N << std::endl;
     for (int i = 0; i < N; i++)
          std::cout << A[i] << " ";
}

int main()
{
     int a[MAXN], n;

     NhapMang(a, n);

     insertionSort_sort_decending(a, n);

     XuatMang(a, n);

     return 0;
}
