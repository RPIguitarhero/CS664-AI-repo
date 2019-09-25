// Tic Tac Toe.cpp :
//Authors:Kai, Sakhan, Shreyas, ak-shay

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int storeMatrix[3][3]; //a global matrix to store the advantageous value to determine the best move for AI

void setupGame(char game[3][3]);
void display(char game[3][3]);
void displayMatrix();
void wipeStoredMatrix(int matrix[3][3]);
void assignWeight(char game[3][3]);
bool checkWin(char game[3][3], char a);
int calculateWeight(char game[3][3], int slotPos[2]);
void playerInput(char game[3][3]);
void coreProcess(char game[3][3]);

int main()
{
	//set up game board and matrix
	char game[3][3];
	setupGame(game);
	wipeStoredMatrix(storeMatrix);

    cout << "Tic Tac Toe starting\n"<<"Do you(player) want to go first? Type T/F";
	char input;
	cin >> input;
	if (input == 'T')//player moves first
	{
		playerInput(game);
		display(game);
		displayMatrix();//DEBUG
		wipeStoredMatrix(storeMatrix);
		coreProcess(game);
	}
	else 
	{
		coreProcess(game);//AI moves first
	}

}

void coreProcess(char game[3][3])
{
bool isWinMove = false;
while (isWinMove!=true)
	{
	assignWeight(game);
	checkWin(game, 'O');
	checkWin(game, 'X');
	//read the weight matrix to get the best move
	int moveI, moveJ, heighestVal = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (storeMatrix[i][j] >= heighestVal)
			{
				heighestVal = storeMatrix[i][j];
				moveI = i;
				moveJ = j;
			}
		}
	}
	displayMatrix();//DEBUG
	game[moveI][moveJ] = 'O'; //move the best move
	if (heighestVal == 100) //winning move, exit loop and print winning message
	{
		isWinMove = true;
		cout << "The AI wins!\n";
		display(game);
		return;
	}
	display(game);
	playerInput(game);
	wipeStoredMatrix(storeMatrix);//reset the weight matrix after a trun(an AI move and a player move) 
	}
}


void playerInput(char game[3][3]) 
{
	cout << "Please enter your move with 2 numbers" << "\n"
		<< "which line?" << "\n";
	int i,j;
	cin >>i;
	cout << "which column?" << "\n";
	cin >> j;
	game[i][j] = 'X';
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

//a function to reset the calculated weight matrix, called after decision making for every move
void wipeStoredMatrix(int matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

//a simple function to display the current board weighted values
void displayMatrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << storeMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}

//a simple function to display the current board in command line
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
	
	//everything for AI
	if (a=='O') 
	{
		char arr[3] = {' ',' ',' '};

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

		//check first diagnoal(topleft to bottomright) 
		int winNum = 0;
		for (int i = 0; i < 3; i++)
		{
			if (game[i][i] == 'X') { break; }//automatically go to next row caz' we know this row fails

			arr[i] = game[i][i];
			if (game[i][i] == 'O') { winNum += 1; }
		}
		if (winNum == 2 && i == 3)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[k] == ' ') { storeMatrix[k][i] = 100; return true; }
			}
		}

		//check second diagnoal(topright to bottomleft) 
		winNum = 0;
		for (int i = 0; i < 3; i++)
		{
			if (game[i][2-i] == 'X') { break; }//note how the reversed diagonal index work differently

			arr[i] = game[i][2-i];
			if (game[i][2-i] == 'O') { winNum += 1; }
		}
		if (winNum == 2 && i == 3)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[k] == ' ') { storeMatrix[k][i] = 100; return true; }
			}
		}
	}

	//everything for player's turn, copied form the previous part, just reversed X and O
	else if (a == 'X')
	{
		char arr[3] = { ' ',' ',' ' };

		for (i = 0; i < 3; i++)
		{
			int winNum = 0;
			for (j = 0; j < 3; j++)
			{
				if (game[i][j] == 'O') { break; }//automatically go to next row caz' we know this row fails

				arr[j] = game[i][j];
				if (game[i][j] == 'X') { winNum += 1; }

			}
			if (winNum == 2 && j == 3)
			{
				for (int k = 0; k < 3; k++)
				{
					if (arr[k] == ' ') { storeMatrix[i][k] = 50; return true; } //Player's move should always have a smaller value
				}
			}
		}

		//check columns
		for (i = 0; i < 3; i++)
		{
			int winNum = 0;
			for (j = 0; j < 3; j++)
			{
				if (game[j][i] == 'O') { break; }//automatically go to next row caz' we know this row fails

				arr[j] = game[j][i];
				if (game[j][i] == 'X') { winNum += 1; }

			}
			if (winNum == 2 && j == 3)
			{
				for (int k = 0; k < 3; k++)
				{
					if (arr[k] == ' ') { storeMatrix[k][i] = 50; return true; }
				}
			}
		}

		//check first diagnoal(topleft to bottomright) 
		int winNum = 0;
		for (int i = 0; i < 3; i++)
		{
			if (game[i][i] == 'O') { break; }//automatically go to next row caz' we know this row fails

			arr[i] = game[i][i];
			if (game[i][i] == 'X') { winNum += 1; }
		}
		if (winNum == 2 && i == 3)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[k] == ' ') { storeMatrix[k][i] = 50; return true; }
			}
		}

		//check second diagnoal(topright to bottomleft) 
		winNum = 0;
		for (int i = 0; i < 3; i++)
		{
			if (game[i][2 - i] == 'O') { break; }//note how the reversed diagonal index work differently

			arr[i] = game[i][2 - i];
			if (game[i][2 - i] == 'X') { winNum += 1; }
		}
		if (winNum == 2 && i == 3)
		{
			for (int k = 0; k < 3; k++)
			{
				if (arr[k] == ' ') { storeMatrix[k][i] = 50; return true; }
			}
		}
	}
	return false;
}

//Assign the calculated weight to evvry empty slot, used only for AI 
void assignWeight(char game[3][3])
{
	for (int i = 0; i < 3; i++) //traverse the entire board for every empty slot
	{
		int horizontalO = 0, horizontalX = 0;
		for (int j = 0; j < 3; j++)
		{
			if (game[i][j]==' ') //empty slot located, parse the move position and the current empty slot position to calculate weight
			{
				int slotPos[2] = { i,j };
				storeMatrix[i][j]=calculateWeight(game, slotPos );
			}
		}		
	}
}

//calculate weight for an emoty slot
int calculateWeight(char game[3][3],  int slotPos[2])
{

	int i = slotPos[0], j = slotPos[1], weight = 0;
	//calculate horizontal value
	if (j==0) //all situation for left vertical line
	{
		if (game[i][1] == 'O' || game[i][2] == 'O')
		{
			if (game[i][1] != 'X' && game[i][2] != 'X')
			{
				weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
			}
		}
		else if (game[i][1] == 'X' || game[i][2] == 'X')
		{
			if (game[i][1] == ' ' || game[i][2] == ' ')
			{
				weight += 1; //1 point for blocking opponent path
			}
		}
		else if (game[i][1]==' ' && game[i][2]==' ') 
		{
			weight += 1; //1 point for creating a empty new path
		}
		//0 point if there is a X and a O on the line
	}

	if (j == 1) //all situation for middle vertical line
	{
		if (game[i][0] == 'O' || game[i][2] == 'O')
		{
			if (game[i][0] != 'X' && game[i][2] != 'X')
			{
				weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
			}
		}
		else if (game[i][0] == 'X' || game[i][2] == 'X')
		{
			if (game[i][0] == ' ' || game[i][2] == ' ')
			{
				weight += 1; //1 point for blocking opponent path
			}
		}
		else if (game[i][0] == ' ' && game[i][2] == ' ')
		{
			weight += 1; //1 point for creating a empty new path
		}
	}

	if (j == 2) //all situation for right vertical line
	{
		if (game[i][0] == 'O' || game[i][1] == 'O')
		{
			if (game[i][0] != 'X' && game[i][1] != 'X')
			{
				weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
			}
		}
		else if (game[i][0] == 'X' || game[i][1] == 'X')
		{
			if (game[i][0] == ' ' || game[i][1] == ' ')
			{
				weight += 1; //1 point for blocking opponent path
			}
		}
		else if (game[i][0] == ' ' && game[i][1] == ' ')
		{
			weight += 1; //1 point for creating a empty new path
		}
	}
	//calculate vertical value
	if (i == 0) //all situation for top horizontal line
	{
		if (game[1][j] == 'O' || game[2][j] == 'O')
		{
			if (game[1][j] != 'X' && game[2][j] != 'X')
			{
				weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
			}
		}
		else if (game[1][j] == 'X' || game[2][j] == 'X')
		{
			if (game[1][j] == ' ' || game[2][j] == ' ')
			{
				weight += 1; //1 point for blocking opponent path
			}
		}
		else if (game[1][j] == ' ' && game[2][j] == ' ')
		{
			weight += 1; //1 point for creating a empty new path
		}
	}

	if (i == 1) //all situation for middle horizontal line
	{
		if (game[0][j] == 'O' || game[2][j] == 'O')
		{
			if (game[0][j] != 'X' && game[2][j] != 'X')
			{
				weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
			}
		}
		else if (game[0][j] == 'X' || game[2][j] == 'X')
		{
			if (game[0][j] == ' ' || game[2][j] == ' ')
			{
				weight += 1; //1 point for blocking opponent path
			}
		}
		else if (game[0][j] == ' ' && game[2][j] == ' ')
		{
			weight += 1; //1 point for creating a empty new path
		}
	}

	if (i == 2) //all situation for bottom horizontal line
	{
		if (game[1][j] == 'O' || game[0][j] == 'O')
		{
			if (game[1][j] != 'X' && game[0][j] != 'X')
			{
				weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
			}
		}
		else if (game[1][j] == 'X' || game[0][j] == 'X')
		{
			if (game[1][j] == ' ' || game[0][j] == ' ')
			{
				weight += 1; //1 point for blocking opponent path
			}
		}
		else if (game[1][j] == ' ' && game[0][j] == ' ')
		{
			weight += 1; //1 point for creating a empty new path
		}
	}
	//calculate diagonal value
	if (i == j)//all situations for topleft->bottomright diagonal, {0,0}{1,1}{2,2}
	{
		if(i==0)
		{ 
			if (game[1][1] == 'O' || game[2][2] == 'O')
			{
				if (game[1][1] != 'X' && game[2][2] != 'X')
				{
					weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
				}
			}
			else if (game[1][1] == 'X' || game[2][2] == 'X')
			{
				if (game[1][1] == ' ' || game[2][2] == ' ')
				{
					weight += 1; //1 point for blocking opponent path
				}
			}
			else if (game[1][1] == ' ' && game[2][2] == ' ')
			{
				weight += 1; //1 point for creating a empty new path
			}
		}

		if (i == 1)
		{
			if (game[0][0] == 'O' || game[2][2] == 'O')
			{
				if (game[0][0] != 'X' && game[2][2] != 'X')
				{
					weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
				}
			}
			else if (game[0][0] == 'X' || game[2][2] == 'X')
			{
				if (game[0][0] == ' ' || game[2][2] == ' ')
				{
					weight += 1; //1 point for blocking opponent path
				}
			}
			else if (game[0][0] == ' ' && game[2][2] == ' ')
			{
				weight += 1; //1 point for creating a empty new path
			}
		}

		if (i == 2)
		{
			if (game[1][1] == 'O' || game[0][0] == 'O')
			{
				if (game[1][1] != 'X' && game[0][0] != 'X')
				{
					weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
				}
			}
			else if (game[1][1] == 'X' || game[0][0] == 'X')
			{
				if (game[1][1] == ' ' || game[0][0] == ' ')
				{
					weight += 1; //1 point for blocking opponent path
				}
			}
			else if (game[1][1] == ' ' && game[0][0] == ' ')
			{
				weight += 1; //1 point for creating a empty new path
			}
		}
	}

	if (i + j == 2)//all situations for  topright->bottomleft diagnoal {0,2}{1,1}{2,0}
	{
		if (i == 0)
		{
			if (game[1][1] == 'O' || game[2][0] == 'O')
			{
				if (game[1][1] != 'X' && game[2][0] != 'X')
				{
					weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
				}
			}
			else if (game[1][1] == 'X' || game[2][0] == 'X')
			{
				if (game[1][1] == ' ' || game[2][0] == ' ')
				{
					weight += 1; //1 point for blocking opponent path
				}
			}
			else if (game[1][1] == ' ' && game[2][0] == ' ')
			{
				weight += 1; //1 point for creating a empty new path
			}
		}

		if (i == 1)
		{
			if (game[0][2] == 'O' || game[2][0] == 'O')
			{
				if (game[0][2] != 'X' && game[2][0] != 'X')
				{
					weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
				}
			}
			else if (game[0][2] == 'X' || game[2][0] == 'X')
			{
				if (game[0][2] == ' ' || game[2][0] == ' ')
				{
					weight += 1; //1 point for blocking opponent path
				}
			}
			else if (game[0][2] == ' ' && game[2][0] == ' ')
			{
				weight += 1; //1 point for creating a empty new path
			}
		}

		if (i == 2)
		{
			if (game[1][1] == 'O' || game[0][2] == 'O')
			{
				if (game[1][1] != 'X' && game[0][2] != 'X')
				{
					weight += 2; //2 points when the move(1) will connect AND (2)no opponent on the path
				}
			}
			else if (game[1][1] == 'X' || game[0][2] == 'X')
			{
				if (game[1][1] == ' ' || game[0][2] == ' ')
				{
					weight += 1; //1 point for blocking opponent path
				}
			}
			else if (game[1][1] == ' ' && game[0][2] == ' ')
			{
				weight += 1; //1 point for creating a empty new path
			}
		}
	}
	return weight;
}