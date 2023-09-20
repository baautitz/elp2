/**
 * Um armazém comercializa 100 diferentes mercadorias, identificadas por números
 * inteiros de 1 a 100. A quantidade de mercadorias em estoque e o preço de cada
 * mercadoria devem ser armazenadas em conjuntos distintos. Ao fim de cada dia
 * de trabalho, o comerciante fornece um conjunto com o total de cada mercadoria
 * que foi vendida. Faça um programa em linguagem C que seja capaz de:
 *
 * a) conhecer os valores de cada conjunto(vetor);
 *
 * b) calcular e informar a situação do estoque do comerciante ao fim do dia
 * para cada mercadoria;
 *
 * c) calcular e informar o faturamento do dia com a venda das mercadorias.
 */
#include <stdio.h>
#define TF 100
void main() {
    int i, tl, qtdeVendido, estoque[TF];
    float faturamento = 0, precos[TF];

    printf("Defina a quantida de produtos: ");
    scanf("%d", &tl);

    for (i = 0; i < tl; i++) {
        printf("Defina o estoque e o valor do produto %d: ", (i + 1));
        scanf("%d %f", &estoque[i], &precos[i]);
    }

    for (i = 0; i < tl; i++) {
        printf("Insira a quantida vendida do produto %d: ", (i + 1));
        scanf("%d", &qtdeVendido);

        estoque[i] -= qtdeVendido;
        faturamento += qtdeVendido * precos[i];
    }

    printf("\nSituação de estoque: \n");
    for (i = 0; i < tl; i++) {
        printf(" - Produto: %d\n", (i + 1));
        printf(" - Estoque: %d\n\n", estoque[i]);
    }

    printf("Faturamento: %f", faturamento);
}