# eoChess
by Erik Olivesjoe

 ## Hobby chess project. started 150321



         Anyone who attempts to generate random numbers by deterministic means is, of course, living in a state of sin.

        - John von Neumann



 ### 150321-

    Started project. Wrote defs and a few notes.


 ### 230521-

    Have initialised board, able to print both 64 board for playing and 120 for checking allowed move.

    Started investigating biboards for pawn movement.


 ### 240521-

    Pawn setting and checking working for bitboard.

    Should move my pawn array to pieces instead of having it in bitboard.

    Need to implement an option to remove pawns.

    Might need a pop bit function eventually.

    x |= y;   // equivalent to x = x | y.

    Set and clear bit working.

    Beware of strange side effect where countBits will clear them if they are set. 

    Should work on piece positioning next.


 ### 250521-

    Created hash keys for pieces, side and castling. 

    Added HashKey class.

    Fix random number generator next!


### 260521-

    Hash generation working, ended up using mt19937 with a function reference. 

    Changed from C++11 to C++17

    Moved pawns and piece list to a board struct

    Implemented a funcition to create unique position keys

    Create an undo move struct

    Removed Utility class


### 270521-

    wrote function to reset board state

    Begun looking at FEN record for piece positioning

    started writing function to place pieces on board, start after sideToMove


### 280521-

    readFENString in working condition. But slightly hacky solution.
    Beware of index errors in the future, assert everything!

### 290521-

    readFENString finally working properly after fixing a few bugs.

    En passant square set correctly.

### 180721-

    function to update material lists done.

    Kingsquare storage in updateMaterialLists might not be needed.

    Moves should be up next.

### 190721-

    added two arrays to check which rank and file a square is on

    added bitboard to material list function

### 230721-

    Check board started

### 260721-

    Added arrays of bools to check which type of piece is attacking

### 170821-

    Attacked square by knight working correctly

### 190821-

    Attacked square working correctly

    Updated README

### 240821-

    Code needs a refactor

    Move bitsetting works

### 280821-

    More work on move generation

    Moved the check for specific piece type from Attack.h to Pieces.h
 
### 310821-
    
    Changed 'Move' to struct

    Created 'Validator.h', a struct that will contain various checks to make sure everything works properly

    Added 'Moves.h' to store a number of moves

 
## future goals / notes:

    finish check board function!!

    Turn everything into bit boards

    Make all error messages consistent / create error struct

    Implement the 50 rule move

    Rewrite readFENString eventually. Find a better way of reading it. Switch?

    Clean up some variable names for readability, SQ_120 and SQ_64

    Rewrite the pieces and BoardState class to make it less complicated