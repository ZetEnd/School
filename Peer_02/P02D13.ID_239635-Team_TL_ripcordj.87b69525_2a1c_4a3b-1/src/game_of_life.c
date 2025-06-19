#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define max_x 82
#define max_y 27

void game_rendering(int a[max_y][max_x], int n);
void Top_and_Bot();
void filler(int (*a)[max_x], int i, int j);
void control(int (*a)[max_x], int n);
void mapping(int (*a)[max_x]);
int summator(int (*a)[max_x], int i, int j);
void cleaning_mass(int (*a)[max_x]);
void endless_border(int (*mass)[max_x]);
int menu(int *n, int (*a)[max_x]);
int read_file(char *filename, int (*a)[max_x]);
void introduce();

int main() {
    int n, checkmark, field[max_y][max_x];
    cleaning_mass(field);
    checkmark = menu(&n, field);
    if (!checkmark)
        printf("n/a");
    else {
        initscr();
        game_rendering(field, n);
        control(field, n);
        endwin();
    }
    return 0;
}

void game_rendering(int a[max_y][max_x], int n) {
    start_color();
    erase();
    for (int i = 0; i < max_y; i++) {
        if (i == 0 || i == max_y - 1)
            Top_and_Bot();
        else {
            for (int j = 0; j < max_x; j++) filler(a, i, j);
        }
        printw("\n");
    }
    if (n == 1)
        printw("Glader\n");
    else if (n == 2)
        printw("Beacon\n");
    else if (n == 3)
        printw("Pulsar\n");
    else if (n == 4)
        printw("Penta-decathlon\n");
    else if (n == 5)
        printw("Light-weight spaceship\n");
    else if (n == 6)
        printw("Heavy-weight spaceship\n");
    else if (n == 7)
        printw("R-pentomino\n");
    else if (n == 8)
        printw("Diehard\n");
    else if (n == 9)
        printw("Acorn\n");
    else if (n == 10)
        printw("Gosper glider gun\n");
    else if (n == 11)
        printw("Weldedgeese \n");
    printw("A - acceleration | Z - deceleration | SpaceBar - exit\n");
}

void Top_and_Bot() {
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    for (int j = 0; j < max_x; j++) {
        attron(COLOR_PAIR(1));
        printw("+");
        attron(COLOR_PAIR(2));
    }
}

void filler(int (*a)[max_x], int i, int j) {
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    if (j == 0 || j == max_x - 1) {
        attron(COLOR_PAIR(1));
        printw("+");
        attron(COLOR_PAIR(2));
    } else if (!a[i][j])
        printw(" ");
    else if (a[i][j] == 1) {
        attron(COLOR_PAIR(3));
        printw("@");
        attron(COLOR_PAIR(2));
    } else if (a[i][j] == 2) {
        attron(COLOR_PAIR(4));
        printw("@");
        attron(COLOR_PAIR(2));
    } else {
        attron(COLOR_PAIR(5));
        printw("@");
        attron(COLOR_PAIR(2));
    }
}

void control(int (*a)[max_x], int n) {
    noecho();
    int timer = 300, click = 0;
    while (click != 32) {
        timeout(timer);
        click = getch();
        if (click == ERR) {
            mapping(a);
            game_rendering(a, n);
        } else if ((click == 97 || click == 65) && timer > 25)
            timer -= 25;
        else if ((click == 122 || click == 90) && timer < 1025)
            timer += 25;
    }
}

void mapping(int (*a)[max_x]) {
    int sum, old[max_y][max_x];
    cleaning_mass(old);
    for (int i = 0; i < max_y; i++)
        for (int j = 0; j < max_x; j++) old[i][j] = a[i][j];
    endless_border(old);
    for (int i = 1; i < max_y - 1; i++)
        for (int j = 1; j < max_x - 1; j++) {
            if (old[i][j]) {
                sum = summator(old, i, j);
                sum--;
                if (sum < 2 || sum > 3) a[i][j] = 0;
            } else if (!old[i][j]) {
                sum = summator(old, i, j);
                int rand_color = rand() % 30 + 1;
                if (sum == 3 && rand_color % 3 == 0)
                    a[i][j] = 1;
                else if (sum == 3 && rand_color % 3 != 1)
                    a[i][j] = 2;
                else if (sum == 3 && rand_color % 3 != 2)
                    a[i][j] = 3;
            }
        }
}

int summator(int (*a)[max_x], int i, int j) {
    int sum = 0;
    for (int k = i - 1; k <= i + 1; k++)
        for (int p = j - 1; p <= j + 1; p++)
            if (a[k][p]) sum++;
    return sum;
}

void cleaning_mass(int (*a)[max_x]) {
    for (int i = 0; i < max_y; i++)
        for (int j = 0; j < max_x; j++) a[i][j] = 0;
}

void endless_border(int (*mass)[max_x]) {
    for (int i = 0; i < max_y; i++)
        for (int j = 0; j < max_x; j++) {
            if (j == 0 && i > 0 && i < max_y - 1)
                mass[i][j] = mass[i][max_x - 2];
            else if (j == max_x - 1 && i > 0 && i < max_y - 1)
                mass[i][j] = mass[i][1];
            else if (i == 0 && j > 0 && j < max_x - 1)
                mass[i][j] = mass[max_y - 2][j];
            else if (i == max_y - 1 && j > 0 && j < max_x - 1)
                mass[i][j] = mass[1][j];
        }

    mass[0][0] = mass[max_y - 2][max_x - 2];
    mass[0][max_x - 1] = mass[max_y - 2][1];
    mass[max_y - 1][max_x - 1] = mass[1][1];
    mass[max_y - 1][0] = mass[1][max_x - 2];
}

int menu(int *n, int (*a)[max_x]) {
    int checkmark = 1;
    introduce();
    if (scanf("%d", n) != 1) checkmark = 0;
    if (checkmark && *n == 1)
        checkmark = read_file("file1.txt", a);
    else if (checkmark && *n == 2)
        checkmark = read_file("file2.txt", a);
    else if (checkmark && *n == 3)
        checkmark = read_file("file3.txt", a);
    else if (checkmark && *n == 4)
        checkmark = read_file("file4.txt", a);
    else if (checkmark && *n == 5)
        checkmark = read_file("file5.txt", a);
    else if (checkmark && *n == 6)
        checkmark = read_file("file6.txt", a);
    else if (checkmark && *n == 7)
        checkmark = read_file("file7.txt", a);
    else if (checkmark && *n == 8)
        checkmark = read_file("file8.txt", a);
    else if (checkmark && *n == 9)
        checkmark = read_file("file9.txt", a);
    else if (checkmark && *n == 10)
        checkmark = read_file("file10.txt", a);
    else if (checkmark && *n == 11)
        checkmark = read_file("file11.txt", a);
    else
        checkmark = 0;
    return checkmark;
}

int read_file(char *filename, int (*a)[max_x]) {
    int check = 1;
    FILE *fptr = fopen(filename, "r");
    if (fptr != NULL)
        for (int i = 0; i < max_y; i++)
            for (int j = 0; j < max_x; j++) fscanf(fptr, "%d", &a[i][j]);
    else
        check = 0;
    fclose(fptr);
    return check;
}

void introduce() {
    printf("Enter the file number from 1 to 11 with the game's starting scenario:\n");
    printf("1. Glader\n");
    printf("2. Beacon\n");
    printf("3. Pulsar\n");
    printf("4. Penta-decathlon\n");
    printf("5. Light-weight spaceship\n");
    printf("6. Heavy-weight spaceship\n");
    printf("7. R-pentomino\n");
    printf("8. Diehard\n");
    printf("9. Acorn\n");
    printf("10. Gosper glider gun\n");
    printf("11. Weldedgeese\n");
}
