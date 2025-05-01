#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clean_buffer();

void singularPlural(int *count);
void convert_weight (float weight);


void displayAnimal (Animal * tab, int * c);
void displayAllAnimals (Animal * tab, int * nbAnimals);

void saveAnimal (Animal * tab, Animal * newTab, int i, int *count);
int calculateAge(int yearBirth);

Animal * fillTable (int *nbAnimals);
Animal * search(Animal * tab, int * count, int * pAnimals);
