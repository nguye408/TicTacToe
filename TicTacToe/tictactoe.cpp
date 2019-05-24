// Huy Vu
// tictactoe.cpp
//Purpose

#include "tictactoe.h"

TicTacToe::TicTacToe(int s)
{
  size = s;
  board = new char*[size];
  assert(board != nullptr);
  for (int i = 0 ; i < size; i++){
	board[i] = new char[size];
	assert(board[i] != nullptr);
  }
  for (int r = 0; r < size; r++)
	for (int c = 0; c < size; c++)
	  board[r][c] = SPACE;
}

TicTacToe::TicTacToe(const TicTacToe& t)
{
  //
  board = new char*[SIZE];
  assert (board != nullptr);
  for (int i = 0; i < SIZE; i++){
	board[i] = new char[SIZE];
	assert(board[i] != nullptr);
  }
  for (int r = 0; r < SIZE; r++)
	for (int c = 0; c < SIZE; c++)
	  board[r][c] = t.board[r][c];
}

TicTacToe& TicTacToe::operator=(const TicTacToe& rhs)
{
  if (this != &rhs){
	for (int r = 0; r < SIZE; r++)
	  for (int c = 0; c < SIZE; c++)
		board[r][c] = rhs.board[r][c];
  }
  return *this;
}

void TicTacToe::displayBoard(ostream& outs)
{
  outs << endl << endl;
  for (int i = 0; i < COL_WIDTH - 1; i++)
	outs << SPACE;
  for (int i = 0; i < SIZE; i++)
	outs << setw(COL_WIDTH) << i;
  outs << endl;
  for (int r = 0; r < SIZE; r++){
	outs << setw(COL_WIDTH) << r;
	for (int c = 0; c < SIZE; c++){
	  outs << SPACE << board[r][c] << VERTICAL;
	}
	outs << endl;
	for (int i = 0; i < SIZE; i++)
	  outs << SPACE;
	for (int d = 0; d < SIZE * COL_WIDTH; d++)
	  outs << DASH;
	outs << endl;
  }
}

bool TicTacToe::placePiece(char piece, int row, int col)
{
  if (row >= 0 && row < SIZE &&
	  col >= 0 && col < SIZE && board[row][col] == SPACE){
	board[row][col] = piece;
	return true;
  }else
	return false;
}
bool TicTacToe::winner(char& piece)
{
  bool won = false;
  int row = 0;
  int col =0;
  int index = 0;
  char checkPiece;
  bool spaces = false;
  while (!won && row < SIZE){
	col = 0;
	checkPiece = board[row][col];
	col++;
	while (col < SIZE && checkPiece == board[row][col])
	  col++;
	if (col == SIZE && checkPiece != SPACE){
	  won = true;
	  piece = checkPiece;
	}else{
	  row++;
	}
  }
  // if no winner yet, check for column winner
  row = 0;
  col = 0;
  while (!won && col < SIZE){
	row = 0;
	checkPiece = board [row][col];
	row++;
	while (row < SIZE && checkPiece == board[row][col])
	  row++;
	if (row == SIZE && checkPiece != SPACE){
	  won = true;
	  piece = checkPiece;
	}else{
	  col++;
	}
  }
  //if no winner yet, check for first diagnal
  if (!won){
	checkPiece = board[index][index];
	index++;
	while (index < SIZE && checkPiece == board[index][index])
	  index++;
	if (index == SIZE && checkPiece != SPACE){
	  won = true;
	  piece = checkPiece;
	}else{
	  index++;
	}
  }
  // diag2
  index = 0;
  if (!won){
	checkPiece = board[index][size - 1 - index];
	index++;
	while (index < SIZE && checkPiece == board[index][size - 1 - index])
	  index++;
	if (index == SIZE && checkPiece != SPACE){
	  won = true;
	  piece = checkPiece;
	}else{
	  index++;
	}
  }
  // tie
  row = 0;
  if (!won){
	while (!spaces && row < SIZE){
	  col = 0;
	  while (col < SIZE){
		if (board[row][col] == SPACE)
		  spaces = true;
		col++;
	  }
	  row++;
	}
	if (!spaces)
    won = true;
  }
  
  return won;
}

void TicTacToe::resetBoard()
{
  for (int r = 0; r < SIZE; r++)
	for (int c = 0; c < SIZE; c++)
	  board[r][c] = SPACE;
}

TicTacToe::~TicTacToe()
{
  
}
