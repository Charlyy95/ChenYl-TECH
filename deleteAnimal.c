#include "animal.h"
int askAnimal(Animal *tab, int size) {
    int id;
    int exist = 0;
    do {
        printf("Quel est l'identifiant de l'animal que vous souhaitez retirer ?\n");
        scanf("%d", &id);

       
        for (int i = 0; i < size; i++) {
          if ((tab + i)->id == id)  {
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
    } else {
        printf("Erreur lors de la suppression du fichier '%s'.\n", nameFile);
    }
}

  
   /*for (int i = index; i < *size - 1; i++) {
        *(tab+i) = *(tab+i+1);
    }

    (*size)--;
    tab = realloc(tab, (*size) * sizeof(Animal));
        if (tab == NULL && *size > 0) {
            perror("Erreur lors du realloc");
            exit(EXIT_FAILURE);
    }
    printf("Animal avec ID %d supprimé du tableau.\n", idSearch);
    */
    


// dans le main : 
//int id = askAnimal(animaux, size);
//supprimerAnimalParID(animaux, &size, id);
