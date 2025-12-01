#include "Prototype.h"
#include <math.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 定数の宣言
    SetWindowText("音楽ゲーム"); // ウィンドウのタイトル
    int WIDTH = 960, HEIGHT = 640; // ウィンドウの幅と高さのピクセル数
    SetGraphMode(WIDTH, HEIGHT, 32); // ウィンドウの大きさとカラービット数の指定
    ChangeWindowMode(TRUE); // ウィンドウモードで起動
    if (DxLib_Init() == -1) return -1; // ライブラリ初期化 エラーが起きたら終了
    SetBackgroundColor(0, 0, 0); // 背景色の指定
    SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏画面にする

    Judge judge =
    {
        10, 40, 100
    };
    Color color =
    {
        GetColor(255, 255, 255), // 白
        GetColor(255, 255, 0), // 黄
        GetColor(255, 0, 0), // 赤
        GetColor(0, 255, 0), // 緑
        GetColor(0, 0, 255), // 青
    };
    Se se =
    {
        LoadSoundMem("sounds/Tambourine1.mp3"), // SEの読み込み
        LoadSoundMem("sounds/Tambourine2.mp3"), // SEの読み込み
        LoadSoundMem("sounds/Tambourine3.mp3"), // SEの読み込み
    };
    int titleBg = LoadGraph("image/image.png");
    int bgm = LoadSoundMem("sounds/Caprolactam.mp3");
    int spaceKeyState = 0;
    int timer = 0;
    int judgeCount[] = { 0, 0, 0 };
    int judgePos[] = { WIDTH / 2, HEIGHT / 2, 50 };
    int notePos[] = { 1000, HEIGHT / 2, 50 };
    int scene = TITLE; // どのシーンの処理を行うか
    while (1)
    {
        timer++;
        ClearDrawScreen();
        switch (scene)
        {
        case TITLE:
            StopSoundMem(bgm);
            DrawGraph(0, 0, titleBg, FALSE); // 背景の表示
            title(&timer, &scene, &WIDTH, &HEIGHT, &color, &bgm);
            break;

        case PLAY:
            play(&WIDTH, &HEIGHT, &timer, &scene, &notePos[0], &judgePos[0], &judgeCount[0], &color, &judge, &se, &spaceKeyState);
            break;
        }
        ScreenFlip(); // 裏画面の内容を表画面に反映させる
        WaitTimer(33); // 一定時間待つ
        if (ProcessMessage() == -1) break; // Windowsから情報を受け取りエラーが起きたら終了
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了
        if (se.greatSe == -1 || se.goodSe == -1 || se.missSe == -1) {
            // 何らかのエラー表示やメッセージボックスを表示
            MessageBox(NULL, "サウンドファイルの読み込みに失敗しました。", "エラー", MB_OK | MB_ICONERROR);
            DxLib_End();
            return -1; // 強制終了する
        }
    }
    DxLib_End; // ＤＸライブラリ使用の終了処理
    return 0; // ソフトの終了
}



