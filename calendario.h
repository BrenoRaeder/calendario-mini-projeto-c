#ifndef _CALENDARIO_H_
#define _CALENDARIO_H_

typedef struct{
    int mes;
    int dia;
    int ano;
}TData;

int ignoraResto(int a);
int codigoMes(int mes);
char *diaSemana(int final);
int calculaData(int mes, int dia, int ano);
int qtdDiasMes(int mes, int ano);
char *nomeMes(int mes);
void imprimeCalendario(int mes, int ano);




#endif