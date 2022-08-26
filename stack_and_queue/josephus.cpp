#include <bits/stdc++.h>
using namespace std;
 
int Josephus(int, int);
 
int main()
{
    int n, k;
    cin >> n >> k;
    cout << Josephus(n, k)<<endl;
    return 0;
}
 
int Josephus(int n, int k)
{
    k--;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 1; 
    }
    int cnt = 0, cut = 0,
        num = 1; 
    while (
        cnt
        < (n - 1)) 
    {
        while (num <= k) 
        {
            cut++;
            cut = cut % n; 
            if (arr[cut] == 1) {
                num++; 
            }
        }
        num = 1; 
        arr[cut]
            = 0; 
        cnt++; 
        cut++;
        cut = cut
              % n; 
        while (arr[cut]
               == 0) 
                     
        {
            cut++;
            cut = cut % n; 
        }
    }
    return cut + 1; 
}
