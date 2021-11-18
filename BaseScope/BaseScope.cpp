// All the original content belonged to the US Army


#include "BaseScope.h"

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

// Called when the game starts or when spawned
void ABaseScope::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
void ABaseScope::GetaZoomFOV()
{
	//Return aZoomFOV[iZoomFOV];
}
void ABaseScope::Zoom(APlayerController* PC)
{
	/*
		if (PC == None)
		{
			Return;
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
void ABaseScope::GetZoomOverlay()
{
	/*
		if (Level.GamePlayMode == 1 && tZoomOverlayMILES != None)
		{
			Return tZoomOverlayMILES;
		}
		else
		{
			Return tZoomOverlay;
		}
	*/
}
void ABaseScope::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
		local Texture Overlay;
		local int oldstyle;
		local AGP_Weapon weap;
		if (Canvas == None || bWeaponAndAttachmentsOnly == false)
		{
			Return;
		}
		weap=AGP_Weapon(Weapon(Owner));
		if (weap.ShouldUse3dSights())
		{
			Return;
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
				Canvas.DrawActor(Self,False,False,Weapon(Owner).DisplayFOV);
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
void ABaseScope::GetAimAdjustment()
{
	//Return MakeRot(iPitchOffset,iYawOffset,0);
}
