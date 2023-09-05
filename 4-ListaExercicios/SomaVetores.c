/**
 * Faça um programa em linguagem C que capaz de fazer a soma de dois vetores de
 * dimensões N. Os valores dos dois vetores, bem como os do vetor resultado
 * devem ser armazenados em conjuntos. Os vetores têm no máximo 50 coeficientes.
 */

#include <stdio.h>
#define TF 50
void main() {
    int vet1[TF], vet2[TF], vet3[TF];
    int i, tl;

    printf("Defina o tamanho dos vetores: ");
    scanf("%d %d", &tl);

    printf("\nVetor 1: \n");
    for (i = 0; i < tl; i++) {
        printf(" - Defina o valor %d de %d: ", (i + 1), tl);
        scanf("%d", &vet1[i]);
    }

    printf("\nVetor 2: \n");
    for (i = 0; i < tl; i++) {
        printf(" - Defina o valor %d de %d: ", (i + 1), tl);
        scanf("%d", &vet2[i]);
    }

    for (i = 0; i < tl; i++) {
        vet3[i] = vet1[i] + vet2[i];
    }

    printf("\nResultado: ");
    for (i = 0; i < tl; i++) {
        printf("%d ", vet3[i]);
    }
}