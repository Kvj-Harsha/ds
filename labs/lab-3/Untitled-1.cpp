int evaluatePostfix(char postfix[], int n) {
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        } else {
            int val1 = stack[top--];
            int val2 = stack[top--];

            switch (c) {
                case '+': stack[++top] = val2 + val1; break;
                case '-': stack[++top] = val2 - val1; break;
                case '*': stack[++top] = val2 * val1; break;
                case '/': stack[++top] = val2 / val1; break;
                case '%': stack[++top] = val2 % val1; break;
                case '^': stack[++top] = pow(val2, val1); break;
            }
        }
    }
    return stack[top];
}