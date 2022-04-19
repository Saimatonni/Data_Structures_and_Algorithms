#include<bits/stdc++.h>
using namespace std;
#define empty ""

struct node{
    char val;
    int freq;
    node *left,*right;
};

node * getnode(char val,int freq,node*left,node*right){
    node* n = new node();
    n->val=val;
    n->freq=freq;
    n->left=left;
    n->right = right;

    return n;
}

struct com{
    bool operator()(const node*l,const node*r) const
    {
        return l->left > r->right;
    }
};

bool isLeaf(node* root) {
    return root->left == nullptr && root->right == nullptr;
}

void encode(node* root,string str, unordered_map<char, string> &huffmancode){
    if(root == nullptr){
        return;
    }
    if(isLeaf(root)){
        huffmancode[root->val] = (str!=empty) ? str : "1";
    }
    encode(root->left,str+"0",huffmancode);
    encode(root->right,str+"1",huffmancode);
}

void decode(node* root,int &i,string str){
    if(root==nullptr){
        return;
    }
    if(isLeaf(root)){
        cout<<root->val;
        return;
    }
    if(str[i]=='0'){
       decode(root->left,i,str);
    }
    else{
        decode(root->right,i,str);
    }
}

void huffmantree(string str){
    if(str==empty){
        return;
    }
    unordered_map<char, int> freq;
    for(char c: str){
        freq[c]++;
    }
    priority_queue<node*, vector<node*>, com> pq;

    for(auto pair: freq){
      pq.push(getnode(pair.first,pair.second,nullptr,nullptr));
    }
    while(pq.size()!=1){
        node* left=pq.top(); pq.pop();
        node* right=pq.top(); pq.pop();

        int sum=left->freq+right->freq;
        pq.push(getnode('\0',sum,left,right));
    }
    node* root=pq.top();
    unordered_map<char, string>huffmancode;
    encode(root,empty,huffmancode);
    cout<<"huffman code"<<endl;
    for(auto pair: huffmancode){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    string s;
    for(char c: str){
        s+=huffmancode[c];
    }
    cout<<"encode string : \n"<<s<<endl;
    cout<<"decode : "<<endl;
    if(isLeaf(root)){
       while (root->freq--) {
            cout << root->val;
        }
    }
    else{
        int index = -1;
        while (index < (int)str.size() - 1) {
            decode(root, index, str);
        }
    }

}

int main()
{
    string text = "Huffman coding is a data compression algorithm.";
    huffmantree(text);
 
    return 0;
}