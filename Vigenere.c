#include <stdio.h>
#include <string.h>

void encrypt(char plaintext[], char key[]);
void decrypt(char ciphertext[], char key[]);

int main() {
    char plaintext[100];
    char ciphertext[100];
    char key[100];

    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);

    printf("Enter keyword: ");
    fgets(key, 100, stdin);

    // Remove newline characters from inputs
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the plaintext
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);

    // Decrypt the ciphertext
    decrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);
    printf("\n Name :Raj tuladhar \t Roll no:15");

    return 0;
}

void encrypt(char plaintext[], char key[]) {
    int i, j, key_len;
    char ch;

    key_len = strlen(key);

    for(i = 0, j = 0; plaintext[i] != '\0'; ++i, ++j) {
        ch = plaintext[i];

        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch + key[j % key_len] - 'A' * 2) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            ch = (ch + key[j % key_len] - 'a' * 2) % 26 + 'a';
        }

        plaintext[i] = ch;
    }
}

void decrypt(char ciphertext[], char key[]) {
    int i, j, key_len;
    char ch;

    key_len = strlen(key);

    for(i = 0, j = 0; ciphertext[i] != '\0'; ++i, ++j) {
        ch = ciphertext[i];

        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - key[j % key_len] + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            ch = (ch - key[j % key_len] + 26) % 26 + 'a';
        }

        ciphertext[i] = ch;
    }
}
