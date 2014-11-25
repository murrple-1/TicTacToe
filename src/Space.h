/*
 * GameLocation.h
 *
 *  Created on: 22 Sep 2010
 *      Author: Murray Christopherson
 */

#ifndef GAMELOCATION_H_
#define GAMELOCATION_H_

#include "Player.h"

namespace roadrunner {

/**
 * A space on the game board, with states of empty or taken by a player
 */
class Space {
public:
	/**
	 * Constructor
	 */
	Space();
	/**
	 * Destructor
	 */
	virtual ~Space();
	/**
	 * Return the holder of the space
	 * @return a pointer to the holder of the space, or NULL if space isn't taken
	 */
	Player * getTaker(void) const;
	/**
	 * Tells if the space is empty or taken
	 * @return if the space is taken
	 */
	bool isTaken(void) const;
	/**
	 * Takes the space
	 * @param player - the player taking this space
	 */
	void setTaker(Player * const);
private:
	bool taken;
	Player * taker;
};

}

#endif /* GAMELOCATION_H_ */
