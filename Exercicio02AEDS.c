#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

int main() {
    int numProdutos;
    Produto *produtos;
    int indiceMaiorPreco = 0;
    int indiceMaiorQuantidade = 0;

    printf("Informe o n�mero de produtos a serem cadastrados: ");
    scanf("%d", &numProdutos);

    produtos = (Produto *)malloc(numProdutos * sizeof(Produto));

    if (produtos == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }

    for (int i = 0; i < numProdutos; i++) {
        printf("\nCadastro do produto %d:\n", i + 1);
        printf("C�digo: ");
        scanf("%d", &produtos[i].codigo);
        getchar();

        printf("Nome: ");
        fgets(produtos[i].nome, 50, stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Quantidade dispon�vel: ");
        scanf("%d", &produtos[i].quantidade);

        printf("Pre�o de venda: ");
        scanf("%f", &produtos[i].preco);

        if (produtos[i].preco > produtos[indiceMaiorPreco].preco) {
            indiceMaiorPreco = i;
        }
        if (produtos[i].quantidade > produtos[indiceMaiorQuantidade].quantidade) {
            indiceMaiorQuantidade = i;
        }
    }

    printf("\nDados dos produtos cadastrados:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("C�digo: %d\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Quantidade dispon�vel: %d\n", produtos[i].quantidade);
        printf("Pre�o de venda: %.2f\n", produtos[i].preco);
    }

    printf("\nProduto com o maior pre�o de venda:\n");
    printf("C�digo: %d\n", produtos[indiceMaiorPreco].codigo);
    printf("Nome: %s\n", produtos[indiceMaiorPreco].nome);
    printf("Pre�o de venda: %.2f\n", produtos[indiceMaiorPreco].preco);

    printf("\nProduto com a maior quantidade dispon�vel no estoque:\n");
    printf("C�digo: %d\n", produtos[indiceMaiorQuantidade].codigo);
    printf("Nome: %s\n", produtos[indiceMaiorQuantidade].nome);
    printf("Quantidade dispon�vel: %d\n", produtos[indiceMaiorQuantidade].quantidade);

    free(produtos);

    return 0;
}
