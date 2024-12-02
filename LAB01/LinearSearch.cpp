/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 100000

void NhapMang(int A[], int &N)
{
     std::cin >> N;
     for (int i = 0; i < N; i++)
          std::cin >> A[i];
}

int Sentinel_LinearSearch(int A[], int N, int X)
{
     int last = A[N - 1]; // Lưu lại giá trị cuối danh sách

     A[N - 1] = X; // Đặt giá trị X vào cuối danh sách

     int i = 0;
     while (A[i] != X)
     {
          i++;
     }

     // ###INSERT CODE HERE -
     
     
     if (i < N - 1 or last ==X )
          return 1;

     return -1;
}

int main()
{
     int a[MAXN], n, x;

     std::cin >> x;

     NhapMang(a, n);

     int i = Sentinel_LinearSearch(a, n, x);

     if (i == -1)
          std::cout << "false";
     else
          std::cout << "true";

     return 0;
}
