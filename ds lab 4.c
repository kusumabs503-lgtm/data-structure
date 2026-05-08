#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {

    if (top >= MAX - 1) {

        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = c;
}

// Pop
char pop() {

    if (top < 0) {
        return '\0';
    }

    return stack[top--];
}

// Peek
char peek() {

    if (top < 0) {
        return '\0';
    }

    return stack[top];
}

// Precedence
int precedence(char op) {

    switch(op) {

        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return 0;
    }
}

// Check operator
int isOperator(char c) {

    return (c == '+' ||
            c == '-' ||
            c == '*' ||
            c == '/' ||
            c == '^');
}

// Infix to Postfix
void infixToPostfix(char *infix, char *postfix) {

    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {

        // Operand
        if (isalnum(c)) {

            postfix[j++] = c;
        }

        // Left parenthesis
        else if (c == '(') {

            push(c);
        }

        // Right parenthesis
        else if (c == ')') {

            while (top >= 0 && peek() != '(') {

                postfix[j++] = pop();
            }

            pop();
        }

        // Operator
        else if (isOperator(c)) {

            if (c == '^') {

                while (top >= 0 &&
                       precedence(peek()) > precedence(c)) {

                    postfix[j++] = pop();
                }
            }

            else {

                while (top >= 0 &&
                       precedence(peek()) >= precedence(c)) {

                    postfix[j++] = pop();
                }
            }

            push(c);
        }
    }

    // Remaining operators
    while (top >= 0) {

        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Main
int main() {

    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
