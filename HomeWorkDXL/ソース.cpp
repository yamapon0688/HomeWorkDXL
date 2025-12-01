/*
#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true); // ウィンドウモード
	if (DxLib_Init() == -1) return -1; // ライブラリの初期化、エラーが起きたら終了
	DrawCircle(320, 240, 100, 0x0000ff); // 円を描く
	WaitKey(); // キー入力があるまで待つ
	DxLib_End(); // DXライブラリの終了処理
	return 0; // ソフトの終了
}

*/