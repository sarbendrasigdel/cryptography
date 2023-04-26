#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

int main() {
    int p, q, n, phi, e, d, msg, enc_msg, dec_msg;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    // calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // choose e such that 1 < e < phi and e is coprime to phi
    do {
        e = rand() % (phi - 2) + 2;
    } while (gcd(e, phi) != 1);

    // calculate d such that d is the modular multiplicative inverse of e modulo phi
    d = mod_inverse(e, phi);

    // prompt user for message
    printf("Enter a message (integer): ");
    scanf("%d", &msg);

    // encryption
    enc_msg = fmod(pow(msg, e), n);

    // decryption
    dec_msg = fmod(pow(enc_msg, d), n);

    // output results
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    printf("Original message: %d\n", msg);
    printf("Encrypted message: %d\n", enc_msg);
    printf("Decrypted message: %d\n", dec_msg);

    return 0;
}

