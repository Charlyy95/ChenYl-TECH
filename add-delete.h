#ifndef ADD-DELETE_H
#define ADD-DELETE_H

// System includes needed for file operations and directory creation

#include <stdio.h>    // Standard I/O operations
#include <stdlib.h>   // Memory allocation, system functions
#include <string.h>   // String manipulation functions
#include <stdbool.h>  // Boolean data type
#include <time.h>     // Time functions for random seed
#include <sys/stat.h> // Directory creation (mkdir)
#include <ctype.h>    // Character handling functions
#include <limits.h>   // For INT_MAX, etc.
// File operations
bool saveAnimalToFile(const Animal *animal);

// Animal management
int addAnimal(Animal *tabAnimal, int *count);
int askAnimal(Animal *tab, int size);
void deleteAnimalByID(Animal *tab, int *size, int idSearch);

// Input handling
void clearInputBuffer();
int getValidatedString(const char* prompt, char* buffer, size_t size);
int getValidatedInt(const char* prompt, int* value, int min, int max);
int getValidatedFloat(const char* prompt, float* value, float min, float max);

// String processing

void normalizeSpecies(char* species);
int isValidSpecies(const char* species);


// ID management
int findAvailableId(Animal animals[], int count);

#endif
