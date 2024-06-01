#ifndef FILE_H
#define FILE_H

#define maxCars 10
#define size 100

/*
här ska konstanter, structs(klasser) allt som är statiskt i stort sätt
ska länkas ihop med de andra filerna så de kan kommunicera
*/


typedef struct {
    char name[size];
    int age;
} Person;

typedef struct {
    char type[size];
    char brand[size];
    char registration[size];
    Person Person;
} Car;

/*
alla funktioner ska läggas här
*/

void writetoFile(int fCarSize, Car carArray[]);
void readFromFile(int *fCarSize, Car carArray[]);
void addCar(int *fCarSize, Car carArray[]);
void removeCar(int *fCarSize, Car carArray[]);
void sortCars(int fCarSize, Car carArray[]);
void showCar(int fCarSize, Car carArray[]);
void showRegistry(int fCarSize, Car carArray[]);
void ageNletterChecker(int *fCarSize, Car carArray[]);

#endif


//Adrian Stude