// Huy Vu
// tictactoe.h
// purpose:

#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
 public:
  explicit TicTacToe(int s = 3 );
  //constructor
  
  TicTacToe(const TicTacToe& t);
  //copy constructor

  TicTacToe& operator=(const TicTacToe& rhs);
  //overloaded assignment operator

  void displayBoard(ostream& outs);
  //display board to outs

  bool placePiece(char piece, int row, int col);
  //places piece in board at row/col
  //returns false if spot occupied

  bool winner(char& piece);
  //returns false if no winner else
  //returns true and piece
  //post: piece updated if game over

  void resetBoard();
  //prepare board for new game
  //post: data removed from board

  ~TicTacToe();
  //destructor

 private:
  int size;
  char **board;

  static const int SIZE = 3;
  static const char SPACE = ' ';
  static const char VERTICAL = '|';
  static const char DASH = '-';
  static const int COL_WIDTH = 3;
};

#endif
