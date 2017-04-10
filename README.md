Tetromino-Solver
================
Tetromino Solver

## Compiling
To compile the solver execute the following commands:

```sh
$ mkdir build
$ cd build/
$ cmake ..
$ make
```

After executing these commands, you will have a binary named, "tetro_solve". The binary expects to receive the following input via stdin.

```
<rows> <columns>
<string of pieces>
```

An example of this is:

```
4 6
ITT5LP
```

## Running Tests

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
