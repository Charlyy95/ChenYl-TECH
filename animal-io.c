#include "animal.h"



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
    fprintf(file, "%d\nName: %s\n%s\n%d\n%.2f\n%s\n",
            animal->id,
            animal->name,
            animal->species,
            animal->age,
            animal->weight,
            animal->comment);
    
    fclose(file);
    return true;
}
