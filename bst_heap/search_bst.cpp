#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left;
    Node* right;
};
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
 
struct Node* insertValue(struct Node* root, int value,
                         queue<Node *>& q)
{
    Node* node = newNode(value);
    if (root == NULL)
        root = node;
 
   
    else if (q.front()->left == NULL)
        q.front()->left = node;
 
    else {
        q.front()->right = node;
        q.pop();
    }
 
    
    q.push(node);
    return root;
}
 

Node* createTree(int arr[], int n)
{
    Node* root = NULL;
    queue<Node*> q;
    for (int i = 0; i < n; i++)
      root = insertValue(root, arr[i], q);
    return root;
}
 
// This is used to verify the logic.
void levelOrder(struct Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> n;
    n.push(root);
    while (!n.empty()) {
        cout << n.front()->key << " ";
        if (n.front()->left != NULL)
            n.push(n.front()->left);
        if (n.front()->right != NULL)
            n.push(n.front()->right);
        n.pop();
    }
}
struct Node* search(struct Node* root, int num)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == num)
    {
       return root;
    }
    // Key is greater than root's key
    else if (root->key < num)
    {
       return search(root->right, num);
    }
    // Key is smaller than root's key
    else if(root->key > num)
    {
     return search(root->left, num);
    }
    else
    {
        cout<<"not found"<<endl;
    }
}
 
// Driver code
int main()
{
    int n,i,S,p;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Node* root = createTree(arr, n);
    //levelOrder(root);
    cin>>S;
    //p=search(root,S);
    if(search(root,S))
    {
      //cout<<root<<endl;
      printf("found\n");
    }
    else
    {
      printf("don't\n");
    }
    return 0;
}