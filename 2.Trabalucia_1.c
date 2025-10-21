#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fila.h"
#include <locale.h>
#define n 50
#define e 30

void CabecalhoImprimir()
{
    int largura = 80;

    system("cls");

    PrintCentro("==================================================================", largura);
    PrintCentro("|                  Clinica Veterinaria - Bem-vindo!              |", largura);
    PrintCentro("==================================================================", largura);
    printf("\n");

    PrintCentro("      / \\__", largura);
    PrintCentro("     (    @\\___", largura);
    PrintCentro("     /         O", largura);
    PrintCentro("    /   (_____/", largura);
    PrintCentro("   /_____/   U", largura);
    printf("\n");

    PrintCentro("      |\\__/,|   (`\\", largura);
    PrintCentro("      |o o  |__)   )", largura);
    PrintCentro("      ( T   )  \\  /", largura);
    PrintCentro("     .^`-^-'`-._\\/", largura);
    printf("\n");

    PrintCentro("Gerenciamento do Atendimento da Clinica Veterinaria", largura);
    PrintCentro("------------------------------------------------------------------", largura);

    printf("\n\t");
    system("pause");
}

void ImprimeMenu()
{
    system("cls");
    printf("\n\n\t==~~~~---~~~~==Menu==~~~~---~~~~==");
    printf("\n\n\tEscolha uma das op��es abaixo: \n");
    printf("\n\t1. Inserir um pet na fila de atendimento.");
    printf("\n\t2. Atender o Pet.");
    printf("\n\t3. Buscar um pet pelo nome e/ou ID.");
    printf("\n\t4. Imprimir um Relat�rio com todos os pets na fila de atendimento tanto de emerg�ncia quanto normal.");
    printf("\n\t5. Imprimir o pr�ximo pet a ser atendido.");
    printf("\n\t6. Imprimir todos os pets que j� foram atendidos.");
    printf("\n\t7. Finalizar o sistema.");
}

void EscolhaErrada()
{
    system("cls");
    printf("\n\n\tEssa escolha n�o existe.\n\n\t");
    system("pause");
}

void Escolha1(Fila *Emergencia,Fila *Normal,Fila *Atendidos)
{
    int menu,ID,idade,dia,mes,ano,aux=0,resultado;
    char nome[n],especie[e];
    while(aux < 1)
    {
        do
        {
            system("cls");

            printf("\n\n\tO pet a ser inserido na fila � de emerg�ncia? 0 para SIM, 1 para N�O.");
            printf("\n\tEscolha: ");
            resultado = scanf("%d",&menu);

            if(resultado != 1)
            {
                while(getchar() != '\n');
                {
                    EscolhaErrada();
                }
            }
        }while(resultado != 1);

        PedeData(nome,especie,&idade,&dia,&mes,&ano);

        ID = randomID(Emergencia,Normal,Atendidos);

        switch(menu)
        {
        case 0:
            {
                InsereFila(Emergencia,ID,idade,nome,especie,dia,mes,ano,menu);

                aux++;
                break;
            }
        case 1:
            {
                InsereFila(Normal,ID,idade,nome,especie,dia,mes,ano,menu);

                aux++;
                break;
            }
                    default:
                        system("cls");
                        printf("\n\n\tEssa escolha n�o existe.\n\n\t");
                    }
                    system("pause");
                }
}

void Escolha2(Fila *Emergencia,Fila *Normal,Fila *Atendidos)
{
    Nos *Imprimir;

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
}

void Escolha3(Fila *Emergencia,Fila *Normal,Fila *Atendidos)
{
    int ID;
    char nome[n];
    system("cls");

    printf("\n\n\tDeseja buscar pelo nome ou ID?");
    printf("\n\tEscolha: ");
    fflush(stdin);
    gets(nome);
    CorrigirString(nome);

    while((strcmp(nome,"Nome") != 0) && (strcmp(nome,"Id") != 0))
    {
        EscolhaErrada();

        system("cls");
        printf("\n\n\tDeseja buscar pelo nome ou ID?");
        printf("\n\tEscolha: ");
        fflush(stdin);
        gets(nome);
    }

    system("cls");
    if(strcmp(nome,"Nome") == 0)
    {
        printf("\n\n\tDigite o NOME do Pet que deseja encontrar: ");
        fflush(stdin);
        gets(nome);
        CorrigirString(nome);

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
}

void Escolha4(Fila *Emergencia,Fila *Normal)
{
    system("cls");

    printf("\n\n\tEsses s�o os Pets a serem atendidos com as seguintes informa��es: ");
    printf("\n\tID | Nome | Esp�cie | Idade | Data de Nascimento | Prioridade ( Emerg�ncia = 0 e Normal = 1)\n");
    imprimeRelatorio(Emergencia,Normal);
    printf("\n\n\n\t");
    system("pause");
}

void Escolha5(Fila *Emergencia,Fila *Normal)
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
}

void Escolha6(Fila *Atendidos)
{
    system("cls");

    printf("\n\n\tEsses Pets a seguir j� foram atendidos com as seguintes informa��es: ");
    printf("\n\tID | Nome | Esp�cie | Idade | Prioridade ( Emerg�ncia = 0 e Normal = 1)\n");
    imprimeAtendidos(Atendidos);
    printf("\n\n\n\t");
    system("pause");
}

void EsvaziarFilas(Fila *Emergencia,Fila *Normal,Fila *Atendidos)
{
    Emergencia = liberaFila(Emergencia);
    Normal = liberaFila(Normal);
    Atendidos = liberaFila(Atendidos);
}

void RodapeEncerramento()
{
    int largura = 80;

    system("cls");

    PrintCentro("==================================================================", largura);
    PrintCentro("|          Obrigado por utilizar nossa Clinica Veterinaria!      |", largura);
    PrintCentro("==================================================================", largura);
    printf("\n");

    PrintCentro("          / \\__", largura);
    PrintCentro("         (    @\\___", largura);
    PrintCentro("         /         O", largura);
    PrintCentro("        /   (_____/", largura);
    PrintCentro("       /_____/   U", largura);
    PrintCentro("~ Au Au! Ate logo! ~", largura);
    printf("\n");

    PrintCentro("      |\\__/,|   (`\\", largura);
    PrintCentro("      |o o  |__)   )", largura);
    PrintCentro("      ( T   )  \\  /", largura);
    PrintCentro("     .^`-^-'`-._\\/", largura);
    PrintCentro("~ Miau! Volte sempre! ~", largura);
    printf("\n");

    PrintCentro("------------------------------------------------------------------", largura);
    PrintCentro("     Sistema desenvolvido para gerenciamento de atendimentos      ", largura);
    PrintCentro("------------------------------------------------------------------", largura);

    printf("\n\t");
}


int main()
{
    setlocale(LC_ALL,"Portuguese");

    int encerrador=0,menu,resultado;
    Fila *Normal = CriaFila();
    Fila *Emergencia = CriaFila();
    Fila *Atendidos = CriaFila();

    CabecalhoImprimir();

    while(encerrador < 1)
    {
        do
        {
            ImprimeMenu();

            printf("\n\n\tEscolha: ");
            resultado = scanf("%d",&menu);

            if(resultado != 1)
            {
                while(getchar() != '\n');
                {
                    EscolhaErrada();
                }
            }
        }while(resultado != 1);

        switch(menu)
        {
        case 1:
            {
                Escolha1(Emergencia,Normal,Atendidos);

                break;
            }
        case 2:
            {
                Escolha2(Emergencia,Normal,Atendidos);

                break;
            }
        case 3:
            {
                Escolha3(Emergencia,Normal,Atendidos);

                break;
            }
        case 4:
            {
                Escolha4(Emergencia,Normal);

                break;
            }
        case 5:
            {
                Escolha5(Emergencia,Normal);

                break;
            }
        case 6:
            {
                Escolha6(Atendidos);

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

    EsvaziarFilas(Emergencia,Normal,Atendidos);

    RodapeEncerramento();

    return 0;
}
