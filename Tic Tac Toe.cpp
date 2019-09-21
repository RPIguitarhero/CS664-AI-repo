// Tic Tac Toe.cpp :
//Authors:Kai, Sakhan, Shreyas, ak-shay

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int storeMatrix[3][3];

int main()
{
    cout << "Tic Tac Toe starting\n"<<"Do you(player) want to go first? Type T/F";
	char input;
	cin >> input;
	if (input == 'T')
	{

	}
	else 
	{
	
	}

	//set up matrix
	char game[3][3];
	setupGame(game);
	//user input->decide who goes first
	//

}

//initilize the game board
void setupGame(char game[3][3])
{
	for (int i = 0; i <3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game[i][j] = ' '; //using  space to denote an empty slot
			storeMatrix[i][j] = 0;
		}
	}
}

void display(char game[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << game[i][j]<<" ";
		}
		cout << "\n";
	}
}

//check if either side already has 2 pieces in a line
//first read a char to see which side it is reading. 'X' for player, 'O' for AI
bool checkWin(char game[3][3], char a)
{
	int i=0, j = 0;
	//check rows
	if (a=='O') 
	{
		char arr[3] = { " "," "," " };
		for (i = 0; i < 3; i++)
		{
			int winNum = 0;
			for (j = 0; j < 3; j++)
			{
				if (game[i][j] == 'X') { break; }//automatically go to next row caz' we know this row fails

				arr[j] = game[i][j];
				if (game[i][j] == 'O') { winNum += 1; }
				
			}
			if (winNum == 2 && j==3)
			{
				for (int k = 0; k < 3; k++)
				{
					if (arr[k] == ' ') { storeMatrix[i][k] = 100; return true; }
				}
			}
		}

		//check columns
		for (i = 0; i < 3; i++)
		{
			int winNum = 0;
			for (j = 0; j < 3; j++)
			{
				if (game[j][i] == 'X') { break; }//automatically go to next row caz' we know this row fails

				arr[j] = game[j][i];
				if (game[j][i] == 'O') { winNum += 1; }

			}
			if (winNum == 2 && j == 3)
			{
				for (int k = 0; k < 3; k++)
				{
					if (arr[k] == ' ') { storeMatrix[k][i] = 100; return true; }
				}
			}
		}

		//check diagnoal 1
		for (int i = 0; i < 3; i++)
		{
			int winNum = 0;
			if (game[i][i] == 'X') { break; }//automatically go to next row caz' we know this row fails

			arr[i] = game[i][i];
			if (game[i][i] == 'O') { winNum += 1; }
		}
		if (winNum == 2 && j == 3)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[k] == ' ') { storeMatrix[k][i] = 100; return true; }
			}
		}
	//something
	}
	else 
	{

	//something
	}
}

void checkWin(char game[2][2], char a)
{

}

//traverse the board to diagnose how find the most advantageous next move
void calculateWeight(char game[2][2])
{

	for (int i = 0; i < 3; i++)
	{
		int horizontalO = 0, horizontalX = 0;
		for (int j = 0; j < 3; j++)
		{
			
		}
		
	}
}

//check adjacent slots to calculate most advantageous move
void calculateWeight2(char game[2][2], int posHorizontal, int posVertical)
{
	for (int i = 0; i < 3; i++)
	{
		if(posHorizontal)
		for (int j = 0; j < 3; j++)
		{

		}

	}
}