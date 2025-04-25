#include "animal.h"
#include "fillTable.h"


void displayAnimal (Animal * tab, int * c){
	printf ("Animal n%d :\n\n", (*c+1)); 
	printf ("Id      : %d\n", tab[*c].id);
	printf ("Name    : %s\n", tab[*c].name);
	printf ("Species : %s\n", tab[*c].species);
	printf ("Age     : %d\n", tab[*c].age);
	printf ("Weight  : %.2f\n", tab[*c].weight);
	printf ("Comment : %s\n\n", tab[*c].comment);
		
}

void displayAllAnimals (Animal * tab, int *nbAnimals){			//utile que si chaque fichier rpz un animal existant dans le chenil.
	
	for (int i = 0; i<*nbAnimals; i++){
		displayAnimal (tab, &i);
	}
}

Animal *fillTable (int * nbAnimals){	
	
	FILE *f;
	
	char chain[50];
	
	Animal *tab = malloc (sizeof(Animal) * MAX_ANIMALS);
		
		if (tab == NULL){
			printf ("erreur alloc mémoire");
			exit (1);	
		}
		
	for (int a=0; a<MAX_ANIMALS; a++){	
		
		sprintf(chain, "animaux/%d.txt", a+1);				// create string "animaux/(a+1).txt"
		
		f = fopen(chain, "r");
		
		if (f == NULL){
			//printf ("erreur ouverture fichier\n");
			(*nbAnimals)--;
			continue;											//prevents reading of non-existent files
			//exit (1);
		}
		
		
		
		fscanf (f, "%d", &tab[a].id);
		fgetc(f);												//clean '\n'
		fgets  (tab[a].name, MAX_ANIMALS, f);
		tab[a].name[strcspn(tab[a].name, "\n")] = '\0'; 		//clean '\n'

		fgets  (tab[a].species, 20, f);
		tab[a].species[strcspn(tab[a].species, "\n")] = '\0';
		
		fscanf (f, "%d", &tab[a].age);
		fgetc(f);
		fscanf (f, "%f", &tab[a].weight);
		fgetc(f);
		
		fgets  (tab[a].comment, 100, f);
		tab[a].comment[strcspn(tab[a].comment, "\n")] = '\0';
		fclose (f);
		
	}
	
	printf ("\n%d animals in the shelter\n\n", *nbAnimals);
	
	return tab;
}

Animal * search (Animal * tab, int * count){
		
	int test = 0, num = 0;
	int choice = 0;
	
	int searchAge = 0;
	char searchName[50], searchSpecies[50];
	

	Animal * newTab = NULL;
	newTab = malloc (sizeof (Animal)*MAX_ANIMALS);
	
	if (newTab == NULL){
		printf ("erreur alloc memoire");
		exit(1);
	}
	
	printf ("Rechercher un animal en fonction de :\n");
	printf ("1- Nom\n");
	printf ("2- Espece\n");
	printf ("3- Age\n\n");
	
	do {
		printf("Entrer le numero souhaite : ");
		test = scanf("%d", &num);

		if (test != 1 || num < 1 || num > 3) {
			printf("Numero invalide\n");

			while (getchar() != '\n');					//clean input buffer to avoid infinite loop
		}
	} while (test != 1 || num < 1 || num > 3);
	
	if (num ==1){
		
		printf ("nom recherche (majuscule au debut) : ");
		scanf ("%s", searchName);
		printf ("\n");
		
		for (int i = 0; i<MAX_ANIMALS; i++){
			if (strcmp(tab[i].name, searchName) == 0 ){
				
				newTab[*count].id = tab[i].id;
				strcpy (newTab[*count].name, tab[i].name);
				strcpy (newTab[*count].species, tab[i].species);
				newTab[*count].age = tab[i].age;
				newTab[*count].weight = tab[i].weight;
				strcpy (newTab[*count].comment, tab[i].comment);
				
				displayAnimal (newTab, count);
				(*count)++;
				
				
			}
		}
		printf ("%d animaux correspondent a cette recherche.\n\n", *count);
		
	}
	
	if (num ==2){
		
		printf ("espece recherchee : ");
		scanf ("%s", searchSpecies);
		
		for (int i = 0; i<MAX_ANIMALS; i++){
			if (strcmp(tab[i].species, searchSpecies) == 0 ){
				
				newTab[*count].id = tab[i].id;
				strcpy (newTab[*count].name, tab[i].name);
				strcpy (newTab[*count].species, tab[i].species);
				newTab[*count].age = tab[i].age;
				newTab[*count].weight = tab[i].weight;
				strcpy (newTab[*count].comment, tab[i].comment);
				
				displayAnimal (newTab, count);
				(*count)++;
				
				
			}
		}
		printf ("%d animaux correspondent a cette recherche.\n\n", *count);
	}
	
	if (num ==3){
		
		do {
		
		printf ("Vous recherchez un animal :\n");
		printf ("1-(jeune) age inferieur a :\n");
		printf ("2-(vieux) age superieur a :\n");
		
		test = scanf("%d", &choice);

		if (test != 1 || choice < 1 || choice > 2) {
			printf("Numero invalide\n");

			while (getchar() != '\n');					//clean input buffer to avoid infinite loop
		}
	} while (test != 1 || choice < 1 || choice > 2);
		
		
		if (choice == 1){
			
			do {
			
			printf ("vous recherchez un age inferieur a :\n");
		
			test = scanf("%d", &searchAge);

			if (test != 1 || searchAge < 0 || searchAge > 50) {
				printf("Age invalide\n");

				while (getchar() != '\n');					//clean input buffer to avoid infinite loop
			}
			} while (test != 1 || searchAge < 0 || searchAge > 50);
			
			for (int i = 0; i<MAX_ANIMALS; i++){
				if (tab[i].age <= searchAge && tab[i].age>0){
					
					newTab[*count].id = tab[i].id;
					strcpy (newTab[*count].name, tab[i].name);
					strcpy (newTab[*count].species, tab[i].species);
					newTab[*count].age = tab[i].age;
					newTab[*count].weight = tab[i].weight;
					strcpy (newTab[*count].comment, tab[i].comment);
					
					displayAnimal (newTab, count);
					(*count)++;
				}
			}
			printf ("%d animaux correspondent a cette recherche.\n\n", *count);
		}			
		
		
		if (choice == 2){
			
			do {
			
			printf ("vous recherchez un age superieur a :\n");
			test = scanf("%d", &searchAge);

			if (test != 1 || searchAge < 0 || searchAge > 50) {
				printf("Age invalide\n");

				while (getchar() != '\n');					//clean input buffer to avoid infinite loop
			}
			} while (test != 1 || searchAge < 0 || searchAge > 50);
			
			for (int i = 0; i<MAX_ANIMALS; i++){
				if (tab[i].age >= searchAge && tab[i].age<50 ){
					
					
					newTab[*count].id = tab[i].id;
					strcpy (newTab[*count].name, tab[i].name);
					strcpy (newTab[*count].species, tab[i].species);
					newTab[*count].age = tab[i].age;
					newTab[*count].weight = tab[i].weight;
					strcpy (newTab[*count].comment, tab[i].comment);
					
					displayAnimal (newTab, count);
					(*count)++;
					
				}
			}
			printf ("%d animaux correspondent a cette recherche.\n\n", *count);
		}
				
	}
	
	return newTab;
}
