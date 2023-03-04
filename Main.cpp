#include "Game.h"
using namespace std;


/*
DWORD WINAPI MusicFun(LPVOID lpParamte)
{
//DWORD OBJ;
sndPlaySound(TEXT("bgm.wav"), SND_FILENAME|SND_ASYNC);
return 0;
}
*/


int main()
{
	  
	srand((int)time(0));    //随机种子  
	HideCursor();			//隐藏光标  

	Game game;
	int a = game.DrawMenu();
	if (a == 2)
		game.rank = 20;
	system("cls");
	game.DrawPlaying();
	game.Playing();
	return 0;
}