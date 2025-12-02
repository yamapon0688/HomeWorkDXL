#include "Prototype.h"
void title(int* timer, int* scene, const int* WIDTH, const int* HEIGHT, const Color* color, const int* bgm)
{
    SetFontSize(30);
    DrawFormatString(0, 100, color->WHITE, "title");
    SetFontSize(20);
    int blink = 10;
    int blinkDuration = 5;
    if (*timer % blink < blinkDuration)
    {
        DrawFormatString((*WIDTH / 2) - 100, (*HEIGHT / 2) + 200, color->YELLOW, "PUSH SPACE");
    }
   
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        *timer = 0;
        PlaySoundMem(*bgm, DX_PLAYTYPE_LOOP); // BGMÇÉãÅ[Évçƒê∂
        *scene = PLAY;
    }
}