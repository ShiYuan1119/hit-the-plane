#pragma once
//����һЩȫ�ֺ���
#include "Common.h"
typedef struct Frame												//����һƬ����
{
	COORD position[2];
	int flag;
}Frame;

void SetPos(COORD a);												//����궨λ��һ�㴦
void SetPos(int i, int j);
void HideCursor();													//���ع��
void DrawRow(int y, int x1, int x2, char ch);						//��ĳһ�����Ϊĳ���ַ�
void DrawRow(COORD a, COORD b, char ch);
void DrawCol(int x, int y1, int y2, char ch);						//��ĳһ�����Ϊĳ���ַ�
void DrawCol(COORD a, COORD b, char ch);
void DrawFrame(COORD a, COORD  b, char row, char col);				//��ĳ������ı߿򻭳���
void DrawFrame(int x1, int y1, int x2, int y2, char row, char col);
void DrawFrame(Frame frame, char row, char col);
int Random(int a, int b);											//����һ�������
COORD Random(COORD a, COORD b);										//����һ���������
bool  JudgeCoordInFrame(Frame frame, COORD spot);					//�ж�һ���Ƿ���ĳ��������
bool JudgeCoordInFrame(Frame frame, int x, int y);
bool JudgeFrameInFrame(Frame frame, Frame frame1);					//�ж������Ƿ���������
bool JudgeFrameInFrame(Frame frame, COORD a, COORD b);
bool JudgeFrameInFrame(Frame frame, int x1, int y1, int x2, int y2);
