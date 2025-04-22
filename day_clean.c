#include "animal.h"
#include "fillTable.h"
#include "day_clean.h"

float day_clean (Animal *tab){
	int count = 0;
	int cleaningTime = 0;
	
	for (int i=0; i<MAX_ANIMALS; i++){
		
		if ((strcmp (tab[i].species, "hamster") == 0)||(strcmp (tab[i].species, "chat") == 0)){
			count ++;
			cleaningTime+=(HAMSTER_CAT_SHELTER * WEEK_DAYS + HAMSTER_CAT_SHELTER_WEEK);
			
		}
		
		else if (strcmp (tab[i].species, "autruche") == 0){
			count ++;
			cleaningTime+=(OSTRICH_SHELTER * WEEK_DAYS + OSTRICH_SHELTER_WEEK);
			
		}
		
		else if (strcmp (tab[i].species, "chien") == 0){
			count ++;
			cleaningTime+=(DOG_SHELTER * WEEK_DAYS + DOG_SHELTER_WEEK);
			
		}
		
		else if (strcmp (tab[i].species, "\0") == 0){
			
			cleaningTime+=(EMPTY_SHELTER * WEEK_DAYS);
			
		}
		else {
            // Cas d'espèce non reconnue
            printf("Espce inconnue à l'index %d : \"%s\"\n", i, tab[i].species);
        }
	}	
	
	//printf ("il y a %d animaux dans le chenil\n", count);	
	printf ("il y a %d min de nettoyage pour cette semaine \n", cleaningTime);
	printf ("Temps total de nettoyage : %dh %dmin \n", cleaningTime/60, cleaningTime%60);	
	
	return cleaningTime;
}