#include<stdio.h>

int check_combination(int line[], char board[]) {
  return (board[line[0]] == board[line[1]]) && (board[line[1]] == board[line[2]]);
}

int is_match_draw(char board[]) {
  int i;
  for(i = 0; i < 9; i++){
    if(board[i] != 'X' && board[i] != 'O'){
      return 0;
    }
  }
  return 1;
}

int has_player_won(char board[]) {
  int win_combo[8][3] = {
  {0,1,2},{3,4,5},{6,7,8},
  {0,3,6},{1,4,7},{2,5,8},
  {0,4,8},{2,4,6}
  };
  int i,j;
  for (i = 0; i < 8; i++) {
    if(check_combination(win_combo[i],board)){
      return 1;
    };
  }
  return 0;
}

void display_initial_message(void) {
  printf("please enter a number to place your symbol\n");
  printf("symbol for player 1: X\n");
  printf("symbol for player 2: O\n");
}

void display(char board[]){
  printf("\n%c | %c | %c\n", board[0],board[1],board[2]);
  printf("---------\n");
  printf("%c | %c | %c\n", board[3],board[4],board[5]);
  printf("---------\n");
  printf("%c | %c | %c\n\n\n", board[6],board[7],board[8]);
}

int is_invalid_position(int position, char board[]){
  return position < 0 || position > 8 || board[position] == 'X' || board[position] == 'O';
}


int main(){
  char board[9];
  int i,j,position,turn = 0;
  char symbol[2] = {'X','O'};
  for( j = 49,  i = 0; i < 9; i++, j++){
    board[i] = j;
  }
  display_initial_message();
  printf("turn player: %d", turn + 1);
  display(board);
  while(1) {
    scanf("%d", &position);
    position--;
    if(is_invalid_position(position, board)){
      printf("invalid position\n");
      continue;
    }
    board[position] = symbol[turn];
    printf("turn player: %d", turn + 1);
    display(board);
    if(has_player_won(board)){
      printf("player %d won\n", turn + 1);
      break;
    };
    if(is_match_draw(board)){
      printf("match draw \n");
      break;
    }
    turn = (turn + 1) % 2;
  }
}

