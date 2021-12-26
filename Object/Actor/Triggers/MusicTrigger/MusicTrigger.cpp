// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/MusicTrigger/MusicTrigger.h"

AMusicTrigger::AMusicTrigger()
{
	bCollideActors = false;
}

void AMusicTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (!Triggered)
	{
		Triggered = true;
		if (FadeOutAllSongs)
		{
			//StopAllMusic(FadeOutTime);
		}
		//SongHandle = PlayMusic(Song, FadeInTime);
	}
	else
	{
		Triggered = false;
		if (SongHandle != 0)
		{
			//StopMusic(SongHandle, FadeOutTime);
		}
		else
		{
			//Log("WARNING: invalid song handle");
		}
	}
}
