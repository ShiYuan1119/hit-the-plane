#pragma once
//��Ϸ�࣬��Ҫ���ļ�
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
using namespace std;
class Game
{
public:
	Player p;					//���
	Bullet b;					//�ӵ�
	Enemy e;					//�л�
	int score;					//�÷�
	int rank;					//�ȼ�
	int rankf;					//��һ�ȼ�
	string title;				//�ƺ�
	int flag_rank;				//��ֹ�ظ��ı�ȼ�

	Game();						//���캯��
	void Pause();				//��ͣ������
	void Playing();				//��Ϸ����
	void JudgePlane();			//�ж�����Ƿ�����
	void JudgeEnemy();			//�жϵл���ײ
	void GameOver();			//��Ϸ����
	void PrintScore();			//��Ϸ����
	int DrawMenu();				//��ʾ�˵�
	void DrawPlaying();			//��ʾ��Ϸ����
};