#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct Account {
    char *namePtr;
    int balance;
};

//displays menu
void menu(struct Account *arrPtr);

//creates account and returns number of accounts created
int crtAccount(struct Account *arrPtr);

//displays accounts
void displayAccounts(struct Account *arrPtr, int accountCounter);

void makeTrans(struct Account *arrPtr);

int main(void) {
    struct Account *arr = (struct Account*)malloc(sizeof(struct Account) * 20);
    menu(arr);
    system("pause");
    return 0;
}

void menu(struct Account *arrPtr) {
    
    //char costs 1 byte vs 8 bytes of int
    char choice = '0';

    int accountCounter = 0;
    do {
    system("cls");
    printf("1. Create an account\n2. List of accounts\n3. Edit an account\n4. Make a transaction\n5. Delete an account\n6. Account data\n7. Exit\n");
    scanf("%c", &choice);
    switch (choice)
    {
    case '1':
        accountCounter = crtAccount(arrPtr);
        break;
    case '2':
        displayAccounts(arrPtr, accountCounter);
    case '3':
        printf("TODO");
    case '4':
        makeTrans(arrPtr);
    default:
        printf("Unexpected input...\n");
        break;
    }
    } while(choice != '7');
}

int crtAccount(struct Account *arrPtr) {
    static unsigned int accountCounter = 0;
    //check for realloc TODO
    //if (accountCounter > )
    printf("Enter a name: ");

    //allocating string space
    arrPtr[accountCounter].namePtr = (char*)malloc(MAX * sizeof(char)); 

    //scanf eats character
    scanf(" ");
    fgets(arrPtr[accountCounter].namePtr, MAX, stdin);
    printf("%s", arrPtr[accountCounter].namePtr);

    //default balance is 0
    arrPtr[accountCounter].balance = 0;
    accountCounter++;
    system("pause");
    return accountCounter;
}

void displayAccounts(struct Account *arrPtr, int accountCounter) {
    for (unsigned int i = 0; i < accountCounter; ++i) {
        printf("ID: %d\n", accountCounter);
        printf("Name: %s\n", arrPtr[i].namePtr);
        printf("Balance: %d\n", arrPtr[i].balance);
    }
    system("pause");
}

void makeTrans(struct Account *arrPtr) {
    unsigned int ID = 0;
    printf("Enter ID: ");
    scanf("%d", &ID);

    printf("1. Deposit\n 2.Withdraw\n");
    printf("Enter your choice: ");

    //char costs 1 byte vs 8 bytes of int
    char choice = '0';
    scanf("%c", &choice);
    unsigned int cash = 0;
    switch (choice)
    {
    case '1':
        printf("How much would you like to deposit? ");
        scanf("%d", &cash);
        arrPtr[ID].balance += cash;
        break;
    case '2':
        printf("How much would you like to withdraw? ");
        scanf("%d", &cash);
        arrPtr[ID].balance -= cash;
        break;
    default:
        printf("Unknown choice....");
        break;
    }
    system("pause");
}