#include "CRInclude.h"
#include "CRDrawFuncProto.h"

void Over(System* system)
{
	drawText(180, 240, 0xff0000, "GAME OVER", 0, 80);
	if (system->timer > 60 * 5) system->scene = TITLE;
}