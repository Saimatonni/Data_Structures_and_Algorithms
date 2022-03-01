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

int isBSTUtil(struct Node* node, int min, int max);
 

int isBST(struct Node* node)
{
  return(isBSTUtil(node, INT_MIN, INT_MAX));
}
 
int isBSTUtil(struct Node* node, int min, int max)
{
  /* an empty tree is BST */
  if (node==NULL)
     return 1;
       
  /* false if this node violates the min/max constraint */ 
  if (node->key < min || node->key > max)
     return 0;
 
  return
    isBSTUtil(node->left, min, node->key-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->key+1, max);  // Allow only distinct values
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
    if(isBST(root))
    {
      printf("Is BST\n");
    }
    else
    {
      printf("Not a BST\n");
    }
    return 0;
}