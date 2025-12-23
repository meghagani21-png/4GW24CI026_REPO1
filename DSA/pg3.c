#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int stack[MAX];
int top = -1;

/* Function declarations */
void push(int);
int pop();
void display();
void checkpalindrome();
void isoverflow();
void isunderflow();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Overflow / Underflow\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;

            case 3:
                checkpalindrome();
                break;

            case 4:
                isoverflow();
                isunderflow();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

/* Push function */
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed into stack\n", value);
}

/* Pop function */
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

/* Display stack */
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

/* Palindrome check using stack */
void checkpalindrome() {
    char str[50], rev[50], tempstack[50];
    int len, temptop = -1;

    printf("Enter string: ");
    scanf("%s", str);

    len = strlen(str);

    for (int i = 0; i < len; i++)
        tempstack[++temptop] = str[i];

    for (int i = 0; i < len; i++)
        rev[i] = tempstack[temptop--];

    rev[len] = '\0';

    if (strcmp(str, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");
}

/* Overflow check */
void isoverflow() {
    if (top == MAX - 1)
        printf("Overflow occurs\n");
    else
        printf("No overflow\n");
}

/* Underflow check */
void isunderflow() {
    if (top == -1)
        printf("Underflow occurs\n");
    else
        printf("No underflow\n");
}
