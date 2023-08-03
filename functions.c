/*-------------------------------------------------------------------*
 *    HEADER FILE                                                    *
 *--------------------------------------------------------------------*/
#include "header.h"

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    NAME: int countNeighbours()
    DESCRIPTION: counts the amount of neighbours for our current cell
    Input: int i, j and struct cell board[Y_AXIS][X_AXIS]
    Output: int neighbours
    Used global variables: Y_AXIS and X_AXIS
    REMARKS when using this function:
    -
*********************************************************************/
int countNeighbours(int i, int j, struct cell board[Y_AXIS][X_AXIS])
{
    int neighbours;

    /*counting the neighbours around the cell*/

    neighbours = board[i - 1][j - 1].current +
                 board[i - 1][j].current +
                 board[i - 1][j + 1].current +
                 board[i][j - 1].current +
                 board[i][j + 1].current +
                 board[i + 1][j - 1].current +
                 board[i + 1][j].current +
                 board[i + 1][j + 1].current;

    return neighbours;
}
/*********************************************************************
    NAME: void calculateMoves()
    DESCRIPTION: calculates the next moves and passes them to our current board
    Input: int i, j and struct cell board[Y_AXIS][X_AXIS]
    Output: -
    Used global variables: Y_AXIS and X_AXIS
    REMARKS when using this function:
    -
*********************************************************************/
void calculateMoves(int i, int j, struct cell board[Y_AXIS][X_AXIS])
{
    int neighbours;

    for (i = 1; i < Y_AXIS-1; i++) // looping through the board
    {
        for (j = 1; j < X_AXIS-1; j++)
        {
            neighbours = countNeighbours(i, j, board); // getting the amount of neighbours

            /*calculating the moves*/

            if (board[i][j].current == 1 && neighbours < 2)
            {
                board[i][j].future = 0;
            }
            else if (board[i][j].current == 1 && neighbours >= 4)
            {
                board[i][j].future = 0;
            }
            else if (board[i][j].current == 1 && neighbours == 2 || neighbours == 3)
            {
                board[i][j].future = 1;
            }
            else if (board[i][j].current == 0 && neighbours == 3)
            {
                board[i][j].future = 1;
            }
        }
    }

    for (i = 0; i < Y_AXIS; i++) // moving the data from future board to current board
    {
        for (j = 0; j < X_AXIS; j++)
        {
            board[i][j].current = board[i][j].future;
        }
    }
}

/*********************************************************************
    NAME: void initGameFromFile()
    DESCRIPTION: loads the starting population to grid from file
    Input: struct cell board[Y_AXIS][X_AXIS]
    Output: -
    Used global variables: Y_AXIS and X_AXIS
    REMARKS when using this function:
    function reads the starting positions from .txt file and the cells
    must be represented as 0's and 1's to work.
*********************************************************************/
void initGameFromFile(struct cell board[Y_AXIS][X_AXIS])
{
    FILE *fp;
    char state_c;
    int state, j = 0, i = 0;

    fp = fopen("game.txt", "r");

    if (fp == NULL) // check if file opened successfully
    {
        printf("Error opening file!\n");
        endwin();
        exit(1);
    }

    while (!feof(fp)) // looping till we reach the end
    {
        fscanf(fp, "%c", &state_c); // reading characters one by one
        state = state_c - '0';      // converting the character to integer and assigning it to the variable

        if (state_c != '0' && state_c != '1' && state_c != '\n' && state_c != '\r')
        {
            printf("Error reading from file!\n");
            endwin();
            exit(1);
        }

        board[i][j].current = state; // filling the board with the integers readen from the file

        j++; // moving forward on x axis

        if (j == X_AXIS) // if at the end of the row
        {
            i++;                        // moving to the next row by increasing i
            j = 0;                      // resetting j to start counting from the start of the row
            fscanf(fp, "%c", &state_c); // reads the newline character
        }
    }

    fclose(fp); // closing the file
}

/*********************************************************************
    NAME: void initGame()
    DESCRIPTION: loads the starting population to grid
    Input: struct cell board[Y_AXIS][X_AXIS]
    Output: -
    Used global variables: Y_AXIS and X_AXIS
    REMARKS when using this function:
    You can manually set different starting points for the cells here.
    Just remember that your cells must stay inside the borders.
*********************************************************************/
void initGame(struct cell board[Y_AXIS][X_AXIS])
{
    board[5][20].current = 1;
    board[6][20].current = 1;
    board[7][20].current = 1;
    board[7][22].current = 1;
    board[8][20].current = 1;
    board[8][21].current = 1;
    board[9][20].current = 1;

}