#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "p3onibus.h"

/*
Prova 3 - Algoritmos e l�gica de programa��o - 1� semestre/ADS - 2022
Aluna: Beatriz Bittencourt de Almeida

A proposta desse trabalho era que cri�ssemos um sistema em Linguagem C que fosse como um guich� de �nibus,
em que o usu�rio escolheria sua cidade de origem e a cidade de destino, escolheria um dos hor�rios dispon�veis,
informaria o pre�o da passagem e escolheria quantas passagens seriam necess�rias. Um dos itens obrigat�rios desse
projeto foi a importa��o de uma Fun��o externa para este arquivo (main.c) e a exibi��o de um menu final. 

Ao encerrar o projeto, os dados ficar�o guardados em um arquivo .txt para poder serem lidos posteriormente, ao final
das escolhas do usu�rio temos um menu de 3 op��es: permite escolher ver todo o hist�rico de compras (geral), s� as
compras feitas desta vez que o projeto foi rodado ou encerrar o projeto.
*/


//trazendo as fun��es feitas
void cid();
char horario(int co, int cd);

int main()
{
    int co,cd,h,hor,numpass,conf,vendas;
    float pfinal=0;
    struct passagem;

    //Struct do pre�o da passagem
    struct passagem{
        float preco;
    };
    struct passagem pass;

    setlocale(LC_ALL,"");

    FILE *arq1;
    arq1=fopen("dadostotais.txt","a+");
    FILE *arq;
    arq=fopen("dadosmomento.txt", "w");

    printf("\n----------------- Ol�! Seja bem-vindo(a) � nossa central de venda de passagens de �nibus! -----------------\n");

    //escolher cidade de origem, se colocar n�mero inv�lido o sistema repete a pergunta
    do{
        arq=fopen("dadosmomento.txt","a");
    do{
        do{
    printf("\n\n\n\n\n\n\n\n----------------- Escolha a cidade de ORIGEM -----------------\n\n");
    printf("As cidades de ORIGEM dispon�veis para a viagem s�o: \n\n");
    cid();
    printf("\n\nDigite apenas o n�mero da cidade de ORIGEM: \n");
    scanf("%d",&co);
        } while(co<1 || co>15);

    //escolher cidade de destino, se colocar n�mero inv�lido ou repetir o n�mero da cidade de origem o sistema repete a pergunta
        do{
    printf("\n\n\n\n\n\n\n\n----------------- Escolha a cidade de DESTINO -----------------\n\n");
    printf("*** Esta deve ser diferente da cidade de origem! ***\n");
    printf("As cidades de DESTINO para a viagem s�o: \n\n");
    cid();
    printf("\n\nDigite apenas o n�mero da cidade de DESTINO: \n");
    scanf("%d",&cd);
        } while(cd<1 || cd>12);

    } while(co==cd);

    //escolher hor�rio da viagem, se colocar n�mero inv�lido o sistema repete a pergunta
    do{
    printf("\n\n\n\n\n\n\n\n----------------- Escolha qual hor�rio quer partir da cidade %d para a cidade %d -----------------\n\n",co,cd);
    printf("Os hor�rios de sa�da e chegada para essa linha de �nibus s�o respectivamente: \n\n");
    hor=horario(co,cd);
    printf("%c",hor);
    printf("\n\nDigite apenas o primeiro n�mero do hor�rio escolhido (ex.: 3): \n");
    scanf("%d",&h);
    }while(h>15 || h<1);

    printf("\n\n\n\n\n\n\n\n----------------- Passagem -----------------\n\n");
    printf("Qual � o pre�o da passagem?\n");
    scanf("%f",&pass.preco);

    //retorna a cidade de origem que o usu�rio escolheu
    switch(co){
    case 1:
        fprintf(arq1,"ORIGEM: Aparecida\n"); //fprintf para guardar o resultado no arquivo em que ficam TODOS os resultados
        fprintf(arq,"ORIGEM: Aparecida\n"); //fprintf para guardar o resultado apenas das ultimas vendas do momento (para consulta, se preciso)
        printf("\n\n\n\n\n\nORIGEM: Aparecida"); //printf para imprimir para o usu�rio
        break;
    case 2:
        fprintf(arq1,"ORIGEM: Ca�apava\n");
        fprintf(arq,"ORIGEM: Ca�apava\n");
        printf("\n\n\n\n\n\nORIGEM: Ca�apava");
        break;
    case 3:
        fprintf(arq1,"ORIGEM: Cachoeira Paulista\n");
        fprintf(arq,"ORIGEM: Cachoeira Paulista\n");
        printf("\n\n\n\n\n\nORIGEM: Cachoeira Paulista");
        break;
    case 4:
        fprintf(arq1,"ORIGEM: Caraguatatuba\n");
        fprintf(arq,"ORIGEM: Caraguatatuba\n");
        printf("\n\n\n\n\n\nORIGEM: Caraguatatuba");
        break;
    case 5:
        fprintf(arq1,"ORIGEM: Cruzeiro\n");
        fprintf(arq,"ORIGEM: Cruzeiro\n");
        printf("\n\n\n\n\n\nORIGEM: Cruzeiro");
        break;
    case 6:
        fprintf(arq1,"ORIGEM: Guaratinguat�\n");
        fprintf(arq,"ORIGEM: Guaratinguat�\n");
        printf("\n\n\n\n\n\nORIGEM: Guaratinguat�");
        break;
    case 7:
        fprintf(arq1,"ORIGEM: Jacare�\n");
        fprintf(arq,"ORIGEM: Jacare�\n");
        printf("\n\n\n\n\n\nORIGEM: Jacare�");
        break;
    case 8:
        fprintf(arq1,"ORIGEM: Lorena\n");
        fprintf(arq,"ORIGEM: Lorena\n");
        printf("\n\n\n\n\n\nORIGEM: Lorena");
        break;
    case 9:
        fprintf(arq1,"ORIGEM: Pindamonhangaba\n");
        fprintf(arq,"ORIGEM: Pindamonhangaba\n");
        printf("\n\n\n\n\n\nORIGEM: Pindamonhangaba");
        break;
    case 10:
        fprintf(arq1,"ORIGEM: Piquete\n");
        fprintf(arq,"ORIGEM: Piquete\n");
        printf("\n\n\n\n\n\nORIGEM: Piquete");
        break;
    case 11:
        fprintf(arq1,"ORIGEM: S�o Jos� dos Campos\n");
        fprintf(arq,"ORIGEM: S�o Jos� dos Campos\n");
        printf("\n\n\n\n\n\nORIGEM: S�o Jos� dos Campos");
        break;
    case 12:
        fprintf(arq1,"ORIGEM: Taubat�\n");
        fprintf(arq,"ORIGEM: Taubat�\n");
        printf("\n\n\n\n\n\nORIGEM: Taubat�");
        break;
    }

    //retorna a cidade de destino que o usu�rio escolheu
    switch(cd){
    case 1:
        fprintf(arq1,"DESTINO: Aparecida"); //mesmo racioc�nio do switch/case da cidade de origem
        fprintf(arq,"DESTINO: Aparecida");
        printf("\nDESTINO: Aparecida");
        break;
    case 2:
        fprintf(arq1,"DESTINO: Ca�apava");
        fprintf(arq,"DESTINO: Ca�apava");
        printf("\nDESTINO: Ca�apava");
        break;
    case 3:
        fprintf(arq1,"DESTINO: Cachoeira Paulista");
        fprintf(arq,"DESTINO: Cachoeira Paulista");
        printf("\nDESTINO: Cachoeira Paulista");
        break;
    case 4:
        fprintf(arq1,"DESTINO: Caraguatatuba");
        fprintf(arq,"DESTINO: Caraguatatuba");
        printf("\nDESTINO: Caraguatatuba");
        break;
    case 5:
        fprintf(arq1,"DESTINO: Cruzeiro");
        fprintf(arq,"DESTINO: Cruzeiro");
        printf("\nDESTINO: Cruzeiro");
        break;
    case 6:
        fprintf(arq1,"DESTINO: Guaratinguat�");
        fprintf(arq,"DESTINO: Guaratinguat�");
        printf("\nDESTINO: Guaratinguat�");
        break;
    case 7:
        fprintf(arq1,"DESTINO: Jacare�");
        fprintf(arq,"DESTINO: Jacare�");
        printf("\nDESTINO: Jacare�");
        break;
    case 8:
        fprintf(arq1,"DESTINO: Lorena");
        fprintf(arq,"DESTINO: Lorena");
        printf("\nDESTINO: Lorena");
        break;
    case 9:
        fprintf(arq1,"DESTINO: Pindamonhangaba");
        fprintf(arq,"DESTINO: Pindamonhangaba");
        printf("\nDESTINO: Pindamonhangaba");
        break;
    case 10:
        fprintf(arq1,"DESTINO: Piquete");
        fprintf(arq,"DESTINO: Piquete");
        printf("\nDESTINO: Piquete");
        break;
    case 11:
        fprintf(arq1,"DESTINO: S�o Jos� dos Campos");
        fprintf(arq,"DESTINO: S�o Jos� dos Campos");
        printf("\nDESTINO: S�o Jos� dos Campos");
        break;
    case 12:
        fprintf(arq1,"DESTINO: Taubat�");
        fprintf(arq,"DESTINO: Taubat�");
        printf("\nDESTINO: Taubat�");
        break;
    }

    switch(h){
        case 1:
        fprintf(arq1,"\nSAIDA: 6h \nCHEGADA: 6h40"); //mesmo racioc�nio dos switch/case anteriores
        fprintf(arq,"\nSA�DA: 6h \nCHEGADA: 6h40");
        printf("\nSA�DA: 6h \nCHEGADA: 6h40");
        break;
        case 2:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 12h40");
        fprintf(arq,"\nSA�DA: 12h \nCHEGADA: 12h40");
        printf("\nSA�DA: 12h \nCHEGADA: 12h40");
        break;
        case 3:
        fprintf(arq1,"\nSAIDA: 19h \nCHEGADA: 19h40");
        fprintf(arq,"\nSA�DA: 19h \nCHEGADA: 19h40");
        printf("\nSA�DA: 19h \nCHEGADA: 19h40");
        break;
        case 4:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 6h30");
        fprintf(arq,"\nSA�DA: 5h \nCHEGADA: 6h30");
        printf("\nSA�DA: 5h \nCHEGADA: 6h30");
        break;
        case 5:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 13h30");
        fprintf(arq,"\nSA�DA: 12h \nCHEGADA: 13h30");
        printf("\nSA�DA: 12h \nCHEGADA: 13h30");
        break;
        case 6:
        fprintf(arq1,"\nSAIDA: 19h30 \nCHEGADA: 21h");
        fprintf(arq,"\nSA�DA: 19h30 \nCHEGADA: 21h");
        printf("\nSA�DA: 19h30 \nCHEGADA: 21h");
        break;
        case 7:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 7h30");
        fprintf(arq,"\nSA�DA: 5h \nCHEGADA: 7h30");
        printf("\nSA�DA: 5h \nCHEGADA: 7h30");
        break;
        case 8:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 14h30");
        fprintf(arq,"\nSA�DA: 12h \nCHEGADA: 14h30");
        printf("\nSA�DA: 12h \nCHEGADA: 14h30");
        break;
        case 9:
        fprintf(arq1,"\nSAIDA: 19h30 \nCHEGADA: 22h");
        fprintf(arq,"\nSA�DA: 19h30 \nCHEGADA: 22h");
        printf("\nSA�DA: 19h30 \nCHEGADA: 22h");
        break;
        case 10:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 8h");
        fprintf(arq,"\nSA�DA: 5h \nCHEGADA: 8h");
        printf("\nSA�DA: 5h \nCHEGADA: 8h");
        break;
        case 11:
        fprintf(arq1,"\nSAIDA: 12h30 \nCHEGADA: 15h30");
        fprintf(arq,"\nSA�DA: 12h30 \nCHEGADA: 15h30");
        printf("\nSA�DA: 12h30 \nCHEGADA: 15h30");
        break;
        case 12:
        fprintf(arq1,"\nSAIDA: 19h \nCHEGADA: 22h");
        fprintf(arq,"\nSA�DA: 19h \nCHEGADA: 22h");
        printf("\nSA�DA: 19h \nCHEGADA: 22h");
        break;
        case 13:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 10h");
        fprintf(arq,"\nSA�DA: 5h \nCHEGADA: 10h");
        printf("\nSA�DA: 5h \nCHEGADA: 10h");
        break;
        case 14:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 17h");
        fprintf(arq,"\nSA�DA: 12h \nCHEGADA: 17h");
        printf("\nSA�DA: 12h \nCHEGADA: 17h");
        break;
        case 15:
        fprintf(arq1,"\nSAIDA: 18h \nCHEGADA: 23h");
        fprintf(arq,"\nSA�DA: 18h \nCHEGADA: 23h");
        printf("\nSA�DA: 18h \nCHEGADA: 23h");
        break;
    }
    printf("%d",h);

    //guardar resultados nos arquivos e imprime na tela
    fprintf(arq1,"\nPRE�O: %.2f\n",pass.preco);
    fprintf(arq,"\nPRE�O: %.2f\n",pass.preco);
    printf("\nPRE�O: %.2f\n\n\n\n\n\n",pass.preco);

    //pedir a quantidade de passagens que o usu�rio quer
    printf("Digite o n�mero de passagens que voc� deseja comprar?\n");
    scanf("%d",&numpass);
    pfinal=pass.preco*numpass+pfinal;

    //guardar resultados nos arquivos e imprime na tela
    fprintf(arq1,"\nTOTAL A SER PAGO: %.2f\n\n\n",pfinal);
    fprintf(arq,"\nTOTAL A SER PAGO: %.2f\n\n\n",pfinal);
    printf("\n------------------------------");
    printf("\nTOTAL A SER PAGO: %.2f\n\n",pfinal);

    //perguntar se o usu�rio deseja fazer outra compra ou n�o
    do{
    printf("\n\nPara continuar comprando digite 1, para encerrar suas compras digite 2:\n");
    scanf("%d",&conf);
    }while(conf<1 || conf>2);

    if(conf==2){
        printf("\n\n------------------------------");
        printf("\nCOMPRA EFETUADA!");
            do{
        printf("\n\n\n\n\n\n\n\n\n\n\n----------------- Menu -----------------\n\n"); //abre um menu para o usu�rio decidir, ap�s a compra finalizada, o que deseja fazer
        printf("Digite o n�mero da op��o que voc� deseja:\n\n");
        printf("1 - Ver a listagem de TODAS as vendas j� realizadas (total).\n2 - Ver apenas a �ltima venda que foi realizada neste momento.\n3 - Encerrar o programa.\n");
        printf("----------------------------------------\n");
        scanf("%d",&vendas);

        if(vendas==1){
            system("type dadostotais.txt");
        }
        if(vendas==2){
    switch(co){
    case 1:
        printf("\n\nORIGEM: Aparecida");
        break;
    case 2:
        printf("\n\nORIGEM: Ca�apava");
        break;
    case 3:
        printf("\n\nORIGEM: Cachoeira Paulista");
        break;
    case 4:
        printf("\n\nORIGEM: Caraguatatuba");
        break;
    case 5:
        printf("\n\nORIGEM: Cruzeiro");
        break;
    case 6:
        printf("\n\nORIGEM: Guaratinguat�");
        break;
    case 7:
        printf("\n\nORIGEM: Jacare�");
        break;
    case 8:
        printf("\n\nORIGEM: Lorena");
        break;
    case 9:
        printf("\n\nORIGEM: Pindamonhangaba");
        break;
    case 10:
        printf("\n\nORIGEM: Piquete");
        break;
    case 11:
        printf("\n\nORIGEM: S�o Jos� dos Campos");
        break;
    case 12:
        printf("\n\nORIGEM: Taubat�");
        break;
    }

    //retorna a cidade de destino que o usu�rio escolheu
    switch(cd){
    case 1:
        printf("\nDESTINO: Aparecida");
        break;
    case 2:
        printf("\nDESTINO: Ca�apava");
        break;
    case 3:
        printf("\nDESTINO: Cachoeira Paulista");
        break;
    case 4:
        printf("\nDESTINO: Caraguatatuba");
        break;
    case 5:
        printf("\nDESTINO: Cruzeiro");
        break;
    case 6:
        printf("\nDESTINO: Guaratinguat�");
        break;
    case 7:
        printf("\nDESTINO: Jacare�");
        break;
    case 8:
        printf("\nDESTINO: Lorena");
        break;
    case 9:
        printf("\nDESTINO: Pindamonhangaba");
        break;
    case 10:
        printf("\nDESTINO: Piquete");
        break;
    case 11:
        printf("\nDESTINO: S�o Jos� dos Campos");
        break;
    case 12:
        printf("\nDESTINO: Taubat�");
        break;
    }

    //retorna o hor�rio de sa�da e chegada que o usu�rio escolheu
    switch(h){
        case 1:
        printf("\nSA�DA: 6h \nCHEGADA: 6h40");
        break;
        case 2:
        printf("\nSA�DA: 12h \nCHEGADA: 12h40");
        break;
        case 3:
        printf("\nSA�DA: 19h \nCHEGADA: 19h40");
        break;
        case 4:
        printf("\nSA�DA: 5h \nCHEGADA: 6h30");
        break;
        case 5:
        printf("\nSA�DA: 12h \nCHEGADA: 13h30");
        break;
        case 6:
        printf("\nSA�DA: 19h30 \nCHEGADA: 21h");
        break;
        case 7:
        printf("\nSA�DA: 5h \nCHEGADA: 7h30");
        break;
        case 8:
        printf("\nSA�DA: 12h \nCHEGADA: 14h30");
        break;
        case 9:
        printf("\nSA�DA: 19h30 \nCHEGADA: 22h");
        break;
        case 10:
        printf("\nSA�DA: 5h \nCHEGADA: 8h");
        break;
        case 11:
        printf("\nSA�DA: 12h30 \nCHEGADA: 15h30");
        break;
        case 12:
        printf("\nSA�DA: 19h \nCHEGADA: 22h");
        break;
        case 13:
        printf("\nSA�DA: 5h \nCHEGADA: 10h");
        break;
        case 14:
        printf("\nSA�DA: 12h \nCHEGADA: 17h");
        break;
        case 15:
        printf("\nSA�DA: 18h \nCHEGADA: 23h");
        break;
    }
        }
        if(vendas==3){
            printf("\n\nFinalizando...\n");
            printf("Obrigada por usar o sistema!\n\n");
            exit(0);
        }
        }while(vendas<3 ||vendas>2);
    }

    }while(conf==1);
return 0;
}
