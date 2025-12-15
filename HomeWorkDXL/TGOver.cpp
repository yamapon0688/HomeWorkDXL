#include "TGInclude.h"
void Over(System* system)
{
    SetFontSize(40);
    DrawString(WIDTH / 2 - 40 / 2 * 9 / 2, HEIGHT / 3, "GAME OVER", 0xFF0000);
    if (system->timer > 60 * 5) system->scene = TITLE;
}