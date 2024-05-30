#ifndef FILE_H
#define FILE_H

#define size 100
#define maxCars 10

/*
här ska konstanter, structs(klasser) allt som är statiskt i stort sätt
ska länkas ihop med de andra filerna så de kan kommunicera
*/

typedef struct {
    char type[size];
    char brand[size];
    char registration[size];
    struct {
        char name[size];
        int age;
    } Person;

} Car;

/*
alla funktioner ska läggas här
*/




#endif

//Adrian Stude