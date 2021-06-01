#include <stdio.h>
#include <stdlib.h>
#include "account.h" //account strucrure and functions

int main(void) {
    //will change and realloc array
    int arrayLength = 30;
    Account *accountArray = (Account *)malloc(arrayLength * sizeof(Account));
    //variable for loop;
    int choice = 0;
    int howManyAccounts = 0;
    do {
        system("cls");

        printf("1. Add an account\n2. List of accounts\n
        3. Edit an account\n4. Make a transaction\n
        5. Account data\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            howManyAccounts = add_account(accountArray, &arrayLength);
            break;
        case 2:
            display_accounts(accountArray, howManyAccounts);
            break;
        case 3:
            edit(accountArray);
            break;
        case 4:
            make_transaction(accountArray);
            break;
        case 5:
            display_acc(accountArray);
            break;
        case 0:
            free(accountArray);
            exit(EXIT_SUCCESS);
            break;
        default:
            fputs("Unknown option.", stdout);
            break;
        }
    } while(choice != 0);
    return 0;
}