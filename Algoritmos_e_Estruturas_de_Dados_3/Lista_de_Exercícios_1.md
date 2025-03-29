# Lista de Exercícios - Árvores Binárias de Busca

## 1) Representação de Árvore Binária de Busca

Represente a seguinte árvore binária de busca usando a notação com parênteses aninhados:

      20
     /  \
    10    30
         /  \
        25   35
       /  \
     21    27



## 2) Estrutura de Dados para Árvore Binária de Busca

Defina uma estrutura de dados para representar uma árvore binária de busca, armazenando um conteúdo (char) e uma chave (int).

## 3) Vantagens e Desvantagens de Diferentes Implementações

Descreva vantagens e desvantagens de implementar árvores binárias de busca usando vetores ou ponteiros.

## 4) Inserção Iterativa em Árvore Binária de Busca

Implemente uma função para inserção em uma árvore binária de busca usando o método iterativo (sem recursão). Não é necessário ter ponteiro "pai".

## 5) Cálculo da Altura de uma Árvore Binária de Busca

Implemente uma função que calcule a altura de uma árvore binária de busca. Qual é o tipo de percurso usado na implementação?

## 6) Construção e Manipulação de Árvore Binária de Busca

Mostre passo a passo a árvore binária de busca resultante das seguintes operações:

### a) Inserção de elementos na árvore:

Construa a árvore binária de busca resultante da inserção dos valores: `5, 9, 7, 4, 12, 15, 11`.

### b) Avaliação AVL:

A árvore resultante pode ser considerada uma árvore AVL? Justifique.

### c) Remoção de um nó:

Remova o nó `9` e apresente a árvore resultante.

## 7) Inserção em Árvore 2-3-4

Dada a seguinte árvore 2-3-4:

       20
      /  \
    17  22 - 24 - 29



Insira a chave `25` e mostre a árvore resultante, garantindo que continue sendo uma árvore 2-3-4.

## 8) Vantagem de Inclusão na Raiz

Explique uma vantagem de incluir elementos na raiz de uma árvore binária de busca.

## 9) Construção de Árvore Rubro-Negra (RN)

Crie uma árvore rubro-negra (RN), incluindo as chaves `20, 7, 12, 30, 22`, nesta ordem. Mostre a árvore resultante após cada inserção, aplicando as regras de ajuste corretamente.

## 10) Conversão de Árvore RN para Árvore 2-3-4

Usando a árvore rubro-negra criada no exercício anterior, gere a árvore 2-3-4 correspondente.

## 11) Inserção em Árvore B

Dada a seguinte árvore B de grau mínimo `t = 2`:

### a) Inserção de chaves

Inclua as chaves `20, 21, 28 e 31`, nesta ordem, e mostre a árvore B resultante após cada inserção. A árvore poderá ser dividida antes da inclusão para acomodar as chaves corretamente.

                         26
                     /        \
        12 - 17 - 22             29
       /     |    |  \         /     \
    7 - 9   13  18-19 23-24   27    30-34-35
       /  \
     21    27
    

### b) Restrição na inclusão direta na raiz

Por que não podemos incluir o elemento `25` diretamente na raiz, mesmo que o nó possua espaços livres?

## 12) Inserção de uma Chave na Raiz da Árvore

Considere a estrutura abaixo para representar uma árvore binária de busca:

    typedef struct tNo {

    int chave;

    tNo *esq, *dir, *pai;

    } tNo;

Escreva um algoritmo em C ou pseudocódigo semelhante que insira uma nova chave na raiz de uma árvore binária de busca. O algoritmo deve receber um ponteiro para a raiz da árvore e uma chave e retornar um ponteiro para a nova raiz após a inclusão.

As seguintes funções podem ser utilizadas:

    tNo* rotacaoDir(tNo *no)

    tNo* rotacaoEsq(tNo *no)

estas funções recebem como parâmetro um ponteiro para um nó, raiz de uma subárvore, e retornam um ponteiro para a nova raiz da subárvore após a rotação para direita ou para a esquerda, respectivamente.

## 13) Validação de Árvore Rubro-Negra

Considere uma árvore binária de busca onde os nós contém um campo informando a cor do nó (preto ou vermelho). Implemente uma função de validação que receba uma árvore binária com estas características e verifique se esta árvore é ou não uma árvore rubro-negra.
