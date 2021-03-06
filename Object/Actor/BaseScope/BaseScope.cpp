// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseScope/BaseScope.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

// Sets default values
ABaseScope::ABaseScope()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	fZoomMultiplier      = 1;
	bOnlyRelevantToOwner = true;
	//DrawType = 0;
	//bOnlyOwnerSee = true;
	//RemoteRole = 0
	//Style = 6
}

/*
State Zoomed
{
	Function Zoom(APlayerController* PC)
	{
	}
	simulated Function bool IsZoomed()
	{
		return true;
	}
	simulated Function float GetZoomMultiplier()
	{
		return fZoomMultiplier;
	}
	simulated Function CycleZoom(APlayerController* PC)
	{
		iZoomFOV=int((float((iZoomFOV + 1)) % float(aZoomFOV.Num())));
		SetPlayerZoom(PC);
	}
	simulated Function ZoomIn(APlayerController* PC)
	{
		if (iZoomFOV < (aZoomFOV.Num() - 1))
		{
			iZoomFOV ++;
			SetPlayerZoom(PC);
		}
	}
	simulated Function ZoomOut(APlayerController* PC)
	{
		if (iZoomFOV > 0)
		{
			iZoomFOV --;
			SetPlayerZoom(PC);
		}
	}
	simulated Function SetPlayerZoom(APlayerController* PC)
	{
		if (PC == nullptr)
		{
			return;
		}
		PC.DesiredFOV=aZoomFOV[iZoomFOV];
		PC.FovAngle=PC.DesiredFOV;
		if (Level.debugZoom)
		{
			ScreenPrint("Zoom Index:" @ FString::FromInt(iZoomFOV) @ "FOV" @ FString::FromInt(PC.FovAngle));
		}
	}
	simulated Function UnZoom(APlayerController* PC)
	{
		if (PC == nullptr)
		{
			return;
		}
		if (bInstantZoom)
		{
			PC.DesiredFOV=fPreZoomFOV;
			PC.FovAngle=PC.DesiredFOV;
		}
		else
		{
			PC.DesiredFOV=PC.Default.FovAngle;
		}
		GotoState("None");
	}
}
*/


void ABaseScope::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABaseScope::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseScope::ZoomOut(APlayerController* PC)
{
}
void ABaseScope::ZoomIn(APlayerController* PC)
{
}
void ABaseScope::CycleZoom(APlayerController* PC)
{
}
void ABaseScope::UnZoom(APlayerController* PC)
{
}

float ABaseScope::GetaZoomFOV()
{
	return aZoomFOV[iZoomFOV];
}

void ABaseScope::Zoom(APlayerController* PC)
{
	/*
		if (PC == nullptr)
		{
			return;
		}
		fPreZoomFOV=PC.FovAngle;
		PC.DesiredFOV=aZoomFOV[iZoomFOV];
		if (bInstantZoom)
		{
			PC.FovAngle=PC.DesiredFOV;
		}
		GotoState('Zoomed');
	*/
}
bool ABaseScope::IsZoomed()
{
	return false;
}
float ABaseScope::GetZoomMultiplier()
{
	return 1.0f;
}
bool ABaseScope::HasNVMode()
{
	return bHasNVMode;
}

UMaterialInstance* ABaseScope::GetZoomOverlay()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GamePlayMode == EGameplayModes::GM_MILES && tZoomOverlayMILES != nullptr)
	{
		return tZoomOverlayMILES;
	}
	else
	{
		return tZoomOverlay;
	}
}

void ABaseScope::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	UMaterialInstance* Overlay = nullptr;
	int32 oldstyle = 0;
	AAGP_Weapon* weap = nullptr;
	/*
		if (Canvas == nullptr || bWeaponAndAttachmentsOnly == false)
		{
			return;
		}
		weap=Cast<AAGP_Weapon>(Cast<AWeapon>(GetOwner()));
		if (weap.ShouldUse3dSights())
		{
			return;
		}
		if (IsZoomed())
		{
			oldstyle=Canvas.Style;
			Overlay=GetZoomOverlay();
			if (Canvas.SizeX != _iOldSizeX || Canvas.SizeY != _iOldSizeY)
			{
				_iScopeSize=Canvas.SizeY;
				_iScopePosX=Canvas.SizeX - _iScopeSize / 2;
				_iOldSizeX=Canvas.SizeX;
				_iOldSizeY=Canvas.SizeY;
			}
			Canvas.Style=Style;
			Canvas.SetPos(0,0);
			Canvas.DrawTile(Overlay,_iOldSizeX,_iOldSizeY,0,0,512,512);
			Canvas.Style=oldstyle;
		}
		else
		{
			if (DrawType != 0)
			{
				Canvas.DrawActor(this,false,False,Weapon(GetOwner())->DisplayFOV);
			}
		}
	*/
}
void ABaseScope::VerticalMinuteAngle(bool increase)
{
	/*
		if (increase)
		{
			iPitchOffset += 3;
		}
		else
		{
			iPitchOffset -= 3;
		}
		if (iPitchOffset > 8100)
		{
			iPitchOffset=8100;
		}
		else
		{
			if (iPitchOffset < - 8100)
			{
				iPitchOffset=- 8100;
			}
		}
		if (Level.debugZoom)
		{
			ScreenPrint("AimAdjust" @ GetAimAdjustment());
		}
	*/
}
void ABaseScope::LateralMinuteAngle(bool increase)
{
	/*
		if (increase)
		{
			iYawOffset += 3;
		}
		else
		{
			iYawOffset -= 3;
		}
		if (iYawOffset > 8100)
		{
			iYawOffset=8100;
		}
		else
		{
			if (iYawOffset < - 8100)
			{
				iYawOffset=- 8100;
			}
		}
		if (Level.debugZoom)
		{
			ScreenPrint("AimAdjust" @ GetAimAdjustment());
		}
	*/
}
void ABaseScope::Zero()
{
	iPitchOffset=0;
	iYawOffset=0;
}

FRotator ABaseScope::GetAimAdjustment()
{
	//return FRotator(iPitchOffset,iYawOffset,0);
	return FRotator(0, 0, 0);     //FAKE   /EliZ
}
