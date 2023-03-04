#pragma once
//包含一些全局函数
#include "Common.h"
typedef struct Frame												//定义一片区域
{
	COORD position[2];
	int flag;
}Frame;

void SetPos(COORD a);												//将光标定位至一点处
void SetPos(int i, int j);
void HideCursor();													//隐藏光标
void DrawRow(int y, int x1, int x2, char ch);						//将某一行填充为某个字符
void DrawRow(COORD a, COORD b, char ch);
void DrawCol(int x, int y1, int y2, char ch);						//将某一列填充为某个字符
void DrawCol(COORD a, COORD b, char ch);
void DrawFrame(COORD a, COORD  b, char row, char col);				//将某个区域的边框画出来
void DrawFrame(int x1, int y1, int x2, int y2, char row, char col);
void DrawFrame(Frame frame, char row, char col);
int Random(int a, int b);											//产生一个随机数
COORD Random(COORD a, COORD b);										//产生一个随机坐标
bool  JudgeCoordInFrame(Frame frame, COORD spot);					//判断一点是否在某个区域内
bool JudgeCoordInFrame(Frame frame, int x, int y);
bool JudgeFrameInFrame(Frame frame, Frame frame1);					//判断区域是否在区域内
bool JudgeFrameInFrame(Frame frame, COORD a, COORD b);
bool JudgeFrameInFrame(Frame frame, int x1, int y1, int x2, int y2);
