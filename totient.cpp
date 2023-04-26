#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int totient(int n) {
    int result = 1;
    for (int i = 2; i < n; i++) {
        if (gcd(i, n) == 1) {
            result++;
        }
    }
    return result;
}

int main() {
    int n;
    for(int i=0;i<2;i++){
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The totient of %d is %d\n", n, totient(n));
	}
	printf("\nname:Raj Tuladhar \t ROll no:15");
    return 0;
}

