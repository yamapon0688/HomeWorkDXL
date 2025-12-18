#pragma once
#include "DxLib.h"
#include <stdlib.h>

struct Vector2
{
	int x;
	int y;
};

struct Player
{
	Vector2 pos;
	int type;
};

struct Computer
{
	Vector2 pos;
	int type;
	int flag;
};

struct Fuel
{
	Vector2 pos;
	int fuel;
	int imgFuel;
};

struct System
{
	int scene;
	int timer;
	int score;
	int highScore;
};

struct Sounds
{
	int bgm;
	int jin;
	int seFuel;
	int seCrash;
};

const int WIDTH = 720, HEIGHT = 640;	// ウィンドウの幅と高さのピクセル数
// 車の画像を管理する定数と配列
enum { RED, YELLOW, BLUE, TRUCK };
const int CAR_MAX = 4;
const int COM_MAX = 8;
const int CAR_W[CAR_MAX] = { 32, 26, 26, 40 };
const int CAR_H[CAR_MAX] = { 48, 48, 48, 100 };

enum { TITLE, PLAY, OVER };