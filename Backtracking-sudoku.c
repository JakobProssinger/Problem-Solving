#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DIM 9 


int solveBoard(int arr[DIM][DIM], int x, int y);

int board[DIM][DIM] = {{9, 0, 0, 0, 2, 0, 0, 0, 1},
                         {0, 4, 0, 1, 0, 6, 0, 2, 0},
                         {0, 0, 6, 5, 0, 0, 8, 0, 0},
                         //=====
                         {0, 2, 0, 0, 5, 0, 6, 4, 0},
                         {3, 0, 0, 2, 0, 4, 0, 0, 9},
                         {0, 8, 5, 0, 6, 0, 0, 7, 0},
                         //=====
                         {0, 0, 2, 0, 0, 5, 4, 0, 0},
                         {0, 9, 0, 3, 0, 2, 0, 1, 0},
                         {5, 0, 0, 0, 4, 0, 0, 0, 3}
                         };

void showArr(int arr[DIM][DIM]) {
    //system("chcp 65001 >NUL 2>&1"); Windows output
    int dimkl = sqrt(DIM);          // size of section
 
    // oberste Leiste  -------------------------------------------------
    printf("╔");
    for (int i = 0; i < dimkl; i++) {
        for (int z = 0; z < dimkl-1; z++) {
            printf("═══╤");
        }
        if (i == dimkl-1)
            printf("═══╗\n");
        else
            printf("═══╦");
    }
 
    for (int j = 0; j < DIM; j++) {
        // Ausgabe Inhalt  -------------------------------------------------
        printf("║");
        for (int i = 0; i < dimkl; i++) {
            for (int z = 0; z < dimkl; z++) {
                char val = arr[j][z+i*(dimkl)];
                val = (val == 0) ? ' ' : val+'0';
                if (z == dimkl-1) printf(" %c ║", val);
                else printf(" %c │", val);
            }
        }
        printf("\n");
 
        if (j==DIM-1) {      // Endlinie  -------------------------------------------------
            printf("╚");
            for (int i = 0; i < dimkl; i++) {
                for (int z = 0; z < dimkl-1; z++) {
                    printf("═══╧");
                }
                if (i == dimkl-1)
                    printf("═══╝\n");
                else
                    printf("═══╩");
            }
        } else {
            if (((j+1)%dimkl)) {  // Trennlinie  -------------------------------------------------
                printf("╟");
                for (int i = 0; i < dimkl; i++) {
                    for (int z = 0; z < dimkl-1; z++) {
                        printf("───┼");
                    }
                    if (i == dimkl-1)
                        printf("───╢\n");
                    else
                        printf("───╫");
                }
            }
            else {
                // Doppel-Trennlinie  -------------------------------------------------
                printf("╠");
                for (int i = 0; i < dimkl; i++) {
                    for (int z = 0; z < dimkl-1; z++) {
                        printf("═══╪");
                    }
                    if (i == dimkl-1)
                        printf("═══╣\n");
                    else
                        printf("═══╬");
                }
            }
        }
    }
 
    printf("\n");
}



int main(){

    showArr(board);

    solveBoard(board, 0, 0);

    showArr(board);
    return 0;
}

int tryMove(int board[DIM][DIM], int x, int y, int value){

    //check row
    for(int i = 0; i < DIM; i++){
        if(board[y][i] == value) return -1; 
    }

    //check colum
    for(int i = 0; i < DIM; i++){
        if(board[i][x] == value) return -1;
    }

    //check box

    int startX = x - x % 3;
    int startY = y - y % 3;
    for(int checkX = 0, checkY = 0; checkY < 2; checkX++) {
        if(checkX >= 2) {
            checkX = 0;
            checkY++;
        }
        if(board[startY + checkY][startX + checkX] == value){
            return -1;
        } 
    } 


    return 0;
}

int solveBoard(int arr[DIM][DIM], int x, int y){
    int nextX=x, nextY=y;

    //Find valid position
    while(board[nextY][nextX] != 0){
        nextX++;
        if(nextX >= DIM){
            nextX = 0;
            nextY++;
            if(nextY >= DIM) return 0; //solved
        }
    }

    for(int val = 1; val <= DIM; val++){   
        if (tryMove(board, nextX, nextY, val) == 0){
            board[nextY][nextX] = val;
            if(solveBoard(board, nextX, nextY) == 0){
                return 0;
            } else {
                board[nextY][nextX] = 0;
            }
            
        }    
    }

    return -1; 
}