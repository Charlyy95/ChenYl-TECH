PROG = projet

# Sources

SRC = main.c fillTable.c  addAnimal.c animal-io.c deleteAnimal.c day_clean.c 			#all file.c

#Règle par défaut : compile et exécute

all: $(PROG)
	./$(PROG)


#Compilation du programme

$(PROG): $(SRC) animal.h fillTable.h day_clean.h						#all file.h
	gcc -Wall -o $(PROG) $(SRC)

#Nettoyage

clean: 
	rm -f $(PROG)


#if (*p == 0) { // if no animal found, no further search
                        printf("Aucun resultat trouve. Vous ne pouvez pas pousser la recherche.\n");
                        break;
                    }
                    else if (*p == 1) { // if 1 animal found, no further search
                        printf("Un seul animal existant. Vous ne pouvez pas pousser la recherche.\n");
                        break;
                    }
