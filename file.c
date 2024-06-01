#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "file.h"

void writetoFile(int fCarSize, Car carArray[]) {/*
    skriva till fil funktion
    ska användas i do while loop då man kört en funktion
    */
    
    /*
    kolla så att fil finns
    gör kommandot för att skriva till fil
    skriv till fil med for loop för array
    */
    
    FILE *fptr = fopen("carRegistry.txt", "w");
    
    if (fptr == NULL) {
        printf("Går inte att skriva till fil\n");
        exit(EXIT_FAILURE);
    }

    //skriver in all info om bil till fil
    //ska bara kunna lägga till tills maxstorlek nådd, 10.

    for (int i = 0; i < fCarSize; i++) {
        fprintf(fptr, "%s %s %s %s %d\n", carArray[i].type, carArray[i].brand, carArray[i].registration,carArray[i].Person.name, carArray[i].Person.age); 
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

    FILE *fptr = fopen("carRegistry.txt", "r");
    
    if (fptr == NULL) {
        printf("Går inte att läsa fil\n");
        *fCarSize = 0;
        return;
    }

    /*
    behöva gå igenom varje rad av fil
    rad för rad lägga in separat i lokal array och "dubbelkollas"
    genom = 5 då har alla delar lästs in korrekt
    */

    while (*fCarSize < maxCars && fscanf(fptr, "%s %s %s %s %d", carArray[*fCarSize].type, carArray[*fCarSize].brand, carArray[*fCarSize].registration, carArray[*fCarSize].Person.name, &carArray[*fCarSize].Person.age) == 5) {
        (*fCarSize)++;
    }

    fclose(fptr);
}

void ageNletterChecker(int *fCarSize, Car carArray[]) {
    /*
    ska kolla så att åldern på personen inte är under 18 och faktiskt är ett tal
    */
    char ageInput[size];
    int validAge = 1;

    fgets(ageInput, sizeof(ageInput), stdin);
    ageInput[strcspn(ageInput, "\n")] = '\0';

    for (int i = 0; ageInput[i] != '\0'; i++) {
        if (!isdigit(ageInput[i]) || atoi(ageInput) < 18) {
            validAge = 0;
            break;
        }
    }

    if (validAge && ageInput[0] != '\0') {
        carArray[*fCarSize].Person.age = atoi(ageInput);
    } else {
        printf("Ogiltig ålder. Försök igen.\n");
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
    if (*fCarSize < maxCars) {
        printf("Typ: ");
        fgets(carArray[*fCarSize].type, sizeof(carArray[*fCarSize].type), stdin);
        carArray[*fCarSize].type[strcspn(carArray[*fCarSize].type, "\n")] = '\0';
        
        printf("Märke: ");
        fgets(carArray[*fCarSize].brand, sizeof(carArray[*fCarSize].brand), stdin);
        carArray[*fCarSize].brand[strcspn(carArray[*fCarSize].brand, "\n")] = '\0';
        
        printf("Regnummer: ");
        fgets(carArray[*fCarSize].registration, sizeof(carArray[*fCarSize].registration), stdin);
        carArray[*fCarSize].registration[strcspn(carArray[*fCarSize].registration, "\n")] = '\0';
        
        printf("Namn på förare: ");
        fgets(carArray[*fCarSize].Person.name, sizeof(carArray[*fCarSize].Person.name), stdin);
        carArray[*fCarSize].Person.name[strcspn(carArray[*fCarSize].Person.name, "\n")] = '\0';
        
        //när ålder skrivs in måste även det kollas så att person > 18 å inte är bokstäver
        printf("Ålder på förare: ");
        ageNletterChecker(fCarSize, carArray);
        
        (*fCarSize)++;
        printf("Bil tillagd\n");
    } else {
        printf("Max antal bilar uppnått\n");
    }
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
    printf("Välj position på bil som ska bort: ");
    scanf("%d", &position);
    
    while (getchar() != '\n'); 
    //funkade inte att sätta i = position - 1;
    position--;
    
    if (position >= 0 && position < *fCarSize) {
        for (int i = position; i < *fCarSize - 1; ++i) {
            //flytta upp bilar ett steg
            carArray[i] = carArray[i + 1];
        }
        (*fCarSize)--;
        printf("Bil borttagen\n");
    } else {
        printf("Ogiltig position\n");
    }
}

void sortCars(int fCarSize, Car carArray[]) {
    /*sortera register med bilar efter bilmärke(bokstavsordning)*/

    /*
        strcmp bilmärke > 0
        bubble sort eller q sort om man nu ens får använda det
        behöver göra om alla str till småbokstäver?
    */
    for (int i = 0; i < fCarSize - 1; i++) {
        for (int j = 0; j < fCarSize - i - 1; j++) {
            if (strcmp(carArray[j].brand, carArray[j + 1].brand) > 0) {
                Car temp = carArray[j];
                carArray[j] = carArray[j + 1];
                carArray[j + 1] = temp;
            }
        }
    }
    printf("Bilar sorterade efter bilmärke\n");
}

void showCar(int fCarSize, Car carArray[]) {
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
    printf("Välj position på bil som ska visas: ");
    scanf("%d", &position);
    while (getchar() != '\n');
    //samma som för removeCar funktion
    position--;

    if (position >= 0 && position < fCarSize) {
        printf("Information om utvald bil\n");
        printf("-´`--´`--´`--´`--´`-\n");
        printf("Märke: %s\n", carArray[position].brand);
        printf("Typ: %s\n", carArray[position].type);
        printf("Regnummer: %s\n", carArray[position].registration);
        printf("Ägare: %s\n", carArray[position].Person.name);
        printf("Ålder: %d\n", carArray[position].Person.age);
        printf("-´`--´`--´`--´`--´`-\n");
    } else {
        printf("Ogiltig position\n");
    }
}

void showRegistry(int fCarSize, Car carArray[]) {
    /*ska visa hela registret med bilar i sig, ska bara visas info om bil å it ägare*/

    /*
    
    */
    
    printf("Visar register för bilar:\n");
    for (int i = 1; i < fCarSize + 1; i++) {
        printf("-´`--´`--´`--´`--´`-\n");
        printf("Bil nr: %d\n", i);
        printf("Märke: %s\n", carArray[i - 1].brand);
        printf("Typ: %s\n", carArray[i - 1].type);
        printf("Regnummer: %s\n", carArray[i - 1].registration);
        printf("-´`--´`--´`--´`--´`-\n");
    }
}


//Adrian Stude