/**
 * Faça um programa em linguagem C que capaz de fazer a soma de dois vetores de
 * dimensões N. Os valores dos dois vetores, bem como os do vetor resultado
 * devem ser armazenados em conjuntos. Os vetores têm no máximo 50 coeficientes.
 */

#include <stdio.h>
#define TF 50
void main() {
    int vet1[TF], vet2[TF], vet3[TF * 2];
    int i, tl1, tl2, tl3 = 0;

    printf("Defina o tamanho dos Vetores 1 e 2: ");
    scanf("%d %d", &tl1, &tl2);

    printf("\nVetor 1: \n");
    for (i = 0; i < tl1; i++) {
        printf(" - Defina o valor %d de %d: ", (i + 1), tl1);
        scanf("%d", &vet1[i]);
    }

    printf("\nVetor 2: \n");
    for (i = 0; i < tl2; i++) {
        printf(" - Defina o valor %d de %d: ", (i + 1), tl2);
        scanf("%d", &vet2[i]);
    }

    for (i = 0; i < tl1; i++) {
        tl3++;
        vet3[tl3 - 1] = vet1[i];
    }

    for (i = 0; i < tl2; i++) {
        tl3++;
        vet3[tl3 - 1] = vet2[i];
    }

    printf("\nResultado: ");
    for (i = 0; i < tl3; i++) {
        printf("%d ", vet3[i]);
    }
}