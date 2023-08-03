/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <ncurses.h>
/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Global constants */
#define Y_AXIS 24
#define X_AXIS 44
/* Global structures */
struct cell
{
    int current;
    int future;
};
/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
char askStartup(void);
int askRounds(void);
int countNeighbours(int i, int j, struct cell board[Y_AXIS][X_AXIS]);
void initGame(struct cell board[Y_AXIS][X_AXIS]);
void initGameFromFile(struct cell board[Y_AXIS][X_AXIS]);
void calculateMoves(int i, int j, struct cell board[Y_AXIS][X_AXIS]);
void printRound(int i, int j, struct cell board[Y_AXIS][X_AXIS]);