#include <iostream>
#include <cstring>
#include <stdlib.h>
/*10/1/19 Author: Maggie Bao. Description: In the game Tic-Tac-Toe, the program prompts the X player to go first and input X's into a grid by means of declaring the rows and columns. The O player will take their turn next, and the two users go back and forth until either someone wins, or there is a tie. When the round is finished, the program will display the number of wins of each player and the number of ties. After that, it will prompt the user if they want to play again and the other player will make the first move. */

using namespace std;

//for methods, declare first before initialization
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
char str[5];
bool stillPlaying = true;
char response = ' ';

int main()
{
  while (stillPlaying == true){
    while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false){
      cout << "Please enter in a lowercase letter followed by a number (ex. \"a1\", \"c3\")." << endl;
      printBoard(); //print empty gridboard
      cin.get(str, 5); //put into array of 5. Extra char will be ignored
      cin.clear(); //clear, ignore fixes null bug
      cin.ignore(9999, '\n');
      if (strlen(str) != 2){//if length is not 2, loop to cout above
      }
      else if (str[0] != 'a' && str[0] != 'b' && str[0] != 'c'){//array index 0
        cout << "Row must be letter a, b, or c." << endl;
      }
      else if (str[1] != '1' && str[1] != '2' && str[1] != '3'){//array index 1
        cout << "Column must be number 1, 2, or 3." << endl;
      }
      else{
        int row = str[0] - 'a'; //set index of row
        int column = str[1] - '1';//set index of column
        if (board[row][column] == BLANK){//if the box is blank
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
      if (checkWin(X_MOVE) == true) { //If X move
        cout << "X wins!" << endl;
        xcounter++; //add 1 to counter
      }
      else if (checkWin(O_MOVE) == true) { //If O move
        cout << "O wins!" << endl;
        ocounter++;
      }
      else if (checkTie() == true) { //tie method below
	cout << "It is a tie!" << endl;
	tcounter++;
      }
    }
      cout << "X has " << xcounter << " wins." << endl;
      cout << "O has " << ocounter << " wins." << endl;
      cout << "There has been " << tcounter << " ties." << endl;
      bool ask = true;
      while (ask == true) {//create loop for if response is not valid input
        cout << "Play again? (y/n)" << endl;
        cin >> response;
        if (response == 'n' || response == 'N'){
          cout << "Have a nice day!" << endl;
	  ask = false;
          stillPlaying = false;
          exit(0); //close program
        }
        else if (response == 'y' || response == 'Y'){
  	  ask = false;
	  for (int row = 0; row < 3; row ++){ //reset to a blank board
	    for (int column = 0; column < 3; column++) {
	      board[row][column] = BLANK;
	    }
	  }
        }
        else {
	  cout << "Input must be either \"y\" or \"n\"." << endl;
        }
      }
      cin.get(); //prevent empty board from printing twice
    }
    return 0;
}  

void printBoard(){
  cout <<"\t1\t2\t3 "  << endl; //print header
  for(int row = 0; row < 3; row++){
    cout << (char)('a' + row) << "\t"; //letter and space
    for(int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){ //if box is blank
	cout << "\t";
      }
      else if (board[row][column] == X_MOVE){ //if x calls the shots
	cout << "X\t";
      }
      else if (board[row][column] == O_MOVE){ //if o calls the shots
	cout << "O\t";
      }
    }
    cout << " " << endl; //new row
  }
}
  
bool checkWin (int player){ //checks all possible combinations of a win in two dimentional array
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

 
bool checkTie(){ //if all boxes are filled, return true
  for (int row = 0; row < 3; row++){
    for (int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){
	return false;
      }
    }
  }
  return true;
}
