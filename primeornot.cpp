#include <stdio.h>

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

int main() {
    int n;
    for(int i=0;i<2;i++){
    printf("Enter a number: ");
    scanf("%d", &n);
    if (is_prime(n)) {
        printf("%d is prime.\n", n);
    } else {
        printf("%d is not prime.\n", n);
    }
}
     printf("\nname:Raj Tuladhar \t ROll no:15");
    return 0;
}

