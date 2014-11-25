/*
 * GameBoard.h
 *
 *  Created on: Aug 12, 2010
 *      Author: Murray Christopherson
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <list>
#include "Space.h"

namespace roadrunner {

/**
 * A board representing the TicTacToe game state
 */
class Board {
public:
	/**
	 * Constructor
	 * @param x - the width of the game board
	 * @param y - the height of the game board
	 */
	Board(int = 3, int = 3);
	/**
	 * Destructor
	 */
	virtual ~Board();
	/**
	 * Return the width of the game board
	 * @return width of the game board (x-axis)
	 */
	int getX(void) const;
	/**
	 * Return the height of the game board
	 * @return height of the game board (y-axis)
	 */
	int getY(void) const;
	/**
	 * Return the 2D array of spaces in the game board
	 * @return the game board
	 */
	Space * * const getBoard(void) const;
private:
	int x;
	int y;
	Space ** board;
};

}

#endif /* GAMEBOARD_H_ */
