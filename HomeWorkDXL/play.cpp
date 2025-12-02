#include "Prototype.h"
#define X 0
#define Y 1
#define RADIUS 2

void play(const int* WIDTH, const int* HEIGHT, int* timer, int* scene, int* notePos, int* judgePos, int* judgeCount, const Color* color, const Judge* judge, const Se* se, int* spaceKeyState)
{
    int noteSpeed = 8;
    const int CHECK = 100;

    int currentSpacePress = CheckHitKey(KEY_INPUT_SPACE);
    if (currentSpacePress)
    {
        if (*spaceKeyState == 0)
        {
            *spaceKeyState = 1;
        }
        else
        {
            *spaceKeyState = 2; // 押しっぱなし
        }
    }
    else
    {
        *spaceKeyState = 0; // 離している
    }
    int noteCol = color->WHITE;

    int noteX = notePos[X] - (*timer * noteSpeed);
    DrawFormatString(0, *HEIGHT - 20, color->WHITE, "GREAT:%d GOOD:%d MISS:%d", judgeCount[GREAT], judgeCount[GOOD], judgeCount[MISS]);

    DrawLine(0, (*HEIGHT / 2 - notePos[RADIUS]), *WIDTH, (*HEIGHT / 2 - notePos[RADIUS]), color->WHITE); // 上の線
    DrawLine(0, (*HEIGHT / 2 + notePos[RADIUS]), *WIDTH, (*HEIGHT / 2 + notePos[RADIUS]), color->WHITE); // 下の線

    DrawCircle(judgePos[X], judgePos[Y], judgePos[RADIUS], color->WHITE, FALSE); // 判定円表示
    DrawCircle(noteX, notePos[Y], notePos[RADIUS], noteCol, TRUE); // ノーツ表示
    int d = abs(judgePos[X] - noteX); // 判定円とノーツの差
    DrawFormatString(0, 0, color->WHITE, "判定枠とノーツの距離:%d", d);
    if (*spaceKeyState == 1)
    {
        if (d <= CHECK)
        {
            judgeCheck(judgePos[X], judgePos[Y], d, &judgeCount[0], color, judge, se);
            *timer = 0;
        }
    }

    if (noteX < -notePos[RADIUS])
    {
        judgeCount[MISS]++;
        *timer = 0;
    }
    if (CheckHitKey(KEY_INPUT_T) == 1)
    {

        *scene = TITLE;
    }
}


