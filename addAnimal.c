#include "animal.h"


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isValidSpecies(const char* species) {
    return (strcasecmp(species, "dog") == 0 ||
            strcasecmp(species, "cat") == 0 ||
            strcasecmp(species, "hamster") == 0 ||
            strcasecmp(species, "ostrich") == 0);
}

void normalizeSpecies(char* species) {
    for (int i = 0; species[i]; i++) {
        species[i] = tolower(species[i]);
    }
}

int addAnimal(Animal animals[], int *count) {
    if (*count >= MAX_ANIMALS) {
        printf("Shelter at maximum capacity (%d animals).\n", MAX_ANIMALS);
        return 0;
    }

    // Trouver un ID disponible
    int availableId = findAvailableId(animals, *count);
    if (availableId == -1) {
        printf("Error: No available ID found!\n");
        return 0;
    }

    Animal newAnimal = {0};
    newAnimal.id = availableId; // Utilisation de l'ID disponible
    
    // Collect animal data
    printf("\n=== Adding Animal ID: %d ===\n", newAnimal.id);
    
    clearInputBuffer();
    
    // Get animal name (with newline handling)
    printf("Name: ");
    fgets(newAnimal.name, sizeof(newAnimal.name), stdin);
    newAnimal.name[strcspn(newAnimal.name, "\n")] = '\0'; // Remove trailing newline
 
    // Get species with validation
    do {
        printf("Species (dog, cat, hamster, ostrich): ");
        fgets(newAnimal.species, sizeof(newAnimal.species), stdin);
        newAnimal.species[strcspn(newAnimal.species, "\n")] = '\0';
        
        if (!isValidSpecies(newAnimal.species)) {
            printf("Invalid species. Please enter one of: dog, cat, hamster, ostrich.\n");
        }
    } while (!isValidSpecies(newAnimal.species));
    
    // Normalize species to lowercase
    normalizeSpecies(newAnimal.species);
 
    // Get age with input validation
    printf("Age (years): ");
    while (scanf("%d", &newAnimal.age) != 1 || newAnimal.age < 0) {
        printf("Invalid input. Please enter a positive number: ");
        clearInputBuffer();
    }
    getchar(); // Consume the leftover newline character

    // Get weight with input validation
    printf("Weight (kg): ");
    while (scanf("%f", &newAnimal.weight) != 1 || newAnimal.weight <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        clearInputBuffer();
    }
    getchar(); // Consume the leftover newline character

    // Get optional comment
    printf("Comment (optional): ");
    fgets(newAnimal.comment, sizeof(newAnimal.comment), stdin);
    newAnimal.comment[strcspn(newAnimal.comment, "\n")] = '\0';
    
    // Save to individual file
    if (!saveAnimalToFile(&newAnimal)) {
        printf("Error: Could not save animal file!\n");
        return 0;
    }
    
    animals[(*count)++] = newAnimal;
    printf("Animal successfully registered in file %d.txt\n", newAnimal.id);
    
    return newAnimal.id;
}


