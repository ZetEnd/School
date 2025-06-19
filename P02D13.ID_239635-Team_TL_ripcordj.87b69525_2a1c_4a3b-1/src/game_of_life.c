
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>


#define max_x 82
#define max_y 27

void game_rendering(int a[max_y][max_x]);
void Top_and_Bot();
void filler(int a[max_y][max_x], int i, int j);
int control(int (*a)[max_x]);
void mapping(int (*a)[max_x]);
int summator(int (*a)[max_x], int i, int j);
void cleaning_mass(int (*a)[max_x]);
void endless_border(int (*mass)[max_x]);
void menu(int *n, int (*a)[max_x]);
void read_file(char *filename, int (*a)[max_x]);

int main(){
    int n, field[max_y][max_x];
    cleaning_mass(field);
    menu(&n, field);
    
    game_rendering(field);
    /*field[3][1] = -1;
    field[3][2] = 1;
    field[1][2] = -1;
    field[2][3] = 1;
    field[3][3] = 1;
    field[10][15] = 1;
    field[20][20] = 1;*/
    game_rendering(field);
    control(field);
    
    endwin();
    return 0;
}

void game_rendering(int a[max_y][max_x]){
    
    initscr();
    start_color();
    erase();
    // начало отрисовки
    for(int i = 0; i < max_y; i++){
        //отрисовка верхней и нижней границ
        if (i == 0 || i == max_y - 1) Top_and_Bot();
        // заполнение пустоты
        else{
            for(int j = 0; j < max_x; j++)
                filler(a, i, j);
        }
            printw("\n");}
    
    
    
    endwin();
}
void Top_and_Bot(){
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    for(int j = 0; j < max_x; j++){
        attron(COLOR_PAIR(1));
        printw("+");
        attron(COLOR_PAIR(2));}
}
void filler(int (*a)[max_x], int i, int j){
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    if(j == 0 || j == max_x - 1){
        attron(COLOR_PAIR(1));
        printw("+");
        attron(COLOR_PAIR(2));
    }
    else if(abs(a[i][j]) != 1)
        printw(" ");
    else if (a[i][j] == 1){
        
        attron(COLOR_PAIR(3));
        printw("G");
        attron(COLOR_PAIR(2));
    }
    else{
        attron(COLOR_PAIR(4));
        printw("G");
        attron(COLOR_PAIR(2));
    }
}

int control(int (*a)[max_x]){
    
    initscr();
    noecho();
    int timer = 300, click = 0;
    while (click != 32){
        
        timeout(timer);
        click = getch();
        if (click == ERR){
            
            
            mapping(a);
            game_rendering(a);
        }
        else if (click == 97 &&  timer > 50)
            timer -= 25;
        else if (click == 122 && timer < 1020)
            timer += 25;
  
            
        }
}

void mapping(int (*a)[max_x]){
    int sum, old[max_y][max_x];
    cleaning_mass(old);
    for(int i = 0; i < max_y; i++)
        for(int j = 0; j < max_x; j++)
            old[i][j] = a[i][j];
    endless_border(old);
    for(int i = 1; i < max_y - 1; i++)
        for(int j = 1; j < max_x - 1; j++){
            if (abs(old[i][j]) == 1) {
                sum = summator(old, i, j);
                sum--;
                if(sum < 2 || sum > 3)
                    a[i][j] = 0;}
            else if (old[i][j] == 0){
                sum = summator(old, i, j);
                int rand_color = rand() % 6 + 1;
                if (sum == 3 && rand_color % 2 == 0) a[i][j] = 1;
                else if(sum == 3 && rand_color % 2 != 0) a[i][j] = -1;}
            
        }
            
}
 

int summator(int (*a)[max_x], int i, int j){
    
    
    int sum = 0;
    for(int k = i - 1; k <= i + 1; k++)
        for(int p = j - 1; p <= j + 1; p++)
            sum += abs(a[k][p]);
    
    return sum;
    
    
}

void cleaning_mass(int (*a)[max_x]){
    for(int i = 0; i < max_y; i++)
        for(int j = 0; j < max_x; j++)
            a[i][j] = 0;
    
}
void endless_border(int (*mass)[max_x]){
    
    for(int i = 0; i < max_y; i++)
        for(int j = 0; j < max_x; j++){
            if(j == 0 && i > 0 && i < max_y - 1)
                mass[i][j] = mass[i][max_x-2];
            else if(j == max_x - 1 && i > 0 && i < max_y - 1)
                mass[i][j] = mass[i][1];
            else if(i == 0 && j > 0 && j < max_x-1)
                mass[i][j] = mass[max_y-2][j];
            else if (i == max_y -1 && j > 0 && j < max_x - 1)
                mass[i][j] = mass[1][j];}
    
    mass[0][0] = mass[max_y - 2][max_x - 2];
    mass[0][max_x-1] = mass[max_y - 2][1];
    mass[max_y-1][max_x-1] = mass[1][1];
    mass[max_y-1][0] = mass[1][max_x - 2];
}

void menu(int *n, int (*a)[max_x]){
    int checkmark = 1;
    printf("Введите номер файла со стартовым сценарием игры\n");
    if (scanf("%d", n) != 1) checkmark = 0;
    if (!checkmark) *n = -1;
    else if (*n == 1){
        char *filename = "file1.txt";
        read_file(filename, a);
    }

}

void read_file(char *filename, int (*a)[max_x]) {
    FILE *fptr = fopen(filename, "r");
    if (fptr != NULL)
        for(int i = 0; i < max_y; i++)
            for(int j = 0; j < max_x; j++)
                fscanf(fptr, "%d", &a[i][j]);
    else
    printf("n/a");
  fclose(fptr);
}


