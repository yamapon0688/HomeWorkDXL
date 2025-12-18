#include "CRInclude.h"

void Play(Fuel* fuel, System* system, Sounds* sounds)
{
	fuel->fuel -= 1;
	if (fuel->fuel < 0)
	{
		fuel = 0;
		system->scene = OVER;
		system->timer = 0;
		StopSoundMem(sounds->bgm); // BGM‚ð’âŽ~
		PlaySoundMem(sounds->jin, DX_PLAYTYPE_BACK); // ƒWƒ“ƒOƒ‹‚ðo—Í
	}
}