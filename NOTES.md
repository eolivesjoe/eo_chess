# EOChess

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

### 060921-
    
    Moved files to a Visual Studio repo, with gitignore and removed MakeFile

    Updated some formatting

    Added some checks in utility.h

    Time to start move generation

### 060921-

    Begun move generation with white pawns

### 070921-

    Separated assertbool and assertInt for checking positions

    Added white pawn moves to generator

### 080921-

    Big help from Bluefever Software, buy him a coffee!

    Must complete checkBoard to avoid index errors

    Double check util functions to make sure everything is checked properly

    White pawns might need a few more checks but looks OK

    Add more checks in anything that modifies squares, no more index errors

    Should start adding dates to future goals!

### 090921-

    Utililty.h works properly without warnings

    MoveGeneration for white pawns works as expected

### 171121-
    
    Begun work on move generation for sliding pieces

### 100122-

    Updated makefile

    remember to turn on Wno-unused functions after fixing utility.h!

### 200122-

    Fixed inaccurate naming conventions, added a few notes for future TODOs.

### 230222-

    Minor work on adding moves for sliding pieces.

    Continue to work on non-sliding pieces for move generation, continue in pieces.h
 
### 240222-

    Updated README with some more information.

### 010322-

    Updated arrays with piece directions.

### 060322-

    Move generation for non-sliding pieces almost done.

    Updated some redundant functions.

### 070322-

    Logic for generating sliding piece moves implemented.

    Changed Utility from static to free functions. Removed 'Wno-unused functions' from makefile

### 120322-

    White kingside castling implemented.

### 160322-

    White queenside castling implemented.

### 230322-

    All castling checks implemented except for king danger.

### 290322-
    
    Move generation looks to be working.

    TODO: Additional testing for edge cases.
	
### 080522-
	
	Updated for Visual studio

	Updated file name extensions from .cc to .cpp


## future goals / TODO:

    Condense some of the struct files into more readable option

    finish check board function!

    Turn everything into bit boards

    Make all error messages consistent / create error struct

    Implement the 50 rule move

    Rewrite readFENString eventually. Find a better way of reading it. Switch?

    Clean up some variable names for readability, SQ_120 and SQ_64

    Rewrite the pieces and BoardState class to make it less complicated

    Remember to clean up assertSquare to deal with square values that arent 99! Look at non sliding
    pieces in move_generator.



## references:

    chess programming wiki:

        https://www.chessprogramming.org/Main_Page
        
        https://www.chessprogramming.org/Forsyth-Edwards_Notation


    general:

        https://www.youtube.com/playlist?list=PLZ1QII7yudbc-Ky058TEaOstZHVbT-2hg

        https://stackoverflow.com/questions/246564/what-is-the-lifetime-of-a-static-variable-in-a-c-function

        https://en.cppreference.com/w/cpp/language/operator_precedence

        https://www.youtube.com/playlist?list=PLmN0neTso3Jxh8ZIylk74JpwfiWNI76Cs

        https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception

        https://www.geeksforgeeks.org/sprintf-in-c/

        https://en.cppreference.com/w/cpp/io/c/fprintf

        https://stackoverflow.com/questions/8067394/static-helper-class


    bit boards:

        https://www.chessprogramming.org/Magic_Bitboards

        https://stackoverflow.com/questions/30680559/how-to-find-magic-bitboards

        https://www.youtube.com/watch?v=4ohJQ9pCkHI


    bit operations:

        https://librambutan.readthedocs.io/en/latest/lang/cpp/compoundbitwise.html

        https://librambutan.readthedocs.io/en/latest/lang/cpp/bitwisemath.html#lang-bitwisemath

        https://en.wikipedia.org/wiki/Bitwise_operation

        https://en.wikipedia.org/wiki/Mask_%28computing%29


    hash number generation:

        https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
        
        http://www.cplusplus.com/reference/random/mt19937_64/

        https://stackoverflow.com/questions/14009637/c11-random-numbers

        https://www.geeksforgeeks.org/stduniform_int_distribution-class-in-c/

        https://stackoverflow.com/questions/21328048/using-random-device-in-classes


    positioning

        https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation

        https://www.delftstack.com/howto/c/convert-int-to-char/

        http://www.asciitable.com/

        https://stackoverflow.com/questions/21208308/adding-and-subtracting-chars-why-does-this-work
        
        https://medium.com/swlh/what-does-subtracting-a-char-from-a-char-mean-79da714c1b3b


    move generation
        
        https://www.chessprogramming.org/Encoding_Moves