//30
//30
//30
//30
//30
//30
//30
//30
//30
//30

#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    int freq;
    char data;
    node * left;
    node * right;
} node;

struct deref:public binary_function<node*, node*, bool> {
      bool operator()(const node * a, const node * b)const {
        return a->freq > b->freq;
    }
};

typedef priority_queue<node *, vector<node*>, deref> spq;

node * huffman(string s) {

    spq pq;
    vector<int>count(256,0);

    for(int i = 0; i < s.length(); i++ ) {
        count[s[i]]++;
    }

    for(int i=0; i < 256; i++) {

        node * n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];

        if( count[i] != 0 )
            pq.push(n_node);

    }

    while( pq.size() != 1 ) {

        node * left = pq.top();
        pq.pop();
        node * right = pq.top();
        pq.pop();
        node * comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);

    }

    return pq.top();

}

void print_codes_hidden(node * root, string code, map<char, string>&mp) {

      if(root == NULL)
        return;

      if(root->data != '\0') {
        mp[root->data] = code;
    }

    print_codes_hidden(root->left, code+'0', mp);
    print_codes_hidden(root->right, code+'1', mp);

}
map<char, string> codes; 
map<char, int> freq; 
struct MinHeapNode 
{ 
    char data;          
    int freq;           
    MinHeapNode *left, *right; 
  
    MinHeapNode(char data, int freq) 
    { 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 
struct compare 
{ 
    bool operator()(MinHeapNode* l, MinHeapNode* r) 
    { 
        return (l->freq > r->freq); 
    } 
}; 
void printCodes(struct MinHeapNode* root, string str) 
{ 
    if (!root) 
        return; 
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 
void storeCodes(struct MinHeapNode* root, string str) 
{ 
    if (root==NULL) 
        return; 
    if (root->data != '$') 
        codes[root->data]=str; 
    storeCodes(root->left, str + "0"); 
    storeCodes(root->right, str + "1"); 
} 
  
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
void HuffmanCodes(int size) 
{ 
    struct MinHeapNode *left, *right, *top; 
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++) 
        minHeap.push(new MinHeapNode(v->first, v->second)); 
    while (minHeap.size() != 1) 
    { 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
        top = new MinHeapNode('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        minHeap.push(top); 
    } 
    storeCodes(minHeap.top(), ""); 
} 
void calcFreq(string str, int n) 
{ 
    for (int i=0; i<str.size(); i++) 
        freq[str[i]]++; 
} 
string decode_file(struct MinHeapNode* root, string s) 
{ 
    string ans = ""; 
    struct MinHeapNode* curr = root; 
    for (int i=0;i<s.size();i++) 
    { 
        if (s[i] == '0') 
           curr = curr->left; 
        else
           curr = curr->right; 
  
        if (curr->left==NULL and curr->right==NULL) 
        { 
            ans += curr->data; 
            curr = root; 
        } 
    } 
    return ans+'\0'; 
} 

int main()
{

    string huffmancode = "";
    string str = "";
    map<char, string>mp;
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        char c;
        cin>>c>>x;
        while(x--)
        {
            str+=c;
        }
    }

    int k = str.length();

    node * tree = huffman(str);
    print_codes_hidden(tree, huffmancode, mp);
    sort(str.begin(), str.end());

    for( int i = 0; i < k; i++ ) {
        if(str[i]!=str[i+1])
        {
            cout<<str[i]<<" "<<mp[str[i]]<<endl;
        }
    }



    return 0;
}

