#include "animal.h"
#include "fillTable.h"
#include "day_clean.h"

float day_clean (Animal *tab){
	
	int dailyCleaningTime = 0;
	int weeklyCleaningTime = 0;
	int totalCleaningtime = 0;
	
	for (int i=0; i<MAX_ANIMALS; i++){
		
		if ((strcmp (tab[i].species, "hamster") == 0)||(strcmp (tab[i].species, "chat") == 0)){
			
			dailyCleaningTime+=HAMSTER_CAT_SHELTER * WEEK_DAYS;
			weeklyCleaningTime+= HAMSTER_CAT_SHELTER_WEEK;
		}
		
		else if (strcmp (tab[i].species, "autruche") == 0){
			
			dailyCleaningTime+=OSTRICH_SHELTER * WEEK_DAYS;
			weeklyCleaningTime+= OSTRICH_SHELTER_WEEK;
		}
		
		else if (strcmp (tab[i].species, "chien") == 0){
			
			dailyCleaningTime+=DOG_SHELTER * WEEK_DAYS;
			weeklyCleaningTime+= DOG_SHELTER_WEEK;
		}
		
		else if (strcmp (tab[i].species, "\0") == 0){
			
			dailyCleaningTime+=EMPTY_SHELTER * WEEK_DAYS;
		}
		else {
            // case of unknown species
            printf("Espece inconnue a l'index %d : \"%s\"\n", i, tab[i].species);
        }
	}
	
	totalCleaningtime = dailyCleaningTime + weeklyCleaningTime;
	
	//printf ("il y a %d animaux dans le chenil\n", count);	
	printf ("il y a %d min de nettoyage pour cette semaine \n", totalCleaningtime);
	printf ("Temps total de nettoyage : %dh %dmin \n", totalCleaningtime/60, totalCleaningtime%60);	
	
	return totalCleaningtime;
}
