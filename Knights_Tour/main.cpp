#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstring>

const int size = 5;

void print_maze(int maze[size][size]){
    for (int i=0; i < size;  i++) {
        for (int j = 0; j < size; j++)
        {
            //makes output pretty
            printf(" %2d ", maze[i][j]);
        }
        std::cout << '\n';
    }
}

bool solve(int maze[size][size], int row, int col,int x[size], int y[size], int moveidx)
{
    // if knight has moved to every square, then the tour is complete.
    if (moveidx == size*size)
        return true;

    for (int i = 0; i < 8; i++)
    {
        // if index is valid and the move is an unvisited square
        if (row+x[i] >= 0 && row+x[i] < size && col+y[i] >= 0 && col+y[i] < size && maze[row+x[i]][col+y[i]] == -1)
        {
            maze[row+x[i]][col+y[i]] = moveidx;
            // tour all possible movement combos, which will then tour all their possible movement combos, etc.
            // if it was a successful tour aka all tiles were reached, then we are done. otherwise backtrace, set equal to unvisited square.
            if (solve(maze, row+x[i], col+y[i],x,y,moveidx+1))
                return true;
            else
                maze[row+x[i]][col+y[i]] = -1;
        }
    }
    // if it goes through without ever completing a tour, no solution.
    return false;
}

int main()
{
    int maze[size][size];
    // init all values to -1
    memset(maze, -1, sizeof(maze[0][0]) * size * size);
    // all possible movement combinations
    int x[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int y[8] = {-2, 2, -2, 2, -1, 1, -1, 1};
    // first move is initial idx
    maze[0][0] = 0;
    if(!solve(maze,0,0,x,y,1))
        std::cout << "no solution";
    else
        print_maze(maze);
    return 0;
}
