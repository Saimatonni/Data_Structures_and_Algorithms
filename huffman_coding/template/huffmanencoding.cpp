#include<bits/stdc++.h>
using namespace std;
#define max 100
struct minheapNode{
    char val;
    unsigned freq;
    minheapNode *left, *right;
};

struct minheap{
    unsigned size;
    unsigned capacity;
    struct minheapNode** arr;
};

struct minheapNode* newnode(char val, unsigned freq)
{
   struct minheapNode* temp = (struct minheapNode*)malloc(sizeof(struct minheapNode));
   temp->left = temp->right = NULL;
   temp->val = val;
   temp->freq = freq;
   return temp;
}

struct minheap* createheap(unsigned capacity){
    struct minheap* heap = (struct minheap*)malloc(sizeof(struct minheap));
    heap->size=0;
    heap->capacity = capacity;
    heap->arr=(struct minheapNode**)malloc(heap->capacity* sizeof(struct minheapNode*));
    return heap;
}

void swapH(struct minheapNode**x,struct minheapNode**y)
{
    struct minheapNode* tem = *x;
    *x=*y;
    *y=tem;
}
void heapify(struct minheap*heap,int i){
    int lowest = i;
    int l=2*i+1;
    int r=2*i+2;
    if (l < heap->size && heap->arr[l]->freq < heap->arr[lowest]->freq){
        lowest = l;
    }
    if (r < heap->size && heap->arr[r]->freq < heap->arr[lowest]->freq){
        lowest = r;
    }
        
    if (lowest != i) {
        swapH(&heap->arr[lowest],&heap->arr[i]);
        heapify(heap,lowest);
    }
}
int sizeone(struct minheap*heap){
    return (heap->size==1);
}
struct minheapNode*extract(struct minheap* heap){
    struct minheapNode*temp = heap->arr[0];
    heap->arr[0]=heap->arr[heap->size-1];
    --heap->size;
    heapify(heap,0);
    return temp;
}

void insert(struct minheap*heap,struct minheapNode*node){
    ++heap->size;
    int i=heap->size-1;
    while(i&&node->freq < heap->arr[(i-1)/2]->freq){
       heap->arr[i]=heap->arr[(i-1)/2];
       i=(i-1)/2;
    }
    heap->arr[i]=node;

}

void builHeap(struct minheap* heap)
  
{
  
    int n = heap->size - 1;
    int i;
  
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(heap, i);
}
  
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
    }

   // sort(arr,arr+n);
    printf("\n");
}
  
int isLeaf(struct minheapNode* root)
  
{
  
    return !(root->left) && !(root->right);
}

struct minheap*createbuildheap(char data[],int freq[],int size){
    struct minheap* heap = createheap(size);
    for(int i=0;i<size;++i){
        heap->arr[i]=newnode(data[i],freq[i]);
    }
    heap->size=size;
    builHeap(heap);
    return heap;
}
struct minheapNode* huffmantree(char data[],int freq[],int size){
    struct minheapNode *left, *right, *top;
    struct minheap* heap=createbuildheap(data,freq,size);
    while(!sizeone(heap)){
       left=extract(heap);
       right=extract(heap);
       top=newnode('$',left->freq+right->freq);
       top->left =left;
       top->right =right;
       insert(heap,top);
    }
    return extract(heap);
}

void printcode(struct minheapNode*root,int arr[],int top){
    if(root->left){
        arr[top]=0;
        printcode(root->left,arr,top+1);
    }
    if(root->right){
        arr[top]=1;
        printcode(root->right,arr,top+1);
    }
    if(isLeaf(root)){
        //sort(root->val,);
        printf("%c: ",root->val);
        printArr(arr,top);
    }
}
void huffmancode(char data[],int freq[],int size){
    struct minheapNode*root=huffmantree(data,freq,size);
    int array[max],i=0;
    printcode(root,array,i);
}

int main(){
    int n;
    cin>>n;
    char arr[n];
    int freq[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]>>freq[i];
        //scanf("%d",freq[i]);
    }
    huffmancode(arr,freq,n);
    return 0;
}