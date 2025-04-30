#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_buffer();

void displayAnimal (Animal * tab, int * c);
void displayAllAnimals (Animal * tab, int * nbAnimals);

void saveAnimal (Animal * tab, Animal * newTab, int i, int *count);

Animal * fillTable (int *nbAnimals);
Animal * search(Animal * tab, int * count, int * pAnimals);
