/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
#define MAXN 1000000000
void NhapMang(int a[], int &n)
{
     for (int i = 0; i < n; i++)
     {
          cin >> a[i];
     }
}

int binary_search(int a[], int n, int x)
{
     int d = 0, c = n - 1;
     int g = (d + c) / 2;
     while (d <= c)
     {
          if (x == a[g])
               return 1;
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

int main()
{
     int x, n, a[MAXN];

     cin >> x;
     cin >> n;
     NhapMang(a, n);

     int i = binary_search(a, n, x);

     if (i == -1)
          std::cout << "false";
     else
          std::cout << "true";

     return 0;
}
