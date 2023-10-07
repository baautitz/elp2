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

void main() {
    int num;
    char romano[50] = "";

    printf("Digite o número a ser transformado: ");
    scanf("%d", &num);

    while (num != 0) {
        if (num >= 1000) {
            strcat(romano, "M");
            num -= 1000;
        } else if (num >= 900) {
            strcat(romano, "CM");
            num -= 900;
        } else if (num >= 500) {
            strcat(romano, "D");
            num -= 500;
            while (num >= 500) {
                strcat(romano, "C");
                num -= 100;
            }
        } else if (num >= 400) {
            strcat(romano, "CD");
            num -= 400;
        } else if (num >= 100) {
            while (num >= 100) {
                strcat(romano, "C");
                num -= 100;
            }
        } else if (num >= 90) {
            strcat(romano, "XC");
            num -= 90;
        } else if (num >= 50) {
            strcat(romano, "L");
            num -= 50;
            while (num >= 50) {
                strcat(romano, "X");
                num -= 10;
            }
        } else if (num >= 40) {
            strcat(romano, "XL");
            num -= 40;
        } else if (num >= 10) {
            while (num >= 10) {
                strcat(romano, "X");
                num -= 10;
            }
        } else if (num >= 5) {
            strcat(romano, "V");
            num -= 5;
            while (num >= 5) {
                strcat(romano, "I");
                num -= 1;
            }
        } else if (num >= 4) {
            strcat(romano, "IV");
            num -= 4;
        } else if (num >= 1) {
            while (num >= 1) {
                strcat(romano, "I");
                num -= 1;
            }
        }
    }

    printf("Resultado: %s", romano);
}