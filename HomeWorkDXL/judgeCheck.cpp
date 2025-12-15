#include "Prototype.h"

void judgeCheck(int judgeX, int judgeY, int d, int* judgeCount, const Color* color, const Judge* judge, const Se* se)
{

    if (d <= judge->greatRange)
    {
        DrawFormatString(judgeX, judgeY + 100, color->GREEN, "GREAT");
        judgeCount[GREAT]++;
        PlaySoundMem(se->greatSe, DX_PLAYTYPE_BACK);
    }
    else if (d <= judge->goodRange)
    {
        DrawFormatString(judgeX, judgeY + 100, color->BLUE, "GOOD");
        judgeCount[GOOD]++;
        PlaySoundMem(se->goodSe, DX_PLAYTYPE_BACK);
    }
    else if (d <= judge->missRange)
    {
        DrawFormatString(judgeX, judgeY + 100, color->RED, "MISS");
        judgeCount[MISS]++;
        PlaySoundMem(se->missSe, DX_PLAYTYPE_BACK);
    }
}
