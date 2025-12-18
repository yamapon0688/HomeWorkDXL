/*
#include "TGInclude.h"
void Play(Ball* ball, Racket* racket, System* system, const Sounds& sounds, int* dx, int* dy)
{
    // ボールの移動処理
    ball->pos.x = ball->pos.x + ball->ballVx;
    if (ball->pos.x < ball->ballR && ball->ballVx < 0) ball->ballVx = ball->ballVx * -1;
    if (ball->pos.x > WIDTH - ball->ballR && ball->ballVx > 0) ball->ballVx = ball->ballVx * -1;
    ball->pos.y = ball->pos.y + ball->ballVy;
    if (ball->pos.y < ball->ballR && ball->ballVy < 0) ball->ballVy = ball->ballVy * -1;

    // ボールがHEIGHTより下に行ったら
    if (ball->pos.y > HEIGHT)
    {
        system->scene = OVER;
        system->timer = 0;
        StopSoundMem(sounds.bgm);
        PlaySoundMem(sounds.jin, DX_PLAYTYPE_BACK);
        return;
    }
    // ボール表示
    DrawCircle(ball->pos.x, ball->pos.y, ball->ballR, 0xff0000, TRUE);
    DrawCircle(ball->pos.x - ball->ballR / 4, ball->pos.y - ball->ballR / 4, ball->ballR / 2, 0xffa0a0, TRUE);
    DrawCircle(ball->pos.x - ball->ballR / 4, ball->pos.y - ball->ballR / 4, ball->ballR / 4, 0xffffff, TRUE);

    // ラケット操作
    if (CheckHitKey(KEY_INPUT_LEFT) == 1)
    {
        racket->pos.x = racket->pos.x - 10;
        if (racket->pos.x < racket->racketW / 2) racket->pos.x = racket->racketW / 2;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
    {
        racket->pos.x = racket->pos.x + 10;
        if (racket->pos.x > WIDTH - racket->racketW / 2) racket->pos.x = WIDTH - racket->racketW / 2;
    }

    // ラケット表示
    DrawBox(racket->pos.x - racket->racketW / 2 - 2, racket->pos.y - racket->racketH / 2 - 2, 
        racket->pos.x + racket->racketW / 2, racket->pos.y + racket->racketH / 2, 0x40c0ff, TRUE);
    DrawBox(racket->pos.x - racket->racketW / 2, racket->pos.y - racket->racketH / 2, 
        racket->pos.x + racket->racketW / 2 + 2, racket->pos.y + racket->racketH / 2 + 2, 0x204080, TRUE);
    DrawBox(racket->pos.x - racket->racketW / 2, racket->pos.y - racket->racketH / 2,
        racket->pos.x + racket->racketW / 2, racket->pos.y + racket->racketH / 2, 0x0000ff, TRUE);

    // ボールとラケットの当たり判定
    *dx = ball->pos.x - racket->pos.x;
    *dy = ball->pos.y - racket->pos.y;
    if (racket->racketW * -1 / 2 - 10 < *dx && *dx < racket->racketW / 2 + 10 && -20 < *dy && *dy < 0)
    {
        ball->ballVy = -5 - rand() % 5;
        system->score = system->score + 100;
        if (system->score > system->hiScore) system->hiScore = system->score;
    }
}
*/