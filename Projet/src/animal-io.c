#include "animal.h"



bool saveAnimalToFile(const Animal *animal) {
    // Crée le dossier s'il n'existe pas (ignore les erreurs si existe déjà)
    mkdir(ANIMALS_DIR, 0777);
    
    // Construit le nom de fichier (ex: "animaux/001.txt")
    char filename[256];
    snprintf(filename, sizeof(filename), "%s%03d.txt", ANIMALS_DIR, animal->id);
    
    // Ouvre le fichier en écriture
    FILE *file = fopen(filename, "w");
    if (!file) return false;
    
    // Écrit les données
    fprintf(file, "ID: %d\nName: %s\nSpecies: %s\nAge: %d\nWeight: %.2f\nComment: %s\n",
            animal->id,
            animal->name,
            animal->species,
            animal->age,
            animal->weight,
            animal->comment);
    
    fclose(file);
    return true;
}
