// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/CinematicHud/CinematicHud.h"

ACinematicHud::ACinematicHud(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	bHideScope = true;
	xOffsets.SetNum(2);
	xRates.SetNum(2);
	yOffsets.SetNum(2);
	yRates.SetNum(2);
}

void ACinematicHud::DrawHUD()
{
	if (!bInitialized)
	{
		Initialize(Canvas);
	}
	//Scale = (Canvas->ClipX / float(1024));
	Super::DrawHUD();
}

void ACinematicHud::Initialize(UCanvas* C)
{
	if (Scale == 0)
	{
		return;
	}
	xOffsets[0] = (-123 * Scale);
	xRates[0] = (512 * Scale);
	//xOffsets[1] = (C.ClipY + 1);
	xRates[1] = (512 * Scale);
	//yOffsets[0] = ((C.ClipY / 2) - (64 * Scale));
	yOffsets[1] = yOffsets[0];
	yRates[0] = (-200 * Scale);
	yRates[1] = (256 * Scale);
	bInitialized = true;
}

void ACinematicHud::LocalizedMessage(ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString CriticalString)
{
	/*
	SubTitle = Message->GetString(Switch);
	SubTitleKillTime = (GetWorld()->GetTimeSeconds() + Message->GetLifeTime(Switch));
	*/
}
