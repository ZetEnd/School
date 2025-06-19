#include <stdio.h>
#include <math.h>

void code();
void decode();


int main(int argc, char **argv){

    if (argc > 2) {
        printf("n/a");
        return 0;
    }

    char parametr  = *argv[1];
    //getchar();wqwq

    if(parametr == '0'){
        code();

    } else if(parametr == '1'){

        decode();

    } else {
        printf("n/a");
    }

    //w eweprintf("wd");

    return 0;
}

void code(){

    char ch;
    scanf("%c", &ch);

    printf("%x ", ch);

    //getchar();
    int i = 1;

    while (ch != '\n'){
        
        scanf("%c", &ch);
        if (ch != ' '){
            printf("%x ", ch);
        }


        if (ch == '\n'){
            break;
        }

        }
        if (ch != ' '){
            printf("%x ", ch);
        }


    }
}

void decode(){

    printf("s");
}