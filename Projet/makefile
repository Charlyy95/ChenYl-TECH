
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = shelter_app
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/addAnimal.c $(SRC_DIR)/animal-io.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Rules
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
