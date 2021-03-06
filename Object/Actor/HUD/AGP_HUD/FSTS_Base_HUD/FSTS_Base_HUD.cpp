// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/AGP_HUD/FSTS_Base_HUD/FSTS_Base_HUD.h"

AFSTS_Base_HUD::AFSTS_Base_HUD(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}

void AFSTS_Base_HUD::DrawHUD()
{
	int32 i = 0;
	/*
	Super::DrawHUD();
	ContextTrace(Canvas);
	for (i = 0; i < Overlays.Num(); i++)
	{
		Overlays[i].Render(Canvas);
	}
	*/
}

void AFSTS_Base_HUD::ContextTrace(UCanvas* C)
{
	AActor* HitActor = nullptr;
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	UMaterialInstance* ContextTexture = nullptr;
	if (PawnOwner == nullptr)
	{
		return;
	}
	/*
	GetAxes(PawnOwner.GetViewRotation(), X, Y, Z);
	StartTrace = PawnOwner.EyePosition();
	EndTrace = (StartTrace + (X * float(PawnOwner.GetShortTraceDistance())));
	HitActor = Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	if (((HitActor != nullptr) && HitActor.bUseActionIcon) && (HitActor.ActionIcon != nullptr))
	{
		ContextTexture = HitActor.ActionIcon;
		C.SetPos(((float(C.SizeX) * 0.5) - (0.5 * float(ContextTexture.MaterialUSize()))), ((float(C.SizeY) * 0.5) - (0.5 * float(ContextTexture.MaterialVSize()))));
		C.Style = ERenderStyle.STY_Alpha;
		C.DrawTile(ContextTexture, float(ContextTexture.MaterialUSize()), float(ContextTexture.MaterialVSize()), 0, 0, float(ContextTexture.MaterialUSize()), float(ContextTexture.MaterialVSize()));
	}
	*/
}
