/***************************************************************************
 *   Copyright (C) 2023 by Antti Pirinen   *
 *   e2202869@edu.vamk.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
    Game of life

 2.  DESCRIPTION
    The Game of Life is a cellular automaton, a zero-player game that simulates the evolution of a population of cells based on a set of simple rules.

 3.  VERSIONS
       Original:
         9.4.2023 / pirinen

       Version history:
        13.4.2023 / pirinen

**********************************************************************/
/*-------------------------------------------------------------------*
 *    HEADER FILE                                                    *
 *--------------------------------------------------------------------*/
#include "header.h"

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/
int main()
{
    initscr();
    clear();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    int i, j;
    struct cell board[Y_AXIS][X_AXIS] = {0, 0}; // initializing the array

    char mode = askStartup(); // calling for function which asks user if he wants to load the game from file or not
    erase();
    int rounds = askRounds(); // calling for function which asks user how many rounds do we want to play
    erase();

    if (mode == 'y' || mode == 'Y')
    {
        initGameFromFile(board); // loading the game from file

        for (i = 0; i < rounds; i++)
        {
            erase();
            printRound(i, j, board);
            calculateMoves(i, j, board);
            usleep(500000);
        }
    }
    else if (mode == 'n' || mode == 'N')
    {
        initGame(board); // load the game from function
        for (i = 0; i < rounds; i++)
        {
            erase();
            printRound(i, j, board);
            calculateMoves(i, j, board);
            usleep(500000);
        }
    }
    endwin();
}
