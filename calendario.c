#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "calendario.h"
#include "cor.h"

int ignoraResto(int valor)
{
    while(valor%4!=0) valor--;
    return valor/4; 
}

int codigoMes(int mes)
{
    int resultado;

    switch(mes)
    {
        case 1:
            resultado = 0; break; 
        case 2:
            resultado = 3; break;
        case 3:
            resultado = 3; break;
        case 4:
            resultado = 6; break;
        case 5:
            resultado = 1; break;
        case 6: 
            resultado = 4; break;
        case 7:
            resultado = 6; break;
        case 8:
            resultado = 2; break;
        case 9:
            resultado = 5; break;
        case 10:
            resultado = 0; break; 
        case 11:
            resultado = 3; break;
        case 12:
            resultado = 5; break;
        default:
            break;
    }
    return resultado;
}

char *diaSemana(int dia)
{
    //char diaSemana[20];
    
    switch (dia)
    {
    case 0:
        return ("segunda"); 
    case 1:
        return ("terca"); 
    case 2:
        return ("quarta"); 
    case 3:
        return ("quinta"); 
    case 4:
        return ("sexta"); 
    case 5:
        return ("sabado"); 
    case 6:
        return ("domingo");
    case 7:
        return("data invalida"); 
    default:
        break;
    }
}

int calculaData(int dia, int mes, int ano)
{
    int a, b, c, d, diaSemana; //valores da fórmula 

    if(dia<1 || dia>31 || mes<1 || mes>12) return 7;
    else
    {
        a = ano - 1900;
        b = ignoraResto(a);
        if(ano==1900 || ano%4==0) b--;
        c = codigoMes(mes);
        d = dia - 1;

        diaSemana = (a+b+c+d)%7;

        return diaSemana;
    }  
}

int qtdDiasMes(int mes, int ano)
{
    switch(mes)
    {
        case 1: 
            return 31; 
        case 2: 
            if(ano%4==0 || (ano%100==0 && ano%400!=0)) return 29;
            else return 28;
        case 3: 
            return 31;
        case 4: 
            return 30;
        case 5: 
            return 31;
        case 6: 
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10: 
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
}

char *nomeMes(int mes)
{
    switch(mes)
    {
        case 1: 
            return ("Janeiro"); 
        case 2: 
            return ("Fevereiro");
        case 3: 
            return ("Marco");
        case 4: 
            return ("Abril");
        case 5: 
            return ("Maio");
        case 6: 
            return ("Junho");
        case 7:
            return ("Julho");
        case 8:
            return ("Agosto");
        case 9:
            return ("Setembro");
        case 10: 
            return ("Outubro");
        case 11:
            return ("Novembro");
        case 12:
            return ("Dezembro");
    }
}

void imprimeCalendario(int mes, int ano)
{
    int i, j=1, qtdDias, comecoMes;
    
    qtdDias = qtdDiasMes(mes, ano);
    comecoMes = calculaData(1, mes, ano); //0 é segunda, 1 é terça... 7 é erro
    if(ano%4==0 || (ano%100==0 && ano%400!=0)) comecoMes++;

    //printf("%d - %s\n\n", qtdDias, diaSemana(comecoMes));

    printf("-------------------------\n");
    printf("  %s, %d\n", nomeMes(mes),ano);
    printf("-------------------------\n");
    printf("S   T   Q   Q   S   S   D\n");
    
    for(i=1;j<=qtdDias;i++)
    {
        if(i<comecoMes+1) printf("    ");
        else
        {
            if(i==8 || i==15 || i==22 || i==29) printf("\n"); // organizar isso aqui
        
            if(j<10) printf("0%d  ", j);
            else printf("%d  ",j);
            j++;

            if(i==0 || i%7==0) DefineCores(12);
            else LimpaCores();
        }
    }
    LimpaCores();

    printf("\n");

}