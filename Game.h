#pragma once
//游戏类，主要的文件
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
using namespace std;
class Game
{
public:
	Player p;					//玩家
	Bullet b;					//子弹
	Enemy e;					//敌机
	int score;					//得分
	int rank;					//等级
	int rankf;					//上一等级
	string title;				//称号
	int flag_rank;				//防止重复改变等级

	Game();						//构造函数
	void Pause();				//暂停、继续
	void Playing();				//游戏运行
	void JudgePlane();			//判断玩家是否死亡
	void JudgeEnemy();			//判断敌机碰撞
	void GameOver();			//游戏结束
	void PrintScore();			//游戏结束
	int DrawMenu();				//显示菜单
	void DrawPlaying();			//显示游戏界面
};