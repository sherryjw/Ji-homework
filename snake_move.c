//The function of this version is to get the snake move.
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define WALL_CELL '*'

char map[12][12];
int snakeX[SNAKE_MAX_LENGTH] = {1, 2, 3, 4, 5};//initialize the data of the snake 
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snake_head = 4;

void set_wall() {//set a limited space for the snake
    for (int i = 0; i < 12; i++) {
        map[0][i] = map[11][i] = WALL_CELL;
    }
    for (int i = 1; i < 11; i++) {
        map[i][0] = map[i][11] = WALL_CELL;
        for (int j = 1; j < 11; j++){
        	map[i][j] = BLANK_CELL;
		}  
    }
}

void set_snake() {//renew the position of the snake
    map[snakeX[snake_head]][snakeY[snake_head]] = SNAKE_HEAD; //the head
    for (int i = snake_head - 1; i >= 0; i--) {
        map[snakeX[i]][snakeY[i]] = SNAKE_BODY;//the body
    }
}

void snakeMove(int X, int Y){//move and renew the data of the snake
    int tempX = snakeX[snake_head];
    int tempY = snakeY[snake_head];
    snakeX[snake_head] += X;
    snakeY[snake_head] += Y;
    for (int i = 0; i < snake_head - 1; i++) {
        snakeX[i] = snakeX[i + 1];
        snakeY[i] = snakeY[i + 1];
    }
    snakeX[snake_head - 1] = tempX;
    snakeY[snake_head - 1] = tempY;
}

void output(void){//output the whole screen
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }	
}

int gameover(){//judge whether the snake make a wrong move
	//when hitting the wall
    if (snakeX[snake_head] == 0 || snakeX[snake_head] == 11)
        return 1;
    else if (snakeY[snake_head] == 0 || snakeY[snake_head] == 11)
        return 1;
    //when touching itself
    for (int i = 0; i < snake_head - 1; i++) {
        if (snakeX[snake_head] == snakeX[i] && snakeY[snake_head] == snakeY[i])
            return 1;
    }
    return 0;
}

void print() {//for each move print the screen again
    system("cls");
    set_wall();
    set_snake();
    output();
}

int main() {
    print();
    while (!gameover()) {
        char ch = _getch();
        switch (ch) {
        case 'w' : case 'W':
            snakeMove(-1, 0);
            break;
        case 's' : case 'S':
            snakeMove(1, 0);
            break;
        case 'a' : case 'A':
            snakeMove(0, -1);
            break;
        case 'd' : case 'D':
            snakeMove(0, 1);
            break;
        }
        print();
    }
    printf("Game Over!!!");
    getchar();
}
