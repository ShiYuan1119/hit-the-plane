#pragma once
//�����
#include "Bullet.h"
using namespace std;
class Player
{
public:
	COORD position[10];					//�ɻ������λ��
	void InitPlane();					//�ɻ���ʼ��
	void DrawPlane();					//��ʾ�ɻ�
	void DrawPlaneToNull();				//Ĩȥ�ɻ�
	void PlaneMove(char);				//�ɻ��ƶ�
	void Shoot(Bullet&);				//���
};
