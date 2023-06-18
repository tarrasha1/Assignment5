#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void draw(int a[30][30])      //�� �׸���
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (a[i][j] == 0)	//���� Ȯ�� �ȵ� ���
				printf("��");
			else if (a[i][j] == 1)		//������ ���
				printf("��");
			else if (a[i][j] == 2)		//���ڰ� �ƴ� ���
				printf("��");
		}
		printf("\n");
	}
}

void showIntro() //���� ������ ��Ʈ�� ȭ��
{
	printf("***************************************\n");
	printf("      ����ã�� ���ӿ� ���Ű� ȯ���մϴ�\n");
	printf("***************************************\n");
	printf("���� ����: 30x30 ũ���� ����ã�� �����Դϴ�.\n");
	printf("���ڸ� ���ϰ� ��� ������ ĭ�� ã������!\n");
	printf("�ƹ� Ű�� ������ ������ ���۵˴ϴ�\n");

	_getch();
	system("cls"); // ȭ�� �����
}

int main()
{
	int map[30][30];
	int hide[30][30];
	srand((unsigned)time(NULL));
	int a, b, x, y, mine;

	for (int i = 0; i < 30; i++)	//0���� �迭�� �ʱ�ȭ
	{
		for (int j = 0; j < 30; j++)
		{
			map[i][j] = 0;
			hide[i][j] = 0;
		}
	}
	showIntro();		//��Ʈ�� ȭ�� �����ֱ�
	printf("������ ���ڰ����� �Է����ּ���(30x30)\n");
	scanf_s("%d", &mine);

	for (int i = 0; i < mine; i++)	//���ڻ���
	{
		while (1)
		{
			a = rand() % 30;
			b = rand() % 30;
			if (map[a][b] == 1)
				continue; //�̹� ���ڰ� �ִ� ��� �ٽ� ����

			map[a][b] = 1;
			break;
		}
	}
	while (1)
	{
		draw(hide);
		printf("x��ǥ�Է�: ");
		scanf_s("%d", &y);
		printf("y��ǥ�Է�: ");
		scanf_s("%d", &x);

		x--;
		y--;

		if (x >= 30 || y >= 30 || x < 0 || y < 0) //������ ����� x, y���� �Է����� ���
		{
			printf("������ ������ϴ�\n");
			printf("�ٽ� �Է����ּ���\n");

			Sleep(1000);
		}
		else if (map[x][y] == 1)
		{
			hide[x][y] = 1;
			system("cls");
			draw(hide);
			printf("��...���Դϴ�\n");
			Sleep(2000);
			break;
		}
		else if (hide[x][y] == 2)
		{
			printf("�̹� Ȯ���� ����Դϴ�\n");
		}
		else if (map[x][y] == 0)
		{
			printf("��~ ���ڰ� �ƴմϴ�\n");
			hide[x][y] = 2;
		}

		Sleep(1000);
		system("cls");
	}

	printf("������ġ\n");
	draw(map);	//������ ������ �ʿ��� ��ü ������ġ ������
}