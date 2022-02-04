#include <bits/stdc++.h> 
using namespace std; 
class Stack{  
    public: 
        int top;  
        unsigned capacity;  
        char* array;  
};  
  
Stack* createStack(unsigned capacity){  
    Stack* stack = new Stack(); 
    stack->capacity = capacity;  
    stack->top = -1;  
    stack->array = new char[(stack->capacity * sizeof(char))];  
    return stack;  
}  
  
int isFull(Stack* stack){ 
    return stack->top == stack->capacity - 1; 
}  
  
int isEmpty(Stack* stack){ 
    return stack->top == -1;
}  
  
void push(Stack* stack, char item){  
    if(isFull(stack))  
        return;  
    stack->array[++stack->top] = item;  
}  
  
char pop(Stack* stack){  
    if(isEmpty(stack))  
        return -1;  
    return stack->array[stack->top--];  
}  
int maxDepth(string s){ 
    int n = s.length();  
    Stack* stack = createStack(n);
    int current_max = 0; 
    int max = 0;   
  
    for(int i = 0; i<n; i++){
        
        if(s[i] == '('|| s[i]=='{' || s[i]=='['){ 
            push(stack, s[i]);
            current_max++; 
  
            if(current_max > max){ 
                max = current_max;
            }    
        } 
        
        else if(s[i] == ')'||s[i]=='}'||s[i]==']'){ 
            char c = pop(stack);
            if((current_max > 0) && (c == '('||c=='{'||c=='[')){ 
                current_max--; 
            }    
            else{
                return -1;
            }    
        } 
    } 
  
    if(!isEmpty(stack)){ 
        return -1; 
    }    
  
    return max; 
} 
  
int main(){
    
    string s;
    cin>>s; 
    cout<<maxDepth(s)<<endl; 
    
    return 0; 
}