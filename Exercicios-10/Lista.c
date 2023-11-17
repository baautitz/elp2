#include <stdio.h>
#define MAX 100

typedef int Apontador;
typedef char Chave[50];

typedef struct item {
    Chave nome;
    char sexo;
    int idade;
} Item;

typedef struct lista {
    Item item[MAX];
    Apontador primeiro, ultimo;
} Lista;

void criarLista(Lista *l) {
    l->primeiro = 1;
    l->ultimo = l->primeiro;
}

int estaVazia(Lista l) {
    return l.primeiro == l.ultimo;
}

int estaCheia(Lista l) {
    return l.ultimo == MAX - 1;
}

void inserePos(Lista *l, Item it, Apontador a) {
    for (int i = l->ultimo; i >= a; i--) {
        l->item[i] = l->item[i - 1];
    }

    l->item[a] = it;
    l->ultimo++;
}

void insereUltimo(Lista *l, Item it) {
    l->item[l->ultimo] = it;
    l->ultimo++;
}

void removePos(Lista *l, Apontador a) {
    for (int i = a; i < l->ultimo; i++) {
        l->item[i] = l->item[i + 1];
    }
    l->ultimo--;
}

void msg(char *msg) {
    printf("%s\n", msg);
}

void exibe(Item it) {
    printf("Chave: %s ", it.nome);
    printf("Sexo: %c ", it.sexo);
    printf("Idade: %d \n", it.idade);
}

void relatorio(Lista l) {
    if (estaVazia(l)) {
        msg("Lista vazia.");
    } else {
        printf("\n-----------------------------\n");
        for (int i = l.primeiro; i < l.ultimo; i++) {
            exibe(l.item[i]);
        }
        printf("-----------------------------\n");
    }
}

char confirma() {
    char resp;
    do {
        msg("Confirma? Digite S ou N");
        scanf(" %c", &resp);
    } while(resp != 'S' && resp != 'N');
    
    return resp;
}

void main() {
    confirma();
    Item item1 = {"Vinicius", 'M', 19};
    Item item2 = {"Davi", 'M', 18};
    Item item3 = {"Bruna", 'F', 20};

    Lista lista;
    criarLista(&lista);

    printf("Está vazia? %d\n", estaVazia(lista));
    printf("Está cheia? %d\n", estaCheia(lista));
    relatorio(lista);

    insereUltimo(&lista, item1);
    relatorio(lista);

    inserePos(&lista, item2, 1);
    relatorio(lista);

    inserePos(&lista, item3, 2);
    relatorio(lista);

    removePos(&lista, 0);
    relatorio(lista);
}
