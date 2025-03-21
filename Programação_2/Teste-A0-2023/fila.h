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
void printa_edicao(struct nodo_t *noticia1, struct nodo_t *noticia2, int controle);
void seleciona_noticia(struct fila_t *breaknews, struct fila_t *informe);
void atualiza_filas(struct fila_t *breaknews, struct fila_t *informes);
void lista_imprime(struct fila_t *breaknews, struct fila_t *informes);

#endif