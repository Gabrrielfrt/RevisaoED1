/*
O código abaixo apresenta a implementação de uma lista linear.

Para esse exemplo, faça:
- Implemente funções adicionais como buscar(int elemento) para encontrar a posição de um elemento na lista.
ou 
- Adicione métodos para inverter a lista, encontrar o máximo/mínimo, ou ordenar a lista.
*/

#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void buscar(int num){
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] ==  num){
            printf("Elemento encontrado");
            printf("\n");
            break;
        }
    printf("Elemento não encontrado");
    printf("\n");
    }
}

void inverte(){
    int i,temp;
        for (i = 0; i < tamanho / 2; i++) {
        temp = lista[i];
        lista[i] = lista[tamanho - i - 1];
        lista[tamanho - i - 1] = temp;
    }
}

void ordenar(){
    int i, j, temp;
    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            if (lista[j] > lista[j+1]) {
                // Troca os elementos
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
}


void max(){
    int i;
    int maior = lista[0]; 

    for (i = 1; i < tamanho; i++) {
        if (lista[i] > maior) {
            maior = lista[i]; 
        }
    }
    printf("%d\n",maior);

}

void min(){
    int i;
    int menor = lista[0]; 

    for (i = 1; i < tamanho; i++) {
        if (lista[i] < menor) {
            menor = lista[i]; 
        }
    }
    printf("%d\n",menor);
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    imprimir();
    remover(1);
    imprimir();
    buscar(10);
    inverte();
    imprimir();
    ordenar();
    max();
    min();
    
    return 0;
}