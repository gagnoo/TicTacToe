#include "TicTacToe.h"

int main(void)
{
	int WonOrDraw = 0;
	int StartGame;
	int res;
	int MoveRes;

	Player = PlayerX;

	printf("Do you want to start game? (Y/n): ");
	StartGame = _getch();
	if (StartGame == 'N' || StartGame == 'n')
	{
		printf("\nExiting...\n");
		(void)getchar();
		return 0;
	}
	else if (StartGame == 'Y' || StartGame == 'y')
	{
		fprintf(stdout, "\nIf You want to exit press 'q' or 'Q'\n");
		Sleep(3000);
		while (1)
		{
			system("cls");
			ShowBoard();

			printf("Its %c player turn.\n", toupper(Player));
			do {
				printf("\nEnter your choice: ");
				choice = _getch();
				res = Input(choice);
				MoveRes = CheckMove(choice);
				if (MoveRes == 0 && res == 0)   
					break;
			} while (res == -1 || MoveRes == -1);

			//CheckMove(choice);
			WonOrDraw = CheckWin();
			if (WonOrDraw == 0) {
				printf("\nPlayer %c won.\n", toupper(Player));
				break;
			}
			else if (WonOrDraw == 1) {
				printf("\nIt is draw\n");
				break;
			}
			ChangePlayer();
		}
	}
	else
	{
		fprintf(stderr, "\nPlease, Choose Y or N...\n");
		Sleep(100);
		main();
	}
	system("pause");
	return 0;
}

int CheckWin()
{
	if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2])
		return 0;
	else if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0])
		return 0;
	else if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1])
		return 0;
	else if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2])
		return 0;
	else if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		return 0;
	else if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return 0;
	else if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2])
		return 0;
	else if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2])
		return 0;

	return -1;
}

char Input(char value)
{
	if (!(value >= '1' && value <= '9'))
	{
		if (value == 'q' || value == 'Q')
		{
			fprintf(stderr, "\nExiting...\n");
			Sleep(2000);
			exit(EXIT_SUCCESS);
		}
		printf("\n-------------------------------------------------------------------------\n");
		fprintf(stderr, "\nInvalid argument <%c>!\tEnter Number Between 1 to 9.\n", value);
		printf("\n-------------------------------------------------------------------------\n");
		return -1;
	}
	return 0;
}

void ChangePlayer()
{
	if (Player == PlayerX)
		Player = PlayerO;
	else
		Player = PlayerX;
}

int CheckMove(char choice)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == choice && matrix[i][j] != PlayerX && matrix[i][j] != PlayerO)
			{
				matrix[i][j] = toupper(Player);
				return 0;
			}
		}
	}
	return -1;
}

void ShowBoard()
{
	printf("------------------\n");
	printf("  %c  |  %c  |  %c  \n", matrix[0][0], matrix[0][1], matrix[0][2]);
	printf("------------------\n");
	printf("  %c  |  %c  |  %c  \n", matrix[1][0], matrix[1][1], matrix[1][2]);
	printf("------------------\n");
	printf("  %c  |  %c  |  %c  \n", matrix[2][0], matrix[2][1], matrix[2][2]);
	printf("------------------\n");
}
