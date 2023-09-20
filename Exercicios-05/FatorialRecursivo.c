/**
 * Faça um programa que contenha uma função para calcular o fatorial de um
 * número, a função deve receber um parâmetro número por cópia e retornar um
 * float, utilizar uma função recursiva e não um loop.
 */

#include <stdio.h>

float fatorial(int num) {
    if (num == 1)
        return 1;
    else
        return num * fatorial(num - 1);
}

void main() {
    int numero;
    float fat;

    printf("Digite um número: ");
    scanf("%d", &numero);

    fat = fatorial(numero);

    printf("Fatorial calculado de %d: %f", numero, fat);
}