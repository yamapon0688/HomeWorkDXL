#include "CRInclude.h"

void drawCar(int x, int y, int type);
void Game(Player* player, Computer* computer, Fuel* fuel, System* system, int* bgY, int* imgBG)
{
	// 背景のスクロール処理
	if (system->scene == PLAY) *bgY = (*bgY + 10) % HEIGHT; // プレイ中にだけスクロール;
	DrawGraph(0, *bgY - HEIGHT, *imgBG, FALSE);
	DrawGraph(0, *bgY, *imgBG, FALSE);

	/*
	// 車両表示
	drawCar(300, 360, RED);
	drawCar(340, 360, YELLOW);
	drawCar(380, 360, BLUE);
	drawCar(420, 360, TRUCK);
	*/

	// プレイヤーの車を動かす処理
	if (system->scene == PLAY) // プレイ中にだけ動かす
	{
		GetMousePoint(&player->pos.x, &player->pos.y);
		if (player->pos.x < 260) player->pos.x = 260;
		if (player->pos.x > 460) player->pos.x = 460;
		if (player->pos.y < 40) player->pos.y = 40;
		if (player->pos.y > 600) player->pos.y = 600;
	}
	drawCar(player->pos.x, player->pos.y, player->type);

	// コンピューターの車を動かす処理
	for (int i = 0; i < COM_MAX; i++)
	{
		if (system->scene == PLAY) // プレイ中の車の処理
		{
			computer[i].pos.y = computer[i].pos.y + 1 + i;
			if (computer[i].pos.y > HEIGHT + 100) // 画面の下から外に出たかを判定
			{
				computer[i].pos.x = rand() % 180 + 270;
				computer[i].pos.y = rand() % 200 - 300;
				computer[i].type = YELLOW + rand() % 3;
				computer[i].flag = 0;
			}
			// ヒットチェック
			int dx = abs(computer[i].pos.x - player->pos.x); // x軸方向のピクセル数
			int dy = abs(computer[i].pos.y - player->pos.y); // y軸方向のピクセル数
			int wid = CAR_W[player->type] / 2 + CAR_W[computer[i].type] / 2 - 4;
			int hei = CAR_H[player->type] / 2 + CAR_H[computer[i].type] / 2 - 4;
			if (dx < wid && dy < hei) // 接触しているか
			{
				int col = GetColor(rand() % 256, rand() % 256, rand() % 256); // 重ねる色
				SetDrawBlendMode(DX_BLENDMODE_ADD, 255); // 色を加算する設定
				DrawBox(player->pos.x - CAR_W[player->type] / 2, player->pos.y - CAR_H[player->type] / 2, player->pos.x + CAR_W[player->type] / 2, player->pos.y + CAR_H[player->type] / 2, col, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // 通常の描画に戻す
				fuel->fuel -= 10;
			}
			// 追い抜いたかを判定
			if (computer[i].pos.y > player->pos.y && computer[i].flag == 0)
			{
				computer[i].flag = 1;
				system->score += 100;
				if (system->score > system->highScore) system->highScore = system->score;
			}
		}
		else // タイトル画面とゲームオーバー画面での車の動き
		{
			computer[i].pos.y = computer[i].pos.y - 1 - i;
			if (computer[i].pos.y < -100) computer[i].pos.y = HEIGHT + 100;
		}
		drawCar(computer[i].pos.x, computer[i].pos.y, computer[i].type);
	}

	// 燃料アイテムの処理
	if (system->scene == PLAY) // ゲーム中だけ出現
	{
		fuel->pos.y += 4;
		if (fuel->pos.y > HEIGHT) fuel->pos.y = -100;
		if (abs(fuel->pos.x - player->pos.x) < CAR_W[player->type] / 2 + 12 && abs(fuel->pos.y - player->pos.y) < CAR_H[player->type] / 2 + 12)
		{
			fuel->pos.x = rand() % 180 + 270;
			fuel->pos.y = -500;
			fuel->fuel += 200;
		}
		DrawGraph(fuel->pos.x - 12, fuel->pos.y - 12, fuel->imgFuel, TRUE);
	}
}
