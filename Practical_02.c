// 2.) Write a C program to find the factorial of a number using recursion.

#include <stdio.h>
#include <stdlib.h>

long int fact(long int n);

int main() {
    long int n;
    long int result;
    char ch;

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n Enter a number: ");
        if (scanf("%ld", &n) != 1) {
            printf("\n Invalid input!");
            break;
        }

        if (n < 0) {
            printf("\n Factorial is not defined for negative numbers.");
        } else {
            result = fact(n);
            printf("\n FACTORIAL = %ld", result);
        }

        while ((ch = getchar()) != '\n' && ch != EOF); 

        printf("\n\n Do you wish to continue (Y/N): ");
        scanf("%c", &ch);
    } while(ch == 'Y' || ch == 'y');

    return 0;
}
long int fact(long int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return (n * fact(n - 1));
    }
}
