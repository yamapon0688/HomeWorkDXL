#include "CRInclude.h"
#include "CRDrawFuncProto.h"

void Title(Player* player, Computer* computer, Fuel* fuel, System* system, Sounds* sounds)
{
	drawText(160, 160, 0xffffff, "Car Race", 0, 100);
	if (system->timer % 60 < 30) drawText(210, 400, 0x00ff00, "Click to start.", 0, 40);
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		player->pos.x = WIDTH / 2;
		player->pos.y = HEIGHT / 2;
		for (int i = 0; i < COM_MAX; i++)
		{
			computer[i].pos.y = HEIGHT + 100;
			computer[i].flag = 0;
		}
		fuel->pos.x = WIDTH / 2;
		fuel->pos.y = -100;
		system->score = 0;
		fuel->fuel = 1000;
		system->scene = PLAY;
		PlaySoundMem(sounds->bgm, DX_PLAYTYPE_LOOP); // BGM‚ğƒ‹[ƒvÄ¶
	}
}