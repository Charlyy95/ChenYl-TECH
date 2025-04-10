#include "animal.h"
#include "search.h"

Animal *search (){
	
	FILE *f;
	
	int a = 1;
	
	int id[49];
	
	// Crée la chaîne de caractère complète "animaux/1"
    	sprintf(chaine, "animaux/%d", a+1);
	
	f = fopen("animaux/"a, "r");
	
	if (f == NULL){
		printf ("erreur ouverture fichier");
		exit (1);
	}
	
	Animal *tab = malloc (sizeof(Animal) * 50);
	
	if (tab == NULL){
		printf ("erreur alloc mémoire");
		exit (1);	
	}
	
	fscanf (f, "%d", &tab[1].id);
	fgetc(f); 	
	fgets  (tab[1].name, 50, f);
	fgets  (tab[1].species, 20, f);
	fscanf (f, "%d", &tab[1].age);
	fscanf (f, "%f", &tab[1].weight);
	fgetc(f); 
	fgets  (tab[1].comment, 100, f);
	
	printf ("%d\n", tab[1].id);
	printf ("%s\n", tab[1].name);
	printf ("%s\n", tab[1].species);
	printf ("%d\n", tab[1].age);
	printf ("%f\n", tab[1].weight);
	printf ("%s\n", tab[1].comment);

	return tab;
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
*/
