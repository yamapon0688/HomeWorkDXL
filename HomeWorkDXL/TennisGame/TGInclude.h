/*
#pragma once
#include "DxLib.h"
#include <stdlib.h>

struct Vector2
{
    int x;
    int y;
};

struct Ball
{
    Vector2 pos;
    int ballR;
    int ballVx;
    int ballVy;
};

struct Racket
{
    Vector2 pos;
    int racketW;
    int racketH;
};

struct System
{
    int scene;
    int timer;
    int score;
    int hiScore;
};

struct Sounds
{
    int bgm;
    int jin;
    int se;
};

const int WIDTH = 960, HEIGHT = 640; // ウィンドウの幅と高さのピクセル数
const enum { TITLE, PLAY, OVER };

bool ErrorCheck(const Sounds& sounds, int imgBg);
void Title(Ball* ball, Racket* racket, System* system, const Sounds& bgmSe);
void Play(Ball* ball, Racket* racket, System* system, const Sounds& bgmSe, int* dx, int* dy);
void Over(System* system);
*/