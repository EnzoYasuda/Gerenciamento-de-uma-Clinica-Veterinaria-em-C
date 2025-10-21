#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <string.h>
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
    int idade,ID;
    char nome[n],especie[e],prioridade[n];
    Data *nascimento;
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


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

Nos* ins_fim (Nos *fim, int idade, char nome[], char especie[], int dia, int mes, int ano, char prioridade[])
{
    Nos *p = (Nos*)malloc(sizeof(Nos));
    p->info.ID = randomID();
    p->info.idade = idade;
    p->info.nome[n] = nome[n];
    p->info.especie[e] = especie[e];
    p->info.nascimento->dia = dia;
    p->info.nascimento->mes = mes;
    p->info.nascimento->ano = ano;
    p->info.prioridade[n] = prioridade[n];
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int idade, char nome[], char especie[], int dia, int mes, int ano, char prioridade[])
{
    f->fim = ins_fim(f->fim,idade,nome[n],especie[e],dia,mes,ano,prioridade[n]);
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
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    p->info.ID = f->ini->info.ID;
    p->info.idade = f->ini->info.idade;
    p->info.nome[n] = f->ini->info.nome[n];
    p->info.especie[e] = f->ini->info.especie[e];
    p->info.nascimento->dia = f->ini->info.nascimento->dia;
    p->info.nascimento->mes = f->ini->info.nascimento->mes;
    p->info.nascimento->ano = f->ini->info.nascimento->ano;
    p->info.prioridade[n] = f->ini->info.prioridade[n];
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;

    return p;
}


void imprimeFila (Nos* imp)
{
    printf("--------------------------------------------------------------------------------");
    printf("\n\n\tID: %d",imp->info.ID);
    printf("\n\tNome: %d",imp->info.nome);
    printf("\n\tEspécie: %d",imp->info.especie);
    printf("\n\tData de Nascimento: %d/%d/%d",imp->info.nascimento->dia,imp->info.nascimento->mes,imp->info.nascimento->ano);
    printf("--------------------------------------------------------------------------------");
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
    Nos *aux1,*aux2,*aux3;
    aux1 = emer->ini;
    aux2 = nor->ini;
    aux3 = aten->ini;

    while((aux1 != NULL) && (aux2 != NULL))
    {
        if(aux1->info.nome == nome)
        {
            printf("\n\tAtendimento de Emergência!");
            printf("\n\t\tID: %d",aux1->info.ID);
            printf("\n\t\tNome: %d",aux1->info.nome);
            printf("\n\t\tEspécie: %d",aux1->info.especie);

            while(aux3 != NULL)
            {
                if(aux3->info.ID == aux1->info.ID)
                {
                    printf("\n\t\tJá foi atendido.");
                }
                aux3 = aux3->prox;
            }
            aux3 = aten->ini;
        }

        if(aux2->info.nome == nome)
        {
            printf("\n\tAtendimento Normal.");
            printf("\n\t\tID: %d",aux2->info.ID);
            printf("\n\t\tNome: %d",aux2->info.nome);
            printf("\n\t\tEspécie: %d",aux2->info.especie);

            while(aux3 != NULL)
            {
                if(aux3->info.ID == aux2->info.ID)
                {
                    printf("\n\t\tJá foi atendido.");
                }
                aux3 = aux3->prox;
            }
            aux3 = aten->ini;
        }

        aux1 = aux1->prox;
        aux2 = aux1->prox;
    }
}


#endif // FILA_H_INCLUDED
