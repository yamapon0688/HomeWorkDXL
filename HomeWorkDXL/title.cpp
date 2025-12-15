#include "Prototype.h"
void title(int* timer, int* scene, int WIDTH, int HEIGHT, const Color& color, const int& BGM)
{
    SetFontSize(30);
    DrawFormatString(0, 100, color.WHITE, "title");
    SetFontSize(20);
    const int BLINK = 10;
    const int BLINKDURATION = 5;
    if (*timer % BLINK < BLINKDURATION)
    {
        DrawFormatString((WIDTH / 2) - 100, (HEIGHT / 2) + 200, color.YELLOW, "PUSH SPACE");
    }
   
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        *timer = 0;
        PlaySoundMem(BGM, DX_PLAYTYPE_LOOP); // BGM‚ðƒ‹[ƒvÄ¶
        *scene = PLAY;
    }
}