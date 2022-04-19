//30
//30
//30
//30
#include <bits/stdc++.h>
using namespace std;
char stck[100];
int top = -1;

void push(char x)
{
    stck[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stck[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
} 
// Function to find precedence of
// operators.
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    if(op=='^')
    return 3;
    return 0;
}
 
// Function to perform arithmetic operations.
double applyOp(double a, double b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
    }
    return -1;
}
 

double evaluate(string tokens){
    int i;
     
    // stack to store integer values.
    stack <double> values;
     
    // stack to store operators.
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
         
        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ')
            continue;
         
        
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
         
        
        else if(isdigit(tokens[i])){
            double val = 0;
             
           
            while(i < tokens.length() && isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
             
            values.push(val);
             
            
              i--;
        }
         
        
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                double val2 = values.top();
                values.pop();
                 
                double val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            // pop opening brace.
            if(!ops.empty())
               ops.pop();
        }
         
        // Current token is an operator.
        else
        {
            
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                double val2 = values.top();
                values.pop();
                 
                double val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }
     
    
    while(!ops.empty()){
        double val2 = values.top();
        values.pop();
                 
        double val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
    // Top of 'values' contains result, return it.
    return values.top();
}
 
int main() {
    string str;
    cin>>str;
    //cout<<evaluate(s)<<endl;
    printf("%0.4lf\n",evaluate(str));
    
    return 0;
}