/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define MAXN 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, arr[MAXN], mas_out[MAXN];
    input(arr, &n);
    if (n <= 0) {
        printf("n/a");
    } else {
        int sum = sum_numbers(arr, n);
        printf("%d\n", sum);
        int num_mas = find_numbers(arr, n, sum, mas_out);
        output(mas_out, num_mas);
    }

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % 2 == 0 && *(buffer + i) != 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

void input(int *buffer, int *length) {
    if (scanf("%d", length) != 1) {
        *length = -1;
    }

    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1) {
            *length = -1;
            break;
        }
    }
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d ", *p);
        if (p - buffer < length - 1) printf(" ");
    }
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    // int sum = sum_numbers(buffer,length);
    int count = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p == 0) continue;
        if (number % (*p) == 0) {
            *(numbers + count) = *p;
            count++;
        }
    }

    return count;
}
