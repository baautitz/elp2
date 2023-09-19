#include <stdio.h>
int conte(double n) {
    if ((n - (int)n) > 0) {
        if ((n * 10 - (int)(n * 10)) == 0)
            return 1 + conte(n * 10);
        else
            return conte(n * 10);
    } else {
        if (n < 10)
            return 1;
        else
            return 1 + conte((int)(n / 10));
    }
}

void main() {
    double num;

    printf("Digite um número: ");
    scanf("%lf", &num);

    printf("%d", conte(num));
}