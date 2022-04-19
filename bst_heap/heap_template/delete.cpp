
#include<bits/stdc++.h>
using namespace std;

void heapi(int arr[], int n, int i)
{
    int parent = i;
    if(i<n)
    {
        int l=2*i+1;
        int r=2*i+2;
        if(l<n||r<n){
            if(arr[parent]<arr[l]||arr[parent]<arr[r]){
                if(arr[l]<arr[r]){
                    swap(arr[r],arr[parent]);
                    heapi(arr,n,r);
                }
                else{
                    swap(arr[l],arr[parent]);
                    heapi(arr,n,r);
                }
            }
        }
    }
}

void insert(int arr[],int& n,int val)
{
    swap(arr[0],arr[n-1]);
    n=n-1;
    heapi(arr,n,0);
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