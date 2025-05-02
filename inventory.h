#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SPECIES 4

typedef struct {
    char species[20];
    int count;
}SpeciesCount;

void speciesInsertionSort(SpeciesCount *tab, int n);
void ageInsertionSort(int *tab, int *pAnimals);

void species_inventory(Animal * tab, int * pAnimals);
void age_inventory (Animal*tab, int *pAnimals);