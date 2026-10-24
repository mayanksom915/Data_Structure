// 1.) Write a C program to implement push, pop, traverse operation in a stack using array.

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 2

typedef struct {
    int item[STACKSIZE];
    int top;
} stack;

void push(int x, stack *s);
int pop(stack *s);
void traverse(stack *s);

int main() { 
    int x;
    stack s;
    int choice;
    char ch;
    s.top = -1;

    do {
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.TRAVERSE");
        printf("\n Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n Invalid input!");
            break;
        }

        switch(choice) {
            case 1:
                printf("\n Enter the stack element: ");
                scanf("%d", &x);
                push(x, &s);
                break;
            case 2:
                x = pop(&s);
                if (x != -1) {
                    printf("\n The deleted item: %d", x);
                }
                break;
            case 3:
                traverse(&s);
                break;
            default:
                printf("\n You have entered a wrong choice");
        }

        
        while ((ch = getchar()) != '\n' && ch != EOF); 

        printf("\n Do you wish to continue (Y/N): ");
        scanf("%c", &ch);
    } while(ch == 'Y' || ch == 'y');

    return 0; 
}

void push(int x, stack *s) {
    if(s->top == STACKSIZE - 1) {
        printf("\n Stack Overflow");
    } else {
        s->item[++(s->top)] = x;
        printf("\n %d pushed successfully", x);
    }
}

int pop(stack *s) {
    if(s->top == -1) {
        printf("\n Stack Underflow");
        return -1; 
    } else {
        return (s->item[(s->top)--]);
    }
}

void traverse(stack *s) {
    int i;
    if(s->top == -1) {
        printf("\n Stack is empty");
    } else {
        printf("\n Traversing the elements:");
        for(i = s->top; i >= 0; i--) {
            printf("\n %d", s->item[i]);
        }
    }
}
