
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int KT(int a[], int x, int g)
{
     while(a[g]==x)
     {
          g++;
     }
     return g-1;
}

int binary_search_last_occurrence(int a[], int n, int x)
{
     int d=0, c=n-1;
     int g= (d+c)/2;
     while (d<=c)
     {
          if (a[g]==x)
          {
               return KT(a,x,g);
          }
          if (x < a[g])
          {
               c = g - 1;
               g = (d + c) / 2;
          }
          if (x > a[g])
          {
               d = g + 1;
               g = (d + c) / 2;
          }
     }
     return -1;
     
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}


