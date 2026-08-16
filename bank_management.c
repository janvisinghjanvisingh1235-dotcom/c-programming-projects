#include <stdio.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account *account) {
    printf("\nEnter account number: ");
    scanf("%d", &account->accountNumber);

    printf("Enter account holder name: ");
    scanf(" %[^\n]", account->name);

    printf("Enter initial deposit: ");
    scanf("%f", &account->balance);

    printf("\nAccount created successfully!\n");
}

void deposit(struct Account *account) {
    float amount;

    printf("\nEnter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0) {
        account->balance += amount;
        printf("Deposit successful!\n");
        printf("Current balance: %.2f\n", account->balance);
    } else {
        printf("Invalid amount.\n");
    }
}

void withdraw(struct Account *account) {
    float amount;

    printf("\nEnter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > account->balance) {
        printf("Insufficient balance.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful!\n");
        printf("Current balance: %.2f\n", account->balance);
    }
}

void displayAccount(struct Account account) {
    printf("\n====================================\n");
    printf("         ACCOUNT DETAILS\n");
    printf("====================================\n");

    printf("Account Number : %d\n", account.accountNumber);
    printf("Account Holder : %s\n", account.name);
    printf("Balance        : %.2f\n", account.balance);

    printf("====================================\n");
}

int main() {
    struct Account account;
    int choice;
    int accountCreated = 0;

    while (1) {
        printf("\n====================================\n");
        printf("       BANK MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                createAccount(&account);
                accountCreated = 1;
                break;

            case 2:
                if (accountCreated)
                    deposit(&account);
                else
                    printf("\nPlease create an account first.\n");
                break;

            case 3:
                if (accountCreated)
                    withdraw(&account);
                else
                    printf("\nPlease create an account first.\n");
                break;

            case 4:
                if (accountCreated)
                    displayAccount(account);
                else
                    printf("\nPlease create an account first.\n");
                break;

            case 5:
                printf("\nThank you for using the Bank Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}