#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    int coluna = 1;

    char string[] = {"Ana,25,Recife"};
    char *token = strtok(string, ","); //aqui token aponta para Ana

    while(token != NULL){
        printf("Coluna %d: %s\n", coluna, token);
        token = strtok(NULL, ","); //chamamos pra NULL pra ele partir de onde parou na string, nao do comeco de novo
        coluna ++;
    }
    
    return 0;
}
