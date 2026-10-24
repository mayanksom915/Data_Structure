// 4.) Write a C program to implement Tower of Hanoi problem using recursion.

#include <stdio.h>
#include <stdlib.h>

void tower(int n, char from, char aux, char to);

int main() {
    int n;
    char ch;

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n how many pegs (disks): ");
        if (scanf("%d", &n) != 1) {
            printf("\n Invalid input!");
            break;
        }

        if (n <= 0) {
            printf("\n Number of disks must be greater than 0.");
        } else {
            printf("\n The moves involved in Tower of Hanoi are:\n");
            tower(n, 'A', 'B', 'C');
        }

        while ((ch = getchar()) != '\n' && ch != EOF); 

        printf("\n\n Do you wish to continue (Y/N): ");
        scanf("%c", &ch);
    } while(ch == 'Y' || ch == 'y');

    return 0;
}
void tower(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("\n Move disk 1 from %c to %c", from, to);
        return;
    }
    tower(n - 1, from, to, aux);
    printf("\n Move disk %d from %c to %c", n, from, to);
    tower(n - 1, aux, from, to);
}
