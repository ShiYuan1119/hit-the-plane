#pragma once
//敌机类
#include "OverObject.h"
using namespace std;
#define MAXENEMYNUM				(8)		//最大敌机数量
class Enemy
{
public:
	Frame no[MAXENEMYNUM];				//敌机位置
	void InitEnemy();					//初始化敌机
	void EnemyMove();					//敌机移动
	void DrawEnemy();					//在游戏池中显示敌机
	void DrawEnemyToNull();				//将敌机抹去
	void DrawThisEnemyToNull(Frame&);	//将某一架敌机抹去
};