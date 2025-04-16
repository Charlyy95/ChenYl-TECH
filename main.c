#include "animal.h"
#include "fillTable.h"


int main() {
    Animal shelter[MAX_ANIMALS];
    int animal_count = 0;
    int choice;

    printf("=== ChenYI-Tech Animal Shelter ===\n");
    
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Add animal\n");
        printf("2. Search animal\n");
        printf("4. Exit\n");
        printf("Choice: ");
        
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch (choice) {
            case 1 :
                if (!addAnimal(shelter, &animal_count)) {
                    printf("Failed to add animal!\n");
                }
                break;
            case 2:
                search(fillTable());
				break;
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
