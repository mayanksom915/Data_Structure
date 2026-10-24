// 6.) Write a C program to implement insert, delete and traverse operation in a circular queue using array.

#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 3

typedef struct {
    int item[QUEUESIZE];
    int front, rear;
} queue;

void insert(int x, queue *q);
int deletel(queue *q);
void display(queue *q);

int main() {
    int x;
    queue q;
    int choice;
    char ch;
    q.front = -1;
    q.rear = -1;

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n 1.INSERT (Enqueue)");
        printf("\n 2.DELETE (Dequeue)");
        printf("\n 3.TRAVERSE (Display)");
        printf("\n Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n Invalid input!");
            break;
        }

        switch(choice) {
            case 1:
                printf("\n Enter the queue element: ");
                scanf("%d", &x);
                insert(x, &q);
                break;
            case 2:
                x = deletel(&q);
                if (x != -1) {
                    printf("\n The deleted item: %d", x);
                }
                break;
            case 3:
                display(&q);
                break;
            default:
                printf("\n You have entered a wrong choice");
        }

        while ((ch = getchar()) != '\n' && ch != EOF); 

        printf("\n\n Do you wish to continue (Y/N): ");
        scanf("%c", &ch);
    } while(ch == 'Y' || ch == 'y');

    return 0;
}
void insert(int x, queue *q) {
    if ((q->front == 0 && q->rear == QUEUESIZE - 1) || (q->front == q->rear + 1)) {
        printf("\n Circular Queue Overflow");
    } else {
        if (q->front == -1) {
            q->front = 0; 
        }
        q->rear = (q->rear + 1) % QUEUESIZE; 
        q->item[q->rear] = x;
        printf("\n %d inserted successfully", x);
    }
}
int deletel(queue *q) {
    int x;
    if (q->front == -1) {
        printf("\n Circular Queue Underflow");
        return -1;
    } else {
        x = q->item[q->front];
        
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % QUEUESIZE; 
        }
        return x;
    }
}
void display(queue *q) {
    int i;
    if (q->front == -1) {
        printf("\n Circular Queue is empty");
    } else {
        printf("\n Traversing the elements: ");
        i = q->front;
        while (1) {
            printf("%d ", q->item[i]);
            if (i == q->rear) {
                break;
            }
            i = (i + 1) % QUEUESIZE;
        }
        printf("\n");
    }
}
