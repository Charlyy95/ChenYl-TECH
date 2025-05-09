#include "animal.h"
#include "add-delete.h"

int askAnimal(Animal *tab, int size) {
    int id;
    int exist = 0;
   int result;
    do {
       printf("What is the ID of the animal you want to remove?\n");
        printf("Enter 0 to return to the main menu.🔙.\n");
        result = scanf("%d", &id); //Stores 1 if a readable integer character is successfully read.
		
		if (id == 0){
			break;
		}

        while (getchar() != '\n'); // Clean buffer

        if (result != 1) {
          printf("Invalid input. Please enter an integer.\n");
          continue;
      }

      exist = 0;
      for (int i = 0; i < size; i++) {
          if (tab[i].id == id) {
              exist = 1;
              break;
        }
    }

    if (!exist) {
        printf("No animal with ID %d. Please try again.\n", id);
    }

} while (!exist);


    return id;
}




void deleteAnimalByID(Animal *tab, int *size, int idSearch) {
   if (tab == NULL || size == NULL) { // Check if the pointers are valid.
    fprintf(stderr, "Invalid parameter passed to deleteAnimalByID\n");
    return;
}

    int exist = 0;
    for (int i = 0; i < *size; i++) {
        if ((tab + i)->id == idSearch) {
            exist = 1;
            break;
        }
    }

    if (!exist) {
        printf("No animal with ID %d found.\n", idSearch);
        return; 
    }

    char nameFile[100];
    sprintf(nameFile, "animaux/%d.txt", idSearch); 


    if (remove(nameFile) == 0) {
        printf("File '%s' successfully deleted.\n", nameFile);
      } 
    else {
      perror("Error while deleting the file.");
}

}
