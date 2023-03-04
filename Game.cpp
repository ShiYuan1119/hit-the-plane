#include "Game.h"

Game::Game()
{
	p.InitPlane();				//��ʼ�����б���
	b.InitBullet();
	e.InitEnemy();
	score = 0;
	rank = 25;
	rankf = 0;
	flag_rank = 0;
}

void Game::Pause()
{
	SetPos(61, 2);							//�����Ϸ���ʾ��ʾ��Ϣ
	cout << "               ";
	SetPos(61, 2);
	cout << "��ͣ��...";
	char c = _getch();
	while (c != 'p')						//�ȴ������ͣ
		c = _getch();
	SetPos(61, 2);
	cout << "         ";
}

void Game::JudgePlane()
{
	for (int i = 0; i < MAXENEMYNUM; i++)						//�����л�����
	{
		for (int j = 0; j < 10; j++)
		{
			if (JudgeCoordInFrame(e.no[i], p.position[j]))		//����ɻ���ĳһ�л��غ�
			{
				SetPos(62, 1);
				cout << "׹��";									//��ʾ��ʾ��Ϣ
				DrawFrame(e.no[i], '+', '+');					//�ݻٵл�
				Sleep(1000);
				GameOver();										//��Ϸ����
				break;
			}
		}
	}
}

void Game::JudgeEnemy()
{
	for (int i = 0; i < MAXENEMYNUM; i++)								//�����л�
		for (int j = 0; j < MAXBULLETNUM; j++)							//�����ӵ�
			if (JudgeCoordInFrame(e.no[i], b.position[j]))				//���ӵ�����л�
			{
				score += 5;												//���ӵ÷�
				e.DrawThisEnemyToNull(e.no[i]);							//�����ɻ�
				COORD m = { 1, 1 };
				COORD n = { 45, 3 };
				e.no[i].position[0] = Random(m, n);						//�������ɵл�
				e.no[i].position[1].X = e.no[i].position[0].X + 3;
				e.no[i].position[1].Y = e.no[i].position[0].Y + 2;
				b.DrawThisBulletToNull(b.position[j]);					//�����ӵ�
				b.valid[j] = false;										//���ӵ���Ϊ��Ч
			}
}

void Game::PrintScore()
{
	if (score >= 120 && flag_rank == 0)									//�մﵽĳһ����ʱ
	{
		rank -= 3;														//�ı�ȼ�
		flag_rank = 1;													//��־λ��Ϊ1
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
	cout << score;													//��ʾ����

	if (rank != rankf)												//���ı�ƺ�ʱ����ʾ�µĳƺ�
	{
		SetPos(60, 7);
		if (x == 5)
			title = "�����ŵ�";
		else if (x == 4)
			title = "С��ţ��";
		else if (x == 3)
			title = "��������";
		else if (x == 2)
			title = "ʦ������";
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

	int flag_bullet = 0;								//�ı��ӵ��ٶ�
	int flag_enemy = 0;									//�ı�л��ٶ�

	while (1)
	{
		Sleep(8);
		if (_kbhit())									//������
		{
			char x = _getch();
			if ('a' == x || 's' == x || 'd' == x || 'w' == x)//�ƶ�
			{
				p.DrawPlaneToNull();
				p.PlaneMove(x);
				p.DrawPlane();
				JudgePlane();
			}
			else if ('p' == x)							//��ͣ
				Pause();
			else if ('j' == x)							//���
				p.Shoot(b);
			else if ('e' == x)
			{
				//CloseHandle(MFUN);  
				GameOver();
				break;
			}

		}
		if (0 == flag_bullet)							//ÿ��5֡�����ӵ�
		{
			b.BulletMove();
			b.DrawBulletToNull();
			b.DrawBullet();
			JudgeEnemy();
		}
		flag_bullet++;
		if (5 == flag_bullet)
			flag_bullet = 0;

		if (0 == flag_enemy)							//���ݵȼ���ͬ����л�����ٶ�Ҳ��ͬ
		{
			e.DrawEnemyToNull();
			e.EnemyMove();
			e.DrawEnemy();
			JudgePlane();
		}
		flag_enemy++;
		if (flag_enemy >= rank)
			flag_enemy = 0;

		PrintScore();									//����÷�
	}
}

void Game::GameOver()
{
	system("cls");										//��ʾ��������
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
	cout << "����л���" << score / 5 << " ��";
	SetPos(31, 12);
	cout << "�á����֣�" << score;
	SetPos(31, 13);
	cout << "��óƺţ�" << title;
	SetPos(30, 16);
	Sleep(1000);
	cout << "������ �ǣ�y��| ��n��";
	char x;
	do
	{
		x = _getch();
		if (x == 'n')						//��������������˳��߳�
			exit(0);
		else if (x == 'y')					//��������������¿�ʼ
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
	cout << "�÷֣�";
	SetPos(52, 7);
	cout << "�ƺţ�";
	SetPos(52, 10);
	cout << "������ʽ��";
	SetPos(52, 12);
	cout << "  a,s,d,w ����ս���ƶ���";
	SetPos(52, 14);
	cout << "  j �����";
	SetPos(52, 16);
	cout << "  p ��ͣ��Ϸ��";
	SetPos(52, 18);
	cout << "  e �˳���Ϸ��";
}

int Game::DrawMenu()
{
	SetPos(30, 1);
	cout << "P l a n e  W a r";
	DrawRow(3, 0, 79, '-');
	DrawRow(5, 0, 79, '-');
	SetPos(28, 4);
	cout << "w �� s ѡ�� j ȷ��";
	SetPos(15, 11);
	cout << "1. �򵥵ĵ���";
	SetPos(15, 13);
	cout << "2. ���ĵ���";
	DrawRow(20, 0, 79, '-');
	DrawRow(22, 0, 79, '-');
	SetPos(47, 11);
	cout << "�򵥵ĵ��ˣ�";
	SetPos(51, 13);
	cout << "�򵥵������Ž������ƶ��ٶȡ�";
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
					cout << "��";
					j = 11;
					SetPos(12, j);
					cout << ">>";
					SetPos(51, 13);
					cout << "������������������������";
					SetPos(47, 11);
					cout << "�򵥵ĵ��ˣ�";
					SetPos(47, 13);
					cout << "                                     ";
					SetPos(47, 13);
					cout << "�򵥵������Ž������ƶ��ٶȣ��Ƚ����׶Ը�";
				}
				break;
			}
			case 's':
			{
				if (j == 11)
				{
					SetPos(12, j);
					cout << "��";
					j = 13;
					SetPos(12, j);
					cout << ">>";
					SetPos(51, 13);
					cout << "����������������������������";
					SetPos(47, 11);
					cout << "���ĵ��ˣ�";
					SetPos(47, 13);
					cout << "                                           ";
					SetPos(47, 13);
					cout << "���ĵ����ƶ��ٶȽϿ죬�ѶԸ�Ӵ��";
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

