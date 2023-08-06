#include <stdio.h>
void main() {
    int codSetor, numMat, qtdeSetor = 0, qtdeFunc = 0, qtdeFuncSetor = 0, funcMaiorSalSetor, setorMaiorSal;
    float sal, montanteSal = 0, montanteSalSetor = 0, maiorSalFuncSetor = -999, maiorSalSetor = -999;

    printf("Digite o código do setor: ");
    scanf("%d", &codSetor);
    while (codSetor > 0) {
        qtdeFuncSetor = 0;
        montanteSalSetor = 0;
        maiorSalFuncSetor = -999;

        printf("Digite o número da matrícula: ");
        scanf("%d", &numMat);
        while (numMat > 0) {
            printf("Digite o salário: ");
            scanf("%f", &sal);

            if (sal > maiorSalFuncSetor) {
                maiorSalFuncSetor = sal;
                funcMaiorSalSetor = numMat;
            }

            qtdeFuncSetor++;
            montanteSalSetor += sal;

            printf("Digite o número da matrícula: ");
            scanf("%d", &numMat);
        }

        montanteSal += montanteSalSetor;
        qtdeFunc += qtdeFuncSetor;

        if (montanteSalSetor > maiorSalSetor) {
            maiorSalSetor = montanteSalSetor;
            setorMaiorSal = codSetor;
        }

        qtdeSetor++;

        printf("qtdeFuncSetor=%d montanteSalSetor=%f funcMaiorSalSetor=%d", qtdeFuncSetor, montanteSalSetor, funcMaiorSalSetor);

        printf("\nDigite o código do setor: ");
        scanf("%d", &codSetor);
    }

    printf("qtdeSetor=%d qtdeFunc=%d montanteSal=%f setorMaiorSal=%d", qtdeSetor, qtdeFunc, montanteSal, setorMaiorSal);
}
