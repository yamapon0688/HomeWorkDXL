#include "TGInclude.h"

void Title(Ball* ball, Racket* racket, System* system, const Sounds& sounds)
{
    SetFontSize(50);
    DrawString(WIDTH / 2 - 50 / 2 * 12 / 2, HEIGHT / 3, "Tennis Game", 0x00ff00);
    if (system->timer % 45 < 30)
    {
        SetFontSize(30);
        DrawString(WIDTH / 2 - 30 / 2 * 21 / 2, HEIGHT * 2 / 3, "Press SPACE to start.", 0x00FFFF);
    }
    if (CheckHitKey(KEY_INPUT_SPACE) == 1)
    {
        ball->ballX = 40;
        ball->ballY = 80;
        ball->ballVx = 5;
        ball->ballVy = 5;
        racket->racketX = WIDTH / 2;
        racket->racketY = HEIGHT - 50;
        system->score = 0;
        system->scene = PLAY;
        PlaySoundMem(sounds.bgm, DX_PLAYTYPE_LOOP);
    }
}