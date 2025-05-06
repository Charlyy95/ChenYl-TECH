PROG = projet

# Dossiers
SRC_DIR = fonc.c
INC_DIR = header.h

# Fichiers source
SRC = main.c \
      $(SRC_DIR)/fillTable.c \
      $(SRC_DIR)/addAnimal.c \
      $(SRC_DIR)/animal-io.c \
      $(SRC_DIR)/deleteAnimal.c \
      $(SRC_DIR)/day_clean.c \
      $(SRC_DIR)/inventory.c
      
# Fichiers headers
HEADERS = $(INC_DIR)/animal.h \
          $(INC_DIR)/fillTable.h \
          $(INC_DIR)/day_clean.h \
          $(INC_DIR)/add-delete.h \
          $(INC_DIR)/inventory.h
      
#Règle par défaut : compile et exécute
all: $(PROG)
	./$(PROG)


#Compilation du programme
$(PROG): $(SRC) $(HEADERS)
	gcc -Wall -I$(INC_DIR) -o $(PROG) $(SRC)

#Nettoyage
clean: 
	rm -f $(PROG)
