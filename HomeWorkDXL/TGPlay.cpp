#include "TGInclude.h"
void Play(Ball* ball, Racket* racket, System* system, const Sounds& sounds, int* dx, int* dy)
{
    // ボールの移動処理
    ball->ballX = ball->ballX + ball->ballVx;
    if (ball->ballX < ball->ballR && ball->ballVx < 0) ball->ballVx = ball->ballVx * -1;
    if (ball->ballX > WIDTH - ball->ballR && ball->ballVx > 0) ball->ballVx = ball->ballVx * -1;
    ball->ballY = ball->ballY + ball->ballVy;
    if (ball->ballY < ball->ballR && ball->ballVy < 0) ball->ballVy = ball->ballVy * -1;

    // ボールがHEIGHTより下に行ったら
    if (ball->ballY > HEIGHT)
    {
        system->scene = OVER;
        system->timer = 0;
        StopSoundMem(sounds.bgm);
        PlaySoundMem(sounds.jin, DX_PLAYTYPE_BACK);
        return;
    }
    // ボール表示
    DrawCircle(ball->ballX, ball->ballY, ball->ballR, 0xff0000, TRUE);
    DrawCircle(ball->ballX - ball->ballR / 4, ball->ballY - ball->ballR / 4, ball->ballR / 2, 0xffa0a0, TRUE);
    DrawCircle(ball->ballX - ball->ballR / 4, ball->ballY - ball->ballR / 4, ball->ballR / 4, 0xffffff, TRUE);

    // ラケット操作
    if (CheckHitKey(KEY_INPUT_LEFT) == 1)
    {
        racket->racketX = racket->racketX - 10;
        if (racket->racketX < racket->racketW / 2) racket->racketX = racket->racketW / 2;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
    {
        racket->racketX = racket->racketX + 10;
        if (racket->racketX > WIDTH - racket->racketW / 2) racket->racketX = WIDTH - racket->racketW / 2;
    }

    // ラケット表示
    DrawBox(racket->racketX - racket->racketW / 2 - 2, racket->racketY - racket->racketH / 2 - 2, 
        racket->racketX + racket->racketW / 2, racket->racketY + racket->racketH / 2, 0x40c0ff, TRUE);
    DrawBox(racket->racketX - racket->racketW / 2, racket->racketY - racket->racketH / 2, 
        racket->racketX + racket->racketW / 2 + 2, racket->racketY + racket->racketH / 2 + 2, 0x204080, TRUE);
    DrawBox(racket->racketX - racket->racketW / 2, racket->racketY - racket->racketH / 2,
        racket->racketX + racket->racketW / 2, racket->racketY + racket->racketH / 2, 0x0000ff, TRUE);

    // ボールとラケットの当たり判定
    *dx = ball->ballX - racket->racketX;
    *dy = ball->ballY - racket->racketY;
    if (racket->racketW * -1 / 2 - 10 < *dx && *dx < racket->racketW / 2 + 10 && -20 < *dy && *dy < 0)
    {
        ball->ballVy = -5 - rand() % 5;
        system->score = system->score + 100;
        if (system->score > system->hiScore) system->hiScore = system->score;
    }
}