//cette fonction demande à l'utilisateur quel animal est adopter et donc doit etre retirer elle verifie si il existe bien et retourne son identifiant 
int askAnimal(animal *tab, int taille) {
    int id;
    int existe = 0;

    do {
        printf("Quel est l'identifiant de l'animal que vous souhaitez retirer ?\n");
        scanf("%d", &id);

       
        for (int i = 0; i < taille; i++) {
            if (*(tab+i).id == id) {
                existe = 1;
                break;
            }
        }

        if (!existe) {
            printf("Aucun animal avec l'identifiant %d. Réessayez.\n", id);
        }

    } while (!existe);

    return id;
}



//il faut la taille du tableau l'identifiant de l'animal et le tableau de structure cette fonction retourne le tableau mis à jour
animal* supprimerAnimalParID(animal *tab, int *taille, int idRecherche) {
   
    int index = -1;
    for (int i = 0; i < *taille; i++) {
        if (*(tab+i).id == idRecherche) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Aucun animal avec l'ID %d trouvé.\n", idRecherche);
        return tab;
    }

    
    char nomFichier[100];
    sprintf(nomFichier, "%d.txt", idRecherche); 


    if (remove(nomFichier) == 0) {
        printf("Fichier '%s' supprimé avec succès.\n", nomFichier);
    } else {
        printf("Erreur lors de la suppression du fichier '%s'.\n", nomFichier);
    }

  
    for (int i = index; i < *taille - 1; i++) {
        *(tab+i) = *(tab+i+1);
    }

    (*taille)--;

    printf("Animal avec ID %d supprimé du tableau.\n", idRecherche);
    return tab;
}
