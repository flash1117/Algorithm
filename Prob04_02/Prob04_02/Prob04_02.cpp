#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10
#define square(x,y) 3*(x/3)+(y/3)

int sudoku[SIZE][SIZE], size = 9;
bool row_check[SIZE][SIZE]; // 행에 숫자(1~9)가 존재하는지 여부 확인
bool col_check[SIZE][SIZE]; // 열에 숫자(1~9)가 존재하는지 여부 확인
bool square_check[SIZE][SIZE]; // 정사각형(3x3)에 숫자(1~9)가 존재하는지 여부 확인

void print_Sudoku()
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", sudoku[i][j]);
		
		printf("\n");
	}
}

void complete(int temp)
{
	if (temp >= 81)
	{
		print_Sudoku();
		exit(0);
	}

	int x = temp / size;
	int y = temp % size;

	if (sudoku[x][y] != 0)
		complete(temp + 1);

	// 0이 들어가있는 곳이면
	else
	{
		// 들어갈 숫자 찾기
		for (int i = 1; i <= 9; i++)
		{
			// 해당 열, 행, 정사각형 안에 i가 없으면 i를 사용한다
			if (row_check[x][i] == 0 && col_check[y][i] == 0 && square_check[square(x, y)][i] == 0)
			{
				row_check[x][i] = col_check[y][i] = square_check[square(x, y)][i] = true;
				sudoku[x][y] = i;
				complete(temp + 1);
				// 숫자 i가 아니면 백트래킹
				sudoku[x][y] = 0;
				row_check[x][i] = col_check[y][i] = square_check[square(x, y)][i] = false;
			}
		}
	}
}

int main()
{
	clock_t start, end;
	printf("please input sudoku! (len = 9)\n");
	start = clock();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d ", &sudoku[i][j]);
			if (sudoku[i][j] != 0)
			{
				// 각 열, 행, 정사각형에 입력된 숫자가 있다고 저장한다.
				row_check[i][sudoku[i][j]] = true;
				col_check[j][sudoku[i][j]] = true;
				square_check[square(i, j)][sudoku[i][j]] = true;
			}
		}
	}

	complete(0);
	end = clock();
	printf("소요된 시간 = %.3f", (double)(end - start) / 1000);
	return 0;
}
