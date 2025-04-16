PROG = projet

# Sources

SRC = main.c fillTable.c  addAnimal.c animal-io.c #tous les fichiers compilés

#Règle par défaut : compile et exécute

all: $(PROG)
	./$(PROG)


#Compilation du programme

$(PROG): $(SRC) animal.h fillTable.h
	gcc -Wall -o $(PROG) $(SRC)

#Nettoyage

clean: 
	rm -f $(PROG)
