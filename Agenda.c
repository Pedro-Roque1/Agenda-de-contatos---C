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
    int i, encontrado = 0;
    int indiceAgenda = 0;
    char pesq[60];

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

                fflush(stdin);

                printf("\n Cadastrado com sucesso!\n");

            break;

            case 2:
                printf("\n-----EXCLUIR CONTATO-----\n");
                
                printf("\nInforme o Id do contato:");
                scanf("%d, ", &cod);

                printf("\n--------------------------------\n");
                printf("\n Nome: %s", contatos[cod].nome);
                printf("\n Telefone: %s", contatos[cod].fone);
                printf("\n Tipo de contato: %s", contatos[cod].tipo);
                printf("\n--------------------------------\n");

                printf("\nDeseja excluir o contato? s/n:");

                if (getch() == 's')
                {
                    for (i = cod; i < indiceAgenda; i++)
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
                scanf("%i", &cod);

                printf("\n--------------------------------\n");
                printf("\n Nome: %s", contatos[cod].nome);
                printf("\n Telefone: %s", contatos[cod].fone);
                printf("\n Tipo de contato: %s", contatos[cod].tipo);
                printf("\n--------------------------------\n");

                printf("\nDeseja alterar o contato? s/n: \n");

                if (getch() == 's')
                {
                    for (i = cod; i < indiceAgenda; i++)
                    {
                        fflush(stdin);
                        printf("Digite o nome:");
                        gets(contatos[i].nome);

                        fflush(stdin);
                        printf("Digite o telefone:");
                        gets(contatos[i].fone);

                        fflush(stdin);
                        printf("Digite o tipo do contato: (pessoal ou profissional): ");
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
                    printf("Id: %d", i);
                    printf("\nNome: %s", contatos[i].nome);
                    printf("\nTelefone: %s", contatos[i].fone);
                    printf("\nTipo de contato: %s", contatos[i].tipo);
                    printf("\n--------------------------------\n");
                }

                system("pause");

            break;

            case 5:
                system("cls");
                printf("\n----- CONSULTAR UM CONTATO POR NOME -----");
                fflush(stdin);
                printf("\nBuscar:");
                gets(pesq);

                for(i = 0; i < indiceAgenda; i++) {
                    if (strcmp(pesq, contatos[i].nome) == 0) {
                        fflush(stdin);
                        printf("\n--------------------------------\n");
                        printf("\n Id: %d", i);
                        printf("\n Nome: %s", contatos[i].nome);
                        printf("\n Telefone: %s", contatos[i].fone);
                        printf("\n Tipo de contato: %s", contatos[i].tipo);
                        printf("\n--------------------------------\n");

                        encontrado = 1;
                    }
                }

                fflush(stdin);
                if (encontrado == 0) 
                    printf("\n Nenhum registro encontrado!\n\n");

                printf("\n");
                system("pause");

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