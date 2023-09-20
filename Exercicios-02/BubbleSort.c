#include <stdio.h>
void main() {
    int x, y, tamanho = 100;
    int alt, vet[tamanho];

    for (x = 0; x < tamanho; x++) {
        printf("Digite o valor %d de %d: ", (x + 1), tamanho);
        scanf("%d", &vet[x]);
    }

    printf("Lista de números não ordenada: ");
    for (x = 0; x < tamanho; x++) {
        printf("%d ", vet[x]);
    }

    for (x = 0; x < (tamanho - 1); x++) {
        for (y = x + 1; y < tamanho; y++) {
            if (vet[x] > vet[y]) {
                alt = vet[x];
                vet[x] = vet[y];
                vet[y] = alt;
            }
        }
    }

    printf("\nLista de números ordenada: ");
    for (x = 0; x < tamanho; x++) {
        printf("%d ", vet[x]);
    }
}