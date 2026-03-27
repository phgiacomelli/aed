#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long TipoChave;

typedef struct Registro {
    TipoChave Chave;
} Registro;

typedef struct No* Apontador;

typedef struct No {
    Registro Reg;
    Apontador pEsq, pDir;
} No;

void Pesquisa(Registro* x, Apontador p) {
    if (p == NULL) {
        printf("Erro: Registro não está presente na árvore!");
        return;
    }

    if (x->Chave > p->Reg.Chave) {
        Pesquisa(x, p->pDir);
        return;
    } else if (x->Chave < p->Reg.Chave) {
        Pesquisa(x, p->pEsq);
        return;
    } else
        *x = p->Reg;
}

void Insere(Registro x, Apontador* p) {
    if (*p == NULL) {
        *p = (Apontador)malloc(sizeof(No));
        (*p)->Reg = x;
        (*p)->pDir = NULL;
        (*p)->pEsq = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Insere(x, &(*p)->pEsq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave) {
        Insere(x, &(*p)->pDir);
        return;
    } else {
        printf("Erro: Registro já existe na árvore!");
        return;
    }
}

void Inicializa(Apontador* Dicionario) {
    *Dicionario = NULL;
}

void Antecessor(Apontador q, Apontador* r) {
    Apontador aux;
    if ((*r)->pDir != NULL) {
        Antecessor(q, &(*r)->pDir);
        return;
    }

    q->Reg = (*r)->Reg;
    aux = *r;
    *r = (*r)->pEsq;
    free(aux);
}

void Retira(Registro x, Apontador* p) {
    Apontador Aux;
    if (*p == NULL) {
        printf("Erro: Registro nao está na árvore!\n");
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Retira(x, &(*p)->pEsq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave) {
        Retira(x, &(*p)->pDir);
        return;
    }
    if ((*p)->pDir == NULL) {
        Aux = *p;
        *p = (*p)->pEsq;
        free(Aux);
        return;
    }
    if ((*p)->pEsq != NULL) {
        Antecessor(*p, &(*p)->pEsq);
        return;
    }
    Aux = *p;
    *p = (*p)->pDir;
    free(Aux);
}

int main() {
    Apontador root;

    Registro n1;
    n1.Chave = 40;

    Registro n2;
    n2.Chave = 20;

    Registro n3;
    n3.Chave = 46;
    
    Registro n4;
    n4.Chave = 10;
    
    Registro n5;
    n5.Chave = 37;
    
    Registro n6;
    n6.Chave = 39;
    
    Registro n7;
    n7.Chave = 42;
    
    Registro n8;
    n8.Chave = 78;
    
    Registro n9;
    n9.Chave = 98;

    Inicializa(&root);
    Insere(n1, &root);
    Insere(n2, &root);
    Insere(n3, &root);
    Insere(n4, &root);
    Insere(n5, &root);
    Insere(n6, &root);
    Insere(n7, &root);
    Insere(n8, &root);
    Insere(n9, &root);
    Retira(n1, &root);
    Pesquisa(&n2, root);

    return 0;
}