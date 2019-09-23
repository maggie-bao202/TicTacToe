#include <iostream>
#include <cstring>

using namespace std;

int board [3][3];
int xcounter = 0;
int ocounter = 0;
int tcounter = 0;

int main()
{
  bool stillPlaying = true;
  while (true) {
    while checkWin(X_MOVE) == false && checkWin(O_MOVE) == false checkTie() == false){
      cout << "Please enter in a letter followed by a number." << endl;
      printBoard();
      cin << input;
      if (input.length() != 2){
	cout << "Please enter in a letter followed by a number." << endl;
      }
      else if (){

	cout << "Row must be letter a, b, or c." << endl;
      }
      else if (){

	cout << "Column must be numbers 1, 2, or 3." << endl;
      }
      
  return 0;
}  

  
bool checkWin (int player){
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return true;
  }
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player){
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player){
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player){
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player){
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }
  return false;
}

 
bool checkTie(){
  for (int i = 0; i < board.length; i++){
    for (int j = 0; j < board.length; j++){
      if(board[i][j] == BLANK){
	return false;
      }
    }
  }
  return true;
}
