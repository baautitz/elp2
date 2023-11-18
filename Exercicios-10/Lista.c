#include <stdio.h>
#include <string.h>

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

void msg(char *msg) {
    printf("%s\n", msg);
}

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
    if (a > l->ultimo)
        l->ultimo = a + 1;
    else
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

void exibe(Item it) {
    printf("Chave: %s, ", it.nome);
    printf("Sexo: %c, ", it.sexo);
    printf("Idade: %d \n", it.idade);
}

void relatorio(Lista l) {
    if (estaVazia(l)) {
        msg("Lista vazia.");
    } else {
        printf("\n----------------------------------------------\n");
        for (int i = l.primeiro; i < l.ultimo; i++) {
            exibe(l.item[i]);
        }
        printf("----------------------------------------------\n");
    }
}

char confirma() {
    char resp;
    do {
        msg("Confirma? Digite S ou N");
        scanf(" %c", &resp);
    } while (resp != 'S' && resp != 'N');

    return resp;
}

int pesquisa(Lista l, Chave chave, int quero) {
    int i = l.primeiro, achei;
    Apontador pos = 0;

    while (pos == 0 && i < l.ultimo) {
        if (strcmp(chave, l.item[i].nome) == 0) {
            pos = i;
            achei = 1;
        }

        if (strcmp(chave, l.item[i].nome) < 0) {
            pos = i;
            achei = 0;
        }

        i++;
    }

    if (quero == 1) {
        if (achei == 1)
            return pos;
        else
            return 0;
    } else {
        if (achei == 1)
            return 0;
        else {
            if (pos == 0)
                return l.ultimo;
            else
                return pos;
        }
    }
}

void incluir(Lista *l) {
    Item item;
    Apontador pos;

    if (estaCheia(*l)) {
        msg("Lista está cheia!");
    } else {
        printf("Digite o nome: ");
        scanf(" %s", &item.nome);
        pos = pesquisa(*l, item.nome, 0);
        if (pos == 0) {
            msg("Nome já existe nesta lista.");
        } else {
            printf("Digite o sexo (F ou M): ");
            scanf(" %c", &item.sexo);

            printf("Digite a idade: ");
            scanf(" %d", &item.idade);

            if (confirma() == 'S') {
                inserePos(l, item, pos);
            } else {
                msg("Operação cancelada!");
            }
        }
    }
}

void main() {
    Item item1 = {"Bruna", 'F', 20};
    Item item2 = {"Davi", 'M', 18};
    Item item3 = {"Vinicius", 'M', 19};

    Lista lista;
    criarLista(&lista);

    printf("Está vazia? %d\n", estaVazia(lista));
    printf("Está cheia? %d\n", estaCheia(lista));
    relatorio(lista);

    insereUltimo(&lista, item2);
    relatorio(lista);

    inserePos(&lista, item1, 1);
    relatorio(lista);

    inserePos(&lista, item3, 3);
    relatorio(lista);

    removePos(&lista, 3);
    relatorio(lista);

    inserePos(&lista, item3, 3);
    relatorio(lista);

    Chave nome = "Mirella";
    printf("Procurando %s e não quero achar: %d\n", nome, pesquisa(lista, nome, 0));
    printf("Procurando %s e quero achar: %d\n", nome, pesquisa(lista, nome, 1));

    incluir(&lista);
    relatorio(lista);
}
