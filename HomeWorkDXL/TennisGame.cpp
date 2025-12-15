#include "TGInclude.h"
#include <time.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 定数の宣言  
    SetWindowText("テニスゲーム"); // ウィンドウのタイトル
    SetGraphMode(WIDTH, HEIGHT, 32); // ウィンドウの大きさとカラービット数の指定
    ChangeWindowMode(TRUE); // ウィンドウモードで起動
    if (DxLib_Init() == -1) return -1; // ライブラリ初期化 エラーが起きたら終了
    SetBackgroundColor(0, 0, 0); // 背景色の指定
    SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏画面にする

    // ボール
    Ball ball =
    {
        40, // ballX
        80, // ballY
        10, // ballR
        5,  // ballVx
        5,  // ballVy
    };

    Racket racket =
    {
        WIDTH / 2,      // racketX
        HEIGHT - 50,    // racketY
        120,            // racketW
        12              // racketH
    };

    System system =
    {
        TITLE,  // scene
        0,      // timer
        0,      // score
        1000,   // hiScore
    };

    Sounds sounds =
    {
        LoadSoundMem("sounds/TGSounds/bgm.mp3"),        // bgm
        LoadSoundMem("sounds/TGSounds/gameover.mp3"),   // jin
        LoadSoundMem("sounds/TGSounds/hit.mp3"),        // se
    };
    int imgBg = LoadGraph("image/TGImage/bg.png");      // bg

    if (ErrorCheck(sounds, imgBg)) // エラーチェック
    {
        return 0;   
    }
    int dx = 0;
    int dy = 0;
    bool screenMode = TRUE;
    ; 
    ChangeVolumeSoundMem(128, sounds.bgm);
    ChangeVolumeSoundMem(128, sounds.jin);

    srand((unsigned int)time(NULL));
    while (true)
    {
        ClearDrawScreen(); // 画面をクリアする
        DrawGraph(0, 0, imgBg, FALSE);
        system.timer++;

        switch (system.scene)
        {
        case TITLE:
            Title(&ball, &racket, &system, sounds);
            break;

        case PLAY:
            Play(&ball, &racket, &system, sounds, &dx, &dy);
            break;
        case OVER:
            Over(&system);
            break;
        }

        SetFontSize(30);
        DrawFormatString(10, 10, 0xffffff, "SCORE %d", system.score);
        DrawFormatString(WIDTH - 200, 10, 0xffff00, "HI-SC %d", system.hiScore);


        ScreenFlip(); // 裏画面の内容を表画面に反映させる
        WaitTimer(16); // 一定時間待つ
        if (ProcessMessage() == -1) break; // Windowsから情報を受け取りエラーが起きたら終了
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了
    }
    DxLib_End(); // ＤＸライブラリ使用の終了処理
    return 0; // ソフトの終了
}



