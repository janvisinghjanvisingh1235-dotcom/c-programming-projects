#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers[] = "0123456789";
    const char symbols[] = "!@#$%^&*";

    char password[101];

    int length;
    int useUpper;
    int useNumber;
    int useSymbol;

    printf("========================================\n");
    printf("         PASSWORD GENERATOR\n");
    printf("========================================\n");

    printf("\nEnter password length (8-100): ");
    scanf("%d", &length);

    if (length < 8 || length > 100) {
        printf("\nInvalid length! Choose between 8 and 100.\n");
        return 1;
    }

    printf("\nInclude uppercase letters? (1 = Yes, 0 = No): ");
    scanf("%d", &useUpper);

    printf("Include numbers? (1 = Yes, 0 = No): ");
    scanf("%d", &useNumber);

    printf("Include symbols? (1 = Yes, 0 = No): ");
    scanf("%d", &useSymbol);

    char characters[200] = "";

    strcat(characters, lowercase);

    if (useUpper) {
        strcat(characters, uppercase);
    }

    if (useNumber) {
        strcat(characters, numbers);
    }

    if (useSymbol) {
        strcat(characters, symbols);
    }

    int characterCount = strlen(characters);

    srand((unsigned int)time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % characterCount];
    }

    password[length] = '\0';

    printf("\n========================================\n");
    printf("          GENERATED PASSWORD\n");
    printf("========================================\n");

    printf("%s\n", password);

    printf("========================================\n");
    printf("Password generated successfully!\n");

    return 0;
}