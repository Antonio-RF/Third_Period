#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

struct nodo_t {
    char *titulo;
    char *texto;
    int idade;
    struct nodo_t *prox;
};

struct fila_t {
    struct nodo_t *prim;
    struct nodo_t *fim;
    int num;
};

struct fila_t *cria_fila();
struct nodo_t *cria_nodo(char *titulo, char *texto);
int fila_insere(struct nodo_t *noticia, struct fila_t *fila);
int fila_remove(struct nodo_t *noticia, struct fila_t *fila);

#endif