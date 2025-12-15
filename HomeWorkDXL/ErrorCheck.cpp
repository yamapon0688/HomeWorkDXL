#include "TGInclude.h"
void DrawErrorMessage(int& y, const char* message)
{
    int lineHeight = 20;
    DrawString(0, y, message, 0x00ff00);
    y += lineHeight;
}
bool ErrorCheck(const Sounds& sounds, int imgBg)
{
    if (sounds.bgm == -1 || sounds.jin == -1 || sounds.se == -1 || imgBg == -1)
    {
        int y = 0;
        if (sounds.bgm == -1)
            DrawErrorMessage(y, "[bgm] not found");
        if (sounds.jin == -1)
            DrawErrorMessage(y, "[jin] not found");
        if (sounds.se == -1)
            DrawErrorMessage(y, "[se] not found");
        if (imgBg == -1)
            DrawErrorMessage(y, "[imgBg] not found");
        
        ScreenFlip();
        WaitTimer(5000);
        return TRUE;
    }
    return FALSE;
}