// 3.) Write a C program to find n-th term of a Fibonacci series using recursion

#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main() {
    int n, i;
    char ch;

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n How many terms of fibonacci series: ");
        if (scanf("%d", &n) != 1) {
            printf("\n Invalid input!");
            break;
        }

        if (n <= 0) {
            printf("\n Number of terms must be greater than 0.");
        } else {
            printf("\n Fibonacci Series: ");
            for(i = 1; i <= n; i++) {
                printf("\t%d", fib(i));
            }
        }

        while ((ch = getchar()) != '\n' && ch != EOF); 

        printf("\n\n Do you wish to continue (Y/N): ");
        scanf("%c", &ch);
    } while(ch == 'Y' || ch == 'y');

    return 0;
}
int fib(int n) {
    if (n == 1) {
        return(0);
    } else if (n == 2) {
        return(1);
    } else {
        return(fib(n - 1) + fib(n - 2));
    }
}
