#include <stdio.h>
#include <string.h>

void encrypt(char plaintext[], int key);
void decrypt(char ciphertext[], int key);

int main() {
    char plaintext[100];
    char ciphertext[100];
    int key;

    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt the plaintext
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);

    // Decrypt the ciphertext
    decrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);
    printf("\n Name :Raj tuladhar \t Roll no:15");

    return 0;
}

void encrypt(char plaintext[], int key) {
    int i;
    char ch;

    for(i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];

        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
        }

        plaintext[i] = ch;
    }
}

void decrypt(char ciphertext[], int key) {
    int i;
    char ch;

    for(i = 0; ciphertext[i] != '\0'; ++i) {
        ch = ciphertext[i];

        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - key + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            ch = (ch - key + 26 - 'a') % 26 + 'a';
        }

        ciphertext[i] = ch;
    }
}
