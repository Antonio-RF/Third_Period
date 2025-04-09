#include <stdlib.h>
#include <stdio.h>
#include "redblack.h"

struct nodo *cria_nodo(struct nodo *no, int chave) {
	struct nodo *n = malloc(sizeof(struct nodo));
	n->chave = chave;
	n->esq = NULL;
	n->dir = NULL;
	//Se o nó que foi passado é NULL = Não tem pai.
	//Se não for NULL = Juntar pai e filho:
	if (no == NULL)
		n->pai = NULL;
	else
		n->pai = no;
	return n;
}

struct nodo *inserir(struct nodo *no, int chave) {
	if (no == NULL) 
		return cria_nodo(no, chave);
	if (no->chave > chave)
		return inserir(no->esq, chave);
	// AINDA NÃO DEFINI QUAL LADO VAI SE FOR IGUAL!!!
	if (no->chave < chave) 
		return inserir(no->dir, chave);
	return no;
}

void print_tree(struct nodo *no) {
	if (no == NULL)
		return
	print_tree(no->esq);
	printf("%.d", no->chave);
	print_tree(no->dir);
}

int main() {
	struct nodo *raiz = cria_nodo(NULL, 10);
	inserir(raiz, 7);
	inserir(raiz, 11);
	inserir(raiz, 6);
	inserir(raiz, 8);
	print_tree(raiz);
}
