#pragma once
#include "DxLib.h"
struct Judge
{
    int greatRange; // great”»’è”ÍˆÍ
    int goodRange; // good”»’è”ÍˆÍ
    int missRange; // miss”»’è”ÍˆÍ
};

struct Color
{
    int WHITE;
    int YELLOW;
    int RED;
    int GREEN;
    int BLUE;
};

struct Se
{
    int greatSe;
    int goodSe;
    int missSe;
};

const enum jCount
{
    GREAT = 0,
    GOOD = 1,
    MISS = 2,
};

const enum // ŠeƒV[ƒ“‚ğ’è‚ß‚é’è”
{
    TITLE,
    PLAY,
};

void judgeCheck(int judgeX, int judgeY, int d, int* judgeCount, const Judge* judge, const Se* se);
void title(int* timer, int* scene, const int *WIDTH, const int *HEIGHT, const Color* color, const int* bgm);
void play(const int *WIDTH, const int *HEIGHT, int* timer, int* scene, int* notePos, int* judgePos, int* judgeCount, const Color* color, const Judge* judge, const Se* se, int* spaceKeyState);
