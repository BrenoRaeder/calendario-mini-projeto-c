#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "calendario.h"

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

char *diaSemana(int soma)
{
    //char diaSemana[20];
    
    switch (soma % 7)
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
        return ("sábado"); 
    case 6:
        return ("domingo"); 
    default:
        break;
    }
}

char *calculaData(int dia, int mes, int ano)
{
    int a, b, c, d, soma; //valores da fórmula 

    if(dia<1 || dia>31 || mes<1 || mes>12) return ("Data invalida");
    else
    {
        a = ano - 1900;
    b = ignoraResto(a);
    if(ano==1900 || ano%4==0) b--;
    c = codigoMes(mes);
    d = dia - 1;

    soma = a+b+c+d;

    return diaSemana(soma);
    }  
}