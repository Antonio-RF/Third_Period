#include "fila.h"

struct fila_t *cria_fila() {
    struct fila_t *fila = malloc(sizeof(struct fila_t));
    fila->prim = NULL;
    fila->fim = NULL;
    fila->num = 0;
    return fila;
}

struct nodo_t *cria_nodo(char *titulo, char *texto) {
    struct nodo_t *nodo = malloc(sizeof(struct nodo_t));
    nodo->idade = 0;
    nodo->prox = NULL;
    nodo->titulo = titulo;
    nodo->texto = texto;
    return nodo;
}

int fila_insere(struct nodo_t *noticia, struct fila_t *fila) {
    if (fila->num == 0) {
        fila->prim = noticia;
        fila->fim = noticia;
        noticia->prox = NULL;
    }
    else {
        fila->fim->prox = noticia;
        fila->fim = noticia;
        noticia->prox = NULL;
    }
    fila->num++;
}

int fila_remove(struct nodo_t *noticia, struct fila_t *fila) {
    if (fila->prim == NULL) 
        return -1;
    
    struct nodo_t *aux;
    aux = fila->prim->prox;
    /*printa notícia*/

    //free na notícia.
    free(noticia->prox);
    free(noticia);

    fila->prim = aux;

    //diminuindo tamanho da fila.
    fila->num--;

    if (fila->num == 0) 
        fila->fim = NULL;

    return 0;
}
