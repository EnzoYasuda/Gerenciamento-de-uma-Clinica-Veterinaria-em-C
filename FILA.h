#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <string.h>
#include <time.h>
#include <ctype.h>
#define n 50
#define e 30

/* FUNÇÕES DE MANIPULAÇÃO DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA ESTÁ VAZIA RETORNA 1 QUANDO ESTÁ VAZIA

void InsereFila (Fila* f, int v) INSERÇÃO

int RetiraFila (Fila* f) REMOÇÃO

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/
typedef struct Data
{
    int dia,mes,ano;
}Data;

typedef struct info_pet
{
    int idade,ID,prioridade;
    char nome[n],especie[e];
    Data nascimento;
}info_pet;

typedef struct nos
{
    info_pet info;
    struct nos *prox;
}Nos;

typedef struct fila
{
    Nos * ini;
    Nos * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}

int randomID(Fila *emer,Fila *nor,Fila *aten)
{
    Nos *aux = emer->ini;
    srand(time(NULL));

    int rd_num = 100 + (rand() % 900);

    while(aux != NULL)
    {
        if(aux -> info.ID == rd_num)
        {
            return randomID(emer,nor,aten);
        }

        aux = aux -> prox;
    }

    aux = nor->ini;
    while(aux != NULL)
    {
        if(aux -> info.ID == rd_num)
        {
            return randomID(emer,nor,aten);
        }

        aux = aux -> prox;
    }

    aux = aten->ini;
    while(aux != NULL)
    {
        if(aux -> info.ID == rd_num)
        {
            return randomID(emer,nor,aten);
        }

        aux = aux -> prox;
    }

    return rd_num;
}

void CorrigirString(char s[])
{
    s[0] = toupper(s[0]);
    for(int i = 1;s[i] != '\0';i++)
    {
        if((s[i - 1] == ' ') || (s[i - 1] == '-'))
        {
            s[i] = toupper(s[i]);
        }
        else
        {
            s[i] = tolower(s[i]);
        }
    }
}

void PrintCentro(char s[],int largura)
{
    int len = strlen(s);
    int pad = (largura - len)/2;

    if(pad < 0)
    {
        pad = 0;
    }

    for(int i = 0;i < pad; i++)
    {
        printf(" ");
    }
    printf("%s\n",s);
}

void PedeData(char nome[], char especie[], int *idade, int *dia, int *mes, int *ano)
{
    int valido,resultado;

    printf("\n\n\t--------------------------------------------------------------------------------");
    printf("\n\n\tNome: ");
    fflush(stdin);
    gets(nome);

    printf("\n\tEspécie: ");
    fflush(stdin);
    gets(especie);

    do
    {
        printf("\n\tIdade: ");
        resultado = scanf("%d",idade);

        if(resultado != 1)
        {
            while(getchar() != '\n');
            {
                printf("\n\tDigite uma idade válida: ");
            }
        }
    }while(resultado != 1);

    valido = 0;
    printf("\n\tData de Nascimento: ");
    printf("\n");
    do
    {
        printf("\n\t\tDia: ");
        resultado = scanf("%d",dia);
        if(resultado != 1)
        {
            while(getchar() != '\n')
            {
                printf("\n\t\tDigite um dia válido (1 - 31): ");
            }
        }
        else if((*dia < 1) || (*dia > 31))
        {
            printf("\n\t\tDigite um dia válido (1 - 31): ");
        }
        else
        {
            valido++;
        }
    }while(valido < 1);

    valido = 0;
    do
    {
        printf("\n\t\tMês: ");
        resultado = scanf("%d",mes);
        if(resultado != 1)
        {
            while(getchar() != '\n');
            {
                printf("\n\t\tDigite um mês válido (1 - 12): ");
            }
        }
        else if((*mes < 1) || (*mes > 12))
        {
            printf("\n\t\tDigite um mês válido (1 - 12): ");
        }
        else
        {
            valido++;
        }
    }while(valido < 0);

    valido = 0;
    do
    {
        printf("\n\t\tAno: ");
        resultado = scanf("%d",ano);
        if(resultado != 1)
        {
            while(getchar() != '\n');
            {
                printf("\n\t\tDigite um ano válido (0 - 2025): ");
            }
        }
        else if((*ano < 0) || (*ano > 2025))
        {
            printf("\n\t\tDigite um ano válido (0 - 2025): ");
        }
        else
        {
            valido++;
        }
    }while(valido < 0);
    printf("\n\n\t--------------------------------------------------------------------------------\n\n\t");
}


void ImprimeDadosPet(Nos *aux1)
{
    printf("\n\t\tID: %d",aux1->info.ID);
    printf("\n\t\tNome: %s",aux1->info.nome);
    printf("\n\t\tEspécie: %s",aux1->info.especie);
}

Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

Nos* ins_fim (Fila *f,Nos *fim, int ID, int idade, char nome[], char especie[], int dia, int mes, int ano, int prioridade)
{
    Nos *p = (Nos*)malloc(sizeof(Nos));
    p->info.ID = ID;
    p->info.idade = idade;
    CorrigirString(nome);
    strcpy(p->info.nome,nome);
    CorrigirString(especie);
    strcpy(p->info.especie,especie);
    p->info.nascimento.dia = dia;
    p->info.nascimento.mes = mes;
    p->info.nascimento.ano = ano;
    p->info.prioridade = prioridade;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int ID, int idade, char nome[], char especie[], int dia, int mes, int ano, int prioridade)
{
    f->fim = ins_fim(f,f->fim,ID,idade,nome,especie,dia,mes,ano,prioridade);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

Nos* retira_ini (Nos* ini)
{
    Nos* p = ini->prox;
    free(ini);
    return p;
}

Nos* RetiraFila (Fila* f)
{
    Nos *p = (Nos*)malloc(sizeof(Nos));
    p->info.ID = f->ini->info.ID;
    p->info.idade = f->ini->info.idade;
    strcpy(p->info.nome,f->ini->info.nome);
    strcpy(p->info.especie,f->ini->info.especie);
    p->info.nascimento.dia = f->ini->info.nascimento.dia;
    p->info.nascimento.mes = f->ini->info.nascimento.mes;
    p->info.nascimento.ano = f->ini->info.nascimento.ano;
    p->info.prioridade = f->ini->info.prioridade;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;

    return p;
}


void imprimeFila (Nos* imp)
{
    printf("\n\n\t|----------------------------------------------------------------|");
    printf("\n\t|\t\t\t\t\t\t\t\t |");
    printf("\n\t|\t\tID: %d\t\t\t\t\t\t |",imp->info.ID);
    printf("\n\t|\t\tNome: %s\t\t\t\t\t |",imp->info.nome);
    printf("\n\t|\t\tEspécie: %s\t\t\t\t|",imp->info.especie);
    printf("\n\t|\t\tIdade: %d\t\t\t\t\t |",imp->info.idade);
    printf("\n\t|\t\tData de Nascimento: %d/%d/%d\t\t\t |",imp->info.nascimento.dia,imp->info.nascimento.mes,imp->info.nascimento.ano);
    printf("\n\t|\t\t\t\t\t\t\t\t |");
    printf("\n\t|----------------------------------------------------------------|\n\n\t");
}


Fila* liberaFila (Fila* f)
{
    Nos* q = f->ini;
    while (q!=NULL)
    {
        Nos* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}


void buscaListaNome(Fila* emer,Fila* nor,Fila* aten,char nome[])
{
    Nos *aux1;
    aux1 = emer->ini;
    int vazio=0;

    printf("\n");

    while(aux1 != NULL)
    {
        if(strcmp(aux1->info.nome,nome) == 0)
        {
            printf("\n\tAtendimento de Emergência!");
            ImprimeDadosPet(aux1);
            printf("\n\t\tNão foi atendido.\n");

            vazio++;
        }

        aux1 = aux1->prox;
    }

    aux1 = nor->ini;

    while(aux1 != NULL)
    {
        if(strcmp(aux1->info.nome,nome) == 0)
        {
            printf("\n\tAtendimento Normal.");
            ImprimeDadosPet(aux1);
            printf("\n\t\tNão foi atendido.\n");

            vazio++;
        }

        aux1 = aux1->prox;
    }

    aux1 = aten->ini;

    while(aux1 != NULL)
    {
        if(strcmp(aux1->info.nome,nome) == 0)
        {
            if(aux1->info.prioridade < 1)
            {
                printf("\n\tAtendimento de Emergência!");
                ImprimeDadosPet(aux1);
                printf("\n\t\tJá foi atendido.\n");

                vazio++;
            }
            else
            {
                printf("\n\tAtendimento Normal.");
                ImprimeDadosPet(aux1);
                printf("\n\t\tJá foi atendido.\n");

                vazio++;
            }
        }

        aux1 = aux1->prox;
    }
    if(vazio == 0)
    {
        system("cls");
        printf("\n\n\tNão há Pet com este nome no momento.\n\n\t");
    }
}


void buscaListaID(Fila* emer,Fila* nor,Fila* aten,int ID)
{
    Nos *aux1;
    aux1 = emer->ini;
    int vazio=0;

    while(aux1 != NULL)
    {
        if(aux1->info.ID == ID)
        {
            printf("\n\tAtendimento de Emergência!");
            ImprimeDadosPet(aux1);
            printf("\n\t\tNão foi atendido.\n");

            vazio++;
        }

        aux1 = aux1->prox;
    }

    aux1 = nor->ini;

    while(aux1 != NULL)
    {
        if(aux1->info.ID == ID)
        {
            printf("\n\tAtendimento Normal.");
            ImprimeDadosPet(aux1);
            printf("\n\t\tNão foi atendido.\n");

            vazio++;
        }

        aux1 = aux1->prox;
    }

    aux1 = aten->ini;

    while(aux1 != NULL)
    {
        if(aux1->info.ID == ID)
        {
            if(aux1->info.prioridade == 0)
            {
                printf("\n\tAtendimento de Emergência!");
                ImprimeDadosPet(aux1);
                printf("\n\t\tJá foi atendido.\n");

                vazio++;
            }
            else
            {
                printf("\n\tAtendimento Normal.");
                ImprimeDadosPet(aux1);
                printf("\n\t\tJá foi atendido.\n");

                vazio++;
            }
        }

        aux1 = aux1->prox;
    }
    if(vazio == 0)
    {
        system("cls");
        printf("\n\n\tNão há Pet com este ID no momento.\n\n\t");
    }
}


void imprimeRelatorio(Fila* emer, Fila* nor)
{
    Nos *aux1;
    aux1 = emer->ini;

    if(VaziaFila(emer) < 1)
    {
        while(aux1 != NULL)
        {
            printf("\n\n\t\t%d | %s | %s | %d | %d/%d/%d | %d",aux1->info.ID,aux1->info.nome,aux1->info.especie,aux1->info.idade,aux1->info.nascimento.dia,aux1->info.nascimento.mes,aux1->info.nascimento.ano,aux1->info.prioridade);

            aux1 = aux1->prox;
        }
    }

    else if(VaziaFila(nor) < 1)
    {
        aux1 = nor->ini;
        while(aux1 != NULL)
        {
            printf("\n\n\t\t%d | %s | %s | %d | %d/%d/%d | %d",aux1->info.ID,aux1->info.nome,aux1->info.especie,aux1->info.idade,aux1->info.nascimento.dia,aux1->info.nascimento.mes,aux1->info.nascimento.ano,aux1->info.prioridade);

            aux1 = aux1->prox;
        }
    }
    else
    {
        system("cls");
        printf("\n\n\tNão há nenhum Pet para ser atendido no momento.\n\n\t");
    }
}


void imprimeAtendidos(Fila* aten)
{
    Nos *aux;
    aux = aten->ini;

        if(VaziaFila(aten) < 1)
        {
            while(aux != NULL)
            {
                printf("\n\n\t\t%d | %s | %s | %d | %d",aux->info.ID,aux->info.nome,aux->info.especie,aux->info.idade,aux->info.prioridade);

                aux = aux->prox;
            }
        }
        else
        {
            system("cls");
            printf("\n\n\tNenhum Pet foi atendido no momento.\n\n\t");
        }
}


#endif // FILA_H_INCLUDED
