//cette fonction demande à l'utilisateur quel animal est adopter et donc doit etre retirer elle verifie si il existe bien et retourne son identifiant 
int askAnimal(animal *tab, int size) {
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
animal* deleteAnimalByID(animal *tab, int *size, int idSearch) {
   
    int index = -1;
    for (int i = 0; i < *size; i++) {
       if ((tab + i)->id == idSearch) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Aucun animal avec l'ID %d trouvé.\n", idSearch);
        return tab;
    }

    
    char nameFile[100];
    sprintf(nameFile, "%d.txt", idSearch); 


    if (remove(nameFile) == 0) {
        printf("Fichier '%s' supprimé avec succès.\n", nameFile);
    } else {
        printf("Erreur lors de la suppression du fichier '%s'.\n", nameFile);
    }

  
    for (int i = index; i < *size - 1; i++) {
        *(tab+i) = *(tab+i+1);
    }

    (*size)--;
    tab = realloc(tab, (*size) * sizeof(animal));
        if (tab == NULL && *size > 0) {
            perror("Erreur lors du realloc");
            exit(EXIT_FAILURE);
    }
    printf("Animal avec ID %d supprimé du tableau.\n", idSearch);
    return tab;
}
// dans le main : 
//int id = askAnimal(animaux, size);
//supprimerAnimalParID(animaux, &size, id);
