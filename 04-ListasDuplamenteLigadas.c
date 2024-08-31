/*
O código apresenta uma lista duplamente ligada com operações básicas para inserir, deletar e imprimir.

1 - comente o código.
2 - Modifique a operação de inserção de dados, para que o usuário seja capaz de inserir valores para a lista.
3 - Faça uma operação de buscar por um valor específico, informado pelo usuário, onde o programa deve apresentar se o valor foi encontrado e, em caso afirmativo, exibir detalhes(vizinhos) do nó correspondente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void deleteNode(Node* node) {
    if (node == head)
        head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    free(node);
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void buscar(int n){
    int i=0;
    Node* temp = head;
    //enquanto temp for diferente de NULL
    while(temp) {
        if (temp->data == n) {
            printf("Valor encontrado\n");

            if (temp->prev) 
                printf("O seu antecessor é: %d\n", temp->prev->data);
            else 
                printf("Não há antecessor (é o primeiro nó)\n");

            if (temp->next) 
                printf("O seu sucessor é: %d\n", temp->next->data);
            else 
                printf("Não há sucessor (é o último nó)\n");

            i = 1;
            break;
        }
        temp = temp->next;
    }
    if (i!= 1) printf("Valor não encontrado\n");
}

int main() {
    int n,tamanho;
    int i ;
    //pergunta o tamanho da lista
    printf("Digite quantos numeros devem ser inseridos\n");
    scanf("%d",&tamanho);
    //insere os numeros
    for(i = 0;i<tamanho;i++){
        scanf("%d",&n);
        insertFront(n);
    }
    //busca um certo valor
    printf("Digite um valor para ser buscado:\n");
    scanf("%d",&n);
    buscar(n);

    printList();
    return 0;
}