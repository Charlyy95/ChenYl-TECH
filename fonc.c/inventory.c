#include "animal.h"
#include "inventory.h"
#include "fillTable.h"


void speciesInsertionSort(SpeciesCount *tab, int n){
	
	for (int i = 1; i < n; i++) {
        SpeciesCount key = tab[i];		//key is the element compared to the others
        int j = i - 1;
		
        while (j >= 0 && tab[j].count < key.count) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

void ageInsertionSort(int *tab, int size){
	
	for (int i = 1; i < size; i++) {
        int key = tab[i];		//key is the element compared to the others
        int j = i - 1;
		
        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

void species_inventory(Animal *tab, int *pAnimals) {
	
	int hamster_count = 0;
	int cat_count = 0;
	int ostrich_count = 0;
	int dog_count = 0;
	int other_count = 0;
	
	if (*pAnimals == 0){
		printf ("No animal in the shelter\n");
		return;
	}
	for (int i = 0; i< *pAnimals; i++){			//count all species
		if (strcmp(tab[i].species,"hamster")==0){
			hamster_count+=1;
		}
		else if (strcmp(tab[i].species,"cat")==0){
			cat_count+=1;
		}
		else if (strcmp(tab[i].species,"ostrich")==0){
			ostrich_count+=1;
		}
		else if (strcmp(tab[i].species,"dog")==0){
			dog_count+=1;
		}
		else{
			other_count+=1;
		}
	}
	
	SpeciesCount species_tab[] = {
    {"hamster ", hamster_count},
    {"cat     ", cat_count},
    {"ostrich ", ostrich_count},
    {"dog     ", dog_count},
    {"other   ", other_count}
	};
	
	speciesInsertionSort(species_tab, TOTAL_SPECIES + 1);
	
	printf ("In our shelter we have %d animals :\n\n", *pAnimals);
	
	for (int i = 0; i < TOTAL_SPECIES+1; i++) {					//display all species in ascending order
		printf("%s : %d\n", species_tab[i].species, species_tab[i].count);
	}
	
}


void age_inventory (Animal*tab, int *pAnimals){
	
	int * newTab;
	int quartile = *pAnimals /4;
	newTab = malloc (sizeof (int) * (*pAnimals));
	if (newTab == NULL) {
   		printf("Error : memory allocation problem\n");
   	exit(1);
	}
	
	if (*pAnimals == 0){
			printf ("No animal in the shelter\n");
			return;
	}
	
	for (int i = 0; i< *pAnimals; i++){
		
		newTab[i] = tab[i].age;
	}
	
	
	
	ageInsertionSort (newTab, *pAnimals);
	
	for (int i = 0; i < 4; i++) {
        int start = i * quartile;
        int end;
		
		if (i == 3) {
			end = *pAnimals - 1;
		} else {
			end = (i + 1) * quartile - 1;
		}
	
        printf("Quartile %d : %d animals (aged %d to %d)\n", i + 1, end - start + 1, newTab[start], newTab[end]);
	}
	
	free (newTab);
}
