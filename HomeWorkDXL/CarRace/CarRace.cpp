#include "CRInclude.h"
#include "CRDrawFuncProto.h"

bool ErrorCheck(const Sounds& sounds, const Fuel& fuel, const int& imgBG, const int imgCar[]);
void Game(Player* player, Computer* computer, Fuel* fuel, System* system, int* bgY, int* imgBG);
void Title(Player* player, Computer* computer, Fuel* fuel, System* system, Sounds* sounds);
void Play(Fuel* fuel, System* system, Sounds* sounds);
void Over(System* system);

int imgCar[CAR_MAX];

// 車を表示する関数

void drawCar(int x, int y, int type)
{
	DrawGraph(x - CAR_W[type] / 2, y - CAR_H[type] / 2, imgCar[type], TRUE);
}

// 影を付けた文字列を表示する関数
void drawText(int x, int y, int col, const char* txt, int val, int siz)
{
	SetFontSize(siz);
	DrawFormatString(x + 2, y + 2, 0x000000, txt, val);
	DrawFormatString(x, y, col, txt, val);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 定数/
	SetWindowText("カーレース");			// ウィンドウのタイトル
	SetGraphMode(WIDTH, HEIGHT, 32);		// ウィンドウの大きさとカラービット数の指定
	ChangeWindowMode(TRUE);					// ウィンドウモードで起動
	if (DxLib_Init() == -1) return -1;		// ライブラリ初期化 エラーが起きたら終了
	SetBackgroundColor(0, 0, 0);			// 背景色の指定
	SetDrawScreen(DX_SCREEN_BACK);			// 描画面を裏画面にする

	int bgY = 0;	// 道路をスクロールさせるための変数
	int imgBG = LoadGraph("image/CRImage/bg.png");	// 背景画像

	// 車の画像を配列に読み込む
	imgCar[RED] = LoadGraph("image/CRImage/car_red.png");
	imgCar[YELLOW] = LoadGraph("image/CRImage/car_yellow.png");
	imgCar[BLUE] = LoadGraph("image/CRImage/car_blue.png");
	imgCar[TRUCK] = LoadGraph("image/CRImage/truck.png");

	// プレイヤーの車用の構造体
	Player player
	{
		WIDTH / 2,
		HEIGHT / 2,
		RED,
	};


	// コンピューターが動かす車用の構造体
	Computer computer[COM_MAX];
	for (int i = 0; i < COM_MAX; i++)
	{
		computer[i] =
		{
			rand() % 180 + 270,
			-100 - (i * 150),
			YELLOW + rand() % 3,
			0,
		};
	}
	// 燃料アイテム用の構造体
	Fuel fuel
	{
		0,
		WIDTH / 2,
		0,
		LoadGraph("image/CRImage/fuel.png"),
	};

	// ゲーム進行、スコアに関する構造体
	System system
	{
		TITLE,
		0,
		0,
		5000,
	};

	// サウンドの読み込みと音量設定
	Sounds sounds
	{
		LoadSoundMem("sounds/CRSounds/bgm.mp3"),
		LoadSoundMem("sounds/CRSounds/gameover.mp3"),
		LoadSoundMem("sounds/CRSounds/fuel.mp3"),
		LoadSoundMem("sounds/CRSounds/crash.mp3"),
	};
	if (ErrorCheck(sounds, fuel, imgBG, imgCar)) // エラーチェック
	{
		return 0;
	}

	ChangeVolumeSoundMem(128, sounds.bgm);
	ChangeVolumeSoundMem(128, sounds.jin);

	while (true)
	{
		ClearDrawScreen();	// 画面をクリア
		system.timer++; // タイマーをカウント
		Game(&player, computer, &fuel, &system, &bgY, &imgBG);
		switch (system.scene) // タイトル、ゲームプレイ、ゲームオーバーの分岐
		{
		case TITLE: // タイトル画面の処理
		{
			Title(&player, computer, &fuel, &system, &sounds);
			break;
		}

		case PLAY: // ゲームをプレイする処理
		{
			Play(&fuel, &system, &sounds);
			break;
		}

		case OVER: // ゲームオーバーの処理
		{
			Over(&system);
			break;
		}
		}

		// スコアなどの表示
		drawText(10, 10, 0x00ffff, "SCORE %d", system.score, 30);
		drawText(WIDTH - 200, 10, 0xffff00, "HI-SC %d", system.highScore, 30);
		int col = 0x00ff00; // 燃料の値を表示する色
		if (fuel.fuel < 400) col = 0xffc000;
		if (fuel.fuel < 200) col = 0xff0000;
		drawText(10, HEIGHT - 40, col, "FUEL %d", fuel.fuel, 30);

		ScreenFlip();	// 裏画面の内容を表画面に反映させる
		WaitTimer(16);	// 一定時間待つ
		if (ProcessMessage() == -1) break;	// Windowsから情報を受け取りエラーが起きたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;	// ESCキーが押されたら終了
	}

	InitSoundMem();
	InitGraph();
	DxLib_End();	// DXライブラリ使用の終了処理
	return 0;	// ソフトの終了
}


