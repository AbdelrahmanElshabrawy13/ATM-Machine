#include <stdio.h>
#include <string.h>

// Encryption of pin using hill cipher 2x2
void encrypt_pin(const char* pin, char* encrypted_pin) {
    int key[2][2] = {{3, 3}, {2, 5}};
    for (int i = 0; i < 4; i += 2) {
        encrypted_pin[i] = ((key[0][0] * (pin[i] - '0')) + (key[0][1] * (pin[i + 1] - '0'))) % 10 + '0';
        encrypted_pin[i + 1] = ((key[1][0] * (pin[i] - '0')) + (key[1][1] * (pin[i + 1] - '0'))) % 10 + '0';
    }
    encrypted_pin[4] = '\0';
}

// Dencryption of cipher pin using hill cipher 2x2
void decrypt_pin(const char* encrypted_pin, char* pin) {
    int key_inv[2][2] = {{5, -3}, {-2, 3}};
    for (int i = 0; i < 4; i += 2) {
        pin[i] = ((key_inv[0][0] * (encrypted_pin[i] - '0') + key_inv[0][1] * (encrypted_pin[i + 1] - '0')) % 10 + 10) % 10 + '0';
        pin[i + 1] = ((key_inv[1][0] * (encrypted_pin[i] - '0') + key_inv[1][1] * (encrypted_pin[i + 1] - '0')) % 10 + 10) % 10 + '0';
    }
    pin[4] = '\0';
}
