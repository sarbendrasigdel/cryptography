#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int a, b;
    for(int i=0;i<2;i++){
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    if (gcd(a, b) == 1) {
        printf("%d and %d are coprime.\n", a, b);
    } else {
        printf("%d and %d are not coprime.\n", a, b);
    }
}
printf("\nname:Raj Tuladhar \t ROll no:15");
    return 0;
}

