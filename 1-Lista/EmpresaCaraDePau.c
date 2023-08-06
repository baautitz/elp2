/*
 * A empresa Cara de Pau Ltda. resolveu fazer uma pesquisa de mercado,
 * abrangendo o maior número de pessoas possível, para saber se as pessoas
 * gostando ou não de um novo produto lançado no mercado, coletando o
 * sexo (M=masculino,F=femino), a idade e uma resposta (S=sim, N=não) de cada entrevistado.
 * 
 * Faça um algoritmo que calcule:
 * a) quantas pessoas foram entrevistadas;
 * b) quantas pessoas disseram sim;
 * c) quantas pessoas disseram não;
 * d) o percentual de pessoas que disseram sim:
 * e) quantas mulheres disseram sim;
 * f) quantos homens disseram não;
 * g) quantos homens até 23 anos disseram sim;
 * h) quantas mulheres até 23 anos disseram não;
 *
 * Adote flag adequado
 * 
 * AE(sexo, idade, resposta) 
 * AS(qtdeEnt, qtdeSim, qtdeNao, percSim, qtdeFSim, qtdeMNao, qtdeM23Sim, qtdeF23Nao)
 */

#include <stdio.h>
void main() {
  char sexo, resposta;
  int idade, qtdeEnt = 0, qtdeSim = 0, qtdeNao = 0, qtdeFSim = 0, qtdeMNao = 0,
             qtdeM23Sim = 0, qtdeF23Nao = 0;
  float percSim = 0;

  printf("Digite sua idade: ");
  scanf("%d", &idade);
  while (idade > 0) {
    printf("Digite seu sexo (F ou M): ");
    scanf(" %c", &sexo);

    printf("Digite sua resposta (S ou N): ");
    scanf(" %c", &resposta);

    qtdeEnt++;
    if (resposta == 'S' || resposta == 's') {
      qtdeSim++;
      if (sexo == 'F' || sexo == 'f') {
        qtdeFSim++;
      } else {
        if (idade <= 23) qtdeM23Sim++;
      }
    } else {
      qtdeNao++;
      if (sexo == 'F' || sexo == 'f') {
        if (idade <= 23) qtdeF23Nao++;
      } else {
        qtdeMNao++;
      }
    }

    printf("Digite sua idade: ");
    scanf("%d", &idade);
  }

  if (qtdeEnt > 0) percSim = qtdeSim / (float)qtdeEnt;

  printf(
      "qtdeEnt=%d qtdeSim=%d qtdeNao=%d percSim=%f qtdeFSim=%d qtdeMNao=%d "
      "qtdeM23Sim=%d qtdeF23Nao=%d",
      qtdeEnt, qtdeSim, qtdeNao, percSim, qtdeFSim, qtdeMNao, qtdeM23Sim,
      qtdeF23Nao);
}
