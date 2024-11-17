#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"
#include "util.h"

User* load_users(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    User* head = NULL;
    User* tail = NULL;

    while (!feof(file)) {
        User* user = (User*)malloc(sizeof(User));
        if (!user) {
            printf("Error: Memory allocation failed.\n");
            fclose(file);
            return NULL;
        }

        // Reading user data from file
        if (fscanf(file, "%49[^,],%d,%4[^,],%lf\n", user->username, &user->account_number, user->encrypted_pin, &user->balance) == 4) {
            user->next = NULL;
            if (tail) {
                tail->next = user;
            } else {
                head = user;
            }
            tail = user;
        } else {
            free(user);
        }
    }

    fclose(file);
    return head;
}


int authenticate_user(User* head, int account_number, const char* pin) {
    if (!head) {
        printf("%d",head);
        printf("Error: User list is empty.\n");
        return 0;
    }

    User* current = head;
    while (current) {
        if (current->account_number == account_number) {
            char decrypted_pin[5];
            decrypt_pin(current->encrypted_pin, decrypted_pin);
            return strcmp(pin, decrypted_pin) == 0;
        }
        current = current->next;
    }

    return 0; // Authentication failed
}


void save_users(const char* filename, User* head) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Unable to open file %s for writing.\n", filename);
        return;
    }

    User* current = head;
    while (current) {
        fprintf(file, "%s,%d,%s,%.2f\n", current->username, current->account_number, current->encrypted_pin, current->balance);
        current = current->next;
    }

    fclose(file);
}

