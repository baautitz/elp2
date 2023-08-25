#include <stdio.h>
#define TF 100

void main() {
    int i, j, k, tl1, tl2, tl3 = 0, duplicado = 0;
    int vet1[TF], vet2[TF], vet3[TF];

    printf("Defina o tamanho do vetor 1: ");
    scanf("%d", &tl1);

    printf("Defina o tamanho do vetor 2: ");
    scanf("%d", &tl2);

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
        for (j = 0; j < tl2; j++) {
            if (vet1[i] == vet2[j]) {
                duplicado = 0;
                for (k = 0; k < tl3; k++) {
                    if (vet1[i] == vet3[k]) {
                        duplicado = 1;
                    }
                }

                if (duplicado == 0) {
                    tl3++;
                    vet3[tl3 - 1] = vet1[i];
                }
            }
        }
    }

    printf("\nVetor 1: ");
    for (i = 0; i < tl1; i++) {
        printf("%d ", vet1[i]);
    }

    printf("\nVetor 2: ");
    for (i = 0; i < tl2; i++) {
        printf("%d ", vet2[i]);
    }

    printf("\n\nResultado: ");
    for (i = 0; i < tl3; i++) {
        printf("%d ", vet3[i]);
    }
}