/*
 * 19) Em uma empresa do governo, por sinal uma das mais organizadas, não se
 * sabe quantos setores a compõe e nem quantos funcionários trabalham em cada
 * setor. O diretor, que poucos funcionários conhecem, resolveu fazer um
 * levantamento de funcionários e salários em cada setor, considerando-se que
 * não existem fantasmas (pelo menos isto né?). No final do levantamento,
 * obteve-se uma série de listas contendo, no topo de cada lista, o código do
 * setor e a seguir, o número de matrícula, o salário e o nome de cada
 * funcionário, referentes àquele setor. No final de cada lista o número de
 * matrícula do funcionário é Q. indicando que naquele setor não existem mais
 * funcionários, e nas próximas listas ocorre o mesmo fato, exceto na última
 * lista que contém o número do setor igual a 0, indicando que não existem mais
 * setores na empresa.
 *
 * Faça um algoritmo que calcule:
 * a) quantos setores existem na empresa;
 * b) quantos funcionários trabalham na empresa;
 * c) qual o montante total de salários pagos pela empresa;
 * d) quantos funcionários trabalham em cada setor da empresa;
 * e) qual o montante de salários pagos pela empresa em cada setor;
 * f) qual o funcionário que recebe o maior salário em cada setor;
 * g) qual setor gasta mais em salários;
 *
 * Sugestão: crie dois laços, um dentro do outro, o 1° controlando os setores e
 * o 2º controlando os funcionários de cada setor.
 *
 * AE(codSetor, numMat, sal)
 * AS(qtdeSetor, qtdeFunc, montanteSal, qtdeFuncSetor, montanteSalSetor,
 * funcMaiorSalSetor, setorMaiorSal)
 */

#include <stdio.h>
void main() {
  int codSetor, numMat, qtdeSetor = 0, qtdeFunc = 0, qtdeFuncSetor = 0,
                        funcMaiorSalSetor, setorMaiorSal;
  float sal, montanteSal = 0, montanteSalSetor = 0, maiorSalFuncSetor = -999,
             maiorSalSetor = -999;

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

    printf("qtdeFuncSetor=%d montanteSalSetor=%f funcMaiorSalSetor=%d",
           qtdeFuncSetor, montanteSalSetor, funcMaiorSalSetor);

    printf("\nDigite o código do setor: ");
    scanf("%d", &codSetor);
  }

  printf("qtdeSetor=%d qtdeFunc=%d montanteSal=%f setorMaiorSal=%d", qtdeSetor,
         qtdeFunc, montanteSal, setorMaiorSal);
}
