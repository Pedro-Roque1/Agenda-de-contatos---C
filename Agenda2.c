#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

struct Contato {
    unsigned short int id;
    char nome[60];
    char fone[15];
    char tipo[12]; // poderia ser um enum 
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    struct Contato contatos[100]; // ver como deixar sem tamanho 
    int opcao;
    int cod;
    int i = 0;

    int indiceAgenda = 0;
    printf("indiceAgenda: %d", indiceAgenda);

    do {
        system("cls");
        printf("----------------------------------------------------------\n");
        printf("AGENDA DE CONTATOS\n");
        printf("----------------------------------------------------------\n");
        printf("1 - Inserir novo contato\n");
        printf("2 - Excluir contato\n");
        printf("3 - Alterar contato\n");
        printf("4 - Listar todos contatos cadastrados\n");
        printf("5 - Localizar contato\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção:\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                do
                {
                    contatos->id = indiceAgenda;

                    fflush(stdin);
                    printf("Digite o nome: ");
                    gets(contatos[indiceAgenda].nome);

                    fflush(stdin);
                    printf("Digite o fone: ");
                    gets(contatos[indiceAgenda].fone);

                    fflush(stdin);
                    printf("Digite o tipo do contato: pessoal ou profissional ");
                    gets(contatos[indiceAgenda].tipo);

                    indiceAgenda++;

                    printf("Cadastrado com sucesso! Voltar ao menu? (s/n)");
                } while (getch() != 's');
                
            break;

            case 2:
                printf("\n-----EXCLUIR CONTATO-----\n");
                printf("\nInforme o Id do contato:");
                scanf("%i",&cod);

                printf("\n Nome:%s", contatos[cod].nome);
                printf("\n Telefone:%s", contatos[cod].fone);
                printf("\n tipo:%s", contatos[cod].tipo);

                printf("\nDeseja excluir o contato? s/n:");

                if (getch() == 's')
                {
                    for (i=cod; i < indiceAgenda; i++)
                    {
                        strcpy(contatos[i].nome, contatos[i+1].nome);
                        strcpy(contatos[i].fone, contatos[i+1].fone);
                        strcpy(contatos[i].tipo, contatos[i+1].tipo);
                    }
                    indiceAgenda --;
                }

            break;

            case 3:
                printf("\n-----ALTERAÇÃO DE CONTATO-----\n");
                printf("\nInforme o Id do contato:");
                scanf("%i",&cod);

                printf("\n Nome:%s", contatos[cod].nome);
                printf("\n Telefone:%s", contatos[cod].fone);
                printf("\n tipo:%s", contatos[cod].tipo);

                printf("\nDeseja alterar o contato? s/n: \n");

                if (getch() == 's')
                {
                    for (i = cod; i < indiceAgenda; i++)
                    {
                        fflush(stdin);
                        printf("Digite o nome:");
                        gets(contatos[i].nome);

                        fflush(stdin);
                        printf("Digite o fone:");
                        gets(contatos[i].fone);

                        fflush(stdin);
                        printf("Digite o tipo do contato: pessoal ou profissional: ");
                        gets(contatos[i].tipo);
                    }
                }

            break;

            case 4:
                system("cls");
                printf("----- LISTAR CONTATOS: ----- \n");
                for (int i = 0; i < indiceAgenda; i++)
                {
                    printf("\n--------------------------------\n");
                    printf("Id: %d",i);
                    printf("\nNome: %s", contatos[i].nome);
                    printf("\nFone: %s", contatos[i].fone);
                    printf("\nTipo de contato: %s", contatos[i].tipo);
                    printf("\n--------------------------------\n");
                }
                system("pause");
            break;

            case 5:
                //localizar();
            break;

            case 6:
                printf("Obrigado por usar a agenda de contatos!\n");
                exit(1);
            break;

            default:
                printf("Opção invalida!\n");
                getch();
            break;
        }
    } while(opcao != 6); // corrigir erro quando digitamos uma string ao invés de número

    return 0;
}