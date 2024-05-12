#include <stdio.h>

#include "file.h"

void writeToFile(int fCarSize, char carArray[]) {
    /*
    skriva till fil funktion
    ska användas i do while loop då man kört en funktion
    */
    
    /*
    kolla så att fil finns
    gör kommandot för att skriva till fil
    skriv till fil med for loop för array
    */
    
    FILE *fptr;
    fopen("carRegistry.txt","a");
    
    if(fptr == NULL) {
        printf("går inte att skriva till fil");
        exit(EXIT_FAILURE);
    }
    //skriver in all info om bil till fil
    //ska bara kunna lägga till tills maxstorlek nådd, 10.
    for(int i = 0; i < size; i++) {
        fprintf(fptr,"%s %s %s %s %d",carArray[i].type,carArray[i].brand,carArray[i].registration,carArray[i].Person.name
                ,carArray[i].Person.age); 
    }
    
    fclose(fptr);
}

void readFromFile(int fCarSize, char carArray[]) {
    /*
    läsa från fil funktion, ska användas i main i do while loop för att hållas uppdaterad
    */
    
    /*
    kolla så fil finns
    gör kommado för att läsa från fil och lägg in i array
    */

    FILE *fptr;
    fopen("carRegistry.txt","r");
    
    if(fptr == NULL) {
        printf("går inte att läsa fil");
        fCarSize = 0;
        exit(EXIT_FAILURE);
    }
    
    /*
    behöva gå igenom varje rad av fil
    rad för rad lägga in separat i lokal array
    */
    while(fCarSize <= maxCars && fscanf(fptr,"%s %s %s %s %d"
          ,carArray[fCarSize].type,carArray[fCarSize].brand,carArray[fCarSize].registration,carArray[fCarSize].Person.name
          ,carArray[fCarSize].Person.age) == 5) {
        fCarSize++;
    }
    
    fclose(fptr);
}

void addCar(int fCarSize, char carArray[]) {
    /*
    ska lägga till en bil i registret(txt fil) och öka numrering med 1
    är registret fullt aka 10 så ska man inte kunna lägga till fler bilar
    */
    
    /*
    
    */
    for(i = fCarSize; i < maxCars;i++) {
        //skriva in info till lokal arr
    }

}

void removeCar(int fCarSize, char carArray[]) {
    /*
    ta bort fil från registret mha input från användare om position och minska numrering med 1
    är register tomt ska det visas ett felmeddelande om att det är tomt
    */

    /*
    ta position för vilken bil som ska bort
    leta upp bil på position och ta bort
    minska antalbilar fCarSize--
    flytta upp resterande bilar under ett steg upp
    */
}

void sortCars(int fCarSize, char carArray[]) {
    /*sortera register med bilar efter bilmärke(bokstavsordning)*/

    /*
        strcmp bilmärke > 0
        bubble sort eller q sort om man nu ens får använda det
    */
}

void showCar(int fCarSize, char carArray[]) {
    /*ska visa information om en bil, information om allt + info om ägare*/

    /*
    
    */
}

void showRegistry(int fCarSize, char carArray[]) {
    /*ska visa hela registret med bilar i sig, ska bara visas info om bil å it ägare*/

    /*
    
    */
}


//Adrian Stude