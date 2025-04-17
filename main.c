#include "animal.h"
#include "fillTable.h"


void displayAnimal (Animal * tab, int c){
	printf ("Animal n%d :\n\n", (c+1)); 
	printf ("Id : %d\n", tab[c].id);
	printf ("Name : %s\n", tab[c].name);
	printf ("Species : %s\n", tab[c].species);
	printf ("Age : %d\n", tab[c].age);
	printf ("Weight : %.2f\n", tab[c].weight);
	printf ("Comment : %s\n\n", tab[c].comment);
		
}



Animal *fillTable (){			//initialisé a 50 pour etre récuperé plus tard
	
	FILE *f;
	
	char chaine[50];
	int count = 0;
	
	Animal *tab = malloc (sizeof(Animal) * MAX_ANIMALS);
		
		if (tab == NULL){
			printf ("erreur alloc mémoire");
			exit (1);	
		}
		
	for (int a=0; a<MAX_ANIMALS; a++){	
		// Crée la chaîne de caractère complète "animaux/1"
			sprintf(chaine, "animaux/%d.txt", a+1);
		
		f = fopen(chaine, "r");
		
		if (f == NULL){
			//printf ("erreur ouverture fichier\n");
			//printf ("L'animal %d n'existe pas\n", a+1);
			count++;
			continue;											//empeche la lecture de fichier vides
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
	
	printf ("\n%d places avaible in the kennel\n\n", count);
	/*
	printf ("id : %d\n", tab[a].id);
	printf ("nom : %s\n", tab[a].name);
	printf ("espece : %s\n", tab[a].species);
	printf ("age : %d\n", tab[a].age);
	printf ("poids : %f\n", tab[a].weight);
	printf ("comment : %s\n", tab[a].comment);
	*/

	return tab;
}

Animal * search (Animal * tab){
		
	int test = 0, num = 0;
	int a = 0, b = 0, c = 0;
	int choix = 0;
	
	int ageRecherche = 0;
	char nomRecherche[50], especeRecherche[50];
	
	
	
	Animal * newTab;

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
		scanf ("%s", nomRecherche);
		printf ("\n");
		
		for (int i = 0; i<MAX_ANIMALS; i++){
			if (strcmp(tab[i].name, nomRecherche) == 0 ){
				
				newTab[a].id = tab[i].id;
				strcpy (newTab[a].name, tab[i].name);
				strcpy (newTab[a].species, tab[i].species);
				newTab[a].age = tab[i].age;
				newTab[a].weight = tab[i].weight;
				strcpy (newTab[a].comment, tab[i].comment);
				
				displayAnimal (newTab, c);
				a++;
				
				
			}
		}
		printf ("%d animaux correspondent a cette recherche.\n", a);
		
	}
	
	if (num ==2){
		
		printf ("espece recherchee : ");
		scanf ("%s", especeRecherche);
		
		for (int i = 0; i<MAX_ANIMALS; i++){
			if (strcmp(tab[i].species, especeRecherche) == 0 ){
				
				newTab[b].id = tab[i].id;
				strcpy (newTab[b].name, tab[i].name);
				strcpy (newTab[b].species, tab[i].species);
				newTab[b].age = tab[i].age;
				newTab[b].weight = tab[i].weight;
				strcpy (newTab[b].comment, tab[i].comment);
				
				displayAnimal (newTab, c);
				b++;
				
				
			}
		}
		printf ("%d animaux correspondent a cette recherche.\n", b);
	}
	
	if (num ==3){
		
		do {
		
		printf ("Vous recherchez un animal :\n");
		printf ("1-(jeune) age inferieur a :\n");
		printf ("2-(vieux) age superieur a :\n");
		
		test = scanf("%d", &choix);

		if (test != 1 || choix < 1 || choix > 2) {
			printf("Numero invalide\n");

			while (getchar() != '\n');					//clean input buffer to avoid infinite loop
		}
	} while (test != 1 || choix < 1 || choix > 2);
		
		
		if (choix == 1){
			
			do {
			
			printf ("vous recherchez un age inferieur a :\n");
		
			test = scanf("%d", &ageRecherche);

			if (test != 1 || ageRecherche < 0 || ageRecherche > 50) {
				printf("Age invalide\n");

				while (getchar() != '\n');					//clean input buffer to avoid infinite loop
			}
			} while (test != 1 || ageRecherche < 0 || ageRecherche > 50);
			
			for (int i = 0; i<MAX_ANIMALS; i++){
				if (tab[i].age <= ageRecherche && tab[i].age>0){
					
					newTab[c].id = tab[i].id;
					strcpy (newTab[c].name, tab[i].name);
					strcpy (newTab[c].species, tab[i].species);
					newTab[c].age = tab[i].age;
					newTab[c].weight = tab[i].weight;
					strcpy (newTab[c].comment, tab[i].comment);
					
					displayAnimal (newTab, c);
					c++;
				}
			}
			printf ("%d animaux correspondent a cette recherche.\n", c);
		}			
		
		
		if (choix == 2){
			
			do {
			
			printf ("vous recherchez un age superieur a :\n");
			test = scanf("%d", &ageRecherche);

			if (test != 1 || ageRecherche < 0 || ageRecherche > 50) {
				printf("Age invalide\n");

				while (getchar() != '\n');					//clean input buffer to avoid infinite loop
			}
			} while (test != 1 || ageRecherche < 0 || ageRecherche > 50);
			
			for (int i = 0; i<MAX_ANIMALS; i++){
				if (tab[i].age >= ageRecherche && tab[i].age<50 ){
					
					
					newTab[c].id = tab[i].id;
					strcpy (newTab[c].name, tab[i].name);
					strcpy (newTab[c].species, tab[i].species);
					newTab[c].age = tab[i].age;
					newTab[c].weight = tab[i].weight;
					strcpy (newTab[c].comment, tab[i].comment);
					
					displayAnimal (newTab, c);
					c++;
					
				}
			}
			printf ("%d animaux correspondent a cette recherche.\n", c);
		}
				
	}
	return newTab;
}




/*
typedef struct{
int id;
char name[50];
char species[20];
int age;
float weight;
char comment[100];

}Animal;

OneDrive\Documents\CY_TECH\PREING1-2\INFO\ChenYl-TECH

*/
