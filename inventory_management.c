#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n================================\n");
        printf("     INVENTORY MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count >= MAX_PRODUCTS) {
                    printf("Inventory is full!\n");
                    break;
                }

                printf("\nEnter product ID: ");
                scanf("%d", &products[count].id);

                printf("Enter product name: ");
                scanf(" %[^\n]", products[count].name);

                printf("Enter quantity: ");
                scanf("%d", &products[count].quantity);

                printf("Enter price: ");
                scanf("%f", &products[count].price);

                count++;

                printf("\nProduct added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo products available.\n");
                    break;
                }

                printf("\n========== PRODUCTS ==========\n");

                for (int i = 0; i < count; i++) {
                    printf("\nProduct %d\n", i + 1);
                    printf("ID       : %d\n", products[i].id);
                    printf("Name     : %s\n", products[i].name);
                    printf("Quantity : %d\n", products[i].quantity);
                    printf("Price    : %.2f\n", products[i].price);
                }
                break;

            case 3: {
                int searchID;
                int found = 0;

                printf("\nEnter product ID to search: ");
                scanf("%d", &searchID);

                for (int i = 0; i < count; i++) {
                    if (products[i].id == searchID) {
                        printf("\nProduct Found!\n");
                        printf("ID       : %d\n", products[i].id);
                        printf("Name     : %s\n", products[i].name);
                        printf("Quantity : %d\n", products[i].quantity);
                        printf("Price    : %.2f\n", products[i].price);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nProduct not found.\n");
                }

                break;
            }

            case 4: {
                int updateID;
                int found = 0;

                printf("\nEnter product ID to update: ");
                scanf("%d", &updateID);

                for (int i = 0; i < count; i++) {
                    if (products[i].id == updateID) {

                        printf("Enter new quantity: ");
                        scanf("%d", &products[i].quantity);

                        printf("Enter new price: ");
                        scanf("%f", &products[i].price);

                        printf("\nProduct updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nProduct not found.\n");
                }

                break;
            }

            case 5: {
                int deleteID;
                int found = 0;

                printf("\nEnter product ID to delete: ");
                scanf("%d", &deleteID);

                for (int i = 0; i < count; i++) {
                    if (products[i].id == deleteID) {

                        for (int j = i; j < count - 1; j++) {
                            products[j] = products[j + 1];
                        }

                        count--;

                        printf("\nProduct deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nProduct not found.\n");
                }

                break;
            }

            case 6:
                printf("\nThank you for using Inventory Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}