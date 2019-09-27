#include <iostream>
#include <cstring>

using namespace std;

void printBoard();
bool checkWin(int);
bool checkTie();

int board [3][3];
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;
int turn = X_TURN;
int xcounter = 0;
int ocounter = 0;
int tcounter = 0;
char str[80];
bool stillPlaying = true;
char response = ' ';

int main()
{
  while (stillPlaying == true){
    while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false){
      cout << "Please enter in a letter followed by a number." << endl;
      printBoard();
      cin.get(str, 80);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strlen(str) != 2){
        cout << "Please enter in a letter followed by a number." << endl;
      }
      else if (str[0] != 'a' && str[0] != 'b' && str[0] != 'c'){
        cout << "Row must be letter a, b, or c." << endl;
      }
      else if (str[1] != '1' && str[1] != '2' && str[1] != '3'){
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
  	  else{
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
  	  }
        }
        else {
	  cout << "There's a piece there!" << endl;
        }
      }
      if (checkWin(X_MOVE) == true) {
        cout << "X wins!" << endl;
        xcounter++;
      }
      else if (checkWin(O_MOVE) == true) {
        cout << "O wins!" << endl;
        ocounter++;
      }
      else if (checkTie() == true) {
	cout << "It is a tie!" << endl;
	tcounter++;
      }
    }
      cout << "X has " << xcounter << " wins." << endl;
      cout << "O has " << ocounter << " wins." << endl;
      cout << "There has been " << tcounter << " ties." << endl;
      bool ask = true;
      while (ask == true) {
        cout << "Play again? (y/n)" << endl;
        cin >> response;
        if (response == 'n' || response == 'N'){
          cout << "Have a nice day!" << endl;
	  ask = false;
          stillPlaying = false;
          break;
        }
        else if (response == 'y' || response == 'Y'){
  	  ask = false;
	  for (int row = 0; row < 3; row ++){
	    for (int column = 0; column < 3; column++) {
	      board[row][column] = BLANK;
	      stillPlaying = true;
	    }
	  }
	  break;
        }
        else {
	  cout << "Input must be either y or n." << endl;
	  ask = true;
        }
      }
    }
    return 0;
}  

void printBoard(){
  cout <<"\t1\t2\t3 "  << endl;
  for(int row = 0; row < 3; row++){
    cout << (char)('a' + row) << "\t";
    for(int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){
	cout << "\t";
      }
      else if (board[row][column] == X_MOVE){
	cout << "X\t";
      }
      else if (board[row][column] == O_MOVE){
	cout << "O\t";
      }
    }
    cout << " " << endl;
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
