/**
 * Faça um programa que contenha uma função para calcular o fatorial de um
 * número, a função deve receber um parâmetro número e, por referência, uma
 * variável para armazenar o resultado. Deve ser do tipo void.
 */

#include <stdio.h>

void fatorial(int num, float* fat) {
    int i, resultado = 1;
    for (i = 1; i <= num; i++) {
        resultado *= i;
    }

    *fat = resultado;
}

void main() {
    int numero;
    float fat;

    printf("Digite um número: ");
    scanf("%d", &numero);

    fatorial(numero, &fat);

    printf("Fatorial calculado de %d: %f", numero, fat);
}