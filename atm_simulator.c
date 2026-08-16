#include <stdio.h>

#define CORRECT_PIN 1234

void showMenu() {
    printf("\n====================================\n");
    printf("           ATM SIMULATOR\n");
    printf("====================================\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
    printf("====================================\n");
}

int main() {

    int pin;
    int attempts = 0;
    int choice;
    float balance = 10000.00;
    float amount;

    printf("====================================\n");
    printf("        WELCOME TO ATM\n");
    printf("====================================\n");

    // PIN verification
    while (attempts < 3) {

        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &pin);

        if (pin == CORRECT_PIN) {
            printf("\nLogin successful! ✅\n");
            break;
        }

        attempts++;

        printf("Incorrect PIN! ❌\n");
        printf("Attempts remaining: %d\n", 3 - attempts);
    }

    if (attempts == 3) {
        printf("\nToo many incorrect attempts.\n");
        printf("Your account has been temporarily locked.\n");
        return 0;
    }

    // ATM menu
    while (1) {

        showMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nCurrent Balance: ₹%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter deposit amount: ₹");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Invalid amount.\n");
                } else {
                    balance += amount;

                    printf("\nDeposit successful! ✅\n");
                    printf("New Balance: ₹%.2f\n", balance);
                }
                break;

            case 3:
                printf("\nEnter withdrawal amount: ₹");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Invalid amount.\n");
                } else if (amount > balance) {
                    printf("Insufficient balance! ❌\n");
                } else {
                    balance -= amount;

                    printf("\nWithdrawal successful! ✅\n");
                    printf("Remaining Balance: ₹%.2f\n", balance);
                }
                break;

            case 4:
                printf("\nFor this portfolio version, PIN changing is "
                       "displayed as a simulated feature.\n");
                printf("Current PIN remains 1234.\n");
                break;

            case 5:
                printf("\nThank you for using the ATM Simulator! 👋\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}