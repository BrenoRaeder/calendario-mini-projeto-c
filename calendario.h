#ifndef _CALENDARIO_H_
#define _CALENDARIO_H_

typedef struct{
    int mes;
    int dia;
    int ano;
}TData;

typedef struct{
    int dia;
    int mes;
    char nota[30];
}TNota;

typedef struct{
    TNota nota[350];
    int qtd; 
}TNotas;

void gotoxy (int x, int y);
int ignoraResto(int a);
int codigoMes(int mes);
char *diaSemana(int final);
int calculaData(int mes, int dia, int ano);
void imprimeDiaSemana(int mes, int dia, int ano);
int qtdDiasMes(int mes, int ano);
char *nomeMes(int mes);
void imprimeCalendario(int mes, int ano, TNotas n, int conf);
void inicializarNotas(TNotas *notas); 
void inserirNota(TNotas *n);
void gravaNota(TNotas n);
char *lerAte(FILE *arq, char sep, char destino[]);
void inserirArq(TNotas *n, TNota nota);
void leNotas(TNotas *n);
void leString(char str[], int max);
void imprimeAniversario(TNotas *n, int mes);
void removerAniversariante(TNotas *n);
int confereAniversario(int dia, int mes, TNotas n);


#endif