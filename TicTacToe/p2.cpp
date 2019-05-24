#include <iostream>
#include <cctype>
#include "tictactoe.h"

using namespace std;

void welcome();

void gameStats(int xWins, int oWins, int ties);

void goodbye();

//void clrScreen();

const char X = 'X';
const char O = 'O';
const char TIE = ' ';

int main()
{
  TicTacToe game;
  int xwon = 0, owon = 0, tie = 0;
  int row = 0, col = 0;
  bool xTurn = true;
  char ans = 'y';
  char winningPiece;

  // clrScreen();
  welcome();

  while (ans  == 'y'){
	while (!game.winner(winningPiece)){
	  game.displayBoard(cout);
	  if(xTurn){
		cout << "X, it is your turn." << endl;
		cout << "Which row? ";
		cin >> row;
		cout << "Which column? ";
		cin >> col;
		if (game.placePiece(X, row, col))
		  xTurn = false;
		else
		  cout << "Bad location, try again..." << endl;
	  }else{
		cout << "O, it is your turn." << endl;
		cout << "Which row? ";
		cin >> row;
		cout << "Which column? ";
		cin >> col;
		if (game.placePiece(O, row, col))
		  xTurn = true;
		else
		  cout << "Bad location, try again..." << endl;
	  }
	}
	
	if (winningPiece == X){
	  cout << "X win! Congratulation!" << endl;
	  xwon++;
	}else if (winningPiece == O){
	  cout << "O win! Congratulation!" << endl;
	  owon++;
	}else{
	  cout << "No winner - it was a tie!" << endl;
	  tie++;
	}
	
	gameStats(xwon, owon, tie);
	
	cout << "again? (y/n)";
	cin >> ans;
	if (ans=='y')
	  game.winner(winningPiece) = false;
  }
  
  goodbye();
}

void gameStats(int xWins, int oWins, int ties)
{
  cout << "Player 1: " << xWins << endl;
  cout << "Player 2: " << oWins << endl;
  cout << "Tie: " << ties << endl;
}

void welcome()
{
  cout << "Welcome!" << endl;
}

void goodbye()
{
  cout << "Goodbye!" << endl;
}
