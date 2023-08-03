/*-------------------------------------------------------------------*
 *    HEADER FILE                                                    *
 *--------------------------------------------------------------------*/
#include "header.h"

/*********************************************************************
    NAME: void printRound()
    DESCRIPTION: prints the board to terminal
    Input: int i, j and struct cell board[Y_AXIS][X_AXIS]
    Output: -
    Used global variables: Y_AXIS and X_AXIS
    REMARKS when using this function:
    -
*********************************************************************/
void printRound(int i, int j, struct cell board[Y_AXIS][X_AXIS])
{
    printw("\n");
    curs_set(0);
    for (i = 1; i < Y_AXIS - 1; i++) // looping through the board
    {
        for (j = 1; j < X_AXIS - 1; j++)
        {
            if (board[i][j].current == 0) // printing all 0's from the board as "-"'s
            {
                attron(COLOR_PAIR(2));
                printw(" ");
            }
            else if (board[i][j].current == 1)
            {
                attron(COLOR_PAIR(1));
                printw("O"); // printing all 1's from the board as "O"'s
            }
        }
        printw("\n");
        refresh();
    }
}

/*********************************************************************
    NAME: int askRounds()
    DESCRIPTION: asks user how many rounds we wants to play
    Input: -
    Output: int rounds
    Used global variables: -
    REMARKS when using this function:
    -
*********************************************************************/
int askRounds(void)
{
    int rounds = 0;
    char input[100];
    while (rounds <= 0 || !isdigit(input[0])) // looping till we get valid input from user
    {
        printw("\nHow many rounds do you want to play?\n");
        refresh();
        scanw("%s", input);
        if (!isdigit(input[0])) // if input is not digit
        {
            printw("\nInvalid input! Enter a positive number.\n");
        }
        else
        {
            rounds = atoi(input); // turning char input to integer
            if (rounds <= 0)      // if input is 0 or negative
            {
                printw("\nInvalid input! Enter a positive number.\n");
            }
        }
    }

    return rounds;
}

/*********************************************************************
    NAME: askStartup()
    DESCRIPTION: asks user how we want to start the game
    Input: -
    Output: char mode
    Used global variables: -
    REMARKS when using this function:
    -
*********************************************************************/
char askStartup(void)
{
    char mode;
    while (mode != 'y' && mode != 'Y' && mode != 'n' && mode != 'N') //looping till input is right
    {
        printw("\nLoad the game from file? (y/n)\n");
        refresh();
        scanw(" %c", &mode);
        printw("");

        if (mode != 'y' && mode != 'Y' && mode != 'n' && mode != 'N') //if input is not what we asked for
        {
            printw("Invalid input! Try again\n"); //printing error
            refresh();
        }
    }

    return mode;
}