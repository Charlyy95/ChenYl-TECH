#include "animal.h"
#include "fillTable.h"
#include "day_clean.h"

int main() {
    
    int animal_count = 0;
    int choice;
	int verif = 0;
	
	int nbAnimals = 0;
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
		
        do {
			printf("Entrer le numero souhaite : ");
			verif = scanf("%d", &choice);

			if (verif != 1 || choice < 1 || choice > 6) {
				printf("Numero invalide\n");

				clean_buffer();
			}
		} while (verif != 1 || choice < 1 || choice > 6);
        
        
        switch (choice) {
            case 1 :
                if (!addAnimal(tabAnimal, &animal_count)) {
                    printf("Failed to add animal!\n");
                }
                break;
				
		case 2: {
                if (*pAnimals== 0) {
                    printf("Aucun animal à supprimer.\n");
                    break;
                }

                int id = askAnimal(tabAnimal, *pAnimals); 
                deleteAnimalByID(tabAnimal, pAnimals, id); 
                tabAnimal = fillTable(pAnimals);
                break;
            }
                
				
            case 3: {
				
				Animal * res = NULL;
				Animal * newRes = NULL;
				
				int test = 0;
				verif = 0;
				
				int nbElement = 0;
				int *p;
				p = &nbElement;
				
				res = search(tabAnimal, p, pAnimals);			//first search
				
				do {
				
					if (*p <= 1 ){		// if 1 or 0 animal is found, no further search
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
							clean_buffer();
						}
					} while (test != 1 || verif < 1 || verif > 2);

					
					if (verif == 1) {			//continue to search
						*p = 0;
						newRes = search(res, p, pAnimals);
						free(res);
						res = newRes;
					}

				} while (verif == 1);
				
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
