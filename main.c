#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "cor.h"
#include "calendario.h"



int main()
{
    int opcMenu;
    TData data;
    TNotas n; 
    char ch;

    LimpaConsole(15,1);
    inicializarNotas(&n);
    leNotas(&n);

    while(1)
    {
        system("cls");
        printf("1. Descubra o dia da semana\n");
        printf("2. Veja todos os dias de um mes\n");
        printf("3. Adcione uma nota\n");
        printf("4. SAIR\n");
        printf("DIGITE SUA OPCAO: ");
        scanf("%d", &opcMenu);
        system("cls");

    
        switch (opcMenu)
        {
        case 1:
            printf("Digite a data (DD MM AAAA):");
            scanf("%d %d %d", &data.mes, &data.dia, &data.ano);
            system("cls");
            imprimeDiaSemana(data.mes, data.dia, data.ano); //só tá funcinando para datas acima de 1900
            break;
        
        case 2:
            printf("Digite o mes e o ano (MM AAAA):");              //olhar agosto de 1904; olhar domingos primeiros abaixo de 1900
            scanf("%d %d", &data.mes, &data.ano);
            system("cls");
            imprimeCalendario(data.mes, data.ano);
            ch = getch();

            while(ch!='q')
            {   
                if(ch=='p') 
                {   
                    system("cls");
                    if(data.mes==12)
                    {
                        data.mes=1;
                        data.ano++;
                    }
                    data.mes++;
                    imprimeCalendario(data.mes, data.ano);
                    ch = getch();
                }
                else if(ch=='a')
                {   
                    system("cls");
                    if(data.mes==1)
                    {
                        data.mes=12;
                        data.ano--;
                    }
                    data.mes--;
                    imprimeCalendario(data.mes, data.ano);
                    ch = getch();
                }
                else if(ch=='q')
                {
                    system("cls");
                    break;
                }
                else
                {
                    system("cls");
                    imprimeCalendario(data.mes, data.ano);
                    ch = getch();
                }
            }
            //add parte da nota no futuro

        case 3:
            inserirNota(&n);
            break;

        case 4:
            gravaNota(n);
            exit(0);
        }
    }

    gravaNota(n);

    return 0;
}