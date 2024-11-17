#ifndef USER_H
#define USER_H

typedef struct User {
    char username[50];
    int account_number;
    char encrypted_pin[5];
    double balance;
    struct User* next;
} User;

User* load_users(const char* filename);
int authenticate_user(User* head, int account_number, const char* pin);
void save_users(const char* filename, User* head);

#endif
