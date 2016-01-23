TicTacToe
=========
Created by Murray Christopherson  
Updated October 2010

About the Program
-----------------
This is a simple, but initial attempt at creating a game, and experiencing
game logic. I wanted to focus on the MVC paradigm, and also somewhat on
const-correctness, which has been giving me trouble in the past. The game Tic
Tac Toe is very cliche for programming, but I figured it would be a good game
to get comfortable with, and to be able to rewrite if I made big design errors.  
It is recommended you read the source code to see exactly what the code is
doing.  
Please visit my portfolio at http://murraychristopherson.com

If you discover any bugs or unclear/inconsistent documentation, please contact me
at murraychristopherson@gmail.com with a description of what happened, and I
will try and have a fixed version up shortly.

Installation
------------
If you have the program 'make' installed on your computer, the executable is
easily creatable by running 'make' on the containing directory.

EXAMPLE:
```
$> make
```
To uninstall the file, the executable is easily removed with the 'make clean'
command.

EXAMPLE:
```
$> make clean
```
I recommend you open the 'makefile' for further macros to change (in particular,
if you don't use 'cc' as your C compiler)

Running the Program
-------------------
The program is to be run from the command line. It will ask for the 2 players' names
and markers (usually X and O), and then start playing. You input numbers corresponding
to the locations on the board to make your move. The game ends when there's a draw, or
there's a winner. There is no single player mode.
