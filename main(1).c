#include <stdio.h>

#include "file.h"

//funktioner som ska finnas
    /*
    1.lägga till fordon till txt fil(register) via input av användare
    2.ta bort fordon, användare ger input på position av bil som ska tas bort
    3.sortering efter bilmärke,register ska sorteras i bokstavsordning efterbilmärke
    4.skriva ut information om bil,användare ger input på position av bil som ska visas
    5.skriv ut hela fordonsregistret, ett fordon per rad och ingen info om ägare
    0. avsluta program
    
    
        *säker inmatning på allt(fgets)
        *se till att ifall man ger fel input så ska det inte krascha programmet utan bara ställa fråga igen
        *försöker ägare lägga till fordon när det är fullt ska felmeddelande visas
        *information ska hanteras lokalt i array innan det hanteras och skrivs till txt fil
        *ålder på ägare kan inte vara under 18 eller negativt då ska felmeddelande visas
    */
int secureInput() {
    //säker input som även kollar så talet inte kan vara tvåsiffrigt
    char input[size];
    int choice = -1;
    while(choice < 0 || choice > 5) {
        printf("1. Lägga till fordon\n");
        printf("2. Ta bort fordon\n");
        printf("3. Sortera bilar\n");
        printf("4. skriv ut information om bil\n");
        printf("5. skriv ut fordonsregister\n");
        printf("0. Avsluta program\n");
        
        fgets(input,sizeof(input),stdin);
        if(sscanf(input,"%d",&choice) != 1) {
            printf("felaktig input");
            choice =-1;
            continue;
        }
    }
    return choice;
}

int main() {
    int option;
    int fCarSize;
    Car carArray[size];
    //while loop som kollas med säker inmatning för alla funktioner som finns i file.c
    option = secureInput();
    do{
        switch(option) {
            case 1:
                //addCar(fCarSize,carArray);
            case 2:
                //removeCar(fCarSize,carArray);
            case 3:
                //sortCars(fCarSize,carArray);
            case 4:
                //showCar(fCarSize,carArray);
            case 5:
                //showRegistry(fCarSize,carArray);
            case 0:
                break;
            default:
                printf("försök igen");
        }
    }while(option != 0);
    
    return 0;
}


//Adrian Stude