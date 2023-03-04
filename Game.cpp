#include "Game.h"

Game::Game()
{
	p.InitPlane();				//初始化所有变量
	b.InitBullet();
	e.InitEnemy();
	score = 0;
	rank = 25;
	rankf = 0;
	flag_rank = 0;
}

void Game::Pause()
{
	SetPos(61, 2);							//在右上方显示提示信息
	cout << "               ";
	SetPos(61, 2);
	cout << "暂停中...";
	char c = _getch();
	while (c != 'p')						//等待解除暂停
		c = _getch();
	SetPos(61, 2);
	cout << "         ";
}

void Game::JudgePlane()
{
	for (int i = 0; i < MAXENEMYNUM; i++)						//遍历敌机数组
	{
		for (int j = 0; j < 10; j++)
		{
			if (JudgeCoordInFrame(e.no[i], p.position[j]))		//如果飞机与某一敌机重合
			{
				SetPos(62, 1);
				cout << "坠毁";									//显示提示信息
				DrawFrame(e.no[i], '+', '+');					//摧毁敌机
				Sleep(1000);
				GameOver();										//游戏结束
				break;
			}
		}
	}
}

void Game::JudgeEnemy()
{
	for (int i = 0; i < MAXENEMYNUM; i++)								//遍历敌机
		for (int j = 0; j < MAXBULLETNUM; j++)							//遍历子弹
			if (JudgeCoordInFrame(e.no[i], b.position[j]))				//若子弹进入敌机
			{
				score += 5;												//增加得分
				e.DrawThisEnemyToNull(e.no[i]);							//消除飞机
				COORD m = { 1, 1 };
				COORD n = { 45, 3 };
				e.no[i].position[0] = Random(m, n);						//重新生成敌机
				e.no[i].position[1].X = e.no[i].position[0].X + 3;
				e.no[i].position[1].Y = e.no[i].position[0].Y + 2;
				b.DrawThisBulletToNull(b.position[j]);					//消除子弹
				b.valid[j] = false;										//将子弹置为无效
			}
}

void Game::PrintScore()
{
	if (score >= 120 && flag_rank == 0)									//刚达到某一分数时
	{
		rank -= 3;														//改变等级
		flag_rank = 1;													//标志位置为1
	}

	else if (score >= 360 && flag_rank == 1)
	{
		rank -= 5;
		flag_rank = 2;
	}
	else if (score >= 480 && flag_rank == 2)
	{
		rank -= 5;
		flag_rank = 3;
	}
	int x = rank / 5;
	SetPos(60, 6);
	cout << score;													//显示分数

	if (rank != rankf)												//当改变称号时，显示新的称号
	{
		SetPos(60, 7);
		if (x == 5)
			title = "初入门第";
		else if (x == 4)
			title = "小试牛刀";
		else if (x == 3)
			title = "登堂入室";
		else if (x == 2)
			title = "师出有名";
		cout << title;
	}
	rankf = rank;
}

void Game::Playing()
{
	//HANDLE MFUN;  
	//MFUN= CreateThread(NULL, 0, MusicFun, NULL, 0, NULL);   

	e.DrawEnemy();
	p.DrawPlane();

	int flag_bullet = 0;								//改变子弹速度
	int flag_enemy = 0;									//改变敌机速度

	while (1)
	{
		Sleep(8);
		if (_kbhit())									//处理按键
		{
			char x = _getch();
			if ('a' == x || 's' == x || 'd' == x || 'w' == x)//移动
			{
				p.DrawPlaneToNull();
				p.PlaneMove(x);
				p.DrawPlane();
				JudgePlane();
			}
			else if ('p' == x)							//暂停
				Pause();
			else if ('j' == x)							//射击
				p.Shoot(b);
			else if ('e' == x)
			{
				//CloseHandle(MFUN);  
				GameOver();
				break;
			}

		}
		if (0 == flag_bullet)							//每隔5帧处理子弹
		{
			b.BulletMove();
			b.DrawBulletToNull();
			b.DrawBullet();
			JudgeEnemy();
		}
		flag_bullet++;
		if (5 == flag_bullet)
			flag_bullet = 0;

		if (0 == flag_enemy)							//根据等级不同处理敌机间隔速度也不同
		{
			e.DrawEnemyToNull();
			e.EnemyMove();
			e.DrawEnemy();
			JudgePlane();
		}
		flag_enemy++;
		if (flag_enemy >= rank)
			flag_enemy = 0;

		PrintScore();									//输出得分
	}
}

void Game::GameOver()
{
	system("cls");										//显示结束动画
	COORD p1 = { 28,9 };
	COORD p2 = { 53,15 };
	DrawFrame(p1, p2, '=', '|');
	SetPos(36, 12);
	string str = "Game Over!";
	for (int i = 0; i<str.size(); i++)
	{
		Sleep(80);
		cout << str[i];
	}
	Sleep(1000);
	system("cls");
	DrawFrame(p1, p2, '=', '|');
	SetPos(31, 11);
	cout << "击落敌机：" << score / 5 << " 架";
	SetPos(31, 12);
	cout << "得　　分：" << score;
	SetPos(31, 13);
	cout << "获得称号：" << title;
	SetPos(30, 16);
	Sleep(1000);
	cout << "继续？ 是（y）| 否（n）";
	char x;
	do
	{
		x = _getch();
		if (x == 'n')						//如果不继续，则退出线程
			exit(0);
		else if (x == 'y')					//如果继续，就重新开始
		{
			system("cls");
			Game game;
			int a = DrawMenu();
			if (a == 2)
				game.rank = 20;
			system("cls");
			DrawPlaying();
			game.Playing();
		}
	} while (x != 'y');
}

void Game::DrawPlaying()
{
	DrawFrame(0, 0, 48, 24, '=', '|');
	DrawFrame(49, 0, 79, 4, '-', '|');
	DrawFrame(49, 4, 79, 9, '-', '|');
	DrawFrame(49, 9, 79, 20, '-', '|');
	DrawFrame(49, 20, 79, 24, '-', '|');
	SetPos(52, 6);
	cout << "得分：";
	SetPos(52, 7);
	cout << "称号：";
	SetPos(52, 10);
	cout << "操作方式：";
	SetPos(52, 12);
	cout << "  a,s,d,w 控制战机移动。";
	SetPos(52, 14);
	cout << "  j 射击。";
	SetPos(52, 16);
	cout << "  p 暂停游戏。";
	SetPos(52, 18);
	cout << "  e 退出游戏。";
}

int Game::DrawMenu()
{
	SetPos(30, 1);
	cout << "P l a n e  W a r";
	DrawRow(3, 0, 79, '-');
	DrawRow(5, 0, 79, '-');
	SetPos(28, 4);
	cout << "w 和 s 选择， j 确定";
	SetPos(15, 11);
	cout << "1. 简单的敌人";
	SetPos(15, 13);
	cout << "2. 冷酷的敌人";
	DrawRow(20, 0, 79, '-');
	DrawRow(22, 0, 79, '-');
	SetPos(47, 11);
	cout << "简单的敌人：";
	SetPos(51, 13);
	cout << "简单敌人有着较慢的移动速度。";
	int j = 11;
	SetPos(12, j);
	cout << ">>";

	while (1)
	{
		if (_kbhit())
		{
			char x = _getch();
			switch (x)
			{
			case 'w':
			{
				if (j == 13)
				{
					SetPos(12, j);
					cout << "　";
					j = 11;
					SetPos(12, j);
					cout << ">>";
					SetPos(51, 13);
					cout << "　　　　　　　　　　　　";
					SetPos(47, 11);
					cout << "简单的敌人：";
					SetPos(47, 13);
					cout << "                                     ";
					SetPos(47, 13);
					cout << "简单敌人有着较慢的移动速度，比较容易对付";
				}
				break;
			}
			case 's':
			{
				if (j == 11)
				{
					SetPos(12, j);
					cout << "　";
					j = 13;
					SetPos(12, j);
					cout << ">>";
					SetPos(51, 13);
					cout << "　　　　　　　　　　　　　　";
					SetPos(47, 11);
					cout << "冷酷的敌人：";
					SetPos(47, 13);
					cout << "                                           ";
					SetPos(47, 13);
					cout << "冷酷的敌人移动速度较快，难对付哟。";
				}
				break;
			}
			case 'j':
			{
				if (j == 8) return 1;
				else return 2;
			}
			}
		}
	}
}

