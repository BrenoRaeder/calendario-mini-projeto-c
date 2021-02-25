#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "cor.h"
#include "calendario.h"



int main()
{
    int opcMenu;
    TData data;

    LimpaConsole(15,1);

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
            printf("O dia eh: %s\n\n",diaSemana(calculaData(data.mes, data.dia, data.ano))); //só tá funcinando para datas acima de 1900
            system("pause");
            break;
        
        case 2:
            printf("Digite o mes e o ano (MM AAAA):");
            scanf("%d %d", &data.mes, &data.ano);
            imprimeCalendario(data.mes, data.ano);
            system("pause");
            system("cls");
            break;

        case 3:
            //code
            break;

        case 4:
            exit(0);
        }
    }
}