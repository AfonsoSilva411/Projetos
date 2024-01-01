#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int id;
    int quantidade;
    float preco;
    int quantidadeNoCarrinho;  // Novo campo para armazenar a quantidade escolhida
} Produto;

int produtoJaExistente(Produto* produtos, int numProdutos, const char* nome) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            return i;  // Retorna o índice do produto encontrado
        }
    }
    return -1;  // Produto não existe
}

void mostrarCarrinho(Produto* carrinho, int numItensCarrinho) {
    printf("Produtos no carrinho:\n");
    for (int i = 0; i < numItensCarrinho; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", carrinho[i].nome);
        printf("ID: %d\n", carrinho[i].id);
        printf("Quantidade no Carrinho: %d\n", carrinho[i].quantidadeNoCarrinho);
        printf("Preco unitario: %.2f\n", carrinho[i].preco);
        printf("Total: %.2f\n", carrinho[i].preco * carrinho[i].quantidadeNoCarrinho);
        printf("\n");
    }
}

int main() {
    int op1;
    int i = 0;
    Produto produtos[100];
    Produto carrinho[100];
    int numItensCarrinho = 0;

    do {
        // Display the menu options
        printf("\nEscolha uma opcao:\n");
        printf("1. Adicionar produto\n");
        printf("2. Mostrar produtos\n");
        printf("3. Comprar produtos\n");
        printf("4. Mostrar carrinho\n");
        printf("5. Sair\n");

        // Solicitação da escolha do usuário
        scanf("%d", &op1);

        switch (op1) {
        case 1:
            // Adiciona um novo produto ao vetor
            if (i < 100) {
                system("cls");
                printf("Adicione o produto desejado:\n");

                // Ler o nome do produto
                scanf("%s", produtos[i].nome);

                // Verificar se o produto já existe
                int indiceProdutoExistente = produtoJaExistente(produtos, i, produtos[i].nome);

                if (indiceProdutoExistente != -1) {
                    printf("Produto com o mesmo nome ja existe. Escolha um nome diferente.\n");
                    break;
                }

                // Continuar com a leitura dos outros atributos
                printf("Adicione o id desejado:\n");
                scanf("%d", &produtos[i].id);
                printf("Adicione a quantidade desejada:\n");
                scanf("%d", &produtos[i].quantidade);
                printf("Adicione o preco desejado:\n");
                scanf("%f", &produtos[i].preco);
                produtos[i].quantidadeNoCarrinho = 0;  // Inicializa a quantidade no carrinho
                i++;
            }
            else {
                system("cls");
                printf("O vetor de produtos esta cheio.\n");
            }
            break;
        case 2:
            // Mostra todos os produtos no vetor
            system("cls");
            printf("Produtos cadastrados:\n");
            for (int j = 0; j < i; j++) {
                printf("Produto %d:\n", j + 1);
                printf("Nome: %s\n", produtos[j].nome);
                printf("ID: %d\n", produtos[j].id);
                printf("Quantidade: %d\n", produtos[j].quantidade);
                printf("Preco: %.2f\n", produtos[j].preco);
                printf("\n");
            }
            break;
        case 3:
            // Comprar produtos
            system("cls");
            printf("Digite o ID do produto que deseja comprar:\n");
            int idCompra;
            scanf("%d", &idCompra);

            // Verifica se o ID é válido
            if (idCompra < 1 || idCompra > i) {
                printf("ID de produto invalido.\n");
                break;
            }

            // Verifica a quantidade disponível do produto
            if (produtos[idCompra - 1].quantidade > 0) {
                // Adiciona o produto ao carrinho
                carrinho[numItensCarrinho] = produtos[idCompra - 1];
                carrinho[numItensCarrinho].quantidadeNoCarrinho++;
                produtos[idCompra - 1].quantidade--;  // Reduz a quantidade disponível
                numItensCarrinho++;

                printf("Produto adicionado ao carrinho.\n");
            }
            else {
                printf("Produto sem estoque disponível.\n");
            }
            break;
        case 4:
            // Mostra o carrinho
            system("cls");
            mostrarCarrinho(carrinho, numItensCarrinho);
            break;
        case 5:
            // Sai do programa
            system("cls");
            printf("A sair do programa.\n");
            break;
        default:
            // Opção inválida
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (op1 != 5);

    return 0;
}