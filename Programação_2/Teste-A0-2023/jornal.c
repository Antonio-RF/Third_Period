#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void requisita(char *titulo, char *texto, int *tipo){
    getchar();
    printf("\nDigite o título: ");
    fgets(titulo, 33, stdin);
    printf("Digite o texto: ");
    fgets(texto, 513, stdin);
    printf("Digite o tipo (0=Breaknews/1=Informe): ");
    scanf("%d", tipo);
}

int main() {
    int input1;
    printf("- (1) Cadastrar notícia\n");
    printf("- (2) Fechar edição\n");
    printf("- (3) Sair\n");
    scanf("%d", &input1);

    //Criando as duas filas.
    struct fila_t *break_news = cria_fila();
    struct fila_t *informe = cria_fila();

    int controle = 1;
    while (controle != 0) {
        switch(input1) {
            //Entrada = 1.
            case 1:
                char titulo[33], texto[513];
                int tipo;
                requisita(titulo, texto, &tipo);
                //Criando a notícia a partir da entrada do usuário:
                struct nodo_t *noticia = cria_nodo(titulo, texto);
                //breaknews e informe sendo inseridas.
                if (tipo == 0)
                    fila_insere(noticia, break_news);
                else if (tipo == 1)
                    fila_insere(noticia, informe);
                else 
                    return -1;
                break;

            //Entrada = 2.
            case 2:
                break;

            //Entrada = 3.
            case 3:
                controle = 0;
                break;
        }
        printf("\n- (1) Cadastrar notícia\n");
        printf("- (2) Fechar edição\n");
        printf("- (3) Sair\n");
        scanf("%d", &input1);
    }
}