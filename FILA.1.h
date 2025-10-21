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
    char nome[n],especie[e];
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

Nos* ins_fim (Nos *fim, int idade, char nome[], char especie[], int dia, int mes, int ano)
{
    Nos *p = (Nos*)malloc(sizeof(Nos));
    p->info.ID = randomID();
    p->info.idade = idade;
    p->info.nome[n] = nome[n];
    p->info.especie[e] = especie[e];
    p->info.nascimento->dia = dia;
    p->info.nascimento->mes = mes;
    p->info.nascimento->ano = ano;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int idade, char nome[], char especie[], int dia, int mes, int ano)
{
    f->fim = ins_fim(f->fim,idade,nome[n],especie[e],dia,mes,ano);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

Nos* retira_ini (Nos* ini)
{
    Nos* p = ini->prox;
    free(ini);
    return p;
}

char RetiraNome (Fila *f)
{
    char nome[n];
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    nome[n] = f->ini->info.nome[n];

    return nome;
}

char RetiraEspecie (Fila *f)
{
    char especie[e];
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    especie[e] = f->ini->info.especie[e];

    return especie;
}

int RetiraIdade (Fila *f)
{
    int idade;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    idade = f->ini->info.idade;

    return idade;
}

int RetiraID (Fila *f)
{
    int ID;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    ID = f->ini->info.ID;

    return ID;
}

int RetiraDia (Fila *f)
{
    int dia;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    dia = f->ini->info.nascimento->dia;

    return dia;
}

int RetiraMes (Fila *f)
{
    int mes;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    mes = f->ini->info.nascimento->mes;

    return mes;
}

int RetiraAno (Fila *f)
{
    int ano;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    ano = f->ini->info.nascimento->ano;

    return ano;
}

void RetiraFila (Fila* f)
{
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
}

void imprimeFila (Fila* f)
{
    Nos* q;
    printf("\n\t\t");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("%d - ",q->info);
    }
    printf("\n");
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

#endif // FILA_H_INCLUDED
