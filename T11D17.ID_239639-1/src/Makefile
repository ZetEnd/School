TEMP = -Wall -Werror -Wextra -std=c11

ExecDir = ../build/

all: door_struct list_test

door_struct: dmanager_module.c
	gcc $(TEMP) $^ -o $(ExecDir)Quest_1

list_test: list_test.c list.c
	gcc $(TEMP) $^ -o $(ExecDir)Quest_2