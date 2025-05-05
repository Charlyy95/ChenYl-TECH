PROG = projet

# Sources

SRC = main.c fillTable.c  addAnimal.c animal-io.c deleteAnimal.c day_clean.c inventory.c			#all file.c

#Règle par défaut : compile et exécute

all: $(PROG)
	./$(PROG)


#Compilation du programme

$(PROG): $(SRC) animal.h fillTable.h day_clean.h add-delete.h inventory.h						#all file.h
	gcc -Wall -o $(PROG) $(SRC)

#Nettoyage

clean: 
	rm -f $(PROG)
