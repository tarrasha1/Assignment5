# 지뢰찾기 게임입니다.
----


## 실행방법
1. visual studio가 필요합니다.(vscode는 과정이 좀 복잡) [설치방법](https://kimvampa.tistory.com/96)
2. 솔루션 설정, 디버깅 및 실행 [설정방법](https://dasima.xyz/c%EC%96%B8%EC%96%B4-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EB%A7%8C%EB%93%A4%EA%B8%B0-%EC%86%8C%EC%8A%A4-%ED%8C%8C%EC%9D%BC-%EC%83%9D%EC%84%B1/)
3. 소스코드 복사 후 자신의 소스파일에서 새항목을 생성 후 붙여넣기해서 실행하거나 파일을 다운받은 후 소스파일에 기존 항목 추가로 실행

## 실행화면
<img src="https://github.com/tarrasha1/Assignment5/assets/131227777/add7c355-b539-4cc7-bc45-d2031a9d0281" width="700" height="350">

<img src="https://github.com/tarrasha1/Assignment5/assets/131227777/5e159729-b0f9-4ef9-bbc1-0fb4abf202cd" width="700" height="350">

<img src="https://github.com/tarrasha1/Assignment5/assets/131227777/144014c7-1a56-4ee0-86c7-1be702ff6e49" width="700" height="350">

<img src="https://github.com/tarrasha1/Assignment5/assets/131227777/b5c55313-3436-4cac-8329-3c8959bc5d86" width="700" height="350">

<img src="https://github.com/tarrasha1/Assignment5/assets/131227777/d7bf74d6-f609-46d8-9d01-261a60bbd2ff" width="700" height="350">

## 코드

맵을 그려주는 함수입니다. 지뢰찾기 맵을 그리는 함수로 2차원 배열 a를 인자로 받아서 맵을 출력합니다(30*30크기의 맵입니다).
```
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
```
게임 시작 전에 인트로 화면을 출력하는 함수입니다. 아무 키나 누르기 전까지 게임 화면으로 넘어가지 않습니다.
```
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
```
main함수에서 두 함수를 호출하여 각각 화면에 시작화면을 출력하고 맵을 그립니다.

main함수에서 생성할 지뢰 개수를 입력받습니다. 만약 그 개수가 맵의 크기를 벗어나거나 0이하의 값이라면
다시 입력 받습니다.
```
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
  ```
x, y값을 입력 받아서 그 위치에 지뢰가 없는지 판별합니다. 만약 그 값이 범위를 벗어난다면 다시 입력 받습니다.
  
		if (x >= 30 || y >= 30 || x < 0 || y < 0) //범위를 벗어나는 x, y값을 입력했을 경우
		{
			printf("범위를 벗어났습니다\n");
			printf("다시 입력해주세요\n");

			Sleep(1000);
		}

x, y값에 해당하는 위치에 지뢰가 있다면 게임을 종료하고 없으면 x, y값을 입력받고 게임을 계속합니다


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








