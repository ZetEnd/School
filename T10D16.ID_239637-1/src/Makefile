all: strlen_tests

strlen_tests: s21_string_test.c s21_string.c
	gcc $^ -o ../build/Quest_1

strcmp_tests: s21_string_test.c s21_string.c
	gcc $^ -o ../build/Quest_2

strcpy_tests: s21_string_test.c s21_string.c
	gcc $^ -o ../build/Quest_3

strcat_tests: s21_string_test.c s21_string.c
	gcc $^ -o ../build/Quest_4

strchr_tests: s21_string_test.c s21_string.c
	gcc $^ -o ../build/Quest_5

clean:
	rm -rf .o

format:
	clang-format -i *.c
	clang-format -i *.h
