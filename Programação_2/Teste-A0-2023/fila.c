#include "fila.h"
#include <string.h>

struct fila_t *cria_fila() {
    struct fila_t *fila = malloc(sizeof(struct fila_t));
    fila->prim = NULL;
    fila->fim = NULL;
    fila->num = 0;
    return fila;
}

struct nodo_t *cria_nodo(char titulo[33], char texto[513]) {
    struct nodo_t *nodo = malloc(sizeof(struct nodo_t));
    nodo->idade = 0;
    nodo->prox = NULL;
    //destruir tudo no destroi nodo.
    //pedir explicação para algum professor!
    strcpy(nodo->titulo, titulo);
    strcpy(nodo->texto, texto);
    return nodo;
}

int fila_insere(struct nodo_t *noticia, struct fila_t *fila) {
    if (!noticia || !fila) return 0;

    noticia->prox = NULL;
    
    if (fila->num == 0) {
        fila->prim = noticia;
        fila->fim = noticia;
    }
    else {
        fila->fim->prox = noticia;
        fila->fim = noticia;
    }
    fila->num++;
    //conferindo...
    struct nodo_t *aux = fila->prim;
        while(aux != NULL) {
            printf("-------------------------------------------\n");
            printf("Título: %s\n", aux->titulo);
            printf("Texto: %s\n", aux->texto);
            printf("-------------------------------------------\n");
            aux = aux->prox;
        }
    //conferindo...
}

int fila_remove(struct nodo_t *noticia, struct fila_t *fila) {
    if (fila->prim == NULL) 
        return -1;
    
    struct nodo_t *aux;
    aux = fila->prim->prox;

    //free na notícia.
    free(noticia);

    fila->prim = aux;

    //diminuindo tamanho da fila.
    fila->num--;

    if (fila->num == 0) 
        fila->fim = NULL;

    return 0;
}

void printa_edicao(struct nodo_t *noticia1, struct nodo_t *noticia2, int controle) {
    //Controle define se tem duas notícias (controle=1) ou somente uma notícia (controle=0).
    if (controle == 1) {
        printf("=======================================================\n");
        printf("%s\n", noticia1->titulo);
        printf("");
        printf("%s\n", noticia1->texto);
        printf("");
        printf("==\n");
        printf("");
        printf("%s\n", noticia2->titulo);
        printf("");
        printf("%s\n", noticia2->texto);
        printf("=======================================================\n");
    }
    if (controle == 0) {
        printf("=======================================================\n");
        printf("%s\n", noticia1->titulo);
        printf("");
        printf("%s\n", noticia1->texto);
        printf("");
        printf("=======================================================\n");
    }
}

void seleciona_noticia(struct fila_t *breaknews, struct fila_t *informe) {
    if (breaknews->num >= 2) {
        printa_edicao(breaknews->prim, breaknews->prim->prox, 1);
        //Removendo os dois primeiros elementos da fila:
        fila_remove(breaknews->prim, breaknews);
        fila_remove(breaknews->prim, breaknews);
    }
    else if (breaknews->num == 1 && informe->num > 0) {
        printa_edicao(breaknews->prim, informe->prim, 1);
        //Removendo os dois primeiros elementos da fila:
        fila_remove(breaknews->prim, breaknews);
        fila_remove(informe->prim, informe);
    }
    else if (breaknews->num == 0 && informe->num >= 2) {
        printa_edicao(informe->prim, informe->prim, 1);
        //Removendo os dois primeiros elementos da fila:
        fila_remove(informe->prim, informe);
        fila_remove(informe->prim, informe);
    }
    else if (breaknews-> num == 1 && informe->num == 0) {
        printa_edicao(breaknews->prim, breaknews->prim, 0);
        //Removendo os dois primeiros elementos da fila:
        fila_remove(breaknews->prim, breaknews);
    }
    else if (breaknews->num == 0 && informe->num == 1) {
        printa_edicao(informe->prim, informe->prim, 0);
        //Removendo os dois primeiros elementos da fila:
        fila_remove(informe->prim, informe);
    }
    else {
        printf("Esta edição foi pulada por falta de notícias!\n");
    }
}

void atualiza_filas(struct fila_t *fila) {
    //Atualizando:
    struct nodo_t *aux = fila->prim;
    while (aux != NULL) {
        aux->idade++;

        //se for maior, ele irá retirar da fila.
        if (aux->idade > 3) {
            struct nodo_t *aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        else {
            aux = aux->prox;
        }
    }
}

void lista_imprime(struct fila_t *breaknews, struct fila_t *informes) {
    printf("==============================================================\n");
    printf("SOBREVIVENTES NAS DUAS LISTAS: \n");
    printf("==============================================================\n");
    printf("BREAKNEWS: \n");
    if (breaknews->prim != NULL) {
        struct nodo_t *aux = breaknews->prim;
        while(aux != NULL) {
            printf("-------------------------------------------\n");
            printf("Título: %s\n", aux->titulo);
            printf("Texto: %s\n", aux->texto);
            printf("-------------------------------------------\n");
            aux = aux->prox;
        }
    }
    printf("==============================================================\n");
    printf("INFORMES: \n");
    if (informes->prim != NULL) {
        struct nodo_t *aux2 = informes->prim;
        while(aux2 != NULL) {
            printf("-------------------------------------------\n");
            printf("Título: %s\n", aux2->titulo);
            printf("Texto: %s\n", aux2->texto);
            printf("-------------------------------------------\n");
            aux2 = aux2->prox;
        }
        free(aux2);
    }
    printf("==============================================================\n");
}


