#include<bits/stdc++.h>
using namespace std;

void printfreq(int freq[]){
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            printf("%c = %d\n",i +'a',freq[i]);
        }
    }
}
void freq(char arr[]){
    int i=0;
    int freq[26]={0};
    while(arr[i]!='\0')
    {
        freq[arr[i]-'a']++;
        i++;
       
    }
   printfreq(freq);
}
int main(){
    char arr[100];
    cin>>arr;
    freq(arr);
}
