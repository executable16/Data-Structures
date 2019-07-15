#include <iostream>
#include <cstring>
using namespace std;

// N x N chessboard
#define N 8

// Function to check if two queens threaten each other or not
bool isSafe(char mat[][N], int r, int c)
{
	// return false if two queens share the same column
	for (int i = 0; i < r; i++)
		if (mat[i][c] == 'Q')
			return false;

	// return false if two queens share the same \ diagonal
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (mat[i][j] == 'Q')
			return false;

	// return false if two queens share the same / diagonal
	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
		if (mat[i][j] == 'Q')
			return false;

	return true;
}

void nQueen(char mat[][N], int r)
{
	// if N queens are placed successfully, print the solution
	if (r == N)
	{
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		
		return;
	}

	// place Queen at every square in current row r
	// and recur for each valid movement	
	for (int i = 0; i < N; i++) 
	{
		// if no two queens threaten each other
		if (isSafe(mat, r, i)) 
		{
			// place queen on current square
			mat[r][i] = 'Q';

			// recur for next row
			nQueen(mat, r + 1);

			// backtrack and remove queen from current square
			mat[r][i] = '-';
		}
	}
}

int main()
{
	// mat[][] keeps track of position of Queens in current configuration
	char mat[N][N];

	// initalize mat[][] by '-'
	memset(mat, '-', sizeof mat);

	nQueen(mat, 0);

	return 0;
}
