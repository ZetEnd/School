FLAGS = -Wall -Wextra -Werror -std=c11
DYNAMIC_FLAGS = -fPIC -shared
FORMAT = clang-format -i

all: format build build_with_static build_with_dynamic clean

build: data_io.o data_process.o decision.o main_executable_module.o data_stat.o
	gcc $(FLAGS) data_io.o data_process.o decision.o main_executable_module.o data_stat.o -o ../../Build/Quest_3

build_with_static: data_io.o data_process.o decision.o main_executable_module.o data_stat.a
	gcc $(FLAGS) data_io.o data_process.o decision.o main_executable_module.o data_stat.a -o ../../Build/Quest_5

build_with_dynamic: data_io.o decision.o main_executable_module.o data_stat.o data_process.so
	gcc $(FLAGS) data_io.o decision.o main_executable_module.o data_stat.o data_process.so -DUSE_DYNAMIC -o ../../Build/Quest_6

data_io.o: ../data_libs/data_io.c 
	gcc $(FLAGS) -c ../data_libs/data_io.c -o data_io.o

data_process.o: ../data_module/data_process.c
	gcc $(FLAGS) -c ../data_module/data_process.c -o data_process.o

decision.o: ../yet_another_decision_module/decision.c
	gcc $(FLAGS) -c ../yet_another_decision_module/decision.c -o decision.o

main_executable_module.o: main_executable_module.c
	gcc $(FLAGS) -c main_executable_module.c -o main_executable_module.o

data_stat.o: ../data_libs/data_stat.c 
	gcc $(FLAGS) -c ../data_libs/data_stat.c -o data_stat.o

data_process.so: data_process.o data_io.o data_stat.o
	gcc $(DYNAMIC_FLAGS) $^ -o data_process.so

data_stat.a: data_stat.o
	ar rcs data_stat.a data_stat.o

format:
	$(FORMAT) ../*/*.c
	$(FORMAT) ../*/*.h

clean:
	rm -rf *.o *.a

rebuild: clean all
