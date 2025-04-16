#ifndef ANIMAL_H
#define ANIMAL_H

// System includes needed for file operations and directory creation
#include <stdio.h>    // Standard I/O operations
#include <stdlib.h>   // Memory allocation, system functions
#include <string.h>   // String manipulation functions
#include <stdbool.h>  // Boolean data type
#include <time.h>     // Time functions for random seed
#include <sys/stat.h> // Directory creation (mkdir)

// Constants for animal data limits
#define MAX_NAME_LEN 50       // Maximum length for animal names
#define MAX_SPECIES_LEN 20    // Maximum length for species names
#define MAX_COMMENT_LEN 100   // Maximum length for comments
#define MAX_ANIMALS 50        // Maximum shelter capacity
#define ANIMALS_DIR "animaux/" // Directory to store animal files


typedef struct {
    int id;                   // Unique ID (1-50)
    char name[MAX_NAME_LEN];  //Animal's name
    char species[MAX_SPECIES_LEN]; // Animal species (dog, cat, etc.)
    int age;                  //Age in years
    float weight;             // Weight in kilograms
    char comment[MAX_COMMENT_LEN]; // Descriptive comments
} Animal;

// Function prototypes
bool saveAnimalToFile(const Animal *animal);
int addAnimal(Animal animals[], int *count);

#endif // ANIMAL_H


