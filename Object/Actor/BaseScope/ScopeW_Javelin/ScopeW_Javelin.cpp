// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseScope/ScopeW_Javelin/ScopeW_Javelin.h"
#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Jav_Target/Jav_Target.h"
#include "Engine/Canvas.h"

AScopeW_Javelin::AScopeW_Javelin()
{
	RandArray.SetNum(5);
	NightVisionTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Optics/Nightvision1_Mat.Nightvision1_Mat'"), NULL, LOAD_None, NULL);
	DayTex             = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Day_Mat.Day_Mat'"), NULL, LOAD_None, NULL);
	WFOVTex            = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/WFOV_Mat.WFOV_Mat'"), NULL, LOAD_None, NULL);
	NFOVTex            = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/nfov_Mat.nfov_Mat'"), NULL, LOAD_None, NULL);
	SEEKTex            = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Seek_Mat.Seek_Mat'"), NULL, LOAD_None, NULL);
	DIRTex             = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Dir_Mat.Dir_Mat'"), NULL, LOAD_None, NULL);
	TOPTex             = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Top_Mat.Top_Mat'"), NULL, LOAD_None, NULL);
	MBitFailTex        = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/MSBon_Mat.MSBon_Mat'"), NULL, LOAD_None, NULL);
	WFOV_Overlay       = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_WFOV_Mat.Javelin_overlay_WFOV_Mat'"), NULL, LOAD_None, NULL);
	NFOV_Overlay       = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_NFOV_Mat.Javelin_overlay_NFOV_Mat'"), NULL, LOAD_None, NULL);
	Seek_Overlay       = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_seek_Mat.Javelin_overlay_seek_Mat'"), NULL, LOAD_None, NULL);
	CrossHair          = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/CrossHair_Mat.CrossHair_Mat'"), NULL, LOAD_None, NULL);
	TrackGate          = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/track_gate_Mat.track_gate_Mat'"), NULL, LOAD_None, NULL);

	bHasNVMode          = true;
	bInstantZoom        = true;
	fZoomMultiplier     = 4;
	tZoomOverlay        = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_DAY_Mat.Javelin_overlay_DAY_Mat'"), NULL, LOAD_None, NULL);
	aZoomFOV            = { 21.25f, 9.44f };
	VisualFadeInTime    = -1;
	TrackGateY          = 16;
	TrackGateX          = 16;
}

/*
State Javelin_Zoomed extends Zoomed
{
	simulated Function CycleZoom(APlayerController* PC)
	{
		if (fZoomMultiplier == 4)
		{
			fZoomMultiplier=9;
		}
		else
		{
			fZoomMultiplier=4;
		}
		Super::CycleZoom(PC);
	}
Begin:
	ZoomStartTime=GetWorld()->GetTimeSeconds();
}
*/

void AScopeW_Javelin::BeginPlay()
{
	/*
	int32 i = 0;
	Super::BeginPlay();
	for (i = 0; i < 5; i++)
	{
		RandArray[i] = (FMath::FRand() * float(256));
	}
	if (Self.Owner->IsA(AWEAPON_Javelin::StaticClass()))
	{
		mygun = WEAPON_Javelin(Self.Owner);
	}
	if (Cast<AHumanController>(Cast<APawn>(Self.Owner.Owner).Controller) != nullptr)
	{
		Jav_User = Cast<AHumanController>(Cast<APawn>(Self.Owner.Owner).Controller);
	}
	*/
}

void AScopeW_Javelin::UpdatePrecacheMaterials()
{
	/*
	Super::UpdatePrecacheMaterials();
	LeveL->AddPrecacheMaterial(Texture'T_AA2_FX.Optics.Nightvision1');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Javelin_overlay_WFOV');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Javelin_overlay_NFOV');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Javelin_overlay_seek');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Day');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.WFOV');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.nfov');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Seek');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Dir');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Top');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.MSBon');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.CrossHair');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.track_gate');
	LeveL->AddPrecacheMaterial(Texture'T_AAO_Armory.Javelin.Javelin_overlay_DAY');
	*/
}

void AScopeW_Javelin::UpdateTrackGateSize(UCanvas* C)
{
	int32 Size = 0;
	int32 size2 = 0;
	AActor* Target = nullptr;
	AActor* target2 = nullptr;
	/*
	Target = mygun.GetHomingTarget();
	target2 = mygun.GetJ_Target();
	Size = mygun.TrackLength(C, 0, Target.Location);
	size2 = mygun.TrackLength(C, 0, target2.Location);
	TrackGateLeftSize = FMath::Max(Size, size2);
	Size = mygun.TrackLength(C, 1, Target.Location);
	size2 = mygun.TrackLength(C, 1, target2.Location);
	TrackGateRightSize = FMath::Max(Size, size2);
	Size = mygun.TrackLength(C, 2, Target.Location);
	size2 = mygun.TrackLength(C, 2, target2.Location);
	TrackGateUpSize = FMath::Max(Size, size2);
	Size = mygun.TrackLength(C, 3, Target.Location);
	size2 = mygun.TrackLength(C, 3, target2.Location);
	TrackGateDownSize = FMath::Max(Size, size2);
	*/
}

void AScopeW_Javelin::SetbUpdateTrackGateSize()
{
	bUpdateTrackGateSize = true;
}

void AScopeW_Javelin::DrawTrackGate(UCanvas* C)
{
	int32 Left = 0;
	int32 Right = 0;
	int32 Up = 0;
	int32 Down = 0;
	int32 Xsize = 0;
	int32 Ysize = 0;
	float xRatio = 0;
	float yRatio = 0;
	AJav_Target* Target = nullptr;
	FVector ScreenLoc = FVector(0, 0, 0);
	/*
	Target = mygun.GetJ_Target();
	if (Target == nullptr)
	{
		return;
	}
	xRatio = (float(C.SizeX) / 800);
	yRatio = (float(C.SizeY) / 600);
	Xsize = int((float(TrackGateX) * xRatio));
	Ysize = int((float(TrackGateY) * yRatio));
	if (bUpdateTrackGateSize)
	{
		UpdateTrackGateSize(C);
		bUpdateTrackGateSize = false;
	}
	ScreenLoc = C.WorldToScreen(Target.Location);
	Left = int(((ScreenLoc.X - float(TrackGateLeftSize)) - xRatio));
	Right = int(((ScreenLoc.X + float(TrackGateRightSize)) + xRatio));
	Up = int(((ScreenLoc.Y - float(TrackGateUpSize)) - yRatio));
	Down = int(((ScreenLoc.Y + float(TrackGateDownSize)) + yRatio));
	(Right -= Xsize);
	(Down -= Ysize);
	if (float(Right) < (ScreenLoc.X - (float(Xsize) * 0.3)))
	{
		Right = int((ScreenLoc.X - (float(Xsize) * 0.3)));
	}
	if (float(Left) > (ScreenLoc.X - (float(Xsize) * 0.5)))
	{
		Left = int((ScreenLoc.X - (float(Xsize) * 0.5)));
	}
	if (float(Down) < (ScreenLoc.Y - (float(Ysize) * 0.3)))
	{
		Down = int((ScreenLoc.Y - (float(Ysize) * 0.3)));
	}
	if (float(Up) > (ScreenLoc.Y - (float(Ysize) * 0.5)))
	{
		Up = int((ScreenLoc.Y - (float(Ysize) * 0.5)));
	}
	C.SetPos(float(Left), float(Up));
	C.DrawTile(TrackGate, float(Xsize), float(Ysize), 0, 0, 16, 16);
	C.SetPos(float(Right), float(Up));
	C.DrawTile(TrackGate, float(Xsize), float(Ysize), 48, 0, 16, 16);
	C.SetPos(float(Left), float(Down));
	C.DrawTile(TrackGate, float(Xsize), float(Ysize), 0, 16, 16, 16);
	C.SetPos(float(Right), float(Down));
	C.DrawTile(TrackGate, float(Xsize), float(Ysize), 48, 16, 16, 16);
	*/
}

UMaterialInstance* AScopeW_Javelin::GetZoomOverlay()
{
	/*
	if (mygun.GetbIsActive())
	{
		if (mygun.GetbSeekOn())
		{
			return Seek_Overlay;
		}
		else
		{
			if (fZoomMultiplier == 4)
			{
				return WFOV_Overlay;
			}
			else
			{
				return NFOV_Overlay;
			}
		}
	}
	else
	{
		return Super::GetZoomOverlay();
	}
	*/
	return nullptr;     //FAKE   /ELiZ
}

void AScopeW_Javelin::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	FColor OldColor = FColor(0, 0, 0, 0);
	int32 oldstyle = 0;
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	if ((mygun.GetbIsActive() && (!mygun.IsInState('BusyZooming'))) && mygun.bUseNV)
	{
		Canvas.SetPos(0, 0);
		Canvas.Style = ERenderStyle.STY_TrueModulated;
		Canvas.DrawTile(NightVisionTexture, float(Canvas.SizeX), float(Canvas.SizeY), RandArray[RandInd], RandArray[RandInd], 256, 256);
		RandInd = int((float((RandInd + 1)) % 5));
		if (bNeedtoSetNightVision && (Cast<AHumanController>(Cast<APawn>(Self.Owner.Owner).Controller) != nullptr))
		{
			Jav_User.SetNightVision(true);
			Jav_User.HideSmoke(true);
			bNeedtoSetNightVision = false;
		}
	}
	Canvas.bNoNightVision = (!Canvas.bNoNightVision);
	Canvas.Style = ERenderStyle.STY_Normal;
	if ((mygun.GetbLockedOn() && mygun.GetbSeekOn()) && mygun.IsZoomed())
	{
		Canvas.SetDrawColor(255, 255, 255);
		Canvas.SetPos(DrawCrosshairX(Canvas), float((Canvas.SizeY / 16)));
		Canvas.DrawTile(CrossHair, (float(Canvas.SizeX) * 0.0025), (float(Canvas.SizeY) * 0.8), 0, 0, 4, 256);
		Canvas.SetPos(float((Canvas.SizeX / 16)), DrawCrosshairY(Canvas));
		Canvas.DrawTile(CrossHair, (float(Canvas.SizeX) * 0.8), (float(Canvas.SizeY) * 0.0033), 0, 0, 256, 4);
		if (bUseOldTrackGate)
		{
			Canvas.SetPos((Canvas.WorldToScreen(Cast<AWEAPON_Javelin>(Self.Owner).J_Target.Location).X - (float(Canvas.SizeX) * 0.03)), (Canvas.WorldToScreen(Cast<AWEAPON_Javelin>(Self.Owner).J_Target.Location).Y - (float(Canvas.SizeX) * 0.015)));
			Canvas.DrawTile(TrackGate, (float(Canvas.SizeX) * 0.06), (float(Canvas.SizeY) * 0.04), 0, 0, 64, 32);
		}
		else
		{
			DrawTrackGate(Canvas);
		}
		Canvas.DrawColor = OldColor;
	}
	if (((VisualFadeInTime > 0) && (VisualFadeOverlay != nullptr)) && ((GetWorld()->GetTimeSeconds() - ZoomStartTime) < VisualFadeInTime))
	{
		if (IsZoomed())
		{
			Canvas.Style = ERenderStyle.STY_Alpha;
			OldColor = Canvas.DrawColor;
			Canvas.SetPos(0, 0);
			Canvas.SetDrawColor(0, 0, 0, uint8(int((255 - (255 * ((GetWorld()->GetTimeSeconds() - ZoomStartTime) / VisualFadeInTime))))));
			Canvas.DrawTile(VisualFadeOverlay, float(Canvas.SizeX), float(Canvas.SizeY), 0, 0, float(VisualFadeOverlay.USize), float(VisualFadeOverlay.VSize));
			Canvas.DrawColor = OldColor;
			Canvas.Style = ERenderStyle.STY_Normal;
		}
	}
	Super::RenderOverlays(Canvas, bWeaponAndAttachmentsOnly);
	if (mygun.IsZoomed())
	{
		Canvas.SetDrawColor(255, 255, 255);
		if (mygun.GetbSeekOn())
		{
			if (!mygun.GetbLockedOn())
			{
				Canvas.SetPos((float((Canvas.SizeX / 2)) - (float(Canvas.SizeX) * 0.03)), (float((Canvas.SizeY / 2)) - (float(Canvas.SizeX) * 0.015)));
				Canvas.DrawTile(TrackGate, (float(Canvas.SizeX) * 0.06), (float(Canvas.SizeY) * 0.04), 0, 0, 64, 32);
			}
			Canvas.SetPos((float(Canvas.SizeX) * 0.708), (float(Canvas.SizeY) * 0.052));
			Canvas.DrawTile(SEEKTex, (float(Canvas.SizeX) * 0.095), (float(Canvas.SizeY) * 0.126), 0, 0, 64, 64);
		}
		if (fZoomMultiplier == 4)
		{
			Canvas.SetPos((float(Canvas.SizeX) * 0.369), (float(Canvas.SizeY) * 0.05));
			Canvas.DrawTile(WFOVTex, (float(Canvas.SizeX) * 0.095), (float(Canvas.SizeY) * 0.126), 0, 0, 64, 64);
		}
		else
		{
			Canvas.SetPos((float(Canvas.SizeX) * 0.539), (float(Canvas.SizeY) * 0.052));
			Canvas.DrawTile(NFOVTex, (float(Canvas.SizeX) * 0.095), (float(Canvas.SizeY) * 0.126), 0, 0, 64, 64);
		}
		if (mygun.GetbDirectFire())
		{
			Canvas.SetPos((float(Canvas.SizeX) * 0.851), (float(Canvas.SizeY) * 0.435));
			Canvas.DrawTile(DIRTex, (float(Canvas.SizeX) * 0.095), (float(Canvas.SizeY) * 0.126), 0, 0, 64, 64);
		}
		else
		{
			Canvas.SetPos((float(Canvas.SizeX) * 0.851), (float(Canvas.SizeY) * 0.218));
			Canvas.DrawTile(TOPTex, (float(Canvas.SizeX) * 0.095), (float(Canvas.SizeY) * 0.126), 0, 0, 64, 64);
		}
		if (!mygun.GetbIsActive())
		{
			Canvas.SetPos((float(Canvas.SizeX) * 0.199), (float(Canvas.SizeY) * 0.052));
			Canvas.DrawTile(DayTex, (float(Canvas.SizeX) * 0.095), (float(Canvas.SizeY) * 0.126), 0, 0, 64, 64);
		}
		if (mygun.IsJammed())
		{
			Canvas.SetPos((float(Canvas.SizeX) * 0.539), (float(Canvas.SizeY) * 0.821));
			Canvas.DrawTile(MBitFailTex, (float(Canvas.SizeX) * 0.095), (float(Canvas.SizeY) * 0.126), 0, 0, 64, 64);
		}
	}
	Canvas.Style = uint8(oldstyle);
	Canvas.DrawColor = OldColor;
	Canvas.bNoNightVision = (!Canvas.bNoNightVision);
	*/
}

void AScopeW_Javelin::Zoom(APlayerController* PC)
{
	/*
	if (Cast<AAGP_Pawn>(Self.Owner.Owner) != nullptr)
	{
		Boptics = Cast<AAGP_Pawn>(Self.Owner.Owner)._OpticsDevice;
	}
	if (Boptics != nullptr)
	{
		if (Boptics.IsActive())
		{
			Boptics.Toggle();
		}
	}
	if (PC == nullptr)
	{
		return;
	}
	fPreZoomFOV = PC.FovAngle;
	PC.DesiredFOV = aZoomFOV[iZoomFOV];
	PC.FovAngle = PC.DesiredFOV;
	GotoState('Javelin_Zoomed');
	*/
}

float AScopeW_Javelin::DrawCrosshairX(UCanvas* Canvas)
{
	AJav_Target* Target = nullptr;
	Target = mygun->GetJ_Target();
	if (Target != nullptr)
	{
		//return Canvas.WorldToScreen(Target->GetActorLocation())->X;
	}
	else
	{
		return -1;
	}
	return -1;    //FAKE   /EliZ
}

float AScopeW_Javelin::DrawCrosshairY(UCanvas* Canvas)
{
	AJav_Target* Target = nullptr;
	Target = mygun->GetJ_Target();
	if (Target != nullptr)
	{
		//return Canvas.WorldToScreen(Target->GetActorLocation())->Y;
	}
	else
	{
		return -1;
	}
	return -1;    //FAKE   /EliZ
}

