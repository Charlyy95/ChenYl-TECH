#include "animal.h"
#include "fillTable.h"
#include "day_clean.h"
#include "inventory.h"
#include "add-delete.h"
#include <unistd.h> // for sleep/usleep


void showLogo() {
    printf("\x1b[2J\x1b[H"); // Clear screen
    printf("\x1b[48;5;0m"); // Black background
    printf("\x1b[2J"); // Clear again to apply background everywhere
    printf("\x1b[37m"); // White text
    printf("🌟 Welcome to...\n\n");
    usleep(500000);
    printf("   ███████   ██   ██ ███████   ████       ██   ██        ██ ██\n");
    usleep(300000);
    printf("  ██         ██   ██ ██        ██  ██     ██     ██    ██   ██\n");
    usleep(300000);
    printf(" ██          ███████ ██████    ██    ██   ██           ██      ██\n");
    usleep(300000);
    printf(" ██          ██   ██ ██        ██      ██ ██        ██         ██\n");
    usleep(300000);
    printf("   ███████   ██   ██ █████████ ██        ███        ██         ██████████\n");
    usleep(500000);
    printf("\n                    🐾 ChenYI Animal Shelter Simulator 🐾\n");
    sleep(2);
}

int main() {
    int choice;
    int verification = 0;
    int animalCount = 0;
    int *pAnimalCount = &animalCount;
    
    showLogo();
    printf("\x1b[2J\x1b[H"); // Clear screen
    printf("\x1b[48;5;0m"); // Black background
    printf("\x1b[2J"); // Clear to apply background
    printf("\x1b[37m"); // White text
    
    Animal *animalTable = fillTable(pAnimalCount);
    while (1) {
        printf("\x1b[2J\x1b[H"); // Clear screen
        printf("\x1b[48;5;0m"); // Black background
        printf("\x1b[2J"); // Clear to apply background
        printf("\x1b[37m"); // White text
        
        printf("\n🐾 Main Menu 🐾\n");
        printf("1. Add animal 🐶\n");
        printf("2. Delete animal 🗑️\n");
        printf("3. Search animal 🔍\n");
        printf("4. Display all animals 📋\n");
        printf("5. Species inventory 🐾\n");
        printf("6. Age inventory 🎂\n");
        printf("7. Weekly cleaning time 🧹\n");
        printf("8. Exit 🚪\n");
        
        do {
            printf("➡️ Enter your choice (1-8): ");
            verification = scanf("%d", &choice);
            if (verification != 1 || choice < 1 || choice > 8) {
                printf("❌ Invalid choice!\n");
                clean_buffer();
            }
        } while (verification != 1 || choice < 1 || choice > 8);
        
        printf("\x1b[2J\x1b[H"); // Clear screen
        switch (choice) {
            case 1: // Add animal
                printf("\x1b[48;5;232m"); // Dark gray background
                printf("\x1b[2J"); // Clear to apply background
                printf("\x1b[37m"); // White text
                printf("🐶 === Add Animal ===\n");
                if (!addAnimal(animalTable, pAnimalCount)) {
                    printf("❌ Failed to add animal!\n");
                } else {
                    printf("✅ Animal added successfully!\n");
                }
                animalTable = fillTable(pAnimalCount);
                break;
                
            case 2: // Delete animal
                printf("\x1b[48;5;233m"); // Slightly lighter gray background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🗑️ === Delete Animal ===\n");
                if (*pAnimalCount == 0) {
                    printf("⚠️ No animals to delete.\n");
                    clean_buffer();
                } else {
                    int id = askAnimal(animalTable, *pAnimalCount);
                    if (id == 0) break;
                    
                    deleteAnimalByID(animalTable, pAnimalCount, id);
                    printf("✅ Animal deleted.\n");
                    animalTable = fillTable(pAnimalCount);
                }
                break;
                
            case 3: // Search animal
                printf("\x1b[48;5;234m"); // Medium gray background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🔍 === Animal Search ===\n");
                {
                    Animal *results = NULL;
                    Animal *newResults = NULL;
                    int test = 0;
                    int elementCount = 0;
                    int *pElementCount = &elementCount;
                    
                    results = search(animalTable, pElementCount, pAnimalCount);
                    
                    do {
                        if (*pElementCount <= 1) break;
                        
                        do {
                            printf("🔎 Refine search?\n");
                            printf("1 - Yes\n");
                            printf("2 - No\n");
                            test = scanf("%d", &verification);
                            printf("\n");
                            
                            if (test != 1 || verification < 1 || verification > 2) {
                                printf("❌ Invalid choice!\n");
                                clean_buffer();
                            }
                        } while (test != 1 || verification < 1 || verification > 2);
                        
                        if (verification == 1) {
                            *pElementCount = 0;
                            newResults = search(results, pElementCount, pAnimalCount);
                            free(results);
                            results = newResults;
                        }
                    } while (verification == 1);
                    
                    free(results);
                    printf("✅ Search completed.\n");
                }
                clean_buffer();
                break;
                
            case 4: // Display all animals
                printf("\x1b[48;5;235m"); // Light gray background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("📋 === All Animals ===\n");
                displayAllAnimals(animalTable, pAnimalCount);
                printf("✅ Display completed.\n");
                clean_buffer();
                break;
                
            case 5: // Species inventory
                printf("\x1b[48;5;236m"); // Medium-light gray background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🐾 === Species Inventory ===\n");
                species_inventory(animalTable, pAnimalCount);
                printf("✅ Species inventory completed.\n");
                clean_buffer();
                break;
                
            case 6: // Age inventory
                printf("\x1b[48;5;237m"); // Light gray background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🎂 === Age Inventory ===\n");
                age_inventory(animalTable, pAnimalCount);
                printf("✅ Age inventory completed.\n");
                clean_buffer();
                break;
                
            case 7: // Weekly cleaning
                printf("\x1b[48;5;238m"); // Lighter gray background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🧹 === Weekly Cleaning Time ===\n");
                day_clean(animalTable);
                printf("✅ Cleaning time calculated.\n");
                clean_buffer();
                break;
                
            case 8: // Exit
                printf("\x1b[48;5;0m"); // Black background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🚪 === Closing Shelter ===\n");
                printf("Thank you for using ChenYI Animal Shelter Simulator! 🐾\n");
                printf("\x1b[0m"); // Reset colors
                free(animalTable);
                clean_buffer();
                return 0;
                
            default:
                printf("\x1b[48;5;0m"); // Black background
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("❌ Invalid choice!\n");
        }
        printf("\x1b[0m"); // Reset colors
        printf("\nPress Enter to continue...");
        getchar();
    }
}
