#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"
#include "Transaction.h"

int main() {
    User* users = load_users("users.csv");

    int account_number;
    char pin[5];
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    printf("Enter PIN: ");
    scanf("%s", pin);

    if (!authenticate_user(users, account_number, pin)) 
    {
        printf("Invalid credentials.\n");
        return 1;
    }

    printf("Login successful!\n");
    User* current = users;
    while (current && current->account_number != account_number) {
        current = current->next;
    }

    int choice;
    do {
        printf("\n1. Balance Inquiry\n2. Deposit Funds\n3. Withdraw Funds\n4. Transaction History\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your balance is: %.2f\n", current->balance);
                break;
            case 2: {
                double amount;
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                deposit(current, amount);
                break;
            }
            case 3: {
                double amount;
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                withdraw(current, amount);
                break;
            }
            case 4:
                print_transaction_history("transactions.csv", account_number);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    save_users("users.csv", users);
    return 0;
}
