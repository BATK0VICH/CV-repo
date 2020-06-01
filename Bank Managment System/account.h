#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#define NAMELENGTH 64

typedef struct Account {
    char *name;
    int id;
    double balance;
} Account;

//adds account to array
int add_account(Account *arr, int *len);
void input_data(Account *arr, int len);

//display array
void display_accounts(Account *arr, int len);
//display account data
void display_acc(Account* arr);

//edit an account
void edit(Account* arr);

//actions with balance
void make_transaction(Account* arr);
void withdraw(Account *arr, int id, double money);
void deposit(Account* arr, int id, double money);
#endif