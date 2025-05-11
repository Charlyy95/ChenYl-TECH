#ifndef ANIMAL_H
#define ANIMAL_H



// Constants for animal data limits
#define MAX_NAME_LEN 50       // Maximum length for animal names
#define MAX_SPECIES_LEN 20    // Maximum length for species names
#define MAX_COMMENT_LEN 100   // Maximum length for comments
#define MAX_ANIMALS 50        // Maximum shelter capacity
#define ANIMALS_DIR "animaux" // Directory to store animal files

// Validation constants
#define MIN_AGE 1950
#define MAX_AGE 2025
#define MIN_WEIGHT 0.001f
#define MAX_WEIGHT 200.0f

typedef struct {
    int id;                   // Unique ID (1-50)
    char name[MAX_NAME_LEN];  // Animal's name
    char species[MAX_SPECIES_LEN]; // Animal species (dog, cat, etc.)
    int age;                  // Age in years
    float weight;             // Weight in kilograms
    char comment[MAX_COMMENT_LEN]; // Descriptive comments
} Animal;



#endif // ANIMAL_H


