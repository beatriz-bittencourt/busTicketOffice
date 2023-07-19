#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "p3onibus.h"

/*
Prova 3 - Algoritmos e lógica de programação - 1º semestre/ADS - 2022
Aluna: Beatriz Bittencourt de Almeida

A proposta desse trabalho era que criássemos um sistema em Linguagem C que fosse como um guichê de ônibus,
em que o usuário escolheria sua cidade de origem e a cidade de destino, escolheria um dos horários disponíveis,
informaria o preço da passagem e escolheria quantas passagens seriam necessárias. Um dos itens obrigatórios desse
projeto foi a importação de uma Função externa para este arquivo (main.c) e a exibição de um menu final. 

Ao encerrar o projeto, os dados ficarão guardados em um arquivo .txt para poder serem lidos posteriormente, ao final
das escolhas do usuário temos um menu de 3 opções: permite escolher ver todo o histórico de compras (geral), só as
compras feitas desta vez que o projeto foi rodado ou encerrar o projeto.
*/


//trazendo as funções feitas
void cid();
char horario(int co, int cd);

int main()
{
    int co,cd,h,hor,numpass,conf,vendas;
    float pfinal=0;
    struct passagem;

    //Struct do preço da passagem
    struct passagem{
        float preco;
    };
    struct passagem pass;

    setlocale(LC_ALL,"");

    FILE *arq1;
    arq1=fopen("dadostotais.txt","a+");
    FILE *arq;
    arq=fopen("dadosmomento.txt", "w");

    printf("\n----------------- Olá! Seja bem-vindo(a) à nossa central de venda de passagens de ônibus! -----------------\n");

    //escolher cidade de origem, se colocar número inválido o sistema repete a pergunta
    do{
        arq=fopen("dadosmomento.txt","a");
    do{
        do{
    printf("\n\n\n\n\n\n\n\n----------------- Escolha a cidade de ORIGEM -----------------\n\n");
    printf("As cidades de ORIGEM disponíveis para a viagem são: \n\n");
    cid();
    printf("\n\nDigite apenas o número da cidade de ORIGEM: \n");
    scanf("%d",&co);
        } while(co<1 || co>15);

    //escolher cidade de destino, se colocar número inválido ou repetir o número da cidade de origem o sistema repete a pergunta
        do{
    printf("\n\n\n\n\n\n\n\n----------------- Escolha a cidade de DESTINO -----------------\n\n");
    printf("*** Esta deve ser diferente da cidade de origem! ***\n");
    printf("As cidades de DESTINO para a viagem são: \n\n");
    cid();
    printf("\n\nDigite apenas o número da cidade de DESTINO: \n");
    scanf("%d",&cd);
        } while(cd<1 || cd>12);

    } while(co==cd);

    //escolher horário da viagem, se colocar número inválido o sistema repete a pergunta
    do{
    printf("\n\n\n\n\n\n\n\n----------------- Escolha qual horário quer partir da cidade %d para a cidade %d -----------------\n\n",co,cd);
    printf("Os horários de saída e chegada para essa linha de ônibus são respectivamente: \n\n");
    hor=horario(co,cd);
    printf("%c",hor);
    printf("\n\nDigite apenas o primeiro número do horário escolhido (ex.: 3): \n");
    scanf("%d",&h);
    }while(h>15 || h<1);

    printf("\n\n\n\n\n\n\n\n----------------- Passagem -----------------\n\n");
    printf("Qual é o preço da passagem?\n");
    scanf("%f",&pass.preco);

    //retorna a cidade de origem que o usuário escolheu
    switch(co){
    case 1:
        fprintf(arq1,"ORIGEM: Aparecida\n"); //fprintf para guardar o resultado no arquivo em que ficam TODOS os resultados
        fprintf(arq,"ORIGEM: Aparecida\n"); //fprintf para guardar o resultado apenas das ultimas vendas do momento (para consulta, se preciso)
        printf("\n\n\n\n\n\nORIGEM: Aparecida"); //printf para imprimir para o usuário
        break;
    case 2:
        fprintf(arq1,"ORIGEM: Caçapava\n");
        fprintf(arq,"ORIGEM: Caçapava\n");
        printf("\n\n\n\n\n\nORIGEM: Caçapava");
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
        fprintf(arq1,"ORIGEM: Guaratinguatá\n");
        fprintf(arq,"ORIGEM: Guaratinguatá\n");
        printf("\n\n\n\n\n\nORIGEM: Guaratinguatá");
        break;
    case 7:
        fprintf(arq1,"ORIGEM: Jacareí\n");
        fprintf(arq,"ORIGEM: Jacareí\n");
        printf("\n\n\n\n\n\nORIGEM: Jacareí");
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
        fprintf(arq1,"ORIGEM: São José dos Campos\n");
        fprintf(arq,"ORIGEM: São José dos Campos\n");
        printf("\n\n\n\n\n\nORIGEM: São José dos Campos");
        break;
    case 12:
        fprintf(arq1,"ORIGEM: Taubaté\n");
        fprintf(arq,"ORIGEM: Taubaté\n");
        printf("\n\n\n\n\n\nORIGEM: Taubaté");
        break;
    }

    //retorna a cidade de destino que o usuário escolheu
    switch(cd){
    case 1:
        fprintf(arq1,"DESTINO: Aparecida"); //mesmo raciocínio do switch/case da cidade de origem
        fprintf(arq,"DESTINO: Aparecida");
        printf("\nDESTINO: Aparecida");
        break;
    case 2:
        fprintf(arq1,"DESTINO: Caçapava");
        fprintf(arq,"DESTINO: Caçapava");
        printf("\nDESTINO: Caçapava");
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
        fprintf(arq1,"DESTINO: Guaratinguatá");
        fprintf(arq,"DESTINO: Guaratinguatá");
        printf("\nDESTINO: Guaratinguatá");
        break;
    case 7:
        fprintf(arq1,"DESTINO: Jacareí");
        fprintf(arq,"DESTINO: Jacareí");
        printf("\nDESTINO: Jacareí");
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
        fprintf(arq1,"DESTINO: São José dos Campos");
        fprintf(arq,"DESTINO: São José dos Campos");
        printf("\nDESTINO: São José dos Campos");
        break;
    case 12:
        fprintf(arq1,"DESTINO: Taubaté");
        fprintf(arq,"DESTINO: Taubaté");
        printf("\nDESTINO: Taubaté");
        break;
    }

    switch(h){
        case 1:
        fprintf(arq1,"\nSAIDA: 6h \nCHEGADA: 6h40"); //mesmo raciocínio dos switch/case anteriores
        fprintf(arq,"\nSAÍDA: 6h \nCHEGADA: 6h40");
        printf("\nSAÍDA: 6h \nCHEGADA: 6h40");
        break;
        case 2:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 12h40");
        fprintf(arq,"\nSAÍDA: 12h \nCHEGADA: 12h40");
        printf("\nSAÍDA: 12h \nCHEGADA: 12h40");
        break;
        case 3:
        fprintf(arq1,"\nSAIDA: 19h \nCHEGADA: 19h40");
        fprintf(arq,"\nSAÍDA: 19h \nCHEGADA: 19h40");
        printf("\nSAÍDA: 19h \nCHEGADA: 19h40");
        break;
        case 4:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 6h30");
        fprintf(arq,"\nSAÍDA: 5h \nCHEGADA: 6h30");
        printf("\nSAÍDA: 5h \nCHEGADA: 6h30");
        break;
        case 5:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 13h30");
        fprintf(arq,"\nSAÍDA: 12h \nCHEGADA: 13h30");
        printf("\nSAÍDA: 12h \nCHEGADA: 13h30");
        break;
        case 6:
        fprintf(arq1,"\nSAIDA: 19h30 \nCHEGADA: 21h");
        fprintf(arq,"\nSAÍDA: 19h30 \nCHEGADA: 21h");
        printf("\nSAÍDA: 19h30 \nCHEGADA: 21h");
        break;
        case 7:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 7h30");
        fprintf(arq,"\nSAÍDA: 5h \nCHEGADA: 7h30");
        printf("\nSAÍDA: 5h \nCHEGADA: 7h30");
        break;
        case 8:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 14h30");
        fprintf(arq,"\nSAÍDA: 12h \nCHEGADA: 14h30");
        printf("\nSAÍDA: 12h \nCHEGADA: 14h30");
        break;
        case 9:
        fprintf(arq1,"\nSAIDA: 19h30 \nCHEGADA: 22h");
        fprintf(arq,"\nSAÍDA: 19h30 \nCHEGADA: 22h");
        printf("\nSAÍDA: 19h30 \nCHEGADA: 22h");
        break;
        case 10:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 8h");
        fprintf(arq,"\nSAÍDA: 5h \nCHEGADA: 8h");
        printf("\nSAÍDA: 5h \nCHEGADA: 8h");
        break;
        case 11:
        fprintf(arq1,"\nSAIDA: 12h30 \nCHEGADA: 15h30");
        fprintf(arq,"\nSAÍDA: 12h30 \nCHEGADA: 15h30");
        printf("\nSAÍDA: 12h30 \nCHEGADA: 15h30");
        break;
        case 12:
        fprintf(arq1,"\nSAIDA: 19h \nCHEGADA: 22h");
        fprintf(arq,"\nSAÍDA: 19h \nCHEGADA: 22h");
        printf("\nSAÍDA: 19h \nCHEGADA: 22h");
        break;
        case 13:
        fprintf(arq1,"\nSAIDA: 5h \nCHEGADA: 10h");
        fprintf(arq,"\nSAÍDA: 5h \nCHEGADA: 10h");
        printf("\nSAÍDA: 5h \nCHEGADA: 10h");
        break;
        case 14:
        fprintf(arq1,"\nSAIDA: 12h \nCHEGADA: 17h");
        fprintf(arq,"\nSAÍDA: 12h \nCHEGADA: 17h");
        printf("\nSAÍDA: 12h \nCHEGADA: 17h");
        break;
        case 15:
        fprintf(arq1,"\nSAIDA: 18h \nCHEGADA: 23h");
        fprintf(arq,"\nSAÍDA: 18h \nCHEGADA: 23h");
        printf("\nSAÍDA: 18h \nCHEGADA: 23h");
        break;
    }
    printf("%d",h);

    //guardar resultados nos arquivos e imprime na tela
    fprintf(arq1,"\nPREÇO: %.2f\n",pass.preco);
    fprintf(arq,"\nPREÇO: %.2f\n",pass.preco);
    printf("\nPREÇO: %.2f\n\n\n\n\n\n",pass.preco);

    //pedir a quantidade de passagens que o usuário quer
    printf("Digite o número de passagens que você deseja comprar?\n");
    scanf("%d",&numpass);
    pfinal=pass.preco*numpass+pfinal;

    //guardar resultados nos arquivos e imprime na tela
    fprintf(arq1,"\nTOTAL A SER PAGO: %.2f\n\n\n",pfinal);
    fprintf(arq,"\nTOTAL A SER PAGO: %.2f\n\n\n",pfinal);
    printf("\n------------------------------");
    printf("\nTOTAL A SER PAGO: %.2f\n\n",pfinal);

    //perguntar se o usuário deseja fazer outra compra ou não
    do{
    printf("\n\nPara continuar comprando digite 1, para encerrar suas compras digite 2:\n");
    scanf("%d",&conf);
    }while(conf<1 || conf>2);

    if(conf==2){
        printf("\n\n------------------------------");
        printf("\nCOMPRA EFETUADA!");
            do{
        printf("\n\n\n\n\n\n\n\n\n\n\n----------------- Menu -----------------\n\n"); //abre um menu para o usuário decidir, após a compra finalizada, o que deseja fazer
        printf("Digite o número da opção que você deseja:\n\n");
        printf("1 - Ver a listagem de TODAS as vendas já realizadas (total).\n2 - Ver apenas a última venda que foi realizada neste momento.\n3 - Encerrar o programa.\n");
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
        printf("\n\nORIGEM: Caçapava");
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
        printf("\n\nORIGEM: Guaratinguatá");
        break;
    case 7:
        printf("\n\nORIGEM: Jacareí");
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
        printf("\n\nORIGEM: São José dos Campos");
        break;
    case 12:
        printf("\n\nORIGEM: Taubaté");
        break;
    }

    //retorna a cidade de destino que o usuário escolheu
    switch(cd){
    case 1:
        printf("\nDESTINO: Aparecida");
        break;
    case 2:
        printf("\nDESTINO: Caçapava");
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
        printf("\nDESTINO: Guaratinguatá");
        break;
    case 7:
        printf("\nDESTINO: Jacareí");
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
        printf("\nDESTINO: São José dos Campos");
        break;
    case 12:
        printf("\nDESTINO: Taubaté");
        break;
    }

    //retorna o horário de saída e chegada que o usuário escolheu
    switch(h){
        case 1:
        printf("\nSAÍDA: 6h \nCHEGADA: 6h40");
        break;
        case 2:
        printf("\nSAÍDA: 12h \nCHEGADA: 12h40");
        break;
        case 3:
        printf("\nSAÍDA: 19h \nCHEGADA: 19h40");
        break;
        case 4:
        printf("\nSAÍDA: 5h \nCHEGADA: 6h30");
        break;
        case 5:
        printf("\nSAÍDA: 12h \nCHEGADA: 13h30");
        break;
        case 6:
        printf("\nSAÍDA: 19h30 \nCHEGADA: 21h");
        break;
        case 7:
        printf("\nSAÍDA: 5h \nCHEGADA: 7h30");
        break;
        case 8:
        printf("\nSAÍDA: 12h \nCHEGADA: 14h30");
        break;
        case 9:
        printf("\nSAÍDA: 19h30 \nCHEGADA: 22h");
        break;
        case 10:
        printf("\nSAÍDA: 5h \nCHEGADA: 8h");
        break;
        case 11:
        printf("\nSAÍDA: 12h30 \nCHEGADA: 15h30");
        break;
        case 12:
        printf("\nSAÍDA: 19h \nCHEGADA: 22h");
        break;
        case 13:
        printf("\nSAÍDA: 5h \nCHEGADA: 10h");
        break;
        case 14:
        printf("\nSAÍDA: 12h \nCHEGADA: 17h");
        break;
        case 15:
        printf("\nSAÍDA: 18h \nCHEGADA: 23h");
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
