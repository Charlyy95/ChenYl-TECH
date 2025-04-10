PROG = projet

# Sources

SRC = main.c search.c   #tous les fichiers compilés

#Règle par défaut : compile et exécute

all: $(PROG)
	./$(PROG)


#Compilation du programme

$(PROG): $(SRC) animal.h search.h
	gcc -Wall -o $(PROG) $(SRC)

#Nettoyage

clean: 
	rm -f $(PROG)
