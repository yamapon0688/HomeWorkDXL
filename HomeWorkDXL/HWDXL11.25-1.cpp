#include "DxLib.h"
#include "math.h"
/*
struct Circle
{
    int posX;
    int posY;
    int radius;
    int color;
};
int hitCircleCircle(const Circle* circle);

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

    const int BLUE = GetColor(0, 0, 255);
    Circle circle[] =
    {
        {250, 300, 100,BLUE},
        {400, 6, 200,BLUE},
    };

    while (1)
    {
        ClearDrawScreen();
        GetMousePoint(&circle[0].posX, &circle[0].posY);
        for (int i = 0; i < sizeof(circle) / sizeof(circle[0]); i++)
        {
            DrawCircle(circle[i].posX, circle[i].posY, circle[i].radius, circle[i].color, TRUE);
        }
        if (hitCircleCircle(&circle[0]))
        {
            circle[0].color = WHITE;
        }
        else
        {
            circle[0].color = BLUE;
        }
        ScreenFlip(); // 裏画面の内容を表画面に反映させる
        WaitTimer(33); // 一定時間待つ
        if (ProcessMessage() == -1) break; // Windowsから情報を受け取りエラーが起きたら終了
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了
    }
    DxLib_End();// ＤＸライブラリ使用の終了処理
    return 0;// ソフトの終了
}
int hitCircleCircle(const Circle* circle)
{
    int dx = circle[0].posX - circle[1].posX;
    int dy = circle[0].posY - circle[1].posY;
    int totalR = circle[0].radius + circle[1].radius;
    double d = sqrt((dx * dx) + (dy * dy));
    if (d <= totalR)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
*/