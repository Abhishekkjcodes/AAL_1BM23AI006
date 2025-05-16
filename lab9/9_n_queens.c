#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSafe(int board[], int row, int col) {
  for (int i = 0; i < col; i++) {
    if (board[i] == row || abs(board[i] - row) == abs(i - col))
      return false;
  }
  return true;
}

bool solveNQUtil(int board[], int col, int n) {
  if (col >= n)
    return true;
  for (int i = 0; i < n; i++) {
    if (isSafe(board, i, col)) {
      board[col] = i;
      if (solveNQUtil(board, col + 1, n))
        return true;
      board[col] = -1;
    }
  }
  return false;
}

void printSolution(int board[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i] == j)
        printf("Q ");
      else
        printf(". ");
    }
    printf("\n");
  }
  printf("\n");
}

void solveNQ(int n) {
  int* board = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    board[i] = -1;
  if (solveNQUtil(board, 0, n) == false) {
    printf("Solution does not exist");
    return;
  }
  printSolution(board, n);
  free(board);
}

int main() {
  int n;
  printf("enter number of rows or columns");
  scanf("%d",&n);
  solveNQ(n);
  return 0;
}
