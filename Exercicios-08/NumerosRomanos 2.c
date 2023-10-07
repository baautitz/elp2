/**
 * Faça um programa em linguagem C que tendo como dado de entrada um número inteiro positivo inferior a 4.000, que seja capaz de transformar este
 * número no seu equivalente em algarismos romanos.
 *
 * I = 1          V = 5          X = 10         L = 50
 * C = 100        D = 500        M = 1000
 *
 * Lembrando que em algarismos romanos existe uma regra que não permite a mesma letra seja repetida mais de três vezes seguidamente. Exemplo:
 *
 * 4   = IIII está errado. A letra I está repetida seguidamente mais de 3 vezes. A forma correta é IV (cinco com um a menos)
 * 6   =  VI (cinco com um a mais)
 * 9   =  IX (dez com um a menos)
 * 40  =  XL (cinqüenta com dez a menos)
 * 90  =  XC (cem com dez a menos)
 * 400 =  CD (quinhentos com cem a menos)
 * 900 =  CM (mil com cem a menos)
 *
 * Assim, 1998 é equivalente a MCMXCVIII em romano
 *
 * Sugestão: enquanto o número for maior que 1000 subtraia este valor do número dado e concatene a letra 'M' em uma cadeia de caracteres. Após,
 * verifique se o que restou do número cai na exceção do 900, se cair, retire 900 do valor atual e concatene na cadeia as letras 'CM', e assim por
 * diante até o valor do número dado seja zero.
 */

#include <stdio.h>
#include <string.h>

void converteOrdem(int* num, int ordem, char unidade1[2], char unidade5[2], char dezena[2], char* strRomano) {
    int base = 1;
    for (int i = 1; i < ordem; i++)
        base *= 10;

    char romano[3] = "";

    char unidadeECinco[3] = "";
    strcat(unidadeECinco, unidade1);
    strcat(unidadeECinco, unidade5);

    char unidadeEDezena[3] = "";
    strcat(unidadeEDezena, unidade1);
    strcat(unidadeEDezena, dezena);

    while (*num >= base) {
        if (*num >= base * 9) {
            strcat(romano, unidadeEDezena);
            *num = *num - base * 9;
        } else if (*num >= base * 5) {
            strcat(romano, unidade5);
            *num = *num - base * 5;
            while (*num >= base * 5) {
                strcat(romano, unidade1);
                *num = *num - base * 1;
            }
        } else if (*num >= base * 4) {
            strcat(romano, unidadeECinco);
            *num = *num - base * 4;
        } else if (*num >= base * 1) {
            while (*num >= base * 1) {
                strcat(romano, unidade1);
                *num = *num - base * 1;
            }
        }
    }

    strcat(strRomano, romano);
}

void main() {
    int num;
    char romano[50] = "";

    printf("Digite o número a ser transformado: ");
    scanf("%d", &num);

    while (num != 0) {
        if (num < 10) {
            converteOrdem(&num, 1, "I", "V", "X", romano);
        } else if (num < 100) {
            converteOrdem(&num, 2, "X", "L", "C", romano);
        } else if (num < 1000) {
            converteOrdem(&num, 3, "C", "D", "M", romano);
        } else if (num < 10000) {
            converteOrdem(&num, 4, "M", "v", "x", romano);
        }
    }

    printf("Resultado: %s", romano);
}