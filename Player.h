#pragma once
//玩家类
#include "Bullet.h"
using namespace std;
class Player
{
public:
	COORD position[10];					//飞机组件的位置
	void InitPlane();					//飞机初始化
	void DrawPlane();					//显示飞机
	void DrawPlaneToNull();				//抹去飞机
	void PlaneMove(char);				//飞机移动
	void Shoot(Bullet&);				//射击
};
