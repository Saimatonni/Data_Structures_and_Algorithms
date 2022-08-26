#include <bits/stdc++.h>
using namespace std;
 
class node
{
public:
    string info;
    node *left = NULL, *right = NULL;
    node(string x)
    {
        info = x;
    }
};
 
int toInt(string s)
{
    int num = 0;
    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
   
    else
        for (int i=1; i<s.length(); i++)
        {
            num = num*10 + (int(s[i])-48);
            num = num*-1;
        }
     
    return num;
}
 
int eval(node* root)
{
    // empty tree
    if (!root)
        return 0;
 
    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->info);
 
    // Evaluate left subtree
    int l_val = eval(root->left);
 
    // Evaluate right subtree
    int r_val = eval(root->right);
 
    // Check which operator to apply
    if (root->info=="+")
        return l_val+r_val;
 
    if (root->info=="-")
        return l_val-r_val;
 
    if (root->info=="*")
        return l_val*r_val;
 
    return l_val/r_val;
}
 
int main()
{
    // create a syntax tree
    node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("-4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("20");
    cout << eval(root) << endl;
 
    delete(root);
 
    root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");
 
    cout << eval(root);
    return 0;
}
