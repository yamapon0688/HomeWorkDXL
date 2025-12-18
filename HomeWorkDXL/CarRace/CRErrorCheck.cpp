#include "CRInclude.h"

static void DrawErrorMessage(int& y, const char* message)
{
    int lineHeight = 20;
    DrawString(0, y, message, 0x00ff00);
    y += lineHeight;
}
bool ErrorCheck(const Sounds& sounds, const Fuel& fuel, const int& imgBG, const int imgCar[])
{
    bool hasError = false;
    const char* imgCarMessage[] =
    {
        "[RED]",
        "[YELLOW]",
        "[BLUE]",
        "[BLACK]",
    };
    int y = 0;
    if (sounds.bgm == -1 || sounds.jin == -1 || sounds.seFuel == -1 || sounds.seCrash == -1 || fuel.imgFuel == -1 || imgBG == -1)
    {    
        if (sounds.bgm == -1)
            DrawErrorMessage(y, "[bgm] not found");
        if (sounds.jin == -1)
            DrawErrorMessage(y, "[jin] not found");
        if (sounds.seFuel == -1)
            DrawErrorMessage(y, "[seFuel] not found");
        if (sounds.seCrash == -1)
            DrawErrorMessage(y, "[seCrash] not found");
        if (fuel.imgFuel == -1)
            DrawErrorMessage(y, "[imgFuel] not found");
        if (imgBG == -1)
            DrawErrorMessage(y, "[imgBG] not found");
        hasError = true;
        
    }
    char message[128];
    for (int i = 0; i < CAR_MAX; i++)
    {
        if (imgCar[i] == -1)
        {
            sprintf_s(message, "imgCar%s not found", imgCarMessage[i]);
            DrawErrorMessage(y, message);
            hasError = true;
        }
    }

    if (hasError)
    {
        ScreenFlip();
        WaitTimer(5000);
        return TRUE;
    }
    return FALSE;
}
