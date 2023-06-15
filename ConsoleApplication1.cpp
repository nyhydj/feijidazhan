#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void cursor(int x, int y);
struct Plane {
	int x=65;
	int y=44;
}plane;//飞机坐标
struct Player
{
	int score = 0;
	char name[10];
}player;
int bullet[100];
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 }; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void mainmenu();
void startmenu();
void start();
void endmenu();
void help();
void leaderboard();
void line();
void printplane();
void reprintplane();
int main()
{
	HideCursor();
	Sleep(2000);
	mainmenu ();
	while(true)
	{
		start();
		Sleep(30);
	}
	
	return 0;
}
void cursor(int x, int y)//定位控制台坐标
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void line()//边框
{

	cursor(0, 0);
	for (int i = 0; i < 130; i++)
	{
		printf("*");
	}
	cursor(0, 45);
	for (int i = 0; i < 130; i++)
	{
		printf("*");
	}
}
void leaderboard()//排行榜
{
	system("cls");
	cursor(25, 20);
	printf("排行榜");
	int key = getch();
	if (key == 13)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		leaderboard();
	}
}
void help()
{
	system("cls");
	line();
	cursor(50, 20);
	printf("向 左   A");
	cursor(50, 21);
	printf("向 右   B");
	cursor(50, 22);
	printf("发射子弹  space");
	cursor(50, 23);
	printf("返回菜单  enter");
	int key = getch();
	if (key == 13)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		help();
	}

}
void endmenu()
{
	system("cls");
	cursor(60, 20);
	printf("感谢游玩");
	exit(0);

}
void mainmenu()//主菜单
{
	system("cls");
	line();
	cursor(61, 15);
	printf("飞  机  大  战");
	cursor(60, 20);
	printf("****************");
	cursor(60, 21);
	printf("* 1开 始 游 戏 *");
	cursor(60, 22);
	printf("* 2积 分 排 行 *");
	cursor(60, 23);
	printf("* 3游 戏 帮 助 *");
	cursor(60, 24);
	printf("* 4退 出 游 戏 *");
	cursor(60, 25);
	printf("****************\n");
	cursor(0, 45);
	int key = getch();
	switch (key)
	{
	case '1':startmenu(); break;
	case '2':leaderboard(); break;
	case '3':help(); break;
	case '4':endmenu(); break;
	}
	if (key < 49 || key>52)
	{
		mainmenu();
	}
}
void startmenu()//开始菜单
{
	system("cls");
	cursor(25, 20);
	printf("输入你的名字：");
	scanf("%s", &player.name);
	system("cls");
	line();
	cursor(140, 20);
	printf("名字：%s", player.name);
	cursor(140, 23);
	printf("得分:%d", player.score);
}
void start()//开始游戏
{
	reprintplane();
}
void printplane()//打印飞机
{
	cursor(plane.x, plane.y);
	printf("-***-");
}
void cleanplane()//清除己方飞机
{
	cursor(plane.x, plane.y);
	printf("     ");
}
void reprintplane()//重绘飞机
{
	
	int key = getch();
	if ((key == 65)&&(plane.x>2) )
	{
		cleanplane();
		plane.x-=2 ;
		printplane();
	}
	if ((key == 68)&&(plane.x<125))
	{
		cleanplane();
		plane.x += 2;
		printplane();
	}
	if ((key ==87)&&(plane.y>1))
	{
		cleanplane();
		plane.y-= 2;
		printplane();
	}
	if ((key == 83) && (plane.y < 43))
	{
		cleanplane();
		plane.y += 2;
		printplane();
	}
	else
	{
		printplane();
	}
}
void reprintbullet()
{

	
	

}
void printbullet()
{
	int key=getch();
	if (key==19)
	{
		cursor(plane.x + 2, plane.y + 1);
		printf("ww");
	}
}