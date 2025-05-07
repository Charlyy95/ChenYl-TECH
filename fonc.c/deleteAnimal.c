#include "animal.h"
#include "add-delete.h"

int askAnimal(Animal *tab, int size) {
    int id;
    int exist = 0;
   int result;
    do {
       printf("Quel est l'identifiant de l'animal que vous souhaitez retirer ?\n");
        printf("Entrez 0 pour retourner au menu principal🔙.\n");
        result = scanf("%d", &id);
		
		if (id == 0){
			break;
		}

        while (getchar() != '\n'); // Vider le buffer

        if (result != 1) {
          printf("Entrée invalide. Veuillez entrer un entier.\n");
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
        printf("Aucun animal avec l'identifiant %d. Réessayez.\n", id);
    }

} while (!exist);


    return id;
}



//il faut la size du tableau l'identifiant de l'animal et le tableau de structure cette fonction retourne le tableau mis à jour
void deleteAnimalByID(Animal *tab, int *size, int idSearch) {
   if (tab == NULL || size == NULL) {
    fprintf(stderr, "Paramètre invalide passé à deleteAnimalByID\n");
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
        printf("Aucun animal avec l'ID %d trouvé.\n", idSearch);
        return; // Pas besoin de exit(1) : on arrête juste la fonction
    }

    char nameFile[100];
    sprintf(nameFile, "animaux/%d.txt", idSearch); 


    if (remove(nameFile) == 0) {
        printf("Fichier '%s' supprimé avec succès.\n", nameFile);
      } 
    else {
      perror("Erreur lors de la suppression du fichier");
}

}
