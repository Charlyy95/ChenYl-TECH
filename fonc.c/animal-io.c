#include "animal.h"
#include "add-delete.h"

int findAvailableId(Animal animals[], int count){
    // Vérifie les trous dans la séquence d'IDs
    for (int id = 1; id <= MAX_ANIMALS; id++) {
        bool idUsed = false;
        for (int i = 0; i < count; i++) {
            if (animals[i].id == id) {
                idUsed = true;
                break;
            }
        }
        if (!idUsed) {
            return id;
        }
    }
    
    // Si aucun trou trouvé et capacité max non atteinte
    if (count < MAX_ANIMALS) {
        return count + 1;
    }
    
    return -1; // Aucun ID disponible
}


bool saveAnimalToFile(const Animal *animal) {
  struct stat st;
    if (stat(ANIMALS_DIR, &st) == -1) {
        mkdir(ANIMALS_DIR, 0755);
    }
    
    char filename[256];
    snprintf(filename, sizeof(filename), "%s/%d.txt", ANIMALS_DIR, animal->id);
    
    // Ouvre le fichier en écriture
    FILE *file = fopen(filename, "w");
    if (!file) return false;
    
    // Écrit les données
    fprintf(file, "%d\n%s\n%s\n%d\n%.2f\n%s\n",
            animal->id,
            animal->name,
            animal->species,
            animal->age,
            animal->weight,
            animal->comment);
    
    fclose(file);
    return true;
}
