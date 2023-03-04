#include "OverObject.h"
using namespace std;

void SetPos(COORD a)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}

void SetPos(int i, int j) 
{
	COORD pos = { i, j };
	SetPos(pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//�ѵ�y�У�[x1, x2) ֮����������Ϊ ch  
void DrawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1, y);
	for (int i = 0; i <= (x2 - x1); i++)
		cout << ch;
}

//��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch  
void DrawRow(COORD a, COORD b, char ch)
{
	if (a.Y == b.Y)
		DrawRow(a.Y, a.X, b.X, ch);
}

//�ѵ�x�У�[y1, y2] ֮����������Ϊ ch  
void DrawCol(int x, int y1, int y2, char ch)
{
	int y = y1;
	while (y != y2 + 1)
	{
		SetPos(x, y);
		cout << ch;
		y++;
	}
}

//��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch  
void DrawCol(COORD a, COORD b, char ch)
{
	if (a.X == b.X)
		DrawCol(a.X, a.Y, b.Y, ch);
}

//���Ͻ����ꡢ���½����ꡢ��row����С���col�����  
void DrawFrame(COORD a, COORD  b, char row, char col)
{
	DrawRow(a.Y, a.X + 1, b.X - 1, row);
	DrawRow(b.Y, a.X + 1, b.X - 1, row);
	DrawCol(a.X, a.Y + 1, b.Y - 1, col);
	DrawCol(b.X, a.Y + 1, b.Y - 1, col);
}

void DrawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
	COORD a = { x1, y1 };
	COORD b = { x2, y2 };
	DrawFrame(a, b, row, col);
}

void DrawFrame(Frame frame, char row, char col)
{
	COORD a = frame.position[0];
	COORD b = frame.position[1];
	DrawFrame(a, b, row, col);
}

//��[a, b)֮�����һ���������  
int Random(int a, int b)
{
	int c = (rand() % (a - b)) + a;
	return c;
}

//��������������ľ��ο����������һ������  
COORD Random(COORD a, COORD b)
{
	int x = Random(a.X, b.X);
	int y = Random(a.Y, b.Y);
	COORD c = { x, y };
	return c;
}

//�жϵ�spot�Ƿ���frame��
bool JudgeCoordInFrame(Frame frame, COORD spot)
{
	if (spot.X >= frame.position[0].X)
		if (spot.X <= frame.position[1].X)
			if (spot.Y >= frame.position[0].Y)
				if (spot.Y <= frame.position[1].Y)
					return true;
	return false;
}

bool JudgeCoordInFrame(Frame frame, int x, int y)
{
	if (x >= frame.position[0].X)
		if (x <= frame.position[1].X)
			if (y >= frame.position[0].Y)
				if (y <= frame.position[1].Y)
					return true;
	return false;
}

//�ж�����frame1�Ƿ�������frame��
bool JudgeFrameInFrame(Frame frame, Frame frame1)
{
	if (JudgeCoordInFrame(frame, frame1.position[0]))
		if (JudgeCoordInFrame(frame, frame1.position[1]))
			return true;
	return false;
}

bool JudgeFrameInFrame(Frame frame, COORD a, COORD b)
{
	if (JudgeCoordInFrame(frame, a))
		if (JudgeCoordInFrame(frame, b))
			return true;
	return false;
}

bool JudgeFrameInFrame(Frame frame, int x1, int y1, int x2, int y2)
{
	if (JudgeCoordInFrame(frame, x1, y1))
		if (JudgeCoordInFrame(frame, x2, y2))
			return true;
	return false;
}
