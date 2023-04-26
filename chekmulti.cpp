#include <stdio.h>

int main() {
    int a, b, n;
    for(int i=0;i<2;i++){
    printf("Enter two integers a and b: ");
    scanf("%d %d", &a, &b);
    printf("Enter a modulus n: ");
    scanf("%d", &n);
    int prod = (a * b) % n;
    if (prod == 1) {
        printf("%d is the multiplicative inverse of %d modulo %d\n", b, a, n);
    } else {
        printf("%d is not the multiplicative inverse of %d modulo %d\n", b, a, n);
    }
}
     printf("\nname:Raj Tuladhar \t ROll no:15");
    return 0;
}

