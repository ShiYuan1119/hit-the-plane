#pragma once
//�ӵ���ͷ�ļ�
#include "OverObject.h"
using namespace std;

#define MAXBULLETNUM			(30)		//�ӵ�����

class Bullet
{
public:
	COORD position[MAXBULLETNUM];			//�ӵ����꣬���30��
	bool valid[MAXBULLETNUM];				//�ӵ��Ƿ���Ч
	void InitBullet();						//��ʼ���ӵ�
	void BulletMove();						//�ӵ��ƶ�
	void DrawBullet();						//����Ϸ������ʾ�ӵ�
	void DrawBulletToNull();				//Ĩȥ�����ӵ�
	void DrawThisBulletToNull(COORD);		//Ĩȥĳ���ӵ�
};