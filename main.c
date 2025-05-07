#include "animal.h"
#include "fillTable.h"
#include "day_clean.h"
#include "inventory.h"
#include <unistd.h> // pour sleep/usleep
#include "add-delete.h"

void showLogo() {
    printf("\x1b[2J\x1b[H"); // Efface l'écran
    printf("\x1b[48;5;0m"); // Fond noir
    printf("\x1b[2J"); // Efface à nouveau pour appliquer le fond partout
    printf("\x1b[37m"); // Texte blanc
    printf("🌟 Bienvenue dans...\n\n");
    usleep(500000);
    printf("   ███████   ██   ██ ███████   ████       ██   ██        ██ ██\n");
    usleep(300000);
    printf("  ██         ██   ██ ██        ██  ██     ██     ██    ██   ██\n");
    usleep(300000);
    printf(" ██          ███████ ██████    ██    ██   ██   	    ██      ██\n");
    usleep(300000);
    printf(" ██          ██   ██ ██        ██      ██ ██        ██	    ██\n");
    usleep(300000);
    printf("   ███████   ██   ██ █████████ ██        ███        ██ 	    ██████████\n");
    usleep(500000);
    printf("\n                    🐾 ChenYI Animal Shelter Simulator 🐾\n");
    sleep(2);
}

int main() {
    int choice;
    int verif = 0;
    int nbAnimals = 0;
    int *pAnimals = &nbAnimals;
    
    showLogo();
    printf("\x1b[2J\x1b[H"); // Efface l'écran
    printf("\x1b[48;5;0m"); // Fond noir
    printf("\x1b[2J"); // Efface pour appliquer le fond
    printf("\x1b[37m"); // Texte blanc
    
    Animal *tabAnimal = fillTable(pAnimals);
    while (1) {
        printf("\x1b[2J\x1b[H"); // Efface l'écran
        printf("\x1b[48;5;0m"); // Fond noir
        printf("\x1b[2J"); // Efface pour appliquer le fond
        printf("\x1b[37m"); // Texte blanc
        
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
            printf("➡️ Entrer le numéro souhaité : ");
            verif = scanf("%d", &choice);
            if (verif != 1 || choice < 1 || choice > 8) {
                printf("❌ Numéro invalide !\n");
                clean_buffer();
            }
        } while (verif != 1 || choice < 1 || choice > 8);
        
        printf("\x1b[2J\x1b[H"); // Efface l'écran
        switch (choice) {
            case 1:
                printf("\x1b[48;5;232m"); // Fond gris très foncé
                printf("\x1b[2J"); // Efface pour appliquer le fond
                printf("\x1b[37m"); // Texte blanc
                printf("🐶 === Ajout d'un animal ===\n");
                if (!addAnimal(tabAnimal, pAnimals)) {
                    printf("❌ Échec de l'ajout de l'animal !\n");
                } else {
                    printf("✅ Animal ajouté avec succès !\n");
                }
                tabAnimal = fillTable(pAnimals);
                break;
                
            case 2:
                printf("\x1b[48;5;233m"); // Fond gris légèrement plus clair
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🗑️ === Suppression d'un animal ===\n");
                if (*pAnimals == 0) {
                    printf("⚠️ Aucun animal à supprimer.\n");
                    clean_buffer();
                } else {
                    int id = askAnimal(tabAnimal, *pAnimals);

                    if (id == 0){
						break;
					}
                    
                    deleteAnimalByID(tabAnimal, pAnimals, id);
                    printf("✅ Animal supprimé.\n");
                    tabAnimal = fillTable(pAnimals);
                }
                
                break;
                
            case 3:
                printf("\x1b[48;5;234m"); // Fond gris moyen
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🔍 === Recherche d'animaux ===\n");
                {
                    Animal *res = NULL;
                    Animal *newRes = NULL;
                    int test = 0;
                    int nbElement = 0;
                    int *p = &nbElement;
                    
                    res = search(tabAnimal, p, pAnimals);
                    
                    do {
                        if (*p <= 1) {
                            break;
                        }
                        
                        do {
                            printf("🔎 Pousser la recherche ?\n");
                            printf("1 - Oui\n");
                            printf("2 - Non\n");
                            test = scanf("%d", &verif);
                            printf("\n");
                            
                            if (test != 1 || verif < 1 || verif > 2) {
                                printf("❌ Numéro invalide !\n");
                                clean_buffer();
                            }
                        } while (test != 1 || verif < 1 || verif > 2);
                        
                        if (verif == 1) {
                            *p = 0;
                            newRes = search(res, p, pAnimals);
                            free(res);
                            res = newRes;
                        }
                    } while (verif == 1);
                    
                    free(res);
                    printf("✅ Recherche terminée.\n");
                }
                clean_buffer();
                break;
                
            case 4:
                printf("\x1b[48;5;235m"); // Fond gris un peu plus clair
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("📋 === Affichage de tous les animaux ===\n");
                displayAllAnimals(tabAnimal, pAnimals);
                printf("✅ Affichage terminé.\n");
                 clean_buffer();
                break;
                
            case 5:
                printf("\x1b[48;5;236m"); // Fond gris moyen-clair
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🐾 === Inventaire des espèces ===\n");
                species_inventory(tabAnimal, pAnimals);
                printf("✅ Inventaire des espèces terminé.\n");
                clean_buffer();
                break;
                
            case 6:
                printf("\x1b[48;5;237m"); // Fond gris clair
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🎂 === Inventaire des âges ===\n");
                age_inventory(tabAnimal, pAnimals);
                printf("✅ Inventaire des âges terminé.\n");
                clean_buffer();
                break;
                
            case 7:
                printf("\x1b[48;5;238m"); // Fond gris plus clair
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🧹 === Temps de nettoyage hebdomadaire ===\n");
                day_clean(tabAnimal);
                printf("✅ Calcul du temps de nettoyage terminé.\n");
                 clean_buffer();
                break;
                
            case 8:
                printf("\x1b[48;5;0m"); // Fond noir
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("🚪 === Fermeture du refuge ===\n");
                printf("Merci d'avoir utilisé ChenYI Animal Shelter Simulator ! 🐾\n");
                printf("\x1b[0m"); // Réinitialiser les couleurs
                free(tabAnimal);
                 clean_buffer();
                return 0;
                
            default:
                printf("\x1b[48;5;0m"); // Fond noir
                printf("\x1b[2J");
                printf("\x1b[37m");
                printf("❌ Choix invalide !\n");
        }
        printf("\x1b[0m"); // Réinitialiser les couleurs
        printf("\nAppuyez sur Entrée pour continuer...");
        getchar();
        
    }
}
