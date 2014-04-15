#include "graphics.h"
#include "AI.h"

char board[3][3];// = {{'X','O','X'},{'4','5','6'},{'7','8','9'}};

void init()
{
	init_graphics();
	for(int row =0; row< 3;row++)
	{
		for(int col =0; col < 3;col++)
		{
			board[row][col] = 3*row + col + 49;
		}
	}
}

void end()
{
	destroy_graphics();
}
int main()
{
	init();
	int c=-1;
	char player = 'X';
	char AI ='O';
	do{
		c-=49;
		if(c>=0 && c< 9)
		{
			if(board[c/3][c%3]<60)board[c/3][c%3] = player;
			int ai = MinMax(board);
			if((ai--)>=-1)board[ai/3][ai%3] = AI;
		}
		render(board);
	}while((c=getchar())!='q');
	/*int ai = MinMax(board);
	board[ai/3][ai%3] = AI;
	render(board);
	getchar();*/
	end();
}
