#include <stdio.h> 
#include <unistd.h> // для функции usleep() 
#include <stdlib.h> // for system()
#include <ncurses.h>
 
//#define WIDTH 80
 
//#define HEIGHT 25

int WIDTH = 80;
int HEIGHT = 25;
int ballX;// = WIDTH/2; 
int ballY;// = HEIGHT/2;
int velocityX = 1; 
int velocityY = 1; 
int veloPlatform = 2;
int score1 = 0;
int score2 = 0;
int YPlatform1;// = HEIGHT;
int YPlatform2;// = HEIGHT;
int flag = 1;
//int move = 1;

void NewGame(int i);
void UpdateScore(int i);
void ENDGAME();
void CheckPlatform();
void TouchPlatform();
void position();

void DRAW();

void clearScreen() { 
    printw("\033[H\033[J"); 
    clear();
    //printw("\033[2J\033[1;1H");
    //system("clear");
} 
 

 void CheckPlatform(){


    //position();


    char U;
    //scanf("%c",&U);
    //U = getchar();
    //U = getch();
    timeout(1);
    U = wgetch(stdscr);
    if (U == 'a'){
        if(YPlatform1-3>1)
        YPlatform1 = YPlatform1 - veloPlatform;
        //position();
    } else

    if (U == 'z'){
        if(YPlatform1 < HEIGHT)
        YPlatform1 = YPlatform1 + veloPlatform;
        //position();
    } else

    if (U == 'k'){
        if(YPlatform2-3>1)
        YPlatform2 = YPlatform2 - veloPlatform;
        //position();
    } else 

    if (U == 'm'){
        if(YPlatform2 < HEIGHT)
        YPlatform2 = YPlatform2 + veloPlatform;
        //position();
    } else

    if (U == ' '){
        //position();
    } else {
        //move = 0;
    }
    //scanf("%c",&U);

    //U = getchar();


 }

void drawBall(int ballX, int ballY, int YPlatform1, int YPlatform2, int score1, int score2) { 
    for (int i = 0; i < WIDTH/2; i++) { 
        printw(" ");
    }
    printw("%d %d \n", score1, score2);
    for (int i = 0; i <= HEIGHT; i++) { 
        for (int j = 0; j <= WIDTH; j++) { 

            if ((i == 0 || i == HEIGHT) && (j == 0 || j == WIDTH)){
                printw("+");
            } else if (i == 0 || i == HEIGHT){
                printw("-");
            } else if(j == 0 || j == WIDTH){
                printw("|");
            } else 
            if (i == ballY && j == ballX) { 
                printw("o"); 
            } else if( j == 1 && (i < YPlatform1) && i >= YPlatform1-3){
                printw("|");
            } else if( j == WIDTH-1 && ((i < YPlatform2) && i >= YPlatform2-3 )){
                printw("|");
            } else { 
                printw(" "); 
            }
        } 
        printw("\n"); 
    } 
} 

void TouchWall(){

    if(ballX <= 0) NewGame(1);
    if(ballX >= WIDTH - 1) NewGame(2);

    if (ballY <= 1 || ballY >= HEIGHT - 1) { 
            velocityY = -velocityY; 
        } 

    //printw("%d %d", ballY, 2);
    //getchar();


}

void position(){
        ballX += velocityX; 
        ballY += velocityY;
}

void Begin(){
    while (flag == 1) { 
        clearScreen(); 
        drawBall(ballX, ballY, YPlatform1, YPlatform2, score1, score2); 
 
        // Обновление позиции мяча 
        //ballX += velocityX; 
        //ballY += velocityY;
        position();

        CheckPlatform();
 
        // Проверка столкновения с границами и изменение направления 
        TouchWall();
        // Проверка столкновения с платформой 
        TouchPlatform();
 
        // Задержка для замедления движения мяча 
        usleep(100000); // 100000 микросекунд = 0.1 секунд 
    } 
    
}


void TouchPlatform(){

    if(ballX == 2 && (ballY <= YPlatform1 && ballY >= YPlatform1-3))
    {
    velocityX = -velocityX;
    }

    if(ballX == WIDTH - 2 && (ballY <= YPlatform2 && ballY >= YPlatform2-3))
    {
    velocityX = -velocityX;
    }

}

void NewGame(int i){

    ballX = WIDTH / 2; 
    ballY = HEIGHT / 2; 
    usleep(500000);

    UpdateScore(i);

}

void UpdateScore(int i){

    if(i == 1) score1 = score1 + 1;
    if(i == 2) score2= score2 + 1;


    if(score1 == 21 || score2 == 21){
        ENDGAME();
    }

}

void ENDGAME(){

    flag = 0;
    printw("THE END");


}
 
int main() { 
    initscr();
    ballX = WIDTH / 2; 
    ballY = HEIGHT / 2;
    YPlatform1 = HEIGHT;
    YPlatform2 = HEIGHT;
    Begin();

    endwin(); 
 
    return 0; 
}