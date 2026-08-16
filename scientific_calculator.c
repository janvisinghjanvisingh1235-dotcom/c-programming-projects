#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

void showMenu() {
    printf("\n========================================\n");
    printf("       SCIENTIFIC CALCULATOR\n");
    printf("========================================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n");
    printf("11. Exit\n");
    printf("========================================\n");
}

int main() {
    int choice;
    double a, b, result;

    while (1) {
        showMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = a + b;
                printf("Result = %.2lf\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = a - b;
                printf("Result = %.2lf\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = a * b;
                printf("Result = %.2lf\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);

                if (b == 0) {
                    printf("Error: Cannot divide by zero.\n");
                } else {
                    result = a / b;
                    printf("Result = %.2lf\n", result);
                }
                break;

            case 5:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &a, &b);
                result = pow(a, b);
                printf("Result = %.2lf\n", result);
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%lf", &a);

                if (a < 0) {
                    printf("Error: Cannot find square root of a negative number.\n");
                } else {
                    result = sqrt(a);
                    printf("Result = %.2lf\n", result);
                }
                break;

            case 7:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                result = sin(a * M_PI / 180.0);
                printf("sin(%.2lf) = %.4lf\n", a, result);
                break;

            case 8:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                result = cos(a * M_PI / 180.0);
                printf("cos(%.2lf) = %.4lf\n", a, result);
                break;

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                result = tan(a * M_PI / 180.0);
                printf("tan(%.2lf) = %.4lf\n", a, result);
                break;

            case 10:
                printf("Enter a positive number: ");
                scanf("%lf", &a);

                if (a <= 0) {
                    printf("Error: Logarithm requires a positive number.\n");
                } else {
                    result = log(a);
                    printf("ln(%.2lf) = %.4lf\n", a, result);
                }
                break;

            case 11:
                printf("\nThank you for using the Scientific Calculator!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}