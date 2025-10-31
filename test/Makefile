# === Makefile for cub3d unit tests (one executable per test file) ===

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Dossiers
ROOT_DIR = ..
SRC_DIR = $(ROOT_DIR)/SRC
UNITY_DIR = Unity/src
TESTS_DIR = tests

# Fichiers sources du projet
PROJECT_SRC = \
	$(SRC_DIR)/PARSE_MAP/check_extension.c \
	$(SRC_DIR)/GNL/get_next_line.c \
	$(SRC_DIR)/GNL/get_next_line_utils.c

# Fichiers Unity
UNITY_SRC = $(UNITY_DIR)/unity.c

# Fichiers de test
TEST_FILES = $(wildcard $(TESTS_DIR)/*.c)

# Liste des exécutables (un par fichier de test)
TEST_BINS = $(basename $(notdir $(TEST_FILES)))

# Includes
INCLUDES = -I$(UNITY_DIR) -I$(SRC_DIR)/PARSE_MAP -I$(SRC_DIR)/GNL -I$(ROOT_DIR)

.PHONY: all clean re tests_run run_one

# Compilation de tous les tests (un exécutable par fichier)
all: $(TEST_BINS)

# Règle générique : compile un test individuel
%: $(TESTS_DIR)/%.c $(UNITY_SRC) $(PROJECT_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Exécution de tous les tests
tests_run: all
	@echo "\n--- Running all unit tests ---"
	@for test in $(TEST_BINS); do \
		echo "\n>>> Running $$test:"; \
		./$$test || exit 1; \
	done
	@echo "\n✅ All tests passed successfully!"

# Exécution d’un seul test : make run_one TEST=test_check_extension
run_one:
	@if [ -z "$(TEST)" ]; then \
		echo "Usage: make run_one TEST=test_check_extension"; \
		exit 1; \
	fi
	@if [ ! -f "$(TEST)" ]; then \
		echo "Error: $(TEST) not built yet. Run 'make' first."; \
		exit 1; \
	fi
	@echo "\n>>> Running $(TEST):"
	@./$(TEST)

# Nettoyage
clean:
	rm -f $(TEST_BINS) */*.o */*/*.o

re: clean all

