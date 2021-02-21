#include <stdio.h>
#include <stdlib.h>

#define DIM 8

void initBoard(int board[DIM][DIM]);
void printBoard(int board[DIM][DIM]);
int findConfig(int numDam, int board[DIM][DIM]);
int impossibleMove(int x, int y, int board[DIM][DIM]);
    int board[DIM][DIM];
    

int main() {
    initBoard(board);
    findConfig(0, board);
    printBoard(board);
    return 0;
}

int findConfig(int numDam, int board[DIM][DIM]) {
    if (numDam == DIM) return 0;

    for(int y = 0; y < DIM; y++){
          if(0 == impossibleMove(numDam, y, board)){
            board[numDam][y] = numDam;
            if(0 == findConfig(numDam+1, board)) return 0;
            board[numDam][y] = -1;
          }
    }
    return -1;
}

int impossibleMove(int x, int y, int board[DIM][DIM]) {
    
    //In col
    for (size_t i = 0; i < DIM; i++)
    {
      if(i != x){
         if(board[i][y] != -1){
           return -1;
         } 
      }
    }

    //In row
    for (size_t i = 0; i < DIM; i++)
    {
      if(i != y){
         if(board[x][i] != -1){
           return -1;
         } 
      }
    }

    int j = 1;
    while(x-j >= 0 && y-j >= 0){
      if(board[x-j][y-j] != -1){
        return -1;
      }
      j++;
    }

    j = 1;
    while(x+j < DIM && y+j < DIM){
      if(board[x+j][y+j] != -1){
        return -1;
      }
      j++;
    }
    
    j = 1;
    while(x+j < DIM && y-j >= 0){
      if(board[x+j][y-j] != -1){
        return -1;
      }
      j++;
    }
    
    j = 1;
    while(x-j >= 0 && y+j < DIM){
      if(board[x-j][y+j] != -1){
        return -1;
      }
      j++;
    }
    
    
    return 0;
}


void initBoard(int board[DIM][DIM]) {
    int x, y;
    for (x = 0; x < DIM; x++) {
        for (y = 0; y < DIM; y++) {
            board[x][y] = -1;
        }
    }
}

void printBoard(int board[DIM][DIM]) {
    int x, y;

    // Header:
    printf("Loesung %i-Damen-Problem\n\n", DIM);
    printf("Es werden %i Damen so auf dem Feld plaziert,\n", DIM);
    printf("dass sich keine der Damen gegenseitig bedroht.\n");
    printf("Die Loesung wird mittels Backtracking berechnet.\n\n");
    printf("     ");
    for (x = 0; x < DIM; x++) {
        printf(" %c",'A' + x);
    }
    printf("\n    ");
    for (x = 0; x < DIM+1; x++) {
        printf("__");
    }
    printf("\n");
    // Board
    for (y = 0; y < DIM; y++) {
        printf(" %3i|", y+1);
        for (x = 0; x < DIM; x++) {
            if ((board[x][y] >= 0) && (board[x][y] < DIM)) printf("%2i", board[x][y]+1);
            else printf(" .");
        }
        printf("|\n");
    }
    // Footer:
    printf("    |");
    for (x = 0; x < DIM; x++) {
        printf("__");
    }
    printf("|\n");
}
