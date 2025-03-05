#include <stdio.h>

typedef struct registro{
    char nome[20];
    int matricula;
    int anoNascimento;
}registro;


int main(){

    registro aluno[20];
    int i;

    for(i=0; i<20; i++){
        printf("Digite o seu nome-> ");
        scanf("%s", aluno[i].nome);

        printf("Digite sua matricula-> ");
        scanf("%d", &aluno[i].matricula);

        printf("Digite o ano de seu nascimento-> ");
        scanf("%d", &aluno[i].anoNascimento);

        printf("Meu nome eh %s, minha matricula eh %d e nasci em %d", aluno[i].nome, aluno[i].matricula, aluno[i].anoNascimento);
    }

return 0;}
