/*
 * Player.h
 *
 *  Created on: Aug 12, 2010
 *      Author: Murray Christopherson
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

namespace roadrunner {

/**
 * A collection of information about the player, allowing custom game interface
 */
class Player {
public:
	/**
	 * Constructor
	 * @param marker - the "avatar" of the player. Appears on the game board, marking his/her spot
	 * @param name - the player's name, for potential customised game interface
	 */
	Player(const wchar_t, const std::wstring &);
	/**
	 * Destructor
	 */
	virtual ~Player();
	/**
	 * Return the player's marker/game piece/avatar
	 * @return the player's game piece
	 */
	wchar_t getGamePiece(void) const;
	/**
	 * Return the player's name
	 * @return the player's name
	 */
	std::wstring const * getName(void) const;
protected:
	void setGamePiece(const wchar_t);
	void setName(const std::wstring &);
private:
	wchar_t gamePiece;
	std::wstring name;
};

}

#endif /* PLAYER_H_ */
