#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void draw(int a[30][30])      //맵 그리기
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (a[i][j] == 0)	//아직 확인 안된 블록
				printf("■");
			else if (a[i][j] == 1)		//지뢰인 블록
				printf("※");
			else if (a[i][j] == 2)		//지뢰가 아닌 블록
				printf("●");
		}
		printf("\n");
	}
}

void showIntro() //게임 시작전 인트로 화면
{
	printf("***************************************\n");
	printf("      지뢰찾기 게임에 오신걸 환영합니다\n");
	printf("***************************************\n");
	printf("게임 설명: 30x30 크기의 지뢰찾기 게임입니다.\n");
	printf("지뢰를 피하고 모든 안전한 칸을 찾으세요!\n");
	printf("아무 키나 누르면 게임이 시작됩니다\n");

	_getch();
	system("cls"); // 화면 지우기
}

int main()
{
	int map[30][30];
	int hide[30][30];
	srand((unsigned)time(NULL));
	int a, b, x, y, mine;

	for (int i = 0; i < 30; i++)	//0으로 배열값 초기화
	{
		for (int j = 0; j < 30; j++)
		{
			map[i][j] = 0;
			hide[i][j] = 0;
		}
	}
	showIntro();		//인트로 화면 보여주기
	while (1)
	{
		printf("생성할 지뢰 개수를 입력해주세요 (30x30): ");
		scanf_s("%d", &mine);

		if (mine <= 0 || mine >= 900)
		{
			system("cls");
			printf("맵 크기보다 작은 수를 입력해주세요.\n");
			Sleep(1000);
			system("cls");
		}
		else
		{
			break;
		}
	}
	system("cls");

	for (int i = 0; i < mine; i++)	//지뢰생성
	{
		while (1)
		{
			a = rand() % 30;
			b = rand() % 30;
			if (map[a][b] == 1)
				continue; //이미 지뢰가 있는 경우 다시 생성

			map[a][b] = 1;
			break;
		}
	}
	while (1)
	{
		draw(hide);
		printf("x좌표입력: ");
		scanf_s("%d", &y);
		printf("y좌표입력: ");
		scanf_s("%d", &x);

		x--;
		y--;

		if (x >= 30 || y >= 30 || x < 0 || y < 0) //범위를 벗어나는 x, y값을 입력했을 경우
		{
			printf("범위를 벗어났습니다\n");
			printf("다시 입력해주세요\n");

			Sleep(1000);
		}
		else if (map[x][y] == 1)
		{
			hide[x][y] = 1;
			system("cls");
			draw(hide);
			printf("앗...꽝입니다\n");
			printf("아무키나 누르세요\n");

			_getch(); // 아무 키나 누를 때까지 대기

			break;
		}
		else if (hide[x][y] == 2)
		{
			printf("이미 확인한 블록입니다\n");
		}
		else if (map[x][y] == 0)
		{
			printf("휴~ 지뢰가 아닙니다\n");
			hide[x][y] = 2;
		}

		Sleep(1000);
		system("cls");
	}

	system("cls");
	printf("\n");
	printf("지뢰위치\n");
	draw(map);	//게임이 끝난후 맵에서 전체 지뢰위치 보여줌
}