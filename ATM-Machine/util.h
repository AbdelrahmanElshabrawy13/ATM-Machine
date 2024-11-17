#ifndef UTIL_H
#define UTIL_H

void encrypt_pin(const char* pin, char* encrypted_pin);
void decrypt_pin(const char* encrypted_pin, char* pin);

#endif
