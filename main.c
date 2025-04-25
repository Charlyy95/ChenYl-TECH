#include "animal.h"
#include "fillTable.h"
#include "day_clean.h"

int main() {
    Animal shelter[MAX_ANIMALS];
    int animal_count = 0;
    int choice;
	int verif = 0;
	
	int nbAnimals = MAX_ANIMALS;
	int * pAnimals;
	pAnimals = &nbAnimals;
	
    printf("=== ChenYI-Tech Animal Shelter ===\n");
	
	Animal * tabAnimal = fillTable(pAnimals);			//à appeler a chaque ajout/suppr d'animaux
    
	while (1) {
        printf("\nMain Menu:\n");
        printf("1. Add animal\n");
        printf("2. Delete animal\n");
        printf("3. Search animal\n");
        printf("4. Display all animals\n");
		printf("5. Weekly cleaning time\n");
        printf("6. Exit\n");
        printf("Choice: ");
		
        do {
			printf("Entrer le numero souhaite : ");
			verif = scanf("%d", &choice);

			if (verif != 1 || choice < 1 || choice > 6) {
				printf("Numero invalide\n");

				while (getchar() != '\n');							//clean input buffer to avoid infinite loop
			}
		} while (verif != 1 || choice < 1 || choice > 6);
        
        
        switch (choice) {
            case 1 :
                if (!addAnimal(shelter, &animal_count)) {
                    printf("Failed to add animal!\n");
                }
                break;
				
			case 2 :
               //delete animal
                break;
				
            case 3: {
				
				Animal * res = NULL;
				Animal * newRes = NULL;
				
				int test = 0;
				verif = 0;
				
				int nbElement = 0;
				int *p;
				p = &nbElement;
				
				res = search(tabAnimal, p);							//first search
				
				do {
				
					
					if (*p <= 1 ) {									// if 1 or 0 animal is found, no further search
							printf("Aucun resultat trouve. Vous ne pouvez pas pousser la recherche.\n");
							break;
					}
					
					do {
						printf("Pousser la recherche ?\n");
						printf("1 - Oui\n");
						printf("2 - Non\n");

						test = scanf("%d", &verif);
						printf ("\n");
						
						if (test != 1 || verif < 1 || verif > 2) {
							printf("Numéro invalide\n");
							while (getchar() != '\n'); 				//clean buffer 
						}
					} while (test != 1 || verif < 1 || verif > 2);

					
					if (verif == 1) {								// we continue the search
						*p = 0;
						newRes = search(res, p);
						free(res);
						res = newRes;
					}

				} while (verif == 1);
				
				printf ("fin de la recherche.\n");
				free (res);
				
				break;
			}
			
			case 4 :
                displayAllAnimals (tabAnimal, pAnimals);
                break;
				
			case 5 :
                day_clean (tabAnimal);
                break;
				
			case 6 :	
                printf("Exiting...\n");
				free (tabAnimal);
                return 0;
				
            default:
                printf("Invalid choice!\n");
        }
    }
}
