#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push function
void push(char c)
{
    if(top == MAX - 1)
        return;

    stack[++top] = c;
}

// pop function
char pop()
{
    if(top == -1)
        return '\0';

    return stack[top--];
}

// check matching pair
int isMatchingPair(char open, char close)
{
    if(open == '(' && close == ')')
        return 1;

    if(open == '{' && close == '}')
        return 1;

    if(open == '[' && close == ']')
        return 1;

    return 0;
}

// check balanced parentheses
int checkBalanced(char exp[])
{
    int i;
    char popped;

    for(i = 0; i < strlen(exp); i++)
    {
        char ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(top == -1)
                return 0;

            popped = pop();

            if(!isMatchingPair(popped, ch))
                return 0;
        }
    }

    if(top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char expression[100];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if(checkBalanced(expression))
        printf("Parentheses are Balanced\n");
    else
        printf("Parentheses are NOT Balanced\n");

    return 0;
}
