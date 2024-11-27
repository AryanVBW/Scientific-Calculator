#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

// Function to clear screen on macOS
void clearScreen() {
    printf("\033[2J\033[H");
}

// Function to get a single character without waiting for enter
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

// Function to calculate factorial
double factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int choice;
    double num1, num2, result;
    char cont;

    do {
        clearScreen();
        printf("\n\n\t*** Scientific Calculator ***\n");
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Division");
        printf("\n5. Square root");
        printf("\n6. Power");
        printf("\n7. Sine");
        printf("\n8. Cosine");
        printf("\n9. Tangent");
        printf("\n10. Natural logarithm");
        printf("\n11. Factorial");
        printf("\n12. Exit");
        
        printf("\n\nEnter your choice (1-12): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if(num1 >= 0) {
                    result = sqrt(num1);
                    printf("Square root: %.2lf\n", result);
                } else {
                    printf("Error: Cannot calculate square root of negative number!\n");
                }
                break;
            
            case 6:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            
            case 7:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180.0);
                printf("Sine: %.2lf\n", result);
                break;
            
            case 8:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180.0);
                printf("Cosine: %.2lf\n", result);
                break;
            
            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180.0);
                printf("Tangent: %.2lf\n", result);
                break;
            
            case 10:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if(num1 > 0) {
                    result = log(num1);
                    printf("Natural logarithm: %.2lf\n", result);
                } else {
                    printf("Error: Invalid input for logarithm!\n");
                }
                break;
            
            case 11:
                printf("Enter a positive integer: ");
                scanf("%lf", &num1);
                if(num1 >= 0 && num1 == (int)num1) {
                    result = factorial((int)num1);
                    printf("Factorial: %.0lf\n", result);
                } else {
                    printf("Error: Invalid input for factorial!\n");
                }
                break;
            
            case 12:
                printf("Goodbye!\n");
                return 0;
            
            default:
                printf("Invalid choice!\n");
        }
        
        printf("\nPress any key to continue...");
        getchar(); // Consume newline
        getch();
        
    } while(1);

    return 0;
}
