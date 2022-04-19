#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
    int h;
};

int maxi(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return 1 + max(height(n->left), height(n->right));
}
struct node *newn(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->h = 0;
    return (n);
}

struct node *rightroatation(struct node *y)
{
    struct node *x = y->left;
    struct node *t = x->right;

    x->right = y;
    y->left = t;

    y->h = height(y);
    x->h = height(x);
    return x;
}
struct node *leftroatation(struct node *x)
{
    struct node *y = x->right;
    struct node *t = y->left;

    y->left = x;
    x->right = t;

    x->h = height(x);
    y->h = height(y);
    return y;
}

int balance(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

struct node *insert(struct node *n, int val)
{
    if (n == NULL)
    {
        return (newn(val));
    }
    if (val < n->val)
    {
        n->left = insert(n->left, val);
    }
    else if (val > n->val)
    {
        n->right = insert(n->right, val);
    }
    else
    {
        return n;
    }
    n->h = height(n);
    int b = balance(n);
    if (b > 1 && val < n->left->val)
    {
        return rightroatation(n);
    }
    if (b < -1 && val > n->right->val)
    {
        return leftroatation(n);
    }
    if (b > 1 && val > n->left->val)
    {
        n->left = leftroatation(n->left);
        return rightroatation(n);
    }
    if (b < -1 && val < n->right->val)
    {
        n->right = rightroatation(n->right);
        return leftroatation(n);
    }
    return n;
}

struct node* minnode(struct node* n){
    struct node* c =n;
    while(c->left!=NULL){
        c=c->left;
    }
    return c;
}

struct node *deleten(struct node *n, int val){
   if(n==NULL){
       return n;
   }
    if (val < n->val)
    {
        n->left = deleten(n->left, val);
    }
    else if (val > n->val)
    {
        n->right = deleten(n->right, val);
    }
    else{
        if((n->left==NULL)||(n->right==NULL)){
            struct node *temp =n->left ? n->left:n->right;
            if(temp==NULL){
                temp=n;
                n=NULL;
            }
            else{
                *n=*temp;
            }
            free(temp);
        }
        else{
            struct node* temp=minnode(n->right);
            n->val=temp->val;
            n->right=deleten(n->right,temp->val);
        }
    }
    if(n==NULL){
        return n;
    }
    n->h = height(n);
    int b = balance(n);
    if (b > 1 && balance(n->left)>=0)
    {
        return rightroatation(n);
    }
    if (b < -1 && balance(n->right)<=0)
    {
        return leftroatation(n);
    }
    if (b > 1 && balance(n->left)<0)
    {
        n->left = leftroatation(n->left);
        return rightroatation(n);
    }
    if (b < -1 && balance(n->right)>0)
    {
        n->right = rightroatation(n->right);
        return leftroatation(n);
    }
    return n;

}


void preorder(struct node *n)
{
    if (n != NULL)
    {
        printf("%d ", n->val);
        preorder(n->left);
        preorder(n->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    preorder(root);
    cout<<"\nafter delete"<<endl;
    root=deleten(root,10);
    preorder(root);
    return 0;
}