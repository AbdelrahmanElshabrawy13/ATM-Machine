#include <stdio.h>
#include <stdlib.h>
#include "User.h"
#include "Transaction.h"

// Takes the amount that want to be deposited
void deposit(User* user, double amount) {
    user->balance += amount;
    record_transaction("transactions.csv", user->account_number, "Deposit", amount);
}

// Takes the amount that want to be withdraw
void withdraw(User* user, double amount) {
    if (user->balance >= amount) {
        user->balance -= amount;
        record_transaction("transactions.csv", user->account_number, "Withdraw", amount);
    } else {
        printf("Insufficient funds.\n");
    }
}

// Updates the csv file
void record_transaction(const char* filename, int account_number, const char* type, double amount) {
    FILE* file = fopen(filename, "a");
    if (file) {
        fprintf(file, "%d,%s,%.2f\n", account_number, type, amount);
        fclose(file);
    }
}
// Prints out the transaction history
void print_transaction_history(const char* filename, int account_number) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("No transaction history available.\n");
        return;
    }

    char line[100];
    printf("Transaction History:\n");
    while (fgets(line, sizeof(line), file)) {
        int acc_no;
        char type[20];
        double amount;
        if (sscanf(line, "%d,%[^,],%lf", &acc_no, type, &amount) == 3 && acc_no == account_number) {
            printf("%s: %.2f\n", type, amount);
        }
    }

    fclose(file);
}
