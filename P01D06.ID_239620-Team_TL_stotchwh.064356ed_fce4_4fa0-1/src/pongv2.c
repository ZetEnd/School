#include <stdio.h> 
#include <unistd.h> // для функции usleep() 
#include <stdlib.h> // for system()
 
#define WIDTH 80
#define HEIGHT 25 

int ballX = WIDTH/2; 
int ballY = HEIGHT/2;
int velocityX = 1; 
int velocityY = 1; 
int score1 = 0;
int score2 = 0;
int YPlatform1 = HEIGHT;
int YPlatform2 = HEIGHT;
int flag = 1;

void NewGame(int i);
void UpdateScore(int i);
void ENDGAME();
void CheckPlatform1();
void CheckPlatform2();
void TouchPlatform(int ballX, int ballY, int YPlatform1, int YPlatform2);

void clearScreen() { 
    printf("\033[H\033[J"); 
    //printf("\033[2J\033[1;1H");
    //system("clear");
} 
 

 void CheckPlatform1(){

    char U;
    scanf("%c",&U);
    //U = getchar();
    if (U == 'a'){
        if(YPlatform1-3>0)
        YPlatform1 = YPlatform1 - 1;
    }

    if (U == 'z'){
        if(YPlatform1 < HEIGHT)
        YPlatform1 = YPlatform1 + 1;
    }

 }

 void CheckPlatform2(){

    char U;
    scanf("%c",&U);
    //scanf("%c",&U);
    //U = getchar();

    if (U == 'k'){
        if(YPlatform2-3>0)
        YPlatform2 = YPlatform2 - 1;
    }

    if (U == 'm'){
        if(YPlatform2 < HEIGHT)
        YPlatform2 = YPlatform2 + 1;
    }

 }
void drawBall(int x, int y, int YPlatform1, int YPlatform2, int score1, int score2) { 
    for (int i = 0; i < HEIGHT; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
            if (i == y && j == x) { 
                printf("O"); 
            } else { 
                printf(" "); 
            }

            if( j == 0 && (i <= YPlatform1) && i >= YPlatform1-3){
                printf("|");
            }

            if( j == WIDTH-1 && ((i <= YPlatform2) && i >= YPlatform2-3)){
                printf("|");
            }

            if( i == 0 && j == WIDTH/2){
                printf("%d %d", score1, score2);
            }
        } 
        printf("\n"); 
    } 
} 

void TouchWall(int ballX, int ballY){

    if(ballX <= 0) NewGame(1);
    if(ballX >= WIDTH - 1) NewGame(2);

    if (ballY <= 0 || ballY >= HEIGHT - 1) { 
            velocityY = -velocityY; 
        } 


}

void Begin(){
    usleep(100000);
    while (flag == 1) { 
        clearScreen(); 
        drawBall(ballX, ballY, YPlatform1, YPlatform2, score1, score2); 
 
        // Обновление позиции мяча 
        ballX += velocityX; 
        ballY += velocityY;

        CheckPlatform1();
        CheckPlatform2();
 
        // Проверка столкновения с границами и изменение направления 
        TouchWall(ballX, ballY);
        // Проверка столкновения с платформой 
        TouchPlatform(ballX, ballY, YPlatform1, YPlatform2);
 
        // Задержка для замедления движения мяча 
        usleep(100000); // 100000 микросекунд = 0.1 секунд 
    } 
    
}


void TouchPlatform(int ballX, int ballY, int YPlatform1, int YPlatform2){

    if(ballX == 0 && (ballY <= YPlatform1 + 3 || ballY >= YPlatform1))
    {
    velocityX = -velocityX;
    }

    if(ballX == WIDTH - 1 && (ballY <= YPlatform2 + 3 || ballY >= YPlatform2))
    {
    velocityX = -velocityX;
    }

}

void NewGame(int i){

    ballX = WIDTH / 2; 
    ballY = HEIGHT / 2; 
    usleep(2000000);

    if(i != 0)
    UpdateScore(i);
    usleep(100000);
    //Begin();

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
    //NewGame(0);
    Begin();
 
    return 0; 
}