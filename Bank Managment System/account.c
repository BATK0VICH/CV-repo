#include "account.h"
#include <stdlib.h>
#include <stdio.h>


int add_account(Account *arr, int *len) {
    static int currentAccount = 0;
    if (currentAccount > * len) {
        arr = realloc(arr, *len + 30);
        *len = *len + 30;
        input_data(arr, currentAccount);
    }
    else 
        input_data(arr, currentAccount);
    
    ++currentAccount;
    fputs("Account created!\n", stdout);
    system("pause");
    return currentAccount;
}

void input_data(Account *arr, int current) {
    arr[current].name = (char *)malloc(NAMELENGTH * sizeof(char));

    if (arr[current].name == NULL) {
        perror("Error in malloc for name");
        exit(EXIT_FAILURE);
    }

    printf("Enter a name: ");
    scanf(" ");
    fgets(arr[current].name, NAMELENGTH, stdin);
    arr[current].id = current;
    arr[current].balance = 0;
}

void display_accounts(Account* arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("ID: %d\n", arr[i].id);
        printf("Name: %s\n", arr[i].name);
        printf("Balance: %lf\n", arr[i].balance);
        printf("-----------------------\n");
    }
    system("pause");
}

void display_acc(Account* arr) {
    system("cls");
    int ID = 0;
    printf("ID: ");
    printf("\n");
    scanf("%d", &ID);
    printf("Name: %s\n", arr[ID].name);
    printf("Balance: %lf\n", arr[ID].balance);
    system("pause");
}

void edit(Account* arr) {
    printf("Enter account ID you want to edit: ");
    int ID;
    scanf("%d", &ID);
    system("cls");

    int choice = 0;
    int innerChoice = 0;
    double money = 0.00;

    printf("1. Change name\n2. Deposit/Withdraw\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter new name: ");
        scanf(" ");
        fgets(arr[ID].name, NAMELENGTH, stdin);
        break;
    case 2:
        system("cls");
        printf("1. Deposit\n2. Withdraw\n");
        scanf("%d", &innerChoice);
        if (innerChoice == 1) {
            printf("How much to deposit? ");
            scanf("%lf", &money);
            deposit(arr, ID, money);
        }
        else if (innerChoice == 2) {
            printf("How much to withdraw? ");
            scanf("%lf", &money);
            withdraw(arr, ID, money);
        }
        else
            printf("Invalid choice...");
        break;
    default:
        printf("Invalid choice...\n");
        break;
    }
}

void make_transaction(Account* arr) {
    printf("Transfer from ID: ");
    int from = 0;
    scanf("%d", &from);
    printf("Transfer to ID: ");
    int to = 0;
    scanf("%d", &to);
    printf("How much would you like to transfer?\n");
    double howMuch = 0.00;
    scanf("%lf", &howMuch);
    withdraw(arr, from, howMuch);
    deposit(arr, to, howMuch);
}

void withdraw(Account* arr, int id, double money) {
    arr[id].balance = arr[id].balance - money;
}

void deposit(Account* arr, int id, double money) {
    arr[id].balance = arr[id].balance + money;
}