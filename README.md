# eo_chess
by Erik Olivesjoe

### Personal project to develop my knowledge of computer chess



Currently the program reads in a [FEN](https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation) string and displays the board state. 

An example where white has made the first move (e4).

        rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1

        
        8   r  n  b  q  k  b  n  r
        7   p  p  p  p  p  p  p  p
        6   .  .  .  .  .  .  .  . 
        5   .  .  .  .  .  .  .  .    
        4   .  .  .  .  P  .  .  .    
        3   .  .  .  .  .  .  .  .
        2   P  P  P  P  .  P  P  P
        1   R  N  B  Q  K  B  N  R

            a  b  c  d  e  f  g  h

We can also see which squares are currently under attack by white or black, the example below shows the squares white is currently attacking
using two pawns and a bishop.

        8/6P1/3B4/8/8/1P4/8/8 w KQkq - 0 1

        8   .  .  .  .  .  .  .  .
        7   .  .  .  .  .  .  P  . 
        6   .  .  .  B  .  .  .  . 
        5   .  .  .  .  .  .  .  .   
        4   .  .  .  .  .  .  .  .  
        3   .  P  .  .  .  .  .  .
        2   .  .  .  .  .  .  .  .
        1   .  .  .  .  .  .  .  .

        a  b  c  d  e  f  g  h

        -  o  -  -  -  o  -  o
        -  -  o  -  o  -  -  -
        -  -  -  -  -  -  -  -
        -  -  o  -  o  -  -  -
        o  o  o  -  -  o  -  -
        o  -  -  -  -  -  o  -
        -  -  -  -  -  -  -  o
        -  -  -  -  -  -  -  -


 ### Milestone 1 - In progress.
 
Build a working pvp chess game in c++ using various information and references found online. I want to try various ways to represent the game such as bit boards and normal piece arrays to learn more about chess programming. All references and my personal notes and updates can be found in NOTES.md

### Milestone 2
 
Convert it into a pve engine that you can play against.
