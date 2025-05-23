#include "animal.h"
#include "add-delete.h"

/**
 * Clears the input buffer
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Checks if a species is valid
 * return 1 if valid, 0 otherwise
 */
int isValidSpecies(const char* species) {
    const char *validSpecies[] = {"dog", "cat", "hamster", "ostrich"};
    for (size_t i = 0; i < sizeof(validSpecies)/sizeof(validSpecies[0]); i++) {
        if (strcasecmp(species, validSpecies[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/**
 * Normalizes a string (trim and lowercase)
 */
void normalizeString(char* str) {
    if (!str) return;
    
    // Trim leading/trailing whitespace
    size_t start = 0;
    while (isspace((unsigned char)str[start])) start++;
    
    size_t end = strlen(str);
    while (end > start && isspace((unsigned char)str[end-1])) end--;
    
    memmove(str, str + start, end - start);
    str[end - start] = '\0';
    
    // Convert to lowercase
    for (size_t i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

/**
 * Normalizes species string (trim and lowercase)
 */
void normalizeSpecies(char* species) {
    normalizeString(species);
}

/**
 * Gets and validates a string input
 * return 1 if successful
 */
int getValidatedString(const char* prompt, char* buffer, size_t size) {
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) == NULL) {
            clearInputBuffer();
            printf("Input error. Please try again.\n");
            continue;
        }

        size_t len = strcspn(buffer, "\n");
        if (len == 0) {
            printf("Input cannot be empty. Please try again.\n");
            continue;
        }

        if (len == size - 1 && buffer[len] != '\n') {
            clearInputBuffer();
            printf("Input too long. Maximum %zu characters allowed.\n", size - 1);
            continue;
        }

        buffer[len] = '\0';
        normalizeString(buffer);
        return 1;
    }
}

/**
 * Gets and validates an integer input
 * return 1 if successful
 */
int getValidatedInt(const char* prompt, int* value, int min, int max) {
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", value) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
            continue;
        }

        if (*value < min || *value > max) {
            printf("Value must be between %d and %d. Please try again.\n", min, max);
            continue;
        }

        clearInputBuffer();
        return 1;
    }
}

/**
 * Gets and validates a float input
 * return 1 if successful
 */
int getValidatedFloat(const char* prompt, float* value, float min, float max) {
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", value) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number between %.1f and %.1f.\n", min, max);
            continue;
        }

        if (*value < min || *value > max) {
            printf("Value must be between %.1f and %.1f. Please try again.\n", min, max);
            continue;
        }

        clearInputBuffer();
        return 1;
    }
}

/**
 * Adds a new animal to the shelter
 * return ID of new animal if successful, 0 otherwise
 */
int addAnimal(Animal animals[], int *count) {
    if (*count >= MAX_ANIMALS) {
        printf("Shelter full (%d animals max).\n", MAX_ANIMALS);
        return 0;
    }

    Animal newAnimal = {0};
    newAnimal.id = findAvailableId(animals, *count);
    
    if (newAnimal.id <= 0) {  // In case of -1 or 0
        printf("Error: No available ID.\n");
        return 0;
}
    printf("\nAdding Animal ID: %d\n", newAnimal.id);
    clearInputBuffer();

    // Validate and get name (no spaces allowed)
    int valid_name = 0;
    do {
        printf("Name (letters only, 2-30 chars, no spaces): ");
        if (fgets(newAnimal.name, sizeof(newAnimal.name), stdin)) {
            newAnimal.name[strcspn(newAnimal.name, "\n")] = '\0';
            
            // Basic validation
            size_t len = strlen(newAnimal.name);
            if (len < 2 || len > 30) {
                printf("Name must be 2-30 characters.\n");
                continue;
            }
            
            // Check for spaces or non-letters
            int has_space = 0;
            for (size_t i = 0; i < len; i++) {
                if (!isalpha((unsigned char)newAnimal.name[i])) {
                    if (isspace((unsigned char)newAnimal.name[i])) {
                        has_space = 1;
                    }
                    printf("Only letters allowed (no spaces or special characters).\n");
                    break;
                }
                if (i == len - 1 && !has_space) {
                    valid_name = 1; // All valid
                }
            }
        }
        
        // Capitalize first letter, lowercase the rest
        if (valid_name && strlen(newAnimal.name) > 0) {
            newAnimal.name[0] = toupper((unsigned char)newAnimal.name[0]);
            for (size_t i = 1; i < strlen(newAnimal.name); i++) {
                newAnimal.name[i] = tolower((unsigned char)newAnimal.name[i]);
            }
        }
    } while (!valid_name);

    // Get species with validation
    do {
        if (!getValidatedString("Species (dog, cat, hamster, ostrich): ", 
                              newAnimal.species, sizeof(newAnimal.species))) {
            return 0;
        }
        
        if (!isValidSpecies(newAnimal.species)) {
            printf("Invalid species. Please enter one of: dog, cat, hamster, ostrich.\n");
        }
    } while (!isValidSpecies(newAnimal.species));

    // Get age with validation
    if (!getValidatedInt("Year of Birth: ", &newAnimal.age, MIN_AGE, MAX_AGE)) {
        return 0;
    }

    // Get weight with validation
    if (!getValidatedFloat("Weight (kg, 0.001-200): ", &newAnimal.weight, MIN_WEIGHT, MAX_WEIGHT)) {
        return 0;
    }

    // Get optional comment
    printf("Comment (optional, max %zu chars): ", sizeof(newAnimal.comment) - 1);
    if (fgets(newAnimal.comment, sizeof(newAnimal.comment), stdin) != NULL) {
        newAnimal.comment[strcspn(newAnimal.comment, "\n")] = '\0';
        normalizeString(newAnimal.comment);
    } else {
        newAnimal.comment[0] = '\0';
        clearInputBuffer();
    }
    
    // Save to file
    if (!saveAnimalToFile(&newAnimal)) {
        printf("Error: Could not save animal file!\n");
        return 0;
    }
    
    // Add to array
    animals[(*count)++] = newAnimal;
    printf("Animal successfully registered in file %d.txt\n", newAnimal.id);
    
    return newAnimal.id;
}
