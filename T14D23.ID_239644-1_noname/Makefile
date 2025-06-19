CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./src
SRC = src
BUILD = build

FILES = state_sort state_search clear_state file_utils
SRC_FILES = $(addprefix $(SRC)/, $(addsuffix .c, $(FILES)))
OBJ_FILES = $(SRC_FILES:.c=.o)

BIN_Q1 = $(BUILD)/Quest_1
BIN_Q2 = $(BUILD)/Quest_2
BIN_Q3 = $(BUILD)/Quest_3

all: $(BIN_Q1) $(BIN_Q2) $(BIN_Q3)

$(SRC)/state_sort.o: $(SRC)/state_sort.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/state_search.o: $(SRC)/state_search.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/clear_state.o: $(SRC)/clear_state.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/file_utils.o: $(SRC)/file_utils.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_Q1): $(SRC)/state_sort.o $(SRC)/file_utils.o
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_Q2): $(SRC)/state_search.o $(SRC)/file_utils.o
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_Q3): $(SRC)/clear_state.o $(SRC)/file_utils.o
	$(CC) $(CFLAGS) $^ -o $@

state_sort: $(BIN_Q1)
state_search: $(BIN_Q2)
clear_state: $(BIN_Q3)

clean:
	rm -f $(SRC)/*.o $(BUILD)/Quest_* *.tmp temp.tmp sorted.tmp

rebuild: clean all

.PHONY: all clean rebuild state_sort state_search clear_state





