#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "User.h"

// Functions prototypes
void deposit(User* user, double amount);
void withdraw(User* user, double amount);
void record_transaction(const char* filename, int account_number, const char* type, double amount);
void print_transaction_history(const char* filename, int account_number);

#endif
