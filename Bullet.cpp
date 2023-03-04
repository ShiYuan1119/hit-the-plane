#include "Bullet.h"

void Bullet::InitBullet()
{
	for (int i = 0; i < MAXBULLETNUM; i++)				//遍历子弹数组，将其设置为无效
		valid[i] = false;
}

void Bullet::BulletMove()
{
	for (int i = 0; i < MAXBULLETNUM; i++)				//遍历子弹数组
	{
		if (valid[i])									//如果是有效子弹
		{
			position[i].Y -= 1;							//子弹向上挪一格
			if (position[i].Y == 1)						//若移至最上方
			{
				COORD pos = { position[i].X, position[i].Y + 1 };
				DrawThisBulletToNull(pos);				//消去这颗子弹
				valid[i] = false;						//将其赋为无效
			}

		}
	}
}

void Bullet::DrawBullet()
{
	for (int i = 0; i<MAXBULLETNUM; i++)				//遍历数组
	{
		if (valid[i])									//如果有效
		{
			SetPos(position[i]);					
			cout << "*";								//在目标位置显示子弹
		}
	}
}

void Bullet::DrawBulletToNull()							//原理同上
{
	for (int i = 0; i < MAXBULLETNUM; i++)
	{
		if (valid[i])
		{
			COORD pos = { position[i].X, position[i].Y + 1 };
			SetPos(pos);
			cout << " ";
		}
	}
}

void Bullet::DrawThisBulletToNull(COORD c)
{
	SetPos(c);
	cout << " ";
}
