/*
O código abaixo realiza a impressão do vetor na ordem inversa.
1 - comente o código
2 - faça uma modificação para que seja possível inserir um vetor de n elementos.
*/

#include <stdio.h>

int main() {
    //faz com que o usuario digite o tamanho do vetor
    int n;
    scanf("%d",&n);
    int vetor[n];
    
    int i, temp,k;
    // lê cada elemento do vetor
    for (i = 0; i < n; i++) 
    {
        scanf("%d",&k);
        vetor[i] = k;
    }
    
    
    for (i = 0; i < n / 2; i++) {
        temp = vetor[i];
        // Troca o elemento na posição 'i' com o elemento na posição 'n - i - 1'
        vetor[i] = vetor[n - i - 1];
        vetor[n - i - 1] = temp;
    }
    //imprime o  vetor agora invertido
    printf("Vetor invertido:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}