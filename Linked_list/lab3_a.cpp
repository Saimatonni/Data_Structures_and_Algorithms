#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int roll, marks;
    double cg;
    string name;
    node *next;

    node(string name, int roll, double cg, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->cg = cg;
        this->marks = marks;
        next = NULL;
    }
    // ~node();
};

node *merge(node *x, node *y)
{
    node *result = NULL;
    if (x == NULL)
    {
        return y;
    }
    if (y == NULL)
    {
        return x;
    }
    if (x->cg == y->cg)
    {
        if (x->marks == y->marks)
        {
            if (x->roll < y->roll)
            {
                result = x;
                result->next = merge(x->next, y);
            }
            else
            {
                result = y;
                result->next = merge(x, y->next);
            }
        }
        else if (x->marks > y->marks)
        {
            result = x;
            result->next = merge(x->next, y);
        }
        else
        {
            result = y;
            result->next = merge(x, y->next);
        }
    }
    else if (x->cg > y->cg)
    {
        result = x;
        result->next = merge(x->next, y);
    }
    else
    {
        result = y;
        result->next = merge(x, y->next);
    }
    return result;
}

void split(node* source,node** front,node** back)
{
    node* slow;
    node* first;
    slow = source;
    first = source->next;
    while(first!=NULL)
    {
        first = first->next;
        if(first!=NULL)
        {
            
            slow = slow->next;
            first = first->next;
        }
    }

     *front = source;
     *back = slow->next;
     slow->next = NULL;
}

void mergesort(node** headref)
{
    node* head = *headref;
    node* a;
    node* b;
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    split(head,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *headref = merge(a,b);
}

class linked_list{
    public:
         node* head;
         node* tail;
         linked_list()
         {
             head=NULL;
         }
         void insert(string sname,int sroll,double cgpa,int smarks)
         {
             node* node1 = new node(sname,sroll,cgpa,smarks);
             if(this->head==NULL)
             {
                 this->head=node1;
             }
             else
             {
                 this->tail->next=node1;
             }
             this->tail = node1;
         }
         void print()
         {
             node* temp = head;
             int count =1;
             cout<<setprecision(2)<<fixed;
             while(temp!=NULL)
             {
                cout<<count++<<" "<<temp->name<<" "<<temp->roll<<" "<<temp->cg<<" "<<temp->marks<<endl;
                temp=temp->next;
             }
         }
};

int main()
{
    int n;
    cin>>n;
    linked_list link;
    for(int i=0;i<n;i++)
    {
        int roll,marks;
        double cg;
        string name;
        cin>>name>>roll>>cg>>marks;
        link.insert(name,roll,cg,marks);
    }
    mergesort(&link.head);
    link.print();
}