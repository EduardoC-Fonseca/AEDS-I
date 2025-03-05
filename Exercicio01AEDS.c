#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    int anoNascimento;
} Aluno;

int main() {
    int numAlunos;
    Aluno *alunos;

    printf("Informe o número de alunos a serem cadastrados: ");
    scanf("%d", &numAlunos);

    alunos = (Aluno *)malloc(numAlunos * sizeof(Aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < numAlunos; i++) {
        printf("\nCadastro do aluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        getchar();

        printf("Nome: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Ano de nascimento: ");
        scanf("%d", &alunos[i].anoNascimento);
    }

    printf("\nDados dos alunos cadastrados:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Ano de Nascimento: %d\n", alunos[i].anoNascimento);
    }

    free(alunos);

    return 0;
}
