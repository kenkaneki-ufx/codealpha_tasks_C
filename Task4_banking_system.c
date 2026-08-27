// Task 4: Banking System
// CodeAlpha C Programming Internship
// Author: Aryan Pandey

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    struct Account a;
    FILE *fp;

    printf("\n--- New Account ---\n");
    printf("Account no: ");
    scanf("%d", &a.accNo);
    printf("Name: ");
    scanf(" %[^\n]", a.name);
    printf("Initial balance: ");
    scanf("%f", &a.balance);

    fp = fopen("accounts.dat", "ab");
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    printf("Account created!\n");
}

void deposit() {
    struct Account a;
    FILE *fp;
    int accNo, found = 0;
    float amt;

    printf("\nAccount no: ");
    scanf("%d", &accNo);
    printf("Amount to deposit: ");
    scanf("%f", &amt);

    fp = fopen("accounts.dat", "r+b");
    if (fp == NULL) {
        printf("No accounts!\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.accNo == accNo) {
            a.balance += amt;
            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);
            printf("Deposited! New balance: %.2f\n", a.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Account not found!\n");
}

void withdraw() {
    struct Account a;
    FILE *fp;
    int accNo, found = 0;
    float amt;

    printf("\nAccount no: ");
    scanf("%d", &accNo);
    printf("Amount to withdraw: ");
    scanf("%f", &amt);

    fp = fopen("accounts.dat", "r+b");
    if (fp == NULL) {
        printf("No accounts!\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.accNo == accNo) {
            if (a.balance < amt) {
                printf("Not enough balance!\n");
            } else {
                a.balance -= amt;
                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);
                printf("Withdrawn! New balance: %.2f\n", a.balance);
            }
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Account not found!\n");
}

void checkBalance() {
    struct Account a;
    FILE *fp;
    int accNo, found = 0;

    printf("\nAccount no: ");
    scanf("%d", &accNo);

    fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("No accounts!\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.accNo == accNo) {
            printf("\nName: %s\nBalance: %.2f\n", a.name, a.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Account not found!\n");
}

int main() {
    int ch;

    do {
        printf("\n===== Banking System =====\n");
        printf("1. New Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: break;
            default: printf("Invalid!\n");
        }
    } while (ch != 5);

    return 0;
}
