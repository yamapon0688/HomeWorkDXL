#include "DxLib.h"
#include "math.h"

struct Rect
{
    int posX;
    int posY;
    int hw;
    int hh;
    int color;
};
int hitRectRect(const Rect* rect);

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
    Rect rect[] =
    {
        {250, 300, 100, 50, WHITE},
        {400, 400, 100, 75, WHITE},
    };

    while (1)
    {
        ClearDrawScreen();
        GetMousePoint(&rect[0].posX, &rect[0].posY);
        for (int i = 0; i < sizeof(rect) / sizeof(rect[0]); i++)
        {
            DrawBox(rect[i].posX - rect[i].hw, rect[i].posY - rect[i].hh, // 左上の位置
                rect[i].posX + rect[i].hw, rect[i].posY + rect[i].hh,  // 右下の位置
                rect[i].color, TRUE);
        }
        if (hitRectRect(&rect[0]))
        {
            rect[0].color = BLUE;
        }
        else
        {
            rect[0].color = WHITE;
        }
        ScreenFlip(); // 裏画面の内容を表画面に反映させる
        WaitTimer(33); // 一定時間待つ
        if (ProcessMessage() == -1) break; // Windowsから情報を受け取りエラーが起きたら終了
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了
    }
    DxLib_End();// ＤＸライブラリ使用の終了処理
    return 0;// ソフトの終了
}
int hitRectRect(const Rect* rect)
{
    int dx = abs((rect[0].posX - rect[1].posX)); // x軸方向の距離
    int dy = abs((rect[0].posY - rect[1].posY)); // y軸方向の距離

    if (dx <= (rect[0].hw + rect[1].hw) && dy <= (rect[0].hh + rect[1].hh)) // ヒットチェック
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
