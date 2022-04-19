#include<bits/stdc++.h>
using namespace std;

void heapi(int arr[], int n, int i)
{
    int highest = i;
    int l = 2*i+1;
    int r = 2*i +2;
    if(l<n&&arr[l]>arr[highest]){
        highest = l;
    }
    if(r<n&&arr[r]>arr[highest]){
        highest = r;
    }
    if(highest!=i){
        swap(arr[i],arr[highest]);
        heapi(arr,n,highest);
    }
    
}

void heap(int arr[],int n)
{
    int idx=(n/2)-1;
    for(int i=idx;i>=0;i--){
        heapi(arr,n,i);
    }
}
void print(int arr[], int n)
{
    for(int i=0;i<n;i++){
        cout << arr[i]<< " ";
    }
    cout<<"\n";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    //print(arr,n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heap(arr,n);
    print(arr,n);
}