#include "sudoku_code.h"
#include "intitials.h"

///////////////////////////////////////////////////////////////////////////////////////////
void main()
{


	do
	{
		for (i = 0; i < 67; i++)
		{
			blue();
			printf("-");
			reset();
		}

		printf("\n");
		green();
		printf(" | please choose one of the following choices                     | \n");
		printf(" | press (1) to enter your puzzle                                 |\n");
		printf(" | press (2) to play the entered puzzle                           | \n ");
		printf("| press (3) to solve the entered puzzle                          |\n");
		printf(" | press (4) to print the  puzzle                                 |\n");
		printf(" | press (5) to check  the entered puzzle                         |\n");
		printf(" | press (6) to clear the sudoku and return it to the intial state| \n");
		printf(" | press (7) then press (1) to quit the game                      |\n");
		printf(" | press (8) to generate a random sudoku                          |\n");
		printf(" | press (9) to play the generated sudoku                         |\n");
		printf(" |press (10) to  solve the randomized(after play) sudoku          |\n");
		printf(" | press(11) to  solve the randomized sudoku(no play)             |\n");
		reset();
		for (i = 0; i < 67; i++)
		{
			blue();
			printf("-");
			reset();
		}
		printf("\n");

		scanf("%d", &menu_choice);


		if (menu_choice >12 || menu_choice <0 )
		{
			red();
			printf("you have entered an illegal character instead of an integer \n");
			printf("please re-open the program and try again \n");
			reset();
			break;
		}
		if (menu_choice == char{})
		{
			{
				red();
				printf("you have entered an illegal character instead of an integer \n");
				printf("please re-open the program and try again \n");
				reset();
				break;
			}
		}




		switch (menu_choice)
		{
		case 1:
		{
			system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			cyan();
			printf("you have chosen to enter your puzzle                              |\n");
			reset();
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			init(x, sudoku, a, c);

		}
		break;
		case 2:
		{
			system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			cyan();
			printf("you have chosen to play  your puzzle                   |\n");
			reset();
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			play(x, sudoku, y, c);

		}
		break;
		case 3:
		{
			//system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			cyan();
			printf("you have chosen to let the program solve the puzzle  | \n");
			printf("sorry your puzzle seems to be unsolvable             | \n");
			printf("please reopen the program                            |\n");
			
			reset();
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			solve_sudoku(sudoku);
			print_sudoku(sudoku);
			printf("your puzzles solution                                 | \n");

		}
		break;
		case 4:
		{
			system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			printf("you have chosen to print your puzzle               | \n");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			red();
			print_sudoku(sudoku);
			reset();

		}
		break;
		case 5:
		{
			system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			cyan();
			printf("you have chosen to check  your puzzle             |\n");
			reset();
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			checker(y, sudoku);

		}
		break;
		case 6:
		{
			system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			cyan();
			printf("you have chosen to clear  your puzzle             |\n");
			reset();
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			cleared_sudoku(a);


		}
		break;
		case 7:
		{
			system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
			green();
			printf("thank you for using this program \n");
			reset();
			menu_choice = 1;
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");

		}
		break;
		case 8:
		{
			printf("\nyour RNGed sudoku = >>>      \n");
			R_N_G(r,e);
			solve_sudoku(r);
			//SolveSudoku(r);
			
			while (solve_sudoku(r)==0 )
			{

				R_N_G(r, e);
				solve_sudoku(r);
				

				
			
			}
			print_sudoku(e);
			
			


		}
		break;
		case 9:
		{
			system("cls");
			printf("you have chosen to play the randomized sudoku \n");

			R_N_G(r,e);
			magneta();
			play(r, e, y, o);

			reset();


		}
		break;
		case 10:
		{
			system("cls");
			yellow();
			printf("the solved generated sudoku after playing  \n");
			reset();
			solve_sudoku(q);
			green();
			print_sudoku(q);
			reset();

		}
		break;
		case 11:
		{
			system("cls");
			yellow();
			printf("the solved generated sudoku   \n");
			reset();
			solve_sudoku(r);
			green();
			print_sudoku(r);
			reset();
		}
		break;

		default:
		{
			system("cls");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");

			printf("please choose one of the refered choices         |\n");
			for (i = 0; i < 67; i++)
			{
				printf("-");
			}
			printf("\n");
		}
		}
		for (i = 0; i < 67; i++)
		{
			printf("-");
		}
		printf("\n");
		printf("do you want to do another function\n\n \n");
		for (i = 0; i < 67; i++)
		{
			printf("-");
		}
		printf("\n");
		printf("please choose either (0) to continue or (1) to close the program \n");
		for (i = 0; i < 67; i++)
		{
			printf("-");
		}
		printf("\n");
		scanf("%d", &menu_choice);
		if (menu_choice > 10 || menu_choice < 0)
		{
			red();
			printf("you have entered a character instead of an integer \n");
			printf("please re-open the program and try again \n");
			reset();
			break;
		}

	} while (menu_choice != 1);




}