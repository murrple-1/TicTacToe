/*
 * GameBoard.cpp
 *
 *  Created on: Aug 12, 2010
 *      Author: Murray Christopherson
 */

#include <iostream>
#include "Board.h"

namespace roadrunner {

Board::Board(int xInt, int yInt) :
	x(xInt), y(yInt) {
	board = new Space*[x];
	for (int i = 0; i < x; i++) {
		board[i] = new Space[y];
	}
}

Board::~Board() {
	for (int i = 0; i < x; i++) {
		delete[] board[i];
	}
	delete[] board;
}

int Board::getX(void) const {
	return x;
}

int Board::getY(void) const {
	return y;
}

Space * * const Board::getBoard(void) const {
	return board;
}
}
