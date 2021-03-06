#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "cor.h"
#include "calendario.h"


int main()
{
    int opcMenu, mes;
    TData data;
    TNotas n; 
    char ch;
    struct tm *_data_; 

    time_t segundos; time(&segundos); _data_=localtime(&segundos);

    LimpaConsole(15,3);
    inicializarNotas(&n);
    leNotas(&n);

    imprimeAniversario(&n, _data_->tm_mon+1);
    
    while(1)
    {
        system("cls");
        printf("1. Descubra o dia da semana\n");
        printf("2. Veja todos os dias de um mes\n");
        printf("3. Adcione uma nota\n");
        printf("4. Veja todos os aniversariantes de um mes\n");
        printf("5. SAIR\n\n");
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
            printf("Qual mes deseja consultar? ");
            scanf("%d", &mes);
            system("cls");
            imprimeAniversario(&n,mes);
            break;

        case 5:
            gravaNota(n);
            LimpaConsole(15,0);
            exit(0);
        }
    }

    return 0;
}