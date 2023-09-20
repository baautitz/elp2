#include <stdio.h>

int soma(int n) {
    if (n == 1) {
        return 1;
    } else
        return n + soma(n - 1);
}

void main() {
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    printf("%d", soma(num));
}