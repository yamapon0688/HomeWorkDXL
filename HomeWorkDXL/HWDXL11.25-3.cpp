#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 定数の宣言
    const int WIDTH = 960, HEIGHT = 640; // ウィンドウの幅と高さのピクセル数
    const int WHITE = GetColor(255, 255, 255); // よく使う色を定義

    SetWindowText("ＤＸライブラリの使い方"); // ウィンドウのタイトル
    SetGraphMode(WIDTH, HEIGHT, 32); // ウィンドウの大きさとカラービット数の指定
    ChangeWindowMode(TRUE); // ウィンドウモードで起動
    if (DxLib_Init() == -1) return -1; // ライブラリ初期化 エラーが起きたら終了
    SetBackgroundColor(0, 0, 0); // 背景色の指定
    SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏画面にする

    int timer = 0;
    int state = 0;
    int spaceKeyState = 0;
    while (1)
    {
        ClearDrawScreen();

        int currentSpacePress = CheckHitKey(KEY_INPUT_SPACE);
        if (currentSpacePress)
        {
            if (spaceKeyState == 0)
            {
                spaceKeyState = 1;// 押した瞬間
            }
            else
            {
                spaceKeyState = 2; // 押しっぱなし
            }
        }
        else
        {
            spaceKeyState = 0; // 離している
        }
        if (spaceKeyState == 1)
        {
            if (state == 0)
            {
                state = 1;
            }
            else
            {
                state = 0;
            }
        }
        if (state == 0)
        {
            DrawCircle(WIDTH / 2, HEIGHT / 2, 100, GetColor(255, 0, 0), TRUE); // 円を描く
        }
        if (state == 1)
        {
            DrawCircle(WIDTH / 2, HEIGHT / 2, 100, GetColor(255, 0, 0), FALSE); // 円を描く
        }

        ScreenFlip(); // 裏画面の内容を表画面に反映させる
        WaitTimer(33); // 一定時間待つ
        if (ProcessMessage() == -1) break; // Windowsから情報を受け取りエラーが起きたら終了
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了
    }

    DxLib_End; // ＤＸライブラリ使用の終了処理
    return 0; // ソフトの終了
}
