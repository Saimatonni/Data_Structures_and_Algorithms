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
void printList(struct Node* node)
{
    struct Node* last;
    //printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->key);
        last = node;
        node = node->left;
    }
    while (last != NULL) {
        printf(" %d ", last->key);
        last = last->right;
    }
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
struct Node* insert(struct Node* node, int num)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(num);
 
    /* Otherwise, recur down the tree */
    if (num < node->key)
        node->left = insert(node->left, num);
    else if (num > node->key)
        node->right = insert(node->right, num);
 
    /* return the (unchanged) node pointer */
    return node;
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
    insert(root,S);
    printList(root);
    return 0;
}