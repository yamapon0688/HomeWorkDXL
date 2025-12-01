#include "Prototype.h"

void judgeCheck(int judgeX, int judgeY, int d, int* judgeCount, const Judge* judge, const Se* se)
{

    const int YELLOW = GetColor(255, 255, 0);
    const int GREEN = GetColor(0, 255, 0);
    const int BLUE = GetColor(0, 0, 255);
    const int RED = GetColor(255, 0, 0);
    const int GREAT_RANGE = 10;
    const int GOOD_RANGE = 40;
    const int MISS_RANGE = 100;

    if (d <= GREAT_RANGE)
    {
        DrawFormatString(judgeX, judgeY + 100, GREEN, "GREAT");
        judgeCount[GREAT]++;
        PlaySoundMem(se->greatSe, DX_PLAYTYPE_BACK);
    }
    else if (d <= GOOD_RANGE)
    {
        DrawFormatString(judgeX, judgeY + 100, BLUE, "GOOD");
        judgeCount[GOOD]++;
        PlaySoundMem(se->goodSe, DX_PLAYTYPE_BACK);
    }
    else if (d <= MISS_RANGE)
    {
        DrawFormatString(judgeX, judgeY + 100, RED, "MISS");
        judgeCount[MISS]++;
        PlaySoundMem(se->missSe, DX_PLAYTYPE_BACK);
    }
}