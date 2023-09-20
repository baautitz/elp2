#include <stdio.h>

int mdc(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return mdc(num2, num1 % num2);
    }
}

void main() {
    int num1, num2;

    printf("Defina o número 1 e 2: ");
    scanf("%d %d", &num1, &num2);

    printf("MDC calculado: %d", mdc(num1, num2));
}