//CS23B1034
//K V Jaya Harsha
#include<iostream>
using namespace std;
int function(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*' || c == '%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int poster(char expression[],int x){
    char postfix[x];
    char stack[x];
    int top = -1;
    int k = 0;
    for (int q=0; q<x; q++){
        char ch = expression[q];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')) {
            postfix[k++] = ch;
        }
        else{
            while(top!=-1&&function(ch) <= function(stack[top])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }
    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    cout << "-> Postfix => ";
    for(int i=0; i<k; i++) {
        cout << postfix[i];
    }
    cout << endl;
}
int main() {
    int x;
    cin >> x;
    char expression[x];
    for (int i=0; i<x; i++){
        cin >> expression[i];
    }
    cout << endl;
    cout << "-> Infix => ";
    for (int i=0; i<x; i++){
        cout << expression[i];
    }
    cout << endl;

    poster(expression,x);
    
    return 0;
}

//testcase
//15
//a+b%c^w+x*y/z-q