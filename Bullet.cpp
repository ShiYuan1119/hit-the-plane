#include "Bullet.h"

void Bullet::InitBullet()
{
	for (int i = 0; i < MAXBULLETNUM; i++)				//�����ӵ����飬��������Ϊ��Ч
		valid[i] = false;
}

void Bullet::BulletMove()
{
	for (int i = 0; i < MAXBULLETNUM; i++)				//�����ӵ�����
	{
		if (valid[i])									//�������Ч�ӵ�
		{
			position[i].Y -= 1;							//�ӵ�����Ųһ��
			if (position[i].Y == 1)						//���������Ϸ�
			{
				COORD pos = { position[i].X, position[i].Y + 1 };
				DrawThisBulletToNull(pos);				//��ȥ����ӵ�
				valid[i] = false;						//���丳Ϊ��Ч
			}

		}
	}
}

void Bullet::DrawBullet()
{
	for (int i = 0; i<MAXBULLETNUM; i++)				//��������
	{
		if (valid[i])									//�����Ч
		{
			SetPos(position[i]);					
			cout << "*";								//��Ŀ��λ����ʾ�ӵ�
		}
	}
}

void Bullet::DrawBulletToNull()							//ԭ��ͬ��
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
