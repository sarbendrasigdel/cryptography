#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int power(int a, int b, int p) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

int rabin_miller(int n, int k) {
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    int d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < k; i++) {
        int a = rand() % (n - 2) + 2;
        int x = power(a, d, n);
        if (x == 1 || x == n - 1) {
            continue;
        }
        for (int j = 0; j < s - 1; j++) {
            x = (x * x) % n;
            if (x == 1) {
                return 0;
            }
            if (x == n - 1) {
                break;
            }
        }
        if (x != n - 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    for(int i=0;i<2;i++){
	
    printf("Enter a number to check for primality: ");
    scanf("%d", &n);
    printf("Enter the number of iterations (k) for the Rabin-Miller test: ");
    scanf("%d", &k);
    srand(time(NULL));
    if (rabin_miller(n, k)) {
        printf("%d is probably prime\n", n);
    } else {
        printf("%d is composite\n", n);
    }
}
    printf("\nname:Raj Tuladhar \t ROll no:15");
    return 0;
}

