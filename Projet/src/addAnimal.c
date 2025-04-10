#include "animal.h"




int addAnimal(Animal animals[], int *count) {
    if (*count >= MAX_ANIMALS) {
        printf("Shelter at maximum capacity (%d animals).\n", MAX_ANIMALS);
        return 0;
    }

    Animal newAnimal;
    newAnimal.id = *count + 1; // Sequential ID assignment
    
    // Collect animal data
    printf("\n=== Adding Animal ID: %03d ===\n", newAnimal.id);
    
    printf("Name: ");
    fgets(newAnimal.name, MAX_NAME_LEN, stdin);
    newAnimal.name[strcspn(newAnimal.name, "\n")] = '\0';
    
    //// Get animal name (with newline handling)
    printf("Name: ");
    fgets(newAnimal.name, sizeof(newAnimal.name), stdin);
    newAnimal.name[strcspn(newAnimal.name, "\n")] = '\0'; // Remove trailing newline

    // Get species (
    printf("Species (dog, cat, hamster, ostrich, etc.): ");
    fgets(newAnimal.species, sizeof(newAnimal.species), stdin);
    newAnimal.species[strcspn(newAnimal.species, "\n")] = '\0';

    // Get age with input validation
    printf("Age (years): ");
    while (scanf("%d", &newAnimal.age) != 1 || newAnimal.age < 0) {
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    getchar(); // Consume the leftover newline character

    // Get weight with input validation
    printf("Weight (kg): ");
    while (scanf("%f", &newAnimal.weight) != 1 || newAnimal.weight <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n'); // Clear input buffer
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
    
    // Add to memory array
    animals[(*count)++] = newAnimal;
    printf("Animal successfully registered in file %03d.txt\n", newAnimal.id);
    
    return newAnimal.id;
}




