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
 

int maxValue(struct Node* node)
{   
    /* loop down to find the rightmost leaf */
    struct Node* current = node;
    while (current->right != NULL) 
        current = current->right;
      
    return (current->key);
}
 
 
// Driver code
int main()
{
    //int arr[] = { 3, 2, 5, 1, 4};
    //int n = sizeof(arr) / sizeof(arr[0]);
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Node* root = createTree(arr, n);
    //levelOrder(root);
    printf("Max value in BST is %d\n", maxValue(root));
    return 0;
}