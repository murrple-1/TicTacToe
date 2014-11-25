/*
 * File:   Main.cpp
 * Author: Murray Christopherson
 *
 * Created on June 10, 2010, 1:27 PM
 *
 * A simple game of TicTacToe, to practice my C++ programming,
 * and game logic
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <list>
#include <limits>
#include "Board.h"
#include "Player.h"

#define NUM_OF_PLAYERS 2
#define X_LENGTH 3
#define Y_LENGTH 3

/**
 * Status of the game, following last player's move
 */
enum GameStatus {
	IN_PLAY, DRAW, OVER
};

/**
 * Return the pointer to space, based on the space number input
 * @param board - the board to return the space from
 * @param pos - the number of the position to be returned
 * @return a pointer to the space specified, or NULL if space not found
 */
roadrunner::Space * const getSpace(roadrunner::Board const &, const int);
/**
 * Determine the status of the game
 * @param board - the board to examine
 * @return if the game in play, there's a winner or it's a draw
 */
GameStatus checkGameStatus(roadrunner::Board const &);
/**
 * Should only be called if checkGameStatus() == OVER. Gets a
 * pointer to the winner of the game.
 * @param board - the board to get the winner from
 * @return a pointer to the winner, or NULL if there is no winner
 */
roadrunner::Player * const getWinner(roadrunner::Board const &);
/**
 * Prompt the player for a move, then make the move. Error handling handed
 * internally.
 * @param board - the board to play on
 * @param the player making the move
 */
void makeMove(roadrunner::Board &, roadrunner::Player &);
/**
 * Output the board in the format:
 *
 * |?||?||?|
 * |?||?||?|
 * |?||?||?|
 *
 * where '?' is either the position number (@see getSpace()), or the
 * occupying player's marker
 */
void printBoard(roadrunner::Board const &);

const int maxStream = std::numeric_limits<std::streamsize>::max();

/**
 *
 */
int main(int argc, char** argv) {
	std::list<roadrunner::Player> players;
	roadrunner::Board board(X_LENGTH, Y_LENGTH);
	int i = 0;
	while (i < NUM_OF_PLAYERS) {
		std::wstring name;
		wchar_t marker;
		std::wcout << L"Player " << (i + 1) << L", please input your name:"
				<< std::endl;
		std::getline(std::wcin, name);
		std::wcout << name << L", what is your marker?" << std::endl;
		std::wcin >> marker;
		std::wcin.ignore(maxStream, L'\n');
		std::list<roadrunner::Player>::const_iterator iter;
		bool foundDup = false;
		for (iter = players.begin(); iter != players.end(); iter++) {
			if (marker == (*iter).getGamePiece()) {
				std::wcout
						<< L"Sorry, that marker is already taken. Please try again."
						<< std::endl;
				foundDup = true;
				break;
			}
		}
		if (!foundDup) {
			players.push_back(roadrunner::Player(marker, name));
			i++;
		}
	}
	GameStatus status = IN_PLAY;
	while (true) {
		std::list<roadrunner::Player>::iterator iter;
		bool gameOver = false;
		for (iter = players.begin(); iter != players.end(); iter++) {
			printBoard(board);
			makeMove(board, *iter);
			status = checkGameStatus(board);
			if (status != IN_PLAY) {
				gameOver = true;
				break;
			}
		}
		if (gameOver) {
			break;
		}
	}

	printBoard(board); // end result

	if (status == DRAW) {
		std::wcout << L"Game was a Draw" << std::endl;
	} else if (status == OVER) {
		roadrunner::Player * winner = getWinner(board);
		std::wcout << L"Winner is: " << *(winner->getName()) << std::endl;
		std::wcout << L"Congrats!" << std::endl;
	}

	return EXIT_SUCCESS;
}

const int arraySize = 8;
const int sizePerValid = 3;
/**
 * The combinations of spaces that must be held to win
 */
int winningCombinations[][sizePerValid] = { { 1, 2, 3 }, { 4, 5, 6 },
		{ 7, 8, 9 }, // horizontals
		{ 1, 4, 7 }, { 2, 5, 8 }, { 3, 6, 9 }, // verticals
		{ 1, 5, 9 }, { 3, 5, 7 } // diagonals
};

GameStatus checkGameStatus(roadrunner::Board const & board) {
	bool allTaken = true;
	for (int i = 0; i < arraySize; i++) {
		roadrunner::Space * space = getSpace(board, winningCombinations[i][0]);
		if (space == NULL)
			if (!(space->isTaken())) {
				allTaken = false;
				continue;
			}
		bool foundWinner = true;
		for (int j = 1; j < sizePerValid; j++) {
			roadrunner::Space * comp = getSpace(board,
					winningCombinations[i][j]);
			if (!(comp->isTaken())) {
				foundWinner = false;
				allTaken = false;
				break;
			} else {
				if (comp->getTaker() != space->getTaker()) {
					foundWinner = false;
					break;
				}
			}
		}
		if (foundWinner) {
			return OVER;
		}
	}
	if (allTaken == true) {
		return DRAW;
	} else {
		return IN_PLAY;
	}
}

roadrunner::Space * const getSpace(roadrunner::Board const & board,
		const int pos) {
	int count = 1;
	for (int y = 0; y < board.getY(); y++) {
		for (int x = 0; x < board.getX(); x++) {
			if (count == pos) {
				return &board.getBoard()[x][y];
			}
			count++;
		}
	}
	return NULL;
}

roadrunner::Player * const getWinner(roadrunner::Board const & board) {
	for (int i = 0; i < arraySize; i++) {
		roadrunner::Space * space = getSpace(board, winningCombinations[i][0]);
		if (!(space->isTaken())) {
			continue;
		}
		bool foundWinner = true;
		for (int j = 1; j < sizePerValid; j++) {
			roadrunner::Space * comp = getSpace(board,
					winningCombinations[i][j]);
			if (!(comp->isTaken()) || (comp->getTaker() != space->getTaker())) {
				foundWinner = false;
				break;
			}
		}
		if (foundWinner) {
			return space->getTaker();
		}
	}
	return NULL;
}

void makeMove(roadrunner::Board & board, roadrunner::Player & player) {
	int position = 0;
	roadrunner::Space * space = NULL;
	bool goodMove = false;
	while (!goodMove) {
		std::wcout << *(player.getName()) << L", enter your move:" << std::endl;
		while (!(std::wcin >> position)) {
			std::wcout << "Please input a number" << std::endl;
			std::wcout << *(player.getName()) << L", enter your move:"
					<< std::endl;
			std::wcin.clear();
			std::wcin.ignore(maxStream, L'\n');
		}
		std::wcin.ignore(maxStream, L'\n');
		space = getSpace(board, position);
		if (space == NULL) {
			std::wcout << L"Space " << position << L" is not within range"
					<< std::endl;
		} else if (!(space->isTaken())) {
			goodMove = true;
		} else {
			std::wcout << L"Space " << position << L" is already taken"
					<< std::endl;
		}
	}
	space->setTaker(&player);
}

void printBoard(roadrunner::Board const & board) {
	roadrunner::Space ** spaces = board.getBoard();
	int i = 1;
	for (int y = 0; y < board.getY(); y++) {
		for (int x = 0; x < board.getX(); x++) {
			std::wcout << L"|";
			if (spaces[x][y].isTaken()) {
				std::wcout << spaces[x][y].getTaker()->getGamePiece();
			} else {
				std::wcout << i;
			}
			std::wcout << L"|";
			i++;
		}
		std::wcout << std::endl;
	}
}
