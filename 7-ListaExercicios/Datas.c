/**
 * a) Faça um subprograma que ao serem passados como parâmetros um ano e um mês, seja
 * retornado quantos dias existem naquele mês (cuidado com ano bissexto).
 *
 * b) Faça um subprograma que ao ser passado como parâmetro um ano, seja retornado
 * quantos dias existem naquele ano.
 *
 * c) Faça um subprograma que calcule quantos dias já se passaram desde 01/01/1901 até uma
 * data qualquer, maior que a data base, passada como parâmetro. (este é um problema
 * de compactação de data, o resultado é uma data compactada em relação a uma data
 * base.)
 *
 * d) Faça um subprograma que ao serem passados como parâmetros duas datas quaisquer,
 * seja retornado a diferença, em dias, entre as duas datas.
 *
 * e) Faça um subprograma que ao ser passado como parâmetro uma data compactada
 * em dias, a partir de 01/01/1901, seja retornado via parâmetro a data correspondente
 * no formato dia, mês e ano.
 */

#include <stdio.h>
#include <time.h>

int ehBissexto(int ano) {
    if ((ano % 4 == 0) || (ano % 400 == 0) && (ano % 100 != 0))
        return 1;
    else
        return 0;
}

int diasMes(int mes, int ano) {
    if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
        return 30;
    else if (mes == 2)
        return 28 + ehBissexto(ano);
    else
        return 31;
}

int diasAno(int ano) {
    return 365 + ehBissexto(ano);
}

int diasBase(int dia, int mes, int ano) {
    int i, dias = 0;
    for (i = 1901; i < ano; i++) {
        dias += diasAno(i);
    }

    for (i = 1; i < mes; i++) {
        dias += diasMes(i, ano);
    }

    return dias + dia;
}

int difDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int dias1 = diasBase(dia1, mes1, ano1);
    int dias2 = diasBase(dia2, mes2, ano2);
    if (dias1 > dias2)
        return dias1 - dias2;
    else
        return dias2 - dias1;
}

void diasParaData(int dias) {
    int i, aux = 0, ano = 1901, mes = 1, dia = 1;

    for (i = 1901; aux + diasAno(i) < dias; i++) {
        aux += diasAno(i);
        ano++;
    }

    for (i = 1; aux + diasMes(i, ano) < dias; i++) {
        aux += diasMes(i, ano);
        mes++;
    }

    dia = dias - aux;
    aux += dia;

    printf("%02d/%02d/%04d - %d", dia, mes, ano, aux);
}

void main() {
    printf("O ano 2023 é bissexto? %s\n", (ehBissexto(2023) ? "Sim" : "Não"));
    printf("O ano 2020 é bissexto? %s\n", (ehBissexto(2020) ? "Sim" : "Não"));
    printf("\n");

    printf("O ano 2023 tem quantos dias? %d\n", diasAno(2023));
    printf("O ano 2020 tem quantos dias? %d\n", diasAno(2020));
    printf("\n");

    printf("Meses de 2023: \n");
    for (int i = 1; i <= 12; i++) {
        printf(" - O mês %02d tem %02d dias.\n", i, diasMes(i, 2023));
    }
    printf("\n");

    printf("Meses de 2020: \n");
    for (int i = 1; i <= 12; i++) {
        printf(" - O mês %02d tem %02d dias.\n", i, diasMes(i, 2020));
    }
    printf("\n");

    printf("Há %d dias entre os dias 01/01/1901 e 19/09/2023\n", diasBase(19, 9, 2023));
    printf("Há %d dias entre os dias 01/01/1901 e 18/08/2023\n", diasBase(18, 8, 2023));
    printf("Há %d dias entre os dias 01/01/1901 e 27/08/2023\n", diasBase(27, 8, 2023));
    printf("Há %d dias entre os dias 20/08/2023 e 19/09/2023\n", difDias(20, 8, 2023, 19, 9, 2023));
    printf("\n");

    diasParaData(44799);
    printf("\n");
}
