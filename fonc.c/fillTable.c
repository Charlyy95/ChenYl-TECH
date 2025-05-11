#include "animal.h"
#include "fillTable.h"

void clean_buffer(){

	while (getchar() != '\n');					//clean input buffer to avoid infinite loop for scanf
	}
	
void singularPlural(int *count){
	if (*count <= 1){
		printf ("%d animal matches this search\n", *count);
		printf ("You can't search more, end of search.\n");
	}
	else{
		printf ("%d animals match this search\n\n", *count);
	}
}
void convert_weight (float weight){
	float weight_gram = weight * 1000;
    int test_int;
	
    if (weight_gram < 1000) {
        //display g
        test_int = (int)weight_gram == weight_gram;

        if (test_int) {
            printf("Weight  : %.0f g\n", weight_gram);
        } else {
            printf("Weight  : %.2f g\n", weight_gram);
        }
    }
	else {
        // display kg
        test_int = (int)weight == weight;

        if (test_int) {
            printf("Weight  : %.0f kg\n", weight);
        } else {
            printf("Weight  : %.2f kg\n", weight);
        }
    }
}

void displayAnimal (Animal * tab, int * c){
	printf ("Animal #%d :\n\n", (*c+1)); 
	printf ("Id      : %d\n", tab[*c].id);
	printf ("Name    : %s\n", tab[*c].name);
	printf ("Species : %s\n", tab[*c].species);
	printf ("Age     : %d\n", tab[*c].age);
	convert_weight (tab[*c].weight);	
	printf ("Comment : %s\n\n", tab[*c].comment);
		
}

void displayAllAnimals (Animal * tab, int *nbAnimals){
	
	if (*nbAnimals == 0){
		printf ("No animal in the shelter\n");
		return;
	}
	
	for (int i = 0; i<*nbAnimals; i++){
		displayAnimal (tab, &i);
	}
}

void saveAnimal (Animal * tab, Animal * newTab, int i, int *count){
	
	newTab[*count].id = tab[i].id;
	strcpy (newTab[*count].name, tab[i].name);
	strcpy (newTab[*count].species, tab[i].species);
	newTab[*count].age = tab[i].age;
	newTab[*count].weight = tab[i].weight;
	strcpy (newTab[*count].comment, tab[i].comment);
		
	displayAnimal (newTab, count);
	(*count)++;
}

int calculateAge(int yearBirth){
	
	time_t t = time(NULL);			//recup actual time
	struct tm ActualDate = *localtime (&t);		//currrent year in ActualDate.tm_year 
	
	int current_year = ActualDate.tm_year + 1900;		//tm_year gives the number of years since 1900.
	
	int age = current_year - yearBirth;
	return age;
}

Animal *fillTable (int * nbAnimals){	
	
	FILE *f;
	
	char chain[50];
	*nbAnimals = 0;

	Animal *tab = malloc (sizeof(Animal) * MAX_ANIMALS);
		
		if (tab == NULL){
			printf ("memory allocation error");
			exit (1);	
		}
		
	for (int a=0; a<MAX_ANIMALS; a++){	
		
		sprintf(chain, "animaux/%d.txt", a+1);				// create string "animaux/(a+1).txt"
		
		f = fopen(chain, "r");
		
		if (f == NULL){
			continue;											//prevents reading of non-existent files
		}
				
		fscanf (f, "%d", &tab[*nbAnimals].id);
		while (fgetc(f) != '\n' && !feof(f));
												//clean '\n'
		fgets  (tab[*nbAnimals].name, MAX_ANIMALS, f);
		tab[*nbAnimals].name[strcspn(tab[*nbAnimals].name, "\n")] = '\0'; 		//clean '\n'

		fgets  (tab[*nbAnimals].species, 20, f);
		tab[*nbAnimals].species[strcspn(tab[*nbAnimals].species, "\n")] = '\0';
		
		fscanf (f, "%d", &tab[*nbAnimals].age);
		tab[*nbAnimals].age = calculateAge(tab[*nbAnimals].age);			// convert a date into an age
		while (fgetc(f) != '\n' && !feof(f));
		
		fscanf (f, "%f", &tab[*nbAnimals].weight);
		while (fgetc(f) != '\n' && !feof(f));
		
		fgets  (tab[*nbAnimals].comment, 100, f);
		tab[*nbAnimals].comment[strcspn(tab[*nbAnimals].comment, "\n")] = '\0';
		fclose (f);
		
		(*nbAnimals)++;
	}
	
	printf ("\n%d animals in the shelter\n\n", *nbAnimals);

	return tab;
}

Animal * search (Animal * tab, int * count, int * pAnimals){
		
	int test = 0, num = 0;
	int choice = 0;
	
	int searchAge = 0;
	char searchName[50], searchSpecies[50];
	

	Animal * newTab = NULL;
	newTab = malloc (sizeof (Animal)*(*pAnimals));
	
	if (newTab == NULL){
		printf ("memory allocation error");
		exit(1);
	}
	
	printf ("search for an animal based on :\n");
	printf ("1- Name\n");
	printf ("2- Species\n");
	printf ("3- Age\n\n");
	
	do {
		printf("➡️ Enter your choice : ");
		test = scanf("%d", &num);

		if (test != 1 || num < 1 || num > 3) {
			printf("Invalid choice\n");

			clean_buffer();
		}
	} while (test != 1 || num < 1 || num > 3);
	
	if (num ==1){
		
		printf ("name searched : ");
		scanf ("%s", searchName);
		printf ("\n");
		
		if (searchName[0]) {
        		searchName[0] = toupper(searchName[0]); // capitalize first lettre
   		}
   		
   		for (int i = 1; searchName[i]; i++) {
       			searchName[i] = tolower(searchName[i]); // loweracse the rest
   		}
		
		
		for (int i = 0; i<*pAnimals; i++){
			if (strcmp(tab[i].name, searchName) == 0 ){
				saveAnimal (tab, newTab, i, count);				
			}
		}
		singularPlural(count);
		
	}
	
	if (num ==2){
		
		printf ("Species searched : ");
		scanf ("%s", searchSpecies);
		
		for (int i = 0; i<*pAnimals; i++){
			if (strcmp(tab[i].species, searchSpecies) == 0 ){
				
				saveAnimal (tab, newTab, i, count);
			}
		}
		singularPlural(count);
	}
	
	if (num ==3){
		
		do {
		
		printf("Search for an animal by age:\n");
		printf("1 - Young (age below a certain value)\n");
		printf("2 - Old   (age above a certain value)\n");

		
		test = scanf("%d", &choice);

		if (test != 1 || choice < 1 || choice > 2) {
			printf("Invalide choice\n");

			clean_buffer();
		}
	} while (test != 1 || choice < 1 || choice > 2);
		
		
		if (choice == 1){
			
			do {
			
			printf("Enter the maximum age you're looking for:\n");
		
			test = scanf("%d", &searchAge);

			if (test != 1 || searchAge < 0 || searchAge > 100) {
				printf("Invalid age\n");

				clean_buffer();
			}
			} while (test != 1 || searchAge < 0 || searchAge > 100);
			
			for (int i = 0; i<*pAnimals; i++){
				if (tab[i].age <= searchAge && tab[i].age>0){
					
					saveAnimal (tab, newTab, i, count);
				}
			}
			singularPlural(count);
		}			
		
		
		if (choice == 2){
			
			do {
			
			printf("Enter the minimum age you're looking for:\n");;
			test = scanf("%d", &searchAge);

			if (test != 1 || searchAge < 0 || searchAge > 100) {
				printf("Invalid age\n");

				clean_buffer();
			}
			} while (test != 1 || searchAge < 0 || searchAge > 100);
			
			for (int i = 0; i<*pAnimals; i++){
				if (tab[i].age >= searchAge && tab[i].age ){
					
					saveAnimal (tab, newTab, i, count);
				}
			}
			singularPlural(count);
		}
				
	}
	
	return newTab;
}
