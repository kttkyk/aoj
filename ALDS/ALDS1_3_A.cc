#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;


int stack[100];
int p = 0;

void push(int v)
{
    stack[p++] = v;
}


int pop(void)
{
    return stack[--p];
}


int main(void)
{
    char str[128];
    while (scanf("%s", str) != EOF) {
        int tmp, a, b;
        switch (str[0]) {
            case '+':
                tmp = pop() + pop();
                push(tmp);
                break;
            case '*':
                tmp = pop() * pop();
                push(tmp);
                break;
            case '-':
                b = pop();
                a = pop();
                tmp = a - b;
                push(tmp);
                break;
            default:
                push(atoi(str));
                break;
        }
    }
    cout << pop() << endl;

    return 0;
}
