#pragma once
//子弹类头文件
#include "OverObject.h"
using namespace std;

#define MAXBULLETNUM			(30)		//子弹数量

class Bullet
{
public:
	COORD position[MAXBULLETNUM];			//子弹坐标，最多30个
	bool valid[MAXBULLETNUM];				//子弹是否有效
	void InitBullet();						//初始化子弹
	void BulletMove();						//子弹移动
	void DrawBullet();						//在游戏池中显示子弹
	void DrawBulletToNull();				//抹去所有子弹
	void DrawThisBulletToNull(COORD);		//抹去某颗子弹
};