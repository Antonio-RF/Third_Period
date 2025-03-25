#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "jukefila.h"
#include "pedido.h"

jukefila* criar_jukefila() {
    struct jukefila *fila = malloc(sizeof(struct jukefila));
    fila->inicio = NULL;
    fila->final = NULL;
    return fila;
}

void inserir_jukefila(pedido* elemento, jukefila* fila) {
    //primeiro elemento inserido.
    if (fila->inicio == NULL) {
        fila->inicio = elemento;
        fila->final = elemento;
    }
    //elemento inserido na primeira posição.
    else if (fila->inicio->valor < elemento->valor){
        fila->inicio->anterior = elemento;
        elemento->proximo = fila->inicio;
        fila->inicio = elemento;
    }
    //elemento inserido no final da fila.
    else if (fila->final->valor >= elemento->valor) {
        fila->final->proximo = elemento;
        elemento->anterior = fila->final;
        fila->final = elemento;
    }
    else {
        struct pedido *aux = fila->inicio;
        while (aux->proximo != NULL && aux->proximo->valor >= elemento->valor) {
            aux = aux->proximo;
        }
        elemento->proximo = aux->proximo;
        elemento->anterior = aux;
        aux->proximo->anterior = elemento;
        aux->proximo = elemento;
    }
}

pedido* consumir_jukefila(jukefila* fila) {
    if (fila->inicio == NULL)
        return NULL;
    struct pedido *davez = fila->inicio;
    if (fila->inicio->proximo != NULL) {
        fila->inicio = fila->inicio->proximo;
        fila->inicio->anterior = NULL;
    }
    else {
        fila->inicio = NULL;
    }
    return davez;
}

unsigned int contar_jukefila(jukefila* fila) {
    unsigned int count = 0; 
    //Se não tem nenhum elemento na fila.
    if (fila->inicio == NULL) {
        return count;
    }
    else {
        struct pedido *aux = fila->inicio;
        count++;
        while (aux ->proximo != NULL) {
            count++;
            aux = aux->proximo;
        }
        return count;
    }
}

void destruir_jukefila(jukefila *fila) {
    if (fila->inicio == NULL) {
        free(fila);
        return;
    }
    else {
        struct pedido *aux = fila->inicio;
        while (aux != NULL) {
            struct pedido *proxi = aux->proximo;
            if (proxi != NULL) {
                aux->proximo->anterior = NULL;
                fila->inicio = aux->proximo;
            }
            destruir_pedido(aux);
            aux = proxi;
        }
        free(fila);
    }


}
