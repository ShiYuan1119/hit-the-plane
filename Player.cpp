#include "Player.h"

void Player::InitPlane()
{
	int i;
	COORD center = { 40, 22 };							//初始化飞机起始位置
	position[0].X = position[5].X = center.X;			//依次设定组件位置
	position[1].X = center.X - 2;
	position[2].X = position[6].X = center.X - 1;
	position[3].X = position[8].X = center.X + 1;
	position[4].X = center.X + 2;
	position[9].X = center.X + 3;
	position[7].X = center.X - 3;
	for (i = 0; i <= 4; i++)
		position[i].Y = center.Y;
	position[6].Y = center.Y + 1;
	position[8].Y = center.Y + 1;
	position[5].Y = center.Y - 1;
	position[7].Y = center.Y;
	position[9].Y = center.Y;
	/*
	   5
	7120349
	  6 8
	*/
}


void Player::DrawPlane()
{
	int i = 0;
	for (i; i < 10; i++)
	{
		SetPos(position[i]);
		switch (i)
		{
		case 5:
			cout << '^'; break;
		case 7:
			cout << '<'; break;
		case 9:
			cout << '>'; break;
		case 1:case 4:case 6:case 8:
			cout << '*'; break;
		case 0:
			cout << 'U'; break;
		case 2:
			cout << '['; break;
		case 3:
			cout << ']'; break;
		default:;
		}
	}
}

void Player::DrawPlaneToNull()
{
	for (int i = 0; i<10; i++)
	{
		SetPos(position[i]);
		cout << " ";
	}
}

void Player::PlaneMove(char c)
{
	Frame f;
	f.position[0].X = 0;
	f.position[0].Y = 0;
	f.position[1].X = 47;
	f.position[1].Y = 23;
	int x = 3, y = 1;
	switch (c)
	{
	case 'a':
	case 'A':
		for (int i = 0; i < 10; i++)				//飞机所有组件向左移动半个长度
			position[i].X -= x;
		if (!JudgeCoordInFrame(f, position[7]))		//若移出游戏区则向反方向移动回来
		{
			for (int i = 0; i < 10; i++)
				position[i].X += x;
		}
		break;
	case 's':
	case 'S':

		for (int i = 0; i < 10; i++)
			position[i].Y += y;
		if (!JudgeCoordInFrame(f, position[6]))		
		{
			for (int i = 0; i < 10; i++)
				position[i].Y += y;
		}
		break;
	case 'd':
	case 'D':
		for (int i = 0; i < 10; i++)
			position[i].X += x;
		if (!JudgeCoordInFrame(f, position[9]))	
		{
			for (int i = 0; i < 10; i++)
				position[i].X -= x;
		}
		break;
	case 'w':
	case 'W':
		for (int i = 0; i < 10; i++)
			position[i].Y -= y;
		if (!JudgeCoordInFrame(f, position[5]))
		{
			for (int i = 0; i < 10; i++)
				position[i].Y += y;
		}
		break;
	}
}

void Player::Shoot(Bullet &b)
{
	for (int i = 0; i < MAXBULLETNUM; i++)
	{
		if (!b.valid[i])							//遍历子弹数组，若有无效子弹则赋值
		{
			b.position[i].X = position[5].X;
			b.position[i].Y = position[5].Y - 1;
			b.valid[i] = true;
			break;
		}
	}
}
