/*
 * GameLocation.cpp
 *
 *  Created on: 22 Sep 2010
 *      Author: Murray Christopherson
 */

#include "Space.h"

namespace roadrunner {

Space::Space() :
	taken(false), taker(NULL) {

}

Space::~Space() {
	// do nothing
}

Player * Space::getTaker(void) const {
	return taker;
}

bool Space::isTaken(void) const {
	return taken;
}

void Space::setTaker(Player * ava) {
	taker = ava;
	taken = true;
}

}
