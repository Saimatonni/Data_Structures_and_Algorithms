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
 
// Driver code
int main()
{
    int arr[] = { 4, 1, 6, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, n);
    levelOrder(root);n this problem, you have to find the square root of an input number. 
    return 0;
}
