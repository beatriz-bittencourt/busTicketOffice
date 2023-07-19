#include <stdio.h>
#include <locale.h>
#include "p3onibus.h"

void cid(){
    setlocale(LC_ALL,"");
    //mostrar quais cidades sao disponíveis
    printf("1 - Aparecida \n2 - Caçapava \n3 - Cachoeira Paulista \n4 - Caraguatatuba \n5 - Cruzeiro \n6 - Guaratinguatá \n7 - Jacareí \n8 - Lorena \n9 - Pindamonhangaba \n10 - Piquete \n11 - São José dos Campos \n12 - Taubaté");
}

char horario(int co, int cd){
    setlocale(LC_ALL,"");
    //função para mostrar cada horario de saída/chegada de cada cidade para cada cidade
    //aparecida
    if (co==1 && (cd==3 || cd==6 || cd==8 || cd==10)){
        printf("1- 6h -> 6h40 \n2- 12h -> 12h40 \n3- 19h -> 19h40 \n");
    }
    if (co==1 && (cd==2 || cd==5 || cd==9 || cd==11 || cd==12)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==1 && (cd==4 || cd==7)){
        printf("13- 5h -> 10h \n14- 12h -> 17h \n15- 18h -> 23h \n");
    }
    //caçapava
    if (co==2 && (cd==11 || cd==12)){
        printf("1- 6h -> 6h40 \n2- 12h -> 12h40 \n3- 19h -> 19h40 \n");
    }
    if (co==2 && (cd==1 || cd==6 || cd==7 || cd==9 || cd==10)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==2 && (cd==3 || cd==4 || cd==5 || cd==8)){
        printf("7- 5h -> 7h30 \n8- 12h -> 14h30 \n9- 19h30 -> 22h \n");
    }
    //cachoeira paulista
    if (co==3 && (cd==5 || cd==8)){
        printf("1- 6h -> 6h40 \n2- 12h -> 12h40 \n3- 19h -> 19h40 \n");
    }
    if (co==3 && (cd==1 || cd==4 || cd==6 || cd==10)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==3 && (cd==2 || cd==7 || cd==9 || cd==11 || cd==12)){
        printf("10- 5h -> 8h \n11- 12h30 -> 15h30 \n12- 19h -> 22h \n");
    }
    //caraguatatuba
    if (co==4 && (cd==3 || cd==11)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==4 && (cd==2 || cd==7 || cd==10)){
        printf("10- 5h -> 8h \n11- 12h30 -> 15h30 \n12- 19h -> 22h \n");
    }
    if (co==4 && (cd==1 || cd==6 || cd==9 || cd==12 || cd==5 || cd==8)){
        printf("13- 5h -> 10h \n14- 12h -> 17h \n15- 18h -> 23h \n");
    }
    //cruzeiro
    if (co==5 && (cd==3 || cd==8 || cd==10)){
        printf("1- 6h -> 6h40 \n2- 12h -> 12h40 \n3- 19h -> 19h40 \n");
    }
    if (co==5 && (cd==1 || cd==6)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==5 && (cd==2 || cd==9 || cd==11 || cd==12)){
        printf("7- 5h -> 7h30 \n8- 12h -> 14h30 \n9- 19h30 -> 22h \n");
    }
    if (co==5 && (cd==4 || cd==7)){
        printf("13- 5h -> 10h \n14- 12h -> 17h \n15- 18h -> 23h \n");
    }
    //guaratingueta
    if (co==6 && (cd==1 || cd==8|| cd==10)){
        printf("1- 6h -> 6h40 \n2- 12h -> 12h40 \n3- 19h -> 19h40 \n");
    }
    if (co==6 && (cd==2 || cd==3 || cd==5 || cd==9 || cd==11 || cd==12)){
        printf("7- 5h -> 7h30 \n8- 12h -> 14h30 \n9- 19h30 -> 22h \n");
    }
    if (co==6 && (cd==4 || cd==7)){
        printf("10- 5h -> 8h \n11- 12h30 -> 15h30 \n12- 19h -> 22h \n");
    }
    //jacareí
    if (co==7 && (cd==2 || cd==10|| cd==11)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==7 && (cd==1 || cd==4 || cd==6 || cd==8 || cd==9 || cd==12)){
        printf("10- 5h -> 8h \n11- 12h30 -> 15h30 \n12- 19h -> 22h \n");
    }
    if (co==7 && (cd==3 || cd==5)){
        printf("13- 5h -> 10h \n14- 12h -> 17h \n15- 18h -> 23h \n");
    }
    //lorena
    if (co==8 && (cd==1 || cd==3 || cd==5 || cd==6 || cd==10)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==8 && (cd==2 || cd==9 || cd==11 || cd==12)){
        printf("7- 5h -> 7h30 \n8- 12h -> 14h30 \n9- 19h30 -> 22h \n");
    }
    if (co==8 && (cd==4 || cd==7)){
        printf("13- 5h -> 10h \n14- 12h -> 17h \n15- 18h -> 23h \n");
    }
    //pindamonhangaba
    if (co==9 && (cd==1 || cd==2 || cd==6 || cd==8 || cd==10 || cd==12)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==9 && (cd==3 || cd==4 || cd==5 || cd==7 || cd==11)){
        printf("10- 5h -> 8h \n11- 12h30 -> 15h30 \n12- 19h -> 22h \n");
    }
    //piquete
    if (co==10 && (cd==1 || cd==5 || cd==6 || cd==8)){
        printf("1- 6h -> 6h40 \n2- 12h -> 12h40 \n3- 19h -> 19h40 \n");
    }
    if (co==10 && (cd==2 || cd==3 || cd==4 || cd==7 || cd==9 || cd==11 || cd==12)){
        printf("7- 5h -> 7h30 \n8- 12h -> 14h30 \n9- 19h30 -> 22h \n");
    }
    //são josé dos campos
    if (co==11 && (cd==1 || cd==2 || cd==7)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==11 && (cd==4 || cd==6 || cd==8 || cd==9 || cd==10 || cd==12)){
        printf("7- 5h -> 7h30 \n8- 12h -> 14h30 \n9- 19h30 -> 22h \n");
    }
    if (co==11 && (cd==3 || cd==5)){
        printf("13- 5h -> 10h \n14- 12h -> 17h \n15- 18h -> 23h \n");
    }
    //taubaté:
    if (co==12 && (cd==1 || cd==2 || cd==4 || cd==6 || cd==8 || cd==9 || cd==10 || cd==11)){
        printf("4- 5h -> 6h30 \n5- 12h -> 13h30 \n6- 19h30 -> 21h \n");
    }
    if (co==12 && (cd==3 || cd==4 || cd==5 || cd==7)){
        printf("10- 5h -> 8h \n11- 12h30 -> 15h30 \n12- 19h -> 22h \n");
    }
    return(0);
}

