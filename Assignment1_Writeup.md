CS442 Assignment 1: Tetromino Solver
====================================
**Name:** Kevin Midkiff
**Email:** kmidkiff@pdx.edu

The goal of this assignment was to implement a solver for the tetromino game. To implement this program I chose to use C++ 
and CMake for my build system. The basic algorithm I used to solve this problem is a recursive algorithm that goes as follows:

```
solve(board, pieces):
  If the board is solved:
    return true
    
  for each piece in pieces
    pop the first element off of the list
    
    for each possible rotation of the piece
      Try to place the piece at that rotation on the board
      If it succeeds, call solve with the board and the current
      list of pieces, which has the current piece popped off
        If solving from this point in the recursion succeeds, return the solution
        If solving from this point in the recursion fails, then undo the placement of the current piece on the board
        
    If we are unable to find a solution from placing the current piece, then push it onto the back of the list and continue
  
  return false
```

In this algorithm, I tackle the placement of pieces by trying to place the given piece for a specific rotation at the available upper most
left hand cell in the grid of the board. With the knowledge of where this cell is, I use manually calculated offsets for each piece to
figure if I can place the piece at that location. To check if a piece can be placed I check the following two things:

  1. Does the piece cross over the x and y bounds of the board?
  2. Are any of the cells which the piece would fill already occupied?
  
If these two checks succeed, then I can successfully place the piece on the board. At that point I save the piece to a list of known placed
pieces on the board and add the ASCII letters to the cells in the grid of the board which the piece will fill.

I broke the problem down into 5 objects. The first object is called the TetrominoSolver. This object encapsulates the above algorithm, as well 
as holds the list of pieces and the board. This brings us to the second object, which is the Board. The Board represents the current board, it 
contains a multi-dimensional array of chars, which represent the pieces that are placed on the board and how they are placed on the board. It 
also contains a list of PiecePlacement objects, which I will explain later. 

The last three objects are centered around representation of a piece. The first is a representation of an individual piece. The Piece object
is simply an enum with an entry for each piece (i.e. I, O, P, 2, 5, L, and T). In addition, I have another enum for each possible 90 degree 
rotation of a piece (i.e. 0, 90, 180, and 270 degrees). The last object, which was mentioned previously, is the PiecePlacement object, which is a 
C++ struct. The PiecePlacement object represents the placement of a piece on the board. The PiecePlacement structure has the piece which was placed, 
the upper most left x and y coordinates and the offsets from the upper most left x and y coordinates at which it was placed.

To compile my solution execute the following commands:

```sh
$ mkdir build
$ cd build/
$ cmake ..
$ make
```

After executing these commands, you will have a binary named, "tetro_solve". The binary expects to receive the following input via stdin as specified
in the specifications of the assignment:

```
<rows> <columns>
<string of pieces>
```

An example of this is:

```
4 6
ITT5LP
```

To test my solution, I created 9 tests, which are contained in the tests directory. In addition, their expected output is also contained in the tests
directory. Below is an example of executing two of these tests, as well as the output that should be expected from these tests. Note that it is expected
that you are in the build directory when executing these tests.

```sh
$ ./tetro_solve < ../tests/test2-in.txt
aabbcc
aabddc
efbdgc
effdgg
efhiig
ehhhii

$ ./tetro_solve < ../tests/test3-in.txt
?
```
