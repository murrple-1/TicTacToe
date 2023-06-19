# TicTacToe
## About the Program
This is a simple, but initial attempt at creating a game, and experiencing
game logic. I wanted to focus on the MVC paradigm, and also somewhat on
const-correctness, which has been giving me trouble in the past. The game Tic
Tac Toe is very cliche for programming, but I figured it would be a good game
to get comfortable with, and to be able to rewrite if I made big design errors.  

## Installation
If you have the program 'make' installed on your computer, the executable is
easily creatable by running 'make' on the containing directory.

EXAMPLE:
```sh
make
```
To uninstall the file, the executable is easily removed with the 'make clean'
command.

EXAMPLE:
```sh
make clean
```
I recommend you open the 'makefile' for further macros to change (in particular,
if you don't use 'cc' as your C compiler)

## Running the Program
The program is to be run from the command line. It will ask for the 2 players' names
and markers (usually X and O), and then start playing. You input numbers corresponding
to the locations on the board to make your move. The game ends when there's a draw, or
there's a winner. There is no single player mode.
