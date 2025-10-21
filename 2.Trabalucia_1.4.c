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
    printf("\n\t|\tGerenciamento do atendimento da Clínica Veterinária.\t    |");
    printf("\n\t|\t\t\t\t\t\t\t\t    |");
    printf("\n\t|-------------------------------------------------------------------|\n\n\t");
    system("pause");

    while(encerrador < 1)
    {
        system("cls");
        printf("\n\n\tEscolha uma das opções abaixo: \n");
        printf("\n\t\t1. Inserir um pet na fila de atendimento.");
        printf("\n\t\t2. Atender o Pet.");
        printf("\n\t\t3. Buscar um pet pelo nome e/ou ID.");
        printf("\n\t\t4. Imprimir um Relatório com todos os pets na fila de atendimento tanto de emergência quanto normal.");
        printf("\n\t\t5. Imprimir o próximo pet a ser atendido.");
        printf("\n\t\t6. Imprimir todos os pets que já foram atendidos.");
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

                    printf("\n\n\tO pet a ser inserido na fila é de emergência? 0 para SIM, 1 para NÃO.");
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

                            printf("\n\tEspécie: ");
                            fflush(stdin);
                            gets(especie);

                            printf("\n\tIdade: ");
                            scanf("%d",&idade);

                            printf("\n\tData de Nascimento: ");
                            printf("\n\n\t\tDia: ");
                            scanf("%d",&dia);
                            printf("\n\t\tMês: ");
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

                            printf("\n\tEspécie: ");
                            fflush(stdin);
                            gets(especie);

                            printf("\n\tIdade: ");
                            scanf("%d",&idade);

                            printf("\n\tData de Nascimento: ");
                            printf("\n\n\t\tDia: ");
                            scanf("%d",&dia);
                            printf("\n\t\tMês: ");
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
                        printf("\n\n\tEssa escolha não existe.\n\n\t");
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
                    printf("\n\n\tEsse atendimento é de EMERGÊNCIA!");
                    imprimeFila(Imprimir);
                    InsereFila(Atendidos,Imprimir->info.ID,Imprimir->info.idade,Imprimir->info.nome,Imprimir->info.especie,Imprimir->info.nascimento.dia,Imprimir->info.nascimento.mes,Imprimir->info.nascimento.ano,Imprimir->info.prioridade);
                }
                else
                {
                    if(VaziaFila(Normal) < 1)
                    {
                        Imprimir = RetiraFila(Normal);
                        printf("\n\n\tEsse é um atendimeno NORMAL.");
                        imprimeFila(Imprimir);
                        InsereFila(Atendidos,Imprimir->info.ID,Imprimir->info.idade,Imprimir->info.nome,Imprimir->info.especie,Imprimir->info.nascimento.dia,Imprimir->info.nascimento.mes,Imprimir->info.nascimento.ano,Imprimir->info.prioridade);
                    }
                    else
                    {
                        printf("\n\n\tNão há Pet para ser atendido no momento!");
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
                    printf("\n\n\tEssa escolha não existe.\n\n\t");
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
                    printf("\n\n\tO(s) Pet(s) que procura se encontra(m) com as seguintes informações:\n");
                    buscaListaNome(Emergencia,Normal,Atendidos,nome);
                }
                else
                {
                    printf("\n\n\tDigite o ID do Pet que deseja encontrar: ");
                    scanf("%d",&ID);

                    system("cls");
                    printf("\n\n\tO Pet que procura se encontra com as seguintes informações:\n");
                    buscaListaID(Emergencia,Normal,Atendidos,ID);
                }
                printf("\n\n\t");
                system("pause");

                break;
            }
        case 4:
            {
                system("cls");

                printf("\n\n\tEsses são os Pets a serem atendidos com as seguintes informações: ");
                printf("\n\tID | Nome | Espécie | Idade | Data de Nascimento | Prioridade ( Emergência = 0 e Normal = 1)\n");
                imprimeRelatorio(Emergencia,Normal);
                printf("\n\n\n\t");
                system("pause");

                break;
            }
        case 5:
            {
                system("cls");

                printf("\n\n\tEste é o próximo Pet a ser atendido: ");
                if(VaziaFila(Emergencia) < 1)
                {
                    printf("\n\n\t\tEste atendimento é de EMERGÊNCIA!");
                    imprimeFila(Emergencia->ini);
                }
                else
                {
                    if(VaziaFila(Normal) < 1)
                    {
                        printf("\n\n\t\tEste atendimento é NORMAL.");
                        imprimeFila(Normal->ini);
                    }
                    else
                    {
                        printf("\n\n\tA Fila está VAZIA no momento!");
                    }
                }
                printf("\n\n\t");
                system("pause");

                break;
            }
        case 6:
            {
                system("cls");

                printf("\n\n\tEsses Pets a seguir já foram atendidos com as seguintes informações: ");
                printf("\n\tID | Nome | Espécie | Idade | Prioridade ( Emergência = 0 e Normal = 1)\n");
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
            printf("\n\n\tEsta opção não existe!\n\n\t");

            system("pause");
        }
    }

    system("cls");
    printf("\n\n\tObrigado por utilizar o Gerenciamento de Atendimento Online da Clínica Veterinária.\n\n");

    return 0;
}
