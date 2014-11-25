/*
 * Player.cpp
 *
 *  Created on: Aug 12, 2010
 *      Author: Murray Christopherson
 */

#include "Player.h"

namespace roadrunner {

Player::Player(const wchar_t aPiece, const std::wstring &aName) {
	setGamePiece(aPiece);
	setName(aName);
}

Player::~Player() {
	// do nothing
}

wchar_t Player::getGamePiece(void) const {
	return gamePiece;
}

std::wstring const * Player::getName(void) const {
	return &name;
}

void Player::setGamePiece(const wchar_t aPiece) {
	gamePiece = aPiece;
}

void Player::setName(const std::wstring &aName) {
	name = aName;
}

}
