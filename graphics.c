#include <ncurses.h>
#include "graphics.h"

void init_graphics()
{
	initscr();
}

void destroy_graphics()
{
	endwin();
}

void render(char board[3][3])
{
	for(int row = 0; row< 3;row++)
	{
		move(row,0);
		for(int col=0;col<3;col++)
		{
			addch(board[row][col]);
		}
	}
	mvprintw(15,0,"Player X, Pick which space: ");
	refresh();
}

int getchar()
{
	return getch();
}
