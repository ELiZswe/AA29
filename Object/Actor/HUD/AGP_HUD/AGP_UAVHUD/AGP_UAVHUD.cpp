// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_UAVHUD/AGP_UAVHUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseRavenController/NPCBaseRavenController.h"

AAGP_UAVHUD::AAGP_UAVHUD(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	colorText = FColor(255, 255, 255, 255);
	texNightVision = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Optics/Nightvision1_Mat.Nightvision1_Mat'"), NULL, LOAD_None, NULL);
	texVisionOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UAVS/Raven/RavenPrototypeOverlay_Mat.RavenPrototypeOverlay_Mat'"), NULL, LOAD_None, NULL);
}

void AAGP_UAVHUD::DrawHUD()
{
	FString sText = "";
	float fpFeatureVerticalOffset = 0;
	float fpDistanceKm = 0;
	int32 iDirection = 0;
	int32 iOffset = 0;
	int32 iMissionTimeMinutes = 0;
	int32 iMissionTimeSeconds = 0;
	iSizeX = Canvas->SizeX;
	iSizeY = Canvas->SizeY;
	if (!bShowHUD)
	{
		//Super::DrawHUD(Canvas);
		return;
	}
	if (fntHUD == nullptr)
	{
		//fntHUD = Font(DynamicLoadObject("T_AA2_Fonts.NewsGoth14", Class'Font'));
	}
	//Canvas.Font = fntHUD;
	fpFeatureVerticalOffset = 0.1;
	sText = "NAV";
	DrawHUDText(Canvas, sText, 0.12, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Left);
	sText = "LINK 1";
	DrawHUDText(Canvas, sText, 0.85, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Right);
	sText = "25052007 00:";
	//iMissionTimeMinutes = int((GetWorld()->GetTimeSeconds() / float(60)));
	//iMissionTimeSeconds = int((GetWorld()->GetTimeSeconds() % float(60)));
	if (iMissionTimeMinutes < 10)
	{
		sText = sText + "0";
	}
	//sText = sText + FString::FromInt(iMissionTimeMinutes) + ":";
	if (iMissionTimeSeconds < 10)
	{
		sText = sText + "0";
	}
	sText = sText + FString::FromInt(iMissionTimeSeconds) + " GMT";
	(fpFeatureVerticalOffset += 0.03);
	DrawHUDText(Canvas, sText, 0.12, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Left);
	if (GetWorld()->GetNetMode() == ENetMode::NM_Standalone)
	{
		//sText = "Alt " + FString::FromInt(int((Cast<ANPCBaseRavenController>(Cast<AHumanController>(GetOwner())->vehUAV->Controller)->fpRealAltitude / 16.708)));
	}
	else
	{
		//sText = "Alt " +FString::FromInt(int((Cast<AHumanController>(GetOwner())->vehUAV->fpRealAltitude / 16.708)));
	}
	//sText = sText + " / " + FString::FromInt(int((Cast<ANPCBaseRavenController>(Cast<AHumanController>(GetOwner())->vehUAV->Controller)->fpMinAltitude / 16.708)));
	DrawHUDText(Canvas, sText, 0.85, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Right);
	(fpFeatureVerticalOffset += 0.03);
	//iDirection = int(((float(Cast<AHumanController>(GetOwner())->vehUAV.Rotation.Yaw) / 65535) * 360));
	if (iDirection < 0)
	{
		(iDirection += 360);
	}
	sText = "MAG " + FString::FromInt(iDirection);
	sText = sText + " deg";
	DrawHUDText(Canvas, sText, 0.12, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Left);
	//fpDistanceKm = (VSize((Cast<AHumanController>(GetOwner())->vehUAV.Location - Cast<AHumanController>(GetOwner())->Pawn.Location)) / float(55000));
	sText = "" + FString::FromInt(fpDistanceKm);
	//iOffset = InStr(sText, ".");
	if (iOffset != -1)
	{
		//sText = Left(sText, (iOffset + 1));
	}
	sText = FString::FromInt(fpDistanceKm) + " km";
	DrawHUDText(Canvas, sText, 0.85, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Right);
	(fpFeatureVerticalOffset += 0.03);
	//sText = "Mph " + FString::FromInt(int((VSize(Cast<AHumanController>(GetOwner())->vehUAV.Velocity) / 24)));
	DrawHUDText(Canvas, sText, 0.12, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Left);
	//sText = "Grid " + Cast<ANPCBaseRavenController>(Cast<AHumanController>(GetOwner())->vehUAV.Controller).LocationToGrid(Cast<AHumanController>(GetOwner())->vehUAV.Location);
	DrawHUDText(Canvas, sText, 0.85, fpFeatureVerticalOffset, colorText, ETextHorzAlignment::THA_Right);
}

void AAGP_UAVHUD::WorldSpaceOverlays()
{
}

void AAGP_UAVHUD::DrawHUDText(UCanvas* aCanvas, FString sText, float fpScaledX, float fpScaledY, FColor acolorText, ETextHorzAlignment thaAlignment)
{
	float fpTextWidth = 0;
	float fpTextHeight = 0;
	/*
	aCanvas.TextSize(sText, fpTextWidth, fpTextHeight);
	aCanvas.DrawColor = acolorText;
	switch (thaAlignment)
	{
	case 1:
		aCanvas.SetPos(((float(aCanvas.SizeX) * fpScaledX) - (fpTextWidth / 2)), (float(aCanvas.SizeY) * fpScaledY));
		break;
	case 0:
		Canvas.SetPos((float(aCanvas.SizeX) * fpScaledX), (float(aCanvas.SizeY) * fpScaledY));
		break;
	case 2:
		Canvas.SetPos(((float(Canvas.SizeX) * fpScaledX) - fpTextWidth), (float(Canvas.SizeY) * fpScaledY));
		break;
	default:
	}
	Canvas.DrawText(sText);
	*/
}

void AAGP_UAVHUD::DrawHUDTextUnscaled(UCanvas* aCanvas, FString sText, float fpX, float fpY, FColor acolorText)
{
	/*
	float fpTextWidth = 0;
	float fpTextHeight = 0;
	aCanvas.TextSize(sText, fpTextWidth, fpTextHeight);
	aCanvas.DrawColor = acolorText;
	aCanvas.SetPos(fpX, fpY);
	aCanvas.DrawText(sText);
	*/
}

void AAGP_UAVHUD::RenderOverlays_Stage1(UCanvas* aCanvas)
{
	/*
	aCanvas.SetPos(0, 0);
	aCanvas.DrawTile(texVisionOverlay, float(aCanvas.SizeX), float(aCanvas.SizeY), 0, 0, 512, 512);
	*/
}

void AAGP_UAVHUD::Tick(float DeltaTime)
{
	AHumanController* hcOwner = nullptr;
	Super::Tick(DeltaTime);
	hcOwner = Cast<AHumanController>(GetOwner());
	/*
	if (((hcOwner.bFire == 1) && hcOwner.Player.bShowWindowsMouse) && ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastButtonClicked) > 0.5))
	{
		ProcessButtonClicked(GetMouseX(), GetMouseY());
		fpTimeSinceLastButtonClicked = GetWorld()->GetTimeSeconds();
	}
	*/
}

void AAGP_UAVHUD::ProcessButtonClicked(int32 iMouseX, int32 iMouseY)
{
	/*
	if ((((float(iMouseX) >= (float(iSizeX) * 0.097)) && (float(iMouseX) <= (float(iSizeX) * 0.18))) && (float(iMouseY) >= (float(iSizeY) * 0.91))) && (float(iMouseY) <= (float(iSizeY) * 0.98)))
	{
		Cast<AHumanController>(GetOwner())->UAVCameraView();
		return;
	}
	if ((((float(iMouseX) >= (float(iSizeX) * 0.22)) && (float(iMouseX) <= (float(iSizeX) * 0.31))) && (float(iMouseY) >= (float(iSizeY) * 0.91))) && (float(iMouseY) <= (float(iSizeY) * 0.98)))
	{
		Cast<AHumanController>(GetOwner())->UAVStart("first");
		return;
	}
	if ((((float(iMouseX) >= (float(iSizeX) * 0.34)) && (float(iMouseX) <= (float(iSizeX) * 0.43))) && (float(iMouseY) >= (float(iSizeY) * 0.91))) && (float(iMouseY) <= (float(iSizeY) * 0.98)))
	{
		Cast<AHumanController>(GetOwner())->UAVServerCircleHere();
		return;
	}
	if ((((float(iMouseX) >= (float(iSizeX) * 0.47)) && (float(iMouseX) <= (float(iSizeX) * 0.56))) && (float(iMouseY) >= (float(iSizeY) * 0.91))) && (float(iMouseY) <= (float(iSizeY) * 0.98)))
	{
		Cast<AHumanController>(GetOwner())->UAVServerHeadForPlayer();
		return;
	}
	if ((((float(iMouseX) >= (float(iSizeX) * 0.64)) && (float(iMouseX) <= (float(iSizeX) * 0.73))) && (float(iMouseY) >= (float(iSizeY) * 0.91))) && (float(iMouseY) <= (float(iSizeY) * 0.98)))
	{
		Cast<AHumanController>(GetOwner())->UAVServerTurnLeft();
		return;
	}
	if ((((float(iMouseX) >= (float(iSizeX) * 0.76)) && (float(iMouseX) <= (float(iSizeX) * 0.85))) && (float(iMouseY) >= (float(iSizeY) * 0.91))) && (float(iMouseY) <= (float(iSizeY) * 0.98)))
	{
		Cast<AHumanController>(GetOwner())->UAVServerTurnRight();
		return;
	}
	if ((((float(iMouseX) >= (float(iSizeX) * 0.9)) && (float(iMouseX) <= (float(iSizeX) * 0.98))) && (float(iMouseY) >= (float(iSizeY) * 0.65))) && (float(iMouseY) <= (float(iSizeY) * 0.74)))
	{
		Cast<AHumanController>(GetOwner())->UAVServerClimb();
		return;
	}
	if ((((float(iMouseX) >= (float(iSizeX) * 0.9)) && (float(iMouseX) <= (float(iSizeX) * 0.98))) && (float(iMouseY) >= (float(iSizeY) * 0.78))) && (float(iMouseY) <= (float(iSizeY) * 0.87)))
	{
		Cast<AHumanController>(GetOwner())->UAVServerDescend();
		return;
	}
	*/
}
