// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/DisconnectVolume/DisconnectVolume.h"

ADisconnectVolume::ADisconnectVolume()
{
	FadeTime = 1.5;
	//bStatic = false;
}

void ADisconnectVolume::Touch(AActor* Other)
{
	/*
	if (Cast<APawn>(Other) == nullptr)
	{
		return;
	}
	PC = Cast<APlayerController>(Cast<APawn>(Other).Controller);
	if (PC != nullptr)
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
