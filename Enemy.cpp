#include "Enemy.h"

void Enemy::InitEnemy()
{
	COORD a = { 1, 1 };
	COORD b = { 45, 15 };
	for (int i = 0; i<MAXENEMYNUM; i++)						//在屏幕最上方区域生成敌机
	{
		no[i].position[0] = Random(a, b);
		no[i].position[1].X = no[i].position[0].X + 3;
		no[i].position[1].Y = no[i].position[0].Y + 2;
	}
}

void Enemy::EnemyMove()
{
	Frame f;
	f.position[0].X = 0;
	f.position[0].Y = 0;
	f.position[1].X = 47;
	f.position[1].Y = 23;
	for (int i = 0; i<MAXENEMYNUM; i++)
	{
		for (int j = 0; j<2; j++)							//所有敌机向下移动一格
			no[i].position[j].Y++;

		if (!JudgeCoordInFrame(f,no[i].position[1]))		//若移至最下方，则重新在上方生成敌机
		{
			COORD a = { 1, 1 };
			COORD b = { 45, 3 };
			no[i].position[0] = Random(a, b);
			no[i].position[1].X = no[i].position[0].X + 3;
			no[i].position[1].Y = no[i].position[0].Y + 2;
		}
	}
}

void Enemy::DrawEnemy()
{
	for (int i = 0; i<MAXENEMYNUM; i++)
		DrawFrame(no[i].position[0], no[i].position[1], '-', '|');
}

void Enemy::DrawEnemyToNull()
{
	for (int i = 0; i<MAXENEMYNUM; i++)
	{
		DrawFrame(no[i].position[0], no[i].position[1], ' ', ' ');
	}
}

void Enemy::DrawThisEnemyToNull(Frame& f)
{
	DrawFrame(f, ' ', ' ');
}
