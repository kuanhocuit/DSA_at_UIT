
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N)
{
     for (int i = 0; i < N; i++)
          std::cin >> A[i];
}

int binary_searc(int a[],int l,int h,int x){
    if(l<=h){
        int m=(l+h)/2;
        if(a[m]==x)
            return 1;
        if(a[m]<x)
            return binary_searc(a,m+1,h,x);
        else
            return binary_searc(a,l,m-1,x);
    }
    return -1;
}
int binary_search(int a[],int n,int x){
    int low=0;
    int high=n-1;
    if(low<=high){
    int mid=(low+high)/2;
    if(a[mid]==x) return 1;
    if(a[mid]<x)
        return binary_searc(a,mid+1,high,x);
    else
            return binary_searc(a,low,mid-1,x);
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
