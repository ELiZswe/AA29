// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/VolumeTimer/VolumeTimer.h"

AVolumeTimer::AVolumeTimer()
{
	TimerFrequency = 1;
}

void AVolumeTimer::PostBeginPlay()
{
	//Super::PostBeginPlay();
	//SetTimer(1, False);
	//A = Owner;
}
void AVolumeTimer::Timer()
{
	//A.TimerPop(Self);
	//SetTimer(TimerFrequency, False);
}