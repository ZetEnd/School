#include <stdio.h>

#define maxn 10

void input(int *a, int *b, int n);
void output(int *a, int n);
void quick_sort(int *a, int first, int last);
// void piramidal_sort(int *a, int n);
void swap(int *num1, int *num2);
void heapSort(int *numbers, int array_size);

int main() {
    int arr[maxn], arr1[maxn];

    input(arr, arr1, maxn);
    quick_sort(arr, 0, maxn - 1);
    output(arr, maxn);
    heapSort(arr1, maxn);
    printf("\n");
    output(arr1, maxn);

    return 0;
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle) left++;

            while (a[right] > middle) right--;

            if (left <= right) {
                swap(a + left, a + right);
                left++;
                right--;
            }

        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void input(int *a, int *b, int n) {
    int *point = b;

    for (int *p = a; p - a < n; p++) {
        scanf("%d", p);
        *point = *p;
        point++;
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
        if (p - a < n - 1) printf(" ");
    }
}

void swap(int *num1, int *num2) {
    int buf = *num1;
    *num1 = *num2;
    *num2 = buf;
}

void siftDown(int *numbers, int root, int bottom) {
    int maxChild;  // индекс максимального потомка
    int done = 0;  // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)   // если мы в последнем ряду,
            maxChild = root * 2;  // запоминаем левый потомок
        // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root];  // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else         // иначе
            done = 1;  // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size) {
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--) siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}
