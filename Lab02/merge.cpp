#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N)
{
     std::cin >> N;
     for (int i = 0; i < N; i++)
          std::cin >> A[i];
}
void XuatMang(int A[], const int &N)
{
     std::cout << N << std::endl;
     for (int i = 0; i < N; i++)
          std::cout << A[i] << " ";
}

void Copy(int a[], int b[], int l, int r)
{
     int nb = r - l + 1;
     for (int i = 0; i < nb; i++)
     {
          b[i] = a[i + l];
     }
}

void Xu_Li(int a[], int l, int r)
{
     int *b;
     int nb = r - l + 1;
     b = new int[nb];
     Copy(a, b, l, r);
     int mid = (r - l) / 2;
     int i0 = 0;       // chỉ số đầu của nửa mảng đầu
     int i1 = mid + 1; // chỉ số đầu của nửa mảng sau
     for (int j = l; j <= r; j++)
     {
          if (i0 <= mid and (i1 >= nb or b[i0] > b[i1]))
          {
               a[j] = b[i0++];
          }
          else
               a[j] = b[i1++];
     }
     delete[] b;
}

void Xu_Li_Merge(int a[], int l, int r)
{
     if (l < r)
     {
          int mid = (l + r) / 2;
          Xu_Li_Merge(a, l, mid);
          Xu_Li_Merge(a, mid + 1, r);
          Xu_Li(a, l, r);
     }
}

void merge_sort_ascending(int a[], int n)
{
     Xu_Li_Merge(a, 0, n - 1);
}

int main()
{
     int a[MAXN], n;

     NhapMang(a, n);

     merge_sort_ascending(a, n);

     XuatMang(a, n);

     return 0;
}
