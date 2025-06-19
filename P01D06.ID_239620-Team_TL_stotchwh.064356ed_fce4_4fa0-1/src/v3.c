#include <stdio.h> 
#include <unistd.h> // для функции usleep() 
#include <stdlib.h> // for system()
 
//#define WIDTH 80
 
//#define HEIGHT 25

int WIDTH = 80;
int HEIGHT = 25;
int ballX;// = WIDTH/2; 
int ballY;// = HEIGHT/2;
int velocityX = 2; 
int velocityY = 2; 
int score1 = 0;
int score2 = 0;
int YPlatform1;// = HEIGHT;
int YPlatform2;// = HEIGHT;
int flag = 1;
int move = 1;

void NewGame(int i);
void UpdateScore(int i);
void ENDGAME();
void CheckPlatform();
void TouchPlatform();
void position();

void DRAW();

void clearScreen() { 
    printf("\033[H\033[J"); 
    //printf("\033[2J\033[1;1H");
    //system("clear");
} 
 

 void CheckPlatform(){


    //position();


    char U;
    //scanf("%c",&U);
    U = getchar();
    if (U == 'a'){
        if(YPlatform1-3>1)
        YPlatform1 = YPlatform1 - 1;
        //position();
    } else

    if (U == 'z'){
        if(YPlatform1 < HEIGHT)
        YPlatform1 = YPlatform1 + 1;
        //position();
    } else

    if (U == 'k'){
        if(YPlatform2-3>1)
        YPlatform2 = YPlatform2 - 1;
        //position();
    } else 

    if (U == 'm'){
        if(YPlatform2 < HEIGHT)
        YPlatform2 = YPlatform2 + 1;
        //position();
    } else

    if (U == ' '){
        //position();
    } else {
        //move = 0;
    }
    //scanf("%c",&U);

    U = getchar();


 }

void drawBall(int ballX, int ballY, int YPlatform1, int YPlatform2, int score1, int score2) { 
    for (int i = 0; i < WIDTH/2; i++) { 
        printf(" ");
    }
    printf("%d %d \n", score1, score2);
    for (int i = 0; i <= HEIGHT; i++) { 
        for (int j = 0; j <= WIDTH; j++) { 

            if ((i == 0 || i == HEIGHT) && (j == 0 || j == WIDTH)){
                printf("+");
            } else if (i == 0 || i == HEIGHT){
                printf("-");
            } else if(j == 0 || j == WIDTH){
                printf("|");
            } else 
            if (i == ballY && j == ballX) { 
                printf("o"); 
            } else if( j == 1 && (i < YPlatform1) && i >= YPlatform1-3){
                printf("|");
            } else if( j == WIDTH-1 && ((i < YPlatform2) && i >= YPlatform2-3 )){
                printf("|");
            } else { 
                printf(" "); 
            }
        } 
        printf("\n"); 
    } 
} 

void TouchWall(){

    if(ballX <= 0) NewGame(1);
    if(ballX >= WIDTH - 1) NewGame(2);

    if (ballY <= 1 || ballY >= HEIGHT - 1) { 
            velocityY = -velocityY; 
        } 

    //printf("%d %d", ballY, 2);
    //getchar();


}

void position(){

    if(move == 1){
        ballX += velocityX; 
        ballY += velocityY;
    } 

    move = 1;
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
    printf("THE END");


}
 
int main() { 
    ballX = WIDTH / 2; 
    ballY = HEIGHT / 2;
    YPlatform1 = HEIGHT;
    YPlatform2 = HEIGHT;
    Begin();
 
    return 0; 
}