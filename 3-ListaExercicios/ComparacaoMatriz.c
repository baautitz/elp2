/**
 * Faça um programa que leia uma matriz e retorne
 * o maior e menor valor e suas posições.
 */

#include <stdio.h>
#define TF 10

void main() {
    int tlLinha, tlColuna, mat[TF][TF];
    int maior, menor, linhaMenor = 0, colunaMenor = 0, linhaMaior = 0,
                      colunaMaior = 0;

    printf("Defina o número de linhas: ");
    scanf("%d", &tlLinha);

    printf("Defina o número de colunas: ");
    scanf("%d", &tlColuna);

    for (int i = 0; i < tlLinha; i++) {
        for (int j = 0; j < tlColuna; j++) {
            printf("Defina o valor da linha %d na coluna %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    menor = maior = mat[0][0];

    for (int i = 0; i < tlLinha; i++) {
        for (int j = 0; j < tlColuna; j++) {
            if (mat[i][j] < menor) {
                menor = mat[i][j];
                linhaMenor = i;
                colunaMenor = j;
            }

            if (mat[i][j] > maior) {
                maior = mat[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    printf("\nMaior valor: %d, linha: %d, coluna: %d", maior, linhaMaior,
           colunaMaior);
    printf("\nMenor valor: %d, linha: %d, coluna: %d", menor, linhaMenor,
           colunaMenor);
}