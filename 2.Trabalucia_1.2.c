#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fila.h"
#include <locale.h>
#define n 50
#define e 30


int randomID(Fila *Fila)
{
    Nos *aux = Fila -> ini;
    int rd_num = rand()%(999 - 100 + 1) + 100;

    while(aux != NULL)
    {
        if(aux -> info.ID == rd_num)
        {
            randomID(Fila);
        }

        aux = aux -> prox;
    }

    return rd_num;
}


int main()
{
    setlocale(LC_ALL,"Portuguese");

    int encerrador=0,menu,ID,idade,dia,mes,ano;
    char nome[n],especie[e];
    Fila *Normal = CriaFila();
    Fila *Emergencia = CriaFila();
    Fila *Atendidos = CriaFila();
    Nos *Imprimir;

    printf("\n\n\tGerenciamento do atendimento da Cl�nica Veterin�ria.\n\n\t");
    system("pause");

    while(encerrador == 0)
    {
        system("cls");
        printf("\n\n\tEscolha uma das op��es abaixo: \n");
        printf("\n\t\t1. Inserir um pet na fila de atendimento.");
        printf("\n\t\t2. Atender o Pet.");
        printf("\n\t\t3. Buscar um pet pelo nome e/ou ID.");
        printf("\n\t\t4. Imprimir um Relat�rio com todos os pets na fila de atendimento tanto de emerg�ncia quanto normal.");
        printf("\n\t\t5. Imprimir o pr�ximo pet a ser atendido.");
        printf("\n\t\t6. Imprimir todos os pets que j� foram atendidos.");
        printf("\n\t\t7. Finalizar o sistema.");

        printf("\n\n\tEscolha: ");
        scanf("%d",&menu);

        switch(menu)
        {
        case 1:
            {
                system("cls");

                printf("\n\n\tO pet a ser inserido na fila � de emerg�ncia? 0 para sim, 1 para n�o.");
                printf("\n\tEscolha: ");
                scanf("%d",&menu);

                while((menu != 0) && (menu != 1))
                {
                    system("cls");
                    printf("\n\n\tEssa escolha n�o existe.\n\n\t");
                    system("pause");

                    printf("\n\n\tO pet a ser inserido na fila � de emerg�ncia? 1 para sim, 0 para n�o.");
                    printf("\n\tEscolha: ");
                    scanf("%d",&menu);
                }

                if(menu != 1)
                {
                    printf("--------------------------------------------------------------------------------");
                    printf("\n\n\tNome: ");
                    fflush(stdin);
                    gets(nome);

                    printf("\n\tEsp�cie: ");
                    fflush(stdin);
                    gets(especie);

                    printf("\n\tIdade: ");
                    scanf("%d",&idade);

                    printf("\n\tData Nascimento: ");
                    printf("\n\t\tDia: ");
                    scanf("%d",&dia);
                    printf("\n\t\tM�s: ");
                    scanf("%d",&mes);
                    printf("\n\t\tAno: ");
                    scanf("%d",&ano);
                    printf("--------------------------------------------------------------------------------");


                    InsereFila(Emergencia,idade,nome[n],especie[e],dia,mes,ano,"Emerg�ncia");
                }
                else
                {
                    printf("--------------------------------------------------------------------------------");
                    printf("\n\n\tNome: ");
                    fflush(stdin);
                    gets(nome);

                    printf("\n\tEsp�cie: ");
                    fflush(stdin);
                    gets(especie);

                    printf("\n\tIdade: ");
                    scanf("%d",&idade);

                    printf("\n\tData Nascimento: ");
                    printf("\n\t\tDia: ");
                    scanf("%d",&dia);
                    printf("\n\t\tM�s: ");
                    scanf("%d",&mes);
                    printf("\n\t\tAno: ");
                    scanf("%d",&ano);
                    printf("--------------------------------------------------------------------------------");


                    InsereFila(Normal,idade,nome[n],especie[e],dia,mes,ano,"Normal");
                }

                break;
            }
        case 2:
            {
                system("cls");

                if(VaziaFila(Emergencia) != 1)
                {
                    Imprimir = RetiraFila(Emergencia);
                    printf("\n\n\tEsse atendimento foi de EMERG�NCIA!");
                    imprimeFila(Imprimir);
                    printf("\n\n\t");
                }
                else
                {
                    Imprimir = RetiraFila(Normal);
                    printf("\n\n\tEsse foi um atendimeno NORMAL.");
                    imprimeFila(Imprimir);
                    printf("\n\n\t");
                }

                system("pause");

                break;
            }
        case 3:
            {
                system("cls");

                printf("\n\n\tDeseja buscar pelo nome ou ID?");
                printf("\n\tEscolha: ");
                fflush(stdin);
                gets(nome);

                while((nome != nome) && (nome != ID))
                {
                    system("cls");
                    printf("\n\n\tEssa escolha n�o existe.\n\n\t");
                    system("pause");

                    printf("\n\n\tDeseja buscar pelo nome ou ID?");
                    printf("\n\tEscolha: ");
                    fflush(stdin);
                    gets(nome);
                }

                if(nome == nome)
                {
                    buscaListaNome(Emergencia,Normal,Atendidos,nome[n]);
                }

                break;
            }
        case 4:
            {
                break;
            }
        case 5:
            {
                break;
            }
        case 6:
            {
                break;
            }
        case 7:
            {
                encerrador++;

                break;
            }
        default:
            system("cls");
            printf("\n\n\tEsta op��o n�o existe!\n\n\t");

            system("pause");
        }
    }

    return 0;
}
