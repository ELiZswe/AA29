// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/DisconnectVolume/DisconnectVolume.h"

ADisconnectVolume::ADisconnectVolume()
{
	FadeTime = 1.5;
	//bStatic = false;
}

void ADisconnectVolume::Touch(AActor* Other)
{
	/*
	if (Pawn(Other) == None)
	{
		return;
	}
	PC = PlayerController(Pawn(Other).Controller);
	if (PC != None)
	{
		PC.LockPlayer(true, true);
		PC.DoFade(false, true, FadeTime);
		SetTimer(FadeTime, false);
	}
	*/
}

void ADisconnectVolume::Timer()
{
	//PC.ConsoleCommand("disconnect");
}
