#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fila.3.h"
#include <locale.h>
#define n 50
#define e 30


int main()
{
    setlocale(LC_ALL,"Portuguese");

    int encerrador=0,menu,ID,idade,dia,mes,ano,aux=0;
    char nome[n],especie[e];
    Fila *Normal = CriaFila();
    Fila *Emergencia = CriaFila();
    Fila *Atendidos = CriaFila();
    Nos *Imprimir;

    printf("\n\n\t|-------------------------------------------------------------------|");
    printf("\n\t|\t\t\t\t\t\t\t\t    |");
    printf("\n\t|\tGerenciamento do atendimento da Cl�nica Veterin�ria.\t    |");
    printf("\n\t|\t\t\t\t\t\t\t\t    |");
    printf("\n\t|-------------------------------------------------------------------|\n\n\t");
    system("pause");

    while(encerrador < 1)
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
        aux = 0;

        switch(menu)
        {
        case 1:
            {
                while(aux < 1)
                {
                    system("cls");

                    printf("\n\n\tO pet a ser inserido na fila � de emerg�ncia? 0 para SIM, 1 para N�O.");
                    printf("\n\tEscolha: ");
                    scanf("%d",&menu);

                    switch(menu)
                    {
                    case 0:
                        {
                            printf("\n\n\t--------------------------------------------------------------------------------");
                            printf("\n\n\tNome: ");
                            fflush(stdin);
                            gets(nome);

                            printf("\n\tEsp�cie: ");
                            fflush(stdin);
                            gets(especie);

                            printf("\n\tIdade: ");
                            scanf("%d",&idade);

                            printf("\n\tData de Nascimento: ");
                            printf("\n\n\t\tDia: ");
                            scanf("%d",&dia);
                            printf("\n\t\tM�s: ");
                            scanf("%d",&mes);
                            printf("\n\t\tAno: ");
                            scanf("%d",&ano);
                            printf("\n\n\t--------------------------------------------------------------------------------\n\n\t");

                            ID = randomID(Emergencia);

                            InsereFila(Emergencia,ID,idade,nome,especie,dia,mes,ano,menu);

                            aux++;
                            break;
                        }
                    case 1:
                        {
                            printf("\n\n\t--------------------------------------------------------------------------------");
                            printf("\n\n\tNome: ");
                            fflush(stdin);
                            gets(nome);

                            printf("\n\tEsp�cie: ");
                            fflush(stdin);
                            gets(especie);

                            printf("\n\tIdade: ");
                            scanf("%d",&idade);

                            printf("\n\tData de Nascimento: ");
                            printf("\n\n\t\tDia: ");
                            scanf("%d",&dia);
                            printf("\n\t\tM�s: ");
                            scanf("%d",&mes);
                            printf("\n\t\tAno: ");
                            scanf("%d",&ano);
                            printf("\n\n\t--------------------------------------------------------------------------------\n\n\t");

                            ID = randomID(Normal);

                            InsereFila(Normal,ID,idade,nome,especie,dia,mes,ano,menu);

                            aux++;
                            break;
                        }
                    default:
                        system("cls");
                        printf("\n\n\tEssa escolha n�o existe.\n\n\t");
                        system("pause");
                    }
                    system("pause");
                }

                break;
            }
        case 2:
            {
                system("cls");

                if(VaziaFila(Emergencia) < 1)
                {
                    Imprimir = RetiraFila(Emergencia);
                    printf("\n\n\tEsse atendimento � de EMERG�NCIA!");
                    imprimeFila(Imprimir);
                    InsereFila(Atendidos,Imprimir->info.ID,Imprimir->info.idade,Imprimir->info.nome,Imprimir->info.especie,Imprimir->info.nascimento.dia,Imprimir->info.nascimento.mes,Imprimir->info.nascimento.ano,Imprimir->info.prioridade);
                }
                else
                {
                    if(VaziaFila(Normal) < 1)
                    {
                        Imprimir = RetiraFila(Normal);
                        printf("\n\n\tEsse � um atendimeno NORMAL.");
                        imprimeFila(Imprimir);
                        InsereFila(Atendidos,Imprimir->info.ID,Imprimir->info.idade,Imprimir->info.nome,Imprimir->info.especie,Imprimir->info.nascimento.dia,Imprimir->info.nascimento.mes,Imprimir->info.nascimento.ano,Imprimir->info.prioridade);
                    }
                    else
                    {
                        printf("\n\n\tN�o h� Pet para ser atendido no momento!");
                    }
                }

                printf("\n\n\t");
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

                while((strcmp(nome,"nome") != 0) && (strcmp(nome,"ID") != 0))
                {
                    system("cls");
                    printf("\n\n\tEssa escolha n�o existe.\n\n\t");
                    system("pause");

                    system("cls");
                    printf("\n\n\tDeseja buscar pelo nome ou ID?");
                    printf("\n\tEscolha: ");
                    fflush(stdin);
                    gets(nome);
                }

                system("cls");
                if(strcmp(nome,"nome") == 0)
                {
                    printf("\n\n\tDigite o NOME do Pet que deseja encontrar: ");
                    fflush(stdin);
                    gets(nome);

                    system("cls");
                    printf("\n\n\tO(s) Pet(s) que procura se encontra(m) com as seguintes informa��es:\n");
                    buscaListaNome(Emergencia,Normal,Atendidos,nome);
                }
                else
                {
                    printf("\n\n\tDigite o ID do Pet que deseja encontrar: ");
                    scanf("%d",&ID);

                    system("cls");
                    printf("\n\n\tO Pet que procura se encontra com as seguintes informa��es:\n");
                    buscaListaID(Emergencia,Normal,Atendidos,ID);
                }
                printf("\n\n\t");
                system("pause");

                break;
            }
        case 4:
            {
                system("cls");

                printf("\n\n\tEsses s�o os Pets a serem atendidos com as seguintes informa��es: ");
                printf("\n\tID | Nome | Esp�cie | Idade | Data de Nascimento | Prioridade ( Emerg�ncia = 0 e Normal = 1)\n");
                imprimeRelatorio(Emergencia,Normal);
                printf("\n\n\n\t");
                system("pause");

                break;
            }
        case 5:
            {
                system("cls");

                printf("\n\n\tEste � o pr�ximo Pet a ser atendido: ");
                if(VaziaFila(Emergencia) < 1)
                {
                    printf("\n\n\t\tEste atendimento � de EMERG�NCIA!");
                    imprimeFila(Emergencia->ini);
                }
                else
                {
                    if(VaziaFila(Normal) < 1)
                    {
                        printf("\n\n\t\tEste atendimento � NORMAL.");
                        imprimeFila(Normal->ini);
                    }
                    else
                    {
                        printf("\n\n\tA Fila est� VAZIA no momento!");
                    }
                }
                printf("\n\n\t");
                system("pause");

                break;
            }
        case 6:
            {
                system("cls");

                printf("\n\n\tEsses Pets a seguir j� foram atendidos com as seguintes informa��es: ");
                printf("\n\tID | Nome | Esp�cie | Idade | Prioridade ( Emerg�ncia = 0 e Normal = 1)\n");
                imprimeAtendidos(Atendidos);
                printf("\n\n\n\t");
                system("pause");

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

    system("cls");
    printf("\n\n\tObrigado por utilizar o Gerenciamento de Atendimento Online da Cl�nica Veterin�ria.\n\n");

    return 0;
}
