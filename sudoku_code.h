#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<random>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define UNASSIGNED 0
#define N 9 
bool FindUnassignedLocation(int grid[N][N], int& row, int& col);
bool isSafe(int grid[N][N], int row, int col, int num);
void step_checker(int row, int column, int x[9][9]);


bool SolveSudoku(int grid[N][N])
{
	int row, col;

	// If there is no unassigned location, we are done 
	if (!FindUnassignedLocation(grid, row, col))
		return true; // success! 

	 // consider digits 1 to 9 
	for (int num = 1; num <= 9; num++)
	{
		// if looks promising 
		if (isSafe(grid, row, col, num))
		{
			// make tentative assignment 
			grid[row][col] = num;

			// return, if success, yay! 
			if (SolveSudoku(grid))
				return true;

			// failure, unmake & try again 
			grid[row][col] = UNASSIGNED;
		}
	}
	return false; // this triggers backtracking 
}
bool FindUnassignedLocation(int grid[N][N], int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

/* Returns a boolean which indicates whether an assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether an assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether an assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
	return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num)
{
	/* Check if 'num' is not already placed in current row,
	   current column and current 3x3 box */
	return !UsedInRow(grid, row, num) &&
		!UsedInCol(grid, col, num) &&
		!UsedInBox(grid, row - row % 3, col - col % 3, num) &&
		grid[row][col] == UNASSIGNED;
}






void red()
{
	printf("\033[1;31m");
}

void yellow()
{
	printf("\033[1;33m");
}
void green()
{
	printf("\033[;32m");
}
void blue()
{
	printf("\033[0;34m");
}
void magneta()
{
	printf("\033[0;35m");
}
void cyan()
{
	printf("\033[0;36m");
}


void reset()
{
	printf("\033[0m");
}

int solve_sudoku(int y[9][9]);



void empty_grid_printf()
{
	int i, j;
	int y[9][9] = { 0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,

				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,

				0,0,0	,0,0,0	,0,0,0,
				0,0,0	,0,0,0	,0,0,0,
				0,0,0	,0,0,0	,0,0,0
	};
	printf("\t-------------------------\n");
	for (i = 0; i < 9; i++) {
		printf("\t");
		for (j = 0; j < 9; j++) {
			if (j == 0)
				printf("| ");
			if (y[i][j] == 0)
				printf(". ");
			else
				printf("%d ", y[i][j]);
			if ((j + 1) % 3 == 0)
				printf("| ");

		}

		if ((i + 1) % 3 == 0)
			printf("\n\t-------------------------");

		printf("\n");

	}
}
////////////////////////////////////////////////////////////////////////////////////////
void init(int x[9][9], int sudoku[9][9], int a[9][9], int c[9][9])
{


	int i, j;
	int box;
	int z = 0;
	int choice;
	//int row=0, column=0;
	choice = 0;
	int counter_row = 0;
	int counter_column = 0;
	int counter_box = 0;

	int y[9][9] = { 0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,

				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,

				0,0,0	,0,0,0	,0,0,0,
				0,0,0	,0,0,0	,0,0,0,
				0,0,0	,0,0,0	,0,0,0
	};
	/*for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf(" %d ", y[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");*/



	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			x[i][j] = y[i][j];
		}
	}


	while (choice != 1)
	{

		int row = 0, column = 0;
		cyan();
		printf("\nplease enter the row number \n");
		reset();
		scanf("%d", &row);
		
		
		while ((row >10) || (row < 0))
		{


			red();
			printf("please enter a number between 0 and 8 \n");
			printf("\nplease enter the row number \n");
			scanf("%d", &row);
			

			reset();
		}

		cyan();
		printf("\nplease enter the column number \n");
		reset();
		scanf("%d", &column);
		
		while ((column >10) || (column < 0))
		{
			red();
			printf("please enter a number between 0 and 8\n");
			printf("\nplease enter the column number \n");
			scanf("%d", &column);
			

			reset();

		}
		cyan();
		printf("please enter the value you want \n");
		reset();
		scanf("%d", &x[row][column]);
		
		while ((x[row][column] >10) || (x[row][column] < 0))
		{
			red();
			printf("please enter a number between 1 and 9 \n");
			printf("please enter the value you want \n");
			scanf("%d", &x[row][column]);
			
			reset();

		}
		
		/*cyan();
		printf("please enter the number of the box you want to enter the number in \n");
		scanf("%d", &box);
		reset();
		while ((box > 10) || (box < 0))
		{
			red();
			printf("please enter a box number between 1 and 9  \n");
			scanf("%d", &box);
			reset();
		}*/
		if (((row >= 0) || (row <= 2)) && ((column >= 0) || (column <= 2)))
		{
			box = 1;
		}
		else
		{
			if (((row >= 0) || (row <= 2)) && ((column >= 3) || (column <= 5)))
			{
				box = 2;
			}
			else
			{
				if (((row >= 0) || (row <= 2)) && ((column >= 6) || (column <= 8)))
				{
					box = 3;
				}
				else
				{
					if (((row >= 3) || (row <= 5)) && ((column >= 0) || (column <= 2)))
					{
						box = 4;
					}
					else
					{
						if (((row >= 3) || (row <= 5)) && ((column >= 3) || (column <= 5)))
						{
							box = 5;
						}
						else
						{
							if (((row >= 3) || (row <= 5)) && ((column >= 6) || (column <= 8)))
							{
								box = 6;
							}
							else
							{
								if (((row >= 6) || (row <= 8)) && ((column >= 0) || (column <= 2)))
								{
									box = 7;
								}
								else
								{
									if (((row >= 6) || (row <= 8)) && ((column >= 3) || (column <= 5)))
									{
										box = 8;
									}
									else
									{
										if (((row >= 6) || (row <= 8)) && ((column >= 6) || (column <= 8)))
										{
											box = 9;
										}
									}

								}

							}

						}

					}

				}

			}

		}

		
		//row checker
		for (i = 0; i < 9; i++)
		{
			if (x[row][column] == x[row][i])
			{
				if (column != i)
				{
					red();
					printf("illegal move in row \n");
					reset();
				}


			}




		}
		system("cls");
		//column checker
		for (i = 0; i < 9; i++)
		{
			if (x[row][column] == x[i][column])
			{
				if (row != i)
				{
					red();
					printf("illegal move in column \n");
					reset();
				}

			}

		}
		switch (box)
		{

		case 1:
		{
			//box 1  checker 
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 2:
		{
			//box 2 checker
			for (i = 0; i < 3; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 3:
		{

			//box 3 checker
			for (i = 0; i < 3; i++)
			{
				for (j = 6; j < 9; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 4:
		{
			//box 4 checker
			for (i = 3; i < 6; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}

		}
		break;
		case 5:
		{
			//box 5 checker
			for (i = 3; i < 6; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 6:
		{
			//box 6 checker
			for (i = 3; i <= 5; i++)
			{
				for (j = 6; j <= 8; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 7:
		{
			//box 7 checker
			for (i = 6; i < 9; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 8:
		{
			//box 8 checker
			for (i = 6; i < 9; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 9:
		{

			//box 9 checker
			for (i = 6; i <= 9; i++)
			{
				for (j = 6; j <= 9; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 1)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}


					}


				}

			}


		}
		break;
		default:
		{

		}
		}


		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				y[row][column] = x[row][column];
			}
		}

		blue();
		printf("\t-------------------------\n");
		reset();
		for (i = 0; i < 9; i++) {
			printf("\t");
			for (j = 0; j < 9; j++) {
				if (j == 0)
				{
					blue();
					printf("| ");
					reset();
				}
				if (y[i][j] == 0)
				{
					magneta();
					printf(". ");
					reset();
				}
				else
				{
					yellow();
					printf("%d ", y[i][j]);
					reset();
				}
				if ((j + 1) % 3 == 0)
				{
					blue();
					printf("| ");
					reset();
				}

			}

			if ((i + 1) % 3 == 0)
			{
				blue();
				printf("\n\t-------------------------");
				reset();
			}

			printf("\n");

		}
		cyan();
		printf("\ndo you want to continue the input \n");
		printf("if yes choose (0) , if no choose (1)\n");
		reset();
		scanf("%d", &choice);
		
		

	}
	blue();
	printf("\t-------------------------\n");
	reset();
	for (i = 0; i < 9; i++) {
		printf("\t");
		for (j = 0; j < 9; j++) {
			if (j == 0)
			{
				blue();
				printf("| ");
				reset();
			}
			if (y[i][j] == 0)
			{
				magneta();
				printf(". ");
				reset();
			}
			else
			{
				green();
				printf("%d ", y[i][j]);
				reset();
			}
			if ((j + 1) % 3 == 0)
			{
				blue();
				printf("| ");
				reset();
			}

		}

		if ((i + 1) % 3 == 0)
		{
			blue();
			printf("\n\t-------------------------");
			reset();
		}

		printf("\n");

	}
	
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudoku[i][j] = y[i][j];
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			a[i][j] = sudoku[i][j];
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			c[i][j] = sudoku[i][j];
		}
	}
	system("cls");


}
////////////////////////////////////////////////////////////////////////////
void play(int x[9][9], int sudoku[9][9], int y[9][9], int c[9][9])
{
	int i, j;
	int box;
	int row, column;
	int com[9][9];
	int time;
	int time_check = 0;
	int k, l;
	int choice = 0;
	int counter_row = 0, counter_column = 0, counter_box = 0;
	clock_t start, end;
	start = clock();


	system("cls");

	while (choice != 1)
	{
		int row = 0, column = 0;
		cyan();
		printf("\nplease enter the row number \n");
		reset();
		scanf("%d", &row);
		
		while ((row > 10) || (row < 0))
		{


			red();
			printf("please enter a number between 0 and 8 \n");
			printf("\nplease enter the row number \n");
			scanf("%d", &row);
			


			reset();
		}
		cyan();
		printf("\nplease enter the column number \n");
		reset();
		scanf("%d", &column);
		while ((column > 10) || (column < 0))
		{
			red();
			printf("please enter a number between 0 and 8\n");
			printf("\nplease enter the column number \n");
			scanf("%d", &column);
			

			reset();

		}
		cyan();
		printf("please enter the value you want \n");
		reset();
		scanf("%d", &x[row][column]);
		
		while ((x[row][column] > 10) || (x[row][column] < 0))
		{
			red();
			printf("please enter a number between 1 and 8 \n");
			printf("please enter the value you want \n");
			scanf("%d", &x[row][column]);
			
			reset();

		}
		/*cyan();
		printf("please enter the number of the box you want to enter the number in \n");
		scanf("%d", &box);
		reset();
		while ((box > 10) || (box < 0))
		{
			red();
			printf("please enter a box number between 1 and 9  \n");
			scanf("%d", &box);
			reset();
		}*/

		if (((row >= 0) || (row <= 2)) && ((column >= 0) || (column <= 2)))
		{
			box = 1;
		}
		else
		{
			if (((row >= 0) || (row <= 2)) && ((column >= 3) || (column <= 5)))
			{
				box = 2;
			}
			else
			{
				if (((row >= 0) || (row <= 2)) && ((column >= 6) || (column <= 8)))
				{
					box = 3;
				}
				else
				{
					if (((row >= 3) || (row <= 5)) && ((column >= 0) || (column <= 2)))
					{
						box = 4;
					}
					else
					{
						if (((row >= 3) || (row <= 5)) && ((column >= 3) || (column <= 5)))
						{
							box = 5;
						}
						else
						{
							if (((row >= 3) || (row <= 5)) && ((column >= 6) || (column <= 8)))
							{
								box = 6;
							}
							else
							{
								if (((row >= 6) || (row <= 8)) && ((column >= 0) || (column <= 2)))
								{
									box = 7;
								}
								else
								{
									if (((row >= 6) || (row <= 8)) && ((column >= 3) || (column <= 5)))
									{
										box = 8;
									}
									else
									{
										if (((row >= 6) || (row <= 8)) && ((column >= 6) || (column <= 8)))
										{
											box = 9;
										}
									}
									
								}
								
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		

		
		system("cls");
		
		//row checker
		for (i = 0; i < 9; i++)
		{
			if (x[row][column] == x[row][i])
			{
				if (column != i)
				{
					red();
					printf("illegal move in row \n");
					reset();
				}


			}




		}

		//column checker
		for (i = 0; i < 9; i++)
		{
			if (x[row][column] == x[i][column])
			{
				if (row != i)
				{
					red();
					printf("illegal move in column \n");
					reset();
				}

			}

		}
		switch (box)
		{

		case 1:
		{
			//box 1  checker 
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 2:
		{
			//box 2 checker
			for (i = 0; i < 3; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 3:
		{

			//box 3 checker
			for (i = 0; i < 3; i++)
			{
				for (j = 6; j < 9; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 4:
		{
			//box 4 checker
			for (i = 3; i < 6; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}

		}
		break;
		case 5:
		{
			//box 5 checker
			for (i = 3; i < 6; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 6:
		{
			//box 6 checker
			for (i = 3; i <= 5; i++)
			{
				for (j = 6; j <= 8; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 7:
		{
			//box 7 checker
			for (i = 6; i < 9; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 8:
		{
			//box 8 checker
			for (i = 6; i < 9; i++)
			{
				for (j = 3; j < 6; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 0)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
		break;
		case 9:
		{

			//box 9 checker
			for (i = 6; i <= 9; i++)
			{
				for (j = 6; j <= 9; j++)
				{
					if (x[row][column] == x[i][j])
					{
						if ((row != i) && (column != j))
						{
							counter_box = 0;
							counter_box++;
							if (counter_box > 1)
							{

								red();
								printf("illegal move box\n");
								reset();
								counter_box--;
							}
						}


					}


				}

			}


		}
		break;
		default:
		{

		}
		}


		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				sudoku[row][column] = x[row][column];
			}
		}
		magneta();
		blue();
		printf("\t-------------------------\n");
		reset();
		for (i = 0; i < 9; i++) {
			printf("\t");
			for (j = 0; j < 9; j++) {
				if (j == 0)
				{
					blue();
					printf("| ");
					reset();
				}
				if (sudoku[i][j] == 0)
				{
					magneta();
					printf(". ");
					reset();
				}
				else
				{
					green();
					printf("%d ", sudoku[i][j]);
					reset();
				}
				if ((j + 1) % 3 == 0)
				{
					blue();
					printf("| ");
					reset();
				}

			}

			if ((i + 1) % 3 == 0)
			{
				blue();
				printf("\n\t-------------------------");
				reset();
			}

			printf("\n");

		}

		end = clock();
		time = (end - start) / CLOCKS_PER_SEC;
		if (time > 180)
		{
			printf("\ntime is up \n");
			break;
		}

		printf("\ndo you want to continue the input \n");
		printf("if yes choose (0) , if no choose (1)\n");
		scanf("%d", &choice);
		
		
		/*end = clock();
		time = (end - start) / CLOCKS_PER_SEC;
		if (time > 180)
		{
			printf("\ntime is up \n");
			break;
		}*/

	}

	//int row=0, column=0;
	for (row = 0; row < 9; row++)
	{
		for (column = 0; column < 9; column++)
		{
			y[row][column] = sudoku[row][column];
		}
	}


}
////////////////////////////////////////////////////////////////////////////////////////
int number_unassigned(int* row, int* col, int sudoku[9][9])
{
	int num_unassign = 0;
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			//cell is unassigned
			if (sudoku[i][j] == 0)
			{
				//changing the values of row and col
				*row = i;
				*col = j;
				//there is one or more unassigned cells
				num_unassign = 1;
				return num_unassign;
			}
		}
	}
	return num_unassign;
}
////////////////////////////////////////////////////////////////////////////////////////
//function to check if we can put a
//value in a paticular cell or not
int is_safe(int n, int r, int c, int sudoku[9][9])
{
	int i, j;
	//checking in row
	for (i = 0; i < 9; i++)
	{
		//there is a cell with same value
		if (sudoku[r][i] == n)
			return 0;
	}
	//checking column
	for (i = 0; i < 9; i++)
	{
		//there is a cell with the value equal to i
		if (sudoku[i][c] == n)
			return 0;
	}
	//checking sub matrix
	int row_start = (r / 3) * 3;
	int col_start = (c / 3) * 3;
	for (i = row_start; i < row_start + 3; i++)
	{
		for (j = col_start; j < col_start + 3; j++)
		{
			if (sudoku[i][j] == n)
				return 0;
		}
	}
	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////
//function to solve sudoku
//using backtracking
int solve_sudoku(int y[9][9])
{
	int row;
	int col;
	//if all cells are assigned then the sudoku is already solved
	//pass by reference because number_unassigned will change the values of row and col
	if (number_unassigned(&row, &col, y) == 0)
		return 1;
	int n, i;
	//number between 1 to 9
	for (i = 1; i <= 9; i++)
	{
		//if we can assign i to the cell or not
		//the cell is matrix[row][col]
		if (is_safe(i, row, col, y))
		{
			y[row][col] = i;
			//backtracking
			if (solve_sudoku(y))
				return 1;
			//if we can't proceed with this solution
			//reassign the cell
			y[row][col] = 0;
		}
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
void print_sudoku(int sudoku[9][9])
{
	system("cls");
	int i, j;
	printf("\t-------------------------\n");
	for (i = 0; i < 9; i++) {
		printf("\t");
		for (j = 0; j < 9; j++) {
			if (j == 0)
				printf("| ");
			if (sudoku[i][j] == 0)
				printf(". ");
			else
				printf("%d ", sudoku[i][j]);
			if ((j + 1) % 3 == 0)
				printf("| ");

		}

		if ((i + 1) % 3 == 0)
			printf("\n\t-------------------------");

		printf("\n");

	}

}
////////////////////////////////////////////////////////////////////////////////////////
void checker(int y[9][9], int sudoku[9][9])
{
	int i, j;
	int counter = 0;
	system("cls");
	solve_sudoku(y);

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (sudoku[i][j] != y[i][j])
			{
				counter++;
				if (counter > 0)
				{

					printf("the solution  is incorrect \n");
					break;
				}

				break;

			}
			else
			{
				printf("the solution is correct \n");
				break;
			}

		}
		break;

	}

}
////////////////////////////////////////////////////////////////////////////////////////



void cleared_sudoku(int a[9][9])
{
	system("cls");
	int i, j;

	print_sudoku(a);



}
////////////////////////////////////////////////////////////////////////////////////////
void R_N_G(int r[9][9],int e[9][9])
{

	int i, j;
	int l, m, n;
	int k;
	int rng_counter = 0;
	int counter_box = 0;

	
	int a[9][9] = { 0,0,0,	0,0,0,	0,0,0,
				    0,0,0,	0,0,0,	0,0,0,
				    0,0,0,	0,0,0,	0,0,0,

				    0,0,0,	0,0,0,	0,0,0,
			    	0,0,0,	0,0,0,	0,0,0,
			    	0,0,0,	0,0,0,	0,0,0,

			    	0,0,0	,0,0,0	,0,0,0,
			    	0,0,0	,0,0,0	,0,0,0,
			    	0,0,0	,0,0,0	,0,0,0
	};
	


	a[0][0]=  1 + rand() % 9;
	a[1][0]= 1 + rand() % 9;
	a[0][1]= 1 + rand() % 9;
	a[2][1]= 1 + rand() % 9;
	a[2][2] = 1 + rand() % 9;
	a[0][4]= 1 + rand() % 9;
	a[1][3]= 1 + rand() % 9;
	a[1][4]= 1 + rand() % 9;
	a[1][5]= 1 + rand() % 9;
	a[2][7]= 1 + rand() % 9;

	a[3][0] = 1 + rand() % 9;
	a[4][0] = 1 + rand() % 9;
	a[5][1] = 1 + rand() % 9;
	a[3][4] = 1 + rand() % 9;
	a[5][3] = 1 + rand() % 9;
	a[5][5] = 1 + rand() % 9;
	a[6][4] = 1 + rand() % 9;
	a[3][8] = 1 + rand() % 9;
	a[4][8] = 1 + rand() % 9;
	a[5][8] = 1 + rand() % 9;

	a[6][1] = 1 + rand() % 9;
	a[7][3] = 1 + rand() % 9;
	a[7][4] = 1 + rand() % 9;
	a[7][5] = 1 + rand() % 9;
	a[8][5] = 1 + rand() % 9;
	a[6][6] = 1 + rand() % 9;
	a[6][7] = 1 + rand() % 9;
	a[7][8] = 1 + rand() % 9;
	a[7][7] = 1 + rand() % 9;
	a[8][8] = 1 + rand() % 9;

	a[1][7] = 1 + rand() % 9;
	a[0][8] = 1 + rand() % 9;
	a[5][6] = 1 + rand() % 9;
	
	
	//row checker 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			for (k = 0; k < 9; k++)
			{
				if (a[j][k] == a[j][i])
				{
					if (k != i)
					{
						red();
						a[i][j] = 0;
						reset();
					}
				}

			}
		}
	}
	//column checker 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			for (i = 0; i < 9; i++)
			{
				if (a[k][j] == a[i][j])
				{
					if (k != i)
					{
						red();
						a[i][j] = 0;
						reset();
					}

				}

			}
		}
	}





//box 1 
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 2
	for (i = 0; i < 3; i++)
	{
		for (j = 3; j < 6; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (l = 3; l < 6; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 3 
	for (i = 0; i < 3; i++)
	{
		for (j = 6; j < 9; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (l = 6; l < 9; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 4 
	for (i = 3; i < 6; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 3; k < 6; k++)
			{
				for (l = 0; l < 3; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 5 
	for (i = 3; i < 6; i++)
	{
		for (j = 3; j < 6; j++)
		{
			for (k = 3; k <6; k++)
			{
				for (l = 3; l < 6; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 6 
	for (i = 3; i < 6; i++)
	{
		for (j = 6; j < 9; j++)
		{
			for (k = 3; k < 6; k++)
			{
				for (l = 6; l < 9; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 7 
	for (i = 6; i < 9; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 6; k < 9; k++)
			{
				for (l = 0; l < 3; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 8 
	for (i = 6; i < 9; i++)
	{
		for (j = 3; j < 6; j++)
		{
			for (k = 6; k < 9; k++)
			{
				for (l = 3; l < 6; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	//box 9 
	for (i = 6; i < 9; i++)
	{
		for (j = 6; j < 9; j++)
		{
			for (k = 6; k < 9; k++)
			{
				for (l = 6; l < 9; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}
	}
	
	

	/*for (k = 0; k < 9; k++)
	{
		if (a[j][k] == a[j][i])
		{
			if (k != i)
			{
				red();
				a[i][j] = 0;
				reset();
			}
		}

	}
	for (i = 0; i < 9; i++)
	{
		if (a[k][j] == a[i][j])
		{
			if (k != i)
			{
				red();
				a[i][j] = 0;
				reset();
			}

		}

	}*/

	



	

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			r[i][j] = a[i][j];
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			e[i][j] = r[i][j];
		}
	}

	



}
////////////////////////////////////////////////////////////////////////////////////////
void generator(int r[9][9],int e[9][9])
{
	int i, j, k;
	int l, m,n;
	int counter_box = 0;


	int a[9][9] = { 0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,

				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,
				0,0,0,	0,0,0,	0,0,0,

				0,0,0	,0,0,0	,0,0,0,
				0,0,0	,0,0,0	,0,0,0,
				0,0,0	,0,0,0	,0,0,0
	};

	for (i = 0; i < 0; i++)
	{
		for (j = 0; j < 9; j++)
		{
			a[i][j] = 1 + rand() % 9;
			/*for (k = 0; k < 9; k++)
			{
				if (a[j][k] == a[j][i])
				{
					if (k != i)
					{
						red();
						a[i][j] = 0;
						reset();
					}
				}

			}
			for (i = 0; i < 9; i++)
			{
				if (a[k][j] == a[i][j])
				{
					if (k != i)
					{
						red();
						a[i][j] = 0;
						reset();
					}

				}

			}*/

			for (k =0; k < 0; k++)
			{
				for (l = 0; l < 0; l++)
				{
					if (a[k][l] == a[i][j])
					{
						if ((k != i) || (l != j))
						{

							counter_box++;
							if (counter_box > 0)
							{

								red();
								a[i][j] = 0;
								reset();
								counter_box--;
							}
						}

					}


				}

			}
		}

	}
	/*for (k = 0; k < 9; k++)
	{
		if (a[j][k] == a[j][i])
		{
			if (k != i)
			{
				red();
				a[i][j] = 0;
				reset();
			}
		}

	}
	for (i = 0; i < 9; i++)
	{
		if (a[k][j] == a[i][j])
		{
			if (k != i)
			{
				red();
				a[i][j] = 0;
				reset();
			}

		}

	}
	*/

	/*printf("\t-------------------------\n");
	for (i = 0; i < 9; i++) {
		printf("\t");
		for (j = 0; j < 9; j++) {
			if (j == 0)
				printf("| ");
			if (a[i][j] == 0)
				printf(". ");
			else
				printf("%d ", a[i][j]);
			if ((j + 1) % 3 == 0)
				printf("| ");

		}

		if ((i + 1) % 3 == 0)
			printf("\n\t-------------------------");

		printf("\n");

	}*/
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			r[i][j] = a[i][j];
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			e[i][j] = r[i][j];
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////
void step_checker(int row, int column, int x[9][9])
{
	int i, j, k;
	int counter_row = 0;
	int counter_column = 0;
	int counter_box = 0;
	//row checker
	for (i = 0; i < 9; i++)
	{
		if (x[row][column] == x[row][i])
		{
			if (column != i)
			{
				red();
				printf("illegal move \n");
				reset();
			}


		}




	}

	//column checker
	for (i = 0; i < 9; i++)
	{
		if (x[row][column] == x[i][column])
		{
			if (row != i)
			{
				red();
				printf("illegal move \n");
				reset();
			}

		}

	}

	//box 1  checker 
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}
	//box 2 checker
	for (i = 0; i < 3; i++)
	{
		for (j = 3; j < 6; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}
	//box 3 checker
	for (i = 0; i < 3; i++)
	{
		for (j = 6; j < 9; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}
	//box 4 checker
	for (i = 3; i < 6; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}

	//box 5 checker
	for (i = 3; i < 6; i++)
	{
		for (j = 3; j < 6; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}
	//box 6 checker
	for (i = 3; i <= 5; i++)
	{
		for (j = 6; j <= 8; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}
	//box 7 checker
	for (i = 6; i < 9; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}
	//box 8 checker
	for (i = 6; i < 9; i++)
	{
		for (j = 3; j < 6; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}

			}


		}

	}
	//box 9 checker
	for (i = 6; i <= 9; i++)
	{
		for (j = 6; j <= 9; j++)
		{
			if (x[row][column] == x[i][j])
			{
				if ((row != i) && (column != j))
				{
					red();
					printf("illegal move \n");
					reset();
				}


			}


		}

	}
}
///////////////////////////////////////////////////////////////////////////////////////////

