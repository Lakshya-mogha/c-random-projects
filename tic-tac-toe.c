#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main() {

  char winner = ' ';

  resetBoard();
  while (winner == ' ' && checkFreeSpaces() != 0) {
    printBoard();
    playerMove();
    winner = checkWinner();
    if (winner != ' ' || checkFreeSpaces() == 0) {
      printBoard();
      printWinner(winner);
      break;
    }
    computerMove();
    winner = checkWinner();
    if (winner != ' ' || checkFreeSpaces() == 0) {
      printBoard();
      printWinner(winner);
      break;
    }
  }
  return 0;
}

void resetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
};

void printBoard() {
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---|---|---\n");
  printf(" %C | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
};

int checkFreeSpaces() {
  int freeSpace = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        freeSpace--;
      }
    }
  }
  return freeSpace;
};

void playerMove() {

  int x, y;

  do {

    printf("Enter the number of row (1-3)");
    scanf("%d", &x);
    printf("Enter the number of column (1-3)");
    scanf("%d", &y);
    x--, y--;
    if (board[x][y] != ' ') {
      printf("invalid move\n");
    } else {
      board[x][y] = PLAYER;
      break;
    }
  } while (board[x][y] != ' ');
};

void computerMove() {

  srand(time(0));
  int x, y;

  do {
    x = rand() % 3;
    y = rand() % 3;
  } while (board[x][y] != ' ');

  board[x][y] = COMPUTER;
};

char checkWinner() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return board[i][0];
    };

    if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return board[0][i];
    };

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
      return board[0][0];
    };

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
      return board[1][1];
    };
  }
  return ' ';
};
void printWinner(char Winner) {
  if (Winner == PLAYER) {
    printf("yay!! you won\n");
  } else if (Winner == COMPUTER) {
    printf("you LOST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  } else {
    printf("its a tie ;) \n");
  }
};
