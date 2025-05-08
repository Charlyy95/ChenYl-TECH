#include "animal.h"
#include "add-delete.h"

/**
 * Finds the first available ID in the animal array
 * @param animals Array of animals
 * @param count Current number of animals
 * @return Available ID or -1 if no IDs available
 */
int findAvailableId(Animal animals[], int count) {
    // Check for gaps in ID sequence
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
    
    // If no gaps found and capacity not reached
    if (count < MAX_ANIMALS) {
        return count + 1;
    }
    
    return -1; // No available ID
}

/**
 * Saves animal data to a file
 * @param animal Pointer to animal structure
 * @return true if successful, false otherwise
 */
bool saveAnimalToFile(const Animal *animal) {
    struct stat st;
    if (stat(ANIMALS_DIR, &st) == -1) {
        mkdir(ANIMALS_DIR, 0755);
    }
    
    char filename[256];
    snprintf(filename, sizeof(filename), "%s/%d.txt", ANIMALS_DIR, animal->id);
    
    // Open file for writing
    FILE *file = fopen(filename, "w");
    if (!file) return false;
    
    // Write data
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
