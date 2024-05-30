#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "file.h"

void writeToFile(int *fCarSize, Car carArray[]) {
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

void readFromFile(int *fCarSize, Car carArray[]) {
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
    rad för rad lägga in separat i lokal array och "dubbelkollas"
    genom = 5 då har alla delar lästs in korrekt
    */
    
    while(*fCarSize <= maxCars && fscanf(fptr,"%s %s %s %s %d"
          ,carArray[*fCarSize].type,carArray[*fCarSize].brand,carArray[*fCarSize].registration,carArray[*fCarSize].Person.name
          ,carArray[*fCarSize].Person.age) == 5) {
        *fCarSize++;
    }
    
    fclose(fptr);
}

void ageNletterChecker(Car carArray[], int fCarSize) {
        /*
        ska kolla så att åldern på personen inte är under 18 och faktiskt är ett tal
        */    
    char ageInput[size];
    int rättÅlder = 1;
    
    fgets(ageInput,sizeof(ageInput),stdin);
    ageInput[sscanf(ageInput,"\n")] = '\0';
    
      for(int i = 0; ageInput != '\0';i++) {
        if(!isdigit(ageInput[i]) || ageInput[i] < 18) {
            rättÅlder = 0;
            break;
        }
    }
    
    if(rättÅlder && ageInput[0] != '\0') {
        carArray[fCarSize].Person.age = atoi(ageInput);
    }
}

void addCar(int *fCarSize, Car carArray[]) {
    /*
    ska lägga till en bil i registret(txt fil) och öka numrering med 1
    är registret fullt aka 10 så ska man inte kunna lägga till fler bilar
    */
    
    /*
    skriva in info till lokal arr
    fgets ger \0 i varje så använd sscanf för att ta bort \n mot \0 
    så de kan läggas på samma rad
    */
    if(*fCarSize >= maxCars) {
        printf("max antal bilar uppnått");
        return;
    }
        fgets(carArray[*fCarSize].type,sizeof(carArray[*fCarSize]),stdin);
            carArray[*fCarSize].type[strcspn(carArray[*fCarSize].type,"\n")] = '\0';
              
        fgets(carArray[*fCarSize].brand,sizeof(carArray[*fCarSize]),stdin);
              carArray[*fCarSize].brand[strcspn(carArray[*fCarSize].brand,"\n")] = '\0';
              
        fgets(carArray[*fCarSize].registration,sizeof(carArray[*fCarSize]),stdin);
              carArray[*fCarSize].registration[strcspn(carArray[*fCarSize].registration,"\n")] = '\0';
              
        fgets(carArray[*fCarSize].Person.name,sizeof(carArray[*fCarSize]),stdin);
              carArray[*fCarSize].Person.name[strcspn(carArray[*fCarSize].Person.name,"\n")] = '\0';
              
        //när ålder skrivs in måste även det kollas så att person > 18 å inte är bokstäver
        ageNletterChecker(carArray,*fCarSize);
        
        printf("bil tillagd");
        fCarSize++;
}

void removeCar(int *fCarSize, Car carArray[]) {
    /*
    ta bort fil från registret mha input från användare om position och minska numrering med 1
    är register tomt ska det visas ett felmeddelande om att det är tomt
    */

    /*
    ta position för vilken bil som ska bort
    position måste vara giltig
    leta upp bil på position och ta bort
    minska antalbilar fCarSize--
    flytta upp resterande bilar under ett steg upp
    */
    
    int position; 
    scanf("%d",&position);
    
    while(position >= 0 && position <= maxCars) {
        for(int i = position; i < maxCars; i++) {
        //flytta upp bilar ett steg
        carArray[position] = carArray[position - 1];
            
        printf("bil borttagen");
        *fCarSize--;
        }
    }
}

void sortCars(int *fCarSize, Car carArray[]) {
    /*sortera register med bilar efter bilmärke(bokstavsordning)*/

    /*
        strcmp bilmärke > 0
        bubble sort eller q sort om man nu ens får använda det
        behöver göra om alla str till småbokstäver?
    */
    
    for(int i = 0; i < maxCars - 1;i++) {
        for(int j = 0; j < maxCars - i - 1; j++) {
            if(strcmp(carArray[j].brand, carArray[j + 1].brand) > 0) {
                char temp[size];
                strcpy(temp,carArray[j].brand);
                strcpy(carArray[j].brand, carArray[j + 1].brand);
                strcpy(carArray[j + 1].brand, temp);
            }
        }
    }
}

void showCar(int *fCarSize, Car carArray[]) {
    /*
    ska visa information om en bil, information om allt + info om ägare
    användare ska få ge input om vilken bil(position) finns bilen så ska den skrivas ut
    position - 1 pga array startar på 0 
    */

    /*
    gör en snygg ruta för att visa info 
    typ -´`--´`--´`--´`--´`-
            info här
    
        -´`--´`--´`--´`--´`-
    */
    
    int position;
    scanf("%d",&position);
    if(position >= 0 && position <= maxCars) {
        printf("Information om utvald bil\n");
        printf("-´`--´`--´`--´`--´`-\n");
        printf("%s\n",carArray[position - 1].brand);
        printf("%s\n",carArray[position - 1].type);
        printf("%s\n",carArray[position - 1].registration);
        printf("%s\n",carArray[position - 1].Person.name);
        printf("%d\n",carArray[position - 1].Person.age);
        printf("-´`--´`--´`--´`--´`-\n");
    }
}

void showRegistry(int *fCarSize, Car carArray[]) {
    /*ska visa hela registret med bilar i sig, ska bara visas info om bil å it ägare*/

    /*
    
    */
    
    for(int i = 0; i < *fCarSize;i++) {
        printf("-´`--´`--´`--´`--´`-\n");
        printf("bil nmr: %d\n", (i - 1));
        printf("Bil märke %s\n",carArray[i].brand);
        printf("Bil typ %s\n",carArray[i].type);
        printf("Bil regnummer %s\n",carArray[i].registration);
        printf("-´`--´`--´`--´`--´`-\n");
    }
}


//Adrian Stude