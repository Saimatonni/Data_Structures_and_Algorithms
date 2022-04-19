//30
//30
//30
#include<bits/stdc++.h>
using namespace std;
#define SIZE 50            

char stck[SIZE];
int top=-1;       /* Global declarations */
 
 void push(char elem)
{                       /* Function for PUSH operation */
    stck[++top]=elem;
}
 
char pop()
{                      /* Function for POP operation */
    return(stck[top--]);
}
 
int pr(char symbol)
{                 /* Function for precedence */
    
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int prec(char c) {
    if(c == '^')
        return 4;
    else if(c == '/' || c=='*')
        return 3;
    else if(c == '-')
        return 2;
    else if(c == '+')
        return 1;
    else
        return -1;
}


void infixToPostfix(string s) {

    stack<char> st;
    string result;

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];

        if(c >= '0' && c <= '9'){
            result += c;
            if(i!=s.length()-1 && (s[i+1] >= '0' && s[i+1] <= '9'))
            continue;
            result += ",";
        }
        else if(c == '(')
            st.push('(');


        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                result += ',';
                st.pop();
            }
            st.pop();
        }


        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                result += ',';
                st.pop();
            }
            st.push(c);
        }
    }


    while(!st.empty()) {
        result += st.top();
        result += ',';
        st.pop();
    }
    result.pop_back();
    cout << result << endl;
}

int main() {
    string S;
    cin >> S;
    infixToPostfix(S);
    return 0;
}

