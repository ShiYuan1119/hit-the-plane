#pragma once
//�л���
#include "OverObject.h"
using namespace std;
#define MAXENEMYNUM				(8)		//���л�����
class Enemy
{
public:
	Frame no[MAXENEMYNUM];				//�л�λ��
	void InitEnemy();					//��ʼ���л�
	void EnemyMove();					//�л��ƶ�
	void DrawEnemy();					//����Ϸ������ʾ�л�
	void DrawEnemyToNull();				//���л�Ĩȥ
	void DrawThisEnemyToNull(Frame&);	//��ĳһ�ܵл�Ĩȥ
};