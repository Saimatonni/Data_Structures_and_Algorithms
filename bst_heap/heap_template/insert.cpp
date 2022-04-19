#include<bits/stdc++.h>
using namespace std;

void heapi(int arr[], int n, int i)
{
    int parent = (i-1)/2;
    if(arr[parent]>0){
        if(arr[i]>arr[parent]){
            swap(arr[i],arr[parent]);
            heapi(arr,n,parent);
        }
    }
}
void insert(int arr[],int& n,int val)
{
    n=n+1;
    arr[n-1]=val;
    heapi(arr,n,n-1);
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
    int val;
    cin>>val;
    insert(arr,n,val);
    print(arr,n);
}