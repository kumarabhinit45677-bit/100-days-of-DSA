#include <stdio.h>

long long power(int a, int b) {
    if(b == 0)
        return 1;        
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    printf("Enter base (a) and exponent (b): ");
    scanf("%d %d", &a, &b);

    long long result = power(a, b);

    printf("%d raised to %d is %lld\n", a, b, result);

    return 0;
}
