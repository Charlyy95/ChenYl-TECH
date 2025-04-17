#include "animal.h"
#include "fillTable.h"


int main() {
    Animal shelter[MAX_ANIMALS];
    int animal_count = 0;
    int choice;
	int verif = 0;

    printf("=== ChenYI-Tech Animal Shelter ===\n");
    
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Add animal\n");
        printf("2. Search animal\n");
		printf("3. a implementer\n");
        printf("4. Exit\n");
        printf("Choice: ");
		
        do {
			printf("Entrer le numero souhaite : ");
			verif = scanf("%d", &choice);

			if (verif != 1 || choice < 1 || choice > 4) {
				printf("Numero invalide\n");

				while (getchar() != '\n');							//clean input buffer to avoid infinite loop
			}
		} while (verif != 1 || choice < 1 || choice > 4);
        
        
        switch (choice) {
            case 1 :
                if (!addAnimal(shelter, &animal_count)) {
                    printf("Failed to add animal!\n");
                }
                break;
				
            case 2: {
				
				Animal * newRes = NULL;
				Animal * res = NULL;
				
				int test = 0;
				verif = 0;
				res = search(fillTable());							//first search
				do {
					
					newRes = search(res);
					free(res);
					res = newRes;
					
					printf ("pousser la recherche ?\n");
					printf ("1- Yes\n");
					printf ("2- No\n");
					
					test = scanf("%d", &verif);
					if (test != 1 || verif < 1 || verif > 2) {
						printf("Numero invalide\n");

						while (getchar() != '\n');					//clean input buffer to avoid infinite loop
					}
				} while (test != 1 || verif < 1 || verif > 2);

				printf ("fin de la recherche.\n");
				free (res);
				
				break;
			}
			
			case 3 :
                //printf("Exiting...\n");
                break;
			case 4 :	
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
