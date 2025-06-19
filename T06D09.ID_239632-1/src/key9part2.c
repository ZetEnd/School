#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int whisbigger(int *buff1, int len1, int *buff2, int len2);
void input(int *a, int *n);
void output(int *a, int n);
int outzero(int *a, int *n);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int arr1[LEN], n1, arr2[LEN], n2, res1[LEN], nres1, res2[LEN+1], nres2;

    input(arr1, &n1);
    input(arr2, &n2);
    // printf("dwd");
    // printf("%d %d", n1, n2);
    arr1 = arr1 + outzero(arr1, &n1);
    arr2 = arr2 + outzero(arr2, &n2);
    if(whisbigger(arr1, n1, arr2, n2) == 0){
      printf("n/a");
    } else {

    sum(arr1, n1, arr2, n2, res1, &nres1);
    sub(arr1, n1, arr2, n2, res2, &nres2);
    // output(arr1, n1);
    // output(arr2, n2);
    output(res1, nres1);
    output(res2, nres2);

  }
    // printf("%d %d", n1, n2);
    return 0;
}
int outzero(int *a, int *n){

  int * rn = a;
  int count = 0;
  while (*rn == 0 && rn - a < *n-1) {
      rn++;
      count ++;
  }

  return count;

}
int whisbigger(int *buff1, int len1, int *buff2, int len2){

  int flag = 1;

  if( len1 < len2){
    flag = 0;
  } else {
    int count = 0;

    int *p1 = buff1;
    int *p2 = buff2;
    if(*(p1+count) < *(p2+count)) flag = 0;

    while(*(p1+count) >= *(p2+count)){
      if(*(p1+count) < *(p2+count)){
        flag = 0;
        break;
      }
      count++;

    }
  }

  return flag;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    // printf("@ff");
    int flag;
    int minN = len1;
    *result_length = len2;
    if (len2 < len1) {
        minN = len2;
        *result_length = len1;
        flag = 1;
    } else {
        flag = 0;
    }

    // for(int *p = a+n-1; p >= a; )

    int *point1 = buff1 + len1 - 1;
    int *point2 = buff2 + len2 - 1;

    int *res_point = result + *result_length - 1;

    int left_part_res = *result_length - minN;

    int ost = 0;
    // printf("- %d - stoko -", minN);

    while (minN - 1 >= 0) {
        int res = (*point1 + *point2 + ost);

        *res_point = res % 10;
        ost = res / 10;
        point1--;
        point2--;
        res_point--;

        minN--;
        // printf(" %d tyta -", minN);
    }
    // printf("+%d +", left_part_res);

    if (flag == 0) {
        while (left_part_res - 1 >= 0) {
            *res_point = *point2 + ost;
            res_point--;
            point2--;
            ost = 0;
            left_part_res--;
        }
    } else {
        while (left_part_res - 1 >= 0) {
            *res_point = *point1 + ost;
            res_point--;
            point1--;
            ost = 0;
            left_part_res--;
        }
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int flag = 0;
    int minN = len1;
    *result_length = len2;
    if (len2 < len1) {
        minN = len2;
        *result_length = len1;
        flag = 1;
    }

    // for(int *p = a+n-1; p >= a; )

    int *point1 = buff1 + len1 - 1;
    int *point2 = buff2 + len2 - 1;

    int *res_point = result + *result_length - 1;

    int left_part_res = *result_length - minN;

    int ost = 0;
    // printf("- %d - stoko -", minN);

    while (minN - 1 >= 0) {
        int res;
        if (*point1 == 0 && ost + *point2 > 0) {
            res = 10 - *point2 - ost;
            ost = 1;
        } else if (*point1 >= *point2 + ost) {
            res = (*point1 - *point2 - ost);
            ost = 0;
        } else {
            res = (*point1 + 10 - *point2 - ost);
            ost = 1;
        }

        *res_point = res;
        // ost = res / 10;
        point1--;
        point2--;
        res_point--;

        minN--;
        // printf(" %d tyta -", minN);
    }
    // printf("+%d +", left_part_res);

    if (flag == 0) {
        while (left_part_res - 1 >= 0) {
            if (*point2 < ost) {
                *res_point = 9;
                ost = 1;
            } else {
                *res_point = *point2 - ost;
                ost = 0;
            }
            res_point--;
            point2--;
            left_part_res--;
        }
    } else {
        while (left_part_res - 1 >= 0) {
            if (*point1 < ost) {
                *res_point = 9;
                ost = 1;
            } else {
                *res_point = *point1 - ost;
                ost = 0;
            }
            res_point--;
            point1--;
            left_part_res--;
        }
    }
}

void input(int *a, int *n) {
    int coll = 0;
    int *p = a;

    char c;
    scanf("%c", &c);
    // c = getchar();
    // while(c == ' '){
    //   c = getchar();
    // }

    while (c != '\n') {
        if (c == ' ') {
            scanf("%c", &c);
            continue;
        }
        coll += 1;
        *p = c - '0';
        p++;
        scanf("%c", &c);
        // c = getchar();
    }
    // coll -=1;
    // printf("%d a", coll);
    *n = coll;
    // if(c == ' ') continue;

    // for(int*p = a; p - a < n; p++){
    //     scanf("%d", p);
    // }
}

void output(int *a, int n) {
    int *rn = a;

    while (*rn == 0 && rn - a < n-1) {
        rn++;
    }

    for (int *p = rn; p - a < n; p++) {
        printf("%d ", *p);
    }

    printf("\n");
}