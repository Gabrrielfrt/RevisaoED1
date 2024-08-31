/*
O código abaixo recebe do usuário elementos que são inseridos em uma matriz 3x3, em seguida, imprime a soma de sua diagonal principal.
- faça uma modificação para que seja possível dinamizar o tamanho da matriz (utilizar alocação dinâmica de memória usando malloc)
*/

#include <stdio.h>
#include <stdlib.h> //necessário para utilizar o malloc

int main() {
    int **matriz;
    int i, j,n, soma = 0;
    
    printf("Digite o tamanho da matriz quadrada (n x n): ");
    scanf("%d", &n);
    
    // Alocação dinâmica de memória para as colunas da matriz
    matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    //mesmo código porém agora com o tamanho como uma variável 
    printf("Insira os elementos da matriz %dx%d\n",n,n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}