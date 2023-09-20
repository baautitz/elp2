/**
 * Faça um programa que contenha uma função para calcular o fatorial de um
 * número, a função deve receber um parâmetro número por cópia e retornar um
 * float.
 */

#include <stdio.h>

float fatorial(int num) {
    int i, fat = 1;
    for (i = 1; i <= num; i++) {
        fat *= i;
    }

    return fat;
}

void main() {
    int numero;
    float fat;

    printf("Digite um número: ");
    scanf("%d", &numero);

    fat = fatorial(numero);

    printf("Fatorial calculado de %d: %f", numero, fat);
}