#include <iostream>
#include <cstring>

using namespace std;

void printBoard();
bool checkWin();
bool checkTie();

int board [3][3];
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;
int xcounter = 0;
int ocounter = 0;
int tcounter = 0;
char str[80];
int main()
{
  cin.get(str, 80);
  cin.get();
  for (int i = 0; i <strlen(str); i++){
    if (str[2] != "\0"){
      cout << "Please enter in a letter followed by a number." << endl;
    }
    else if (str[0] != 'a' || str[0] != 'b' || str[0] != 'c'){
      cout << "Row must be letter a, b, or c." << endl;
    }
    else if (str[0] != '1' || str[0] != '2' || str[0] != '3'){
      cout << "Columns must be numbers 1, 2, or 3." << endl;
    }
    else{
      int row = str[0] - 'a';
      int column = str[1] - '1';
      if (board[row][column] == BLANK){
	if (turn == X_TURN){
	  board[row][column] = X_MOVE;
	  turn = O_TURN;
    }
  }
  printBoard();
  return 0;
}  

void printBoard(){
  cout <<  << endl;
  for(int row = 0; row < 3; row++){
    cout << (char)('a' + row) << endl;
    for(int column = 0; column < 3; column++){
    //if(board[row][column] == BLANK){
	cout <<"   " << " ";
	//}
	/* else if (board[row][column] == X_MOVE){
	cout << "X  " << " ";

      }
      else if (board[row][column] == O_MOVE){
	cout << "O  " << " ";
	}*/
    }
  }
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
  for (int row = 0; row < 3; row++){
    for (int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){
	return false;
      }
    }
  }
  return true;
}
