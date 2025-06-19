# Флаги компиляции и линковки
CFLAGS = -std=c11 -Wall -Wextra -Werror -c
LDFLAGS = -std=c11 -Wall -Wextra -Werror

all: ../build/graph

# Линковка: создаём исполняемый файл из объектных файлов
../build/graph: graph.o lexer.o parser.o evaluator.o
	gcc $(LDFLAGS) ../build/graph.o ../build/lexer.o ../build/parser.o ../build/evaluator.o -o ../build/graph

graph.o: graph.c lexer.h parser.h evaluator.h graph.h
	gcc $(CFLAGS) graph.c -o ../build/graph.o

lexer.o: lexer.c lexer.h
	gcc $(CFLAGS) lexer.c -o ../build/lexer.o

parser.o: parser.c parser.h lexer.h
	gcc $(CFLAGS) parser.c -o ../build/parser.o

evaluator.o: evaluator.c evaluator.h lexer.h
	gcc $(CFLAGS) evaluator.c -o ../build/evaluator.o

clean:
	rm -f ../build/*.o ../build/graph
	
rebuild: clean all