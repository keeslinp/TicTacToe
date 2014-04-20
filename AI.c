#include "AI.h"
#include <string.h>
#include <stdio.h>


int min(char board[3][3]);

int eqthree(int a, int b, int c)
{
	return (a==b && b==c);
}

int victory_check(char board[3][3])
{
	//Diagonals
	if(eqthree(board[0][0],board[1][1], board[2][2])) return (board[0][0]=='O'?1:-1);
	if(eqthree(board[0][2],board[1][1], board[2][0])) return (board[1][1]=='O'?1:-1);
	//Horizonatls
	if(eqthree(board[0][0],board[0][1], board[0][2])) return (board[0][0]=='O'?1:-1);
	if(eqthree(board[1][0],board[1][1], board[1][2])) return (board[1][0]=='O'?1:-1);
	if(eqthree(board[2][0],board[2][1], board[2][2])) return (board[2][0]=='O'?1:-1);
	//Verticals
	if(eqthree(board[0][0],board[1][0], board[2][0])) return (board[0][0]=='O'?1:-1);
	if(eqthree(board[0][1],board[1][1], board[2][1])) return (board[0][1]=='O'?1:-1);
	if(eqthree(board[0][2],board[1][2], board[2][2])) return (board[0][2]=='O'?1:-1);
	return 0;
}
int max(char board[3][3])
{
	int max_score = -1;
	int max_choice = -1;
	for(int row=0;row<3;row++)
	{
		for(int col =0 ; col<3;col++)
		{
			if(board[row][col]<60)
			{
				char copy[3][3];
				memcpy(copy,board,sizeof(char)*9);
				copy[row][col] = 'O';
				if(victory_check(copy)==1)return 3*row+col+1;
				int min_choice = min(copy)-1;
				copy[min_choice/3][min_choice%3]='X';
				int potential = victory_check(copy);
				if(potential>=max_score)
				{
					max_score = potential;
					max_choice = 3*row + col+1;
				}
			}
		}
	}
	return max_choice;
}

int min(char board[3][3])
{
	int min_score = 1;
	int min_choice = 0;
	for(int row=0;row<3;row++)
	{
		for(int col =0 ; col<3;col++)
		{
			if(board[row][col]<60)
			{
				char copy[3][3];
				memcpy(copy,board,sizeof(char)*9);
				copy[row][col] = 'X';
				int max_choice = max(copy)-1;
				copy[max_choice/3][max_choice%3]='O';
				int potential = victory_check(copy);
				if(potential<=min_score)
				{
					min_score = potential;
					min_choice = 3*row + col+1;
				}
			}
		}
	}
	return min_choice;
}

int MinMax(char board[3][3])
{
	return max(board);
}

/*int main()
{
	char board[3][3] = {{'X','O','X'},{'4','5','6'},{'X','8','O'}};
	printf("%d\n",MinMax(board));
}*/
