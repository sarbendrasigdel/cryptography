#include <stdio.h>

int extended_euclidean(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_euclidean(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int mod_inverse(int a, int m) {
    int x, y;
    int gcd = extended_euclidean(a, m, &x, &y);
    if (gcd != 1) {
        printf("%d is not invertible modulo %d\n", a, m);
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    int a, m;
    for(int i=0;i<2;i++){
	
    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter a modulus: ");
    scanf("%d", &m);
    int inv = mod_inverse(a, m);
    if (inv != -1) {
        printf("The multiplicative inverse of %d modulo %d is %d\n", a, m, inv);
    }
}
    printf("\nname:Raj Tuladhar \t ROll no:15");
    return 0;
}

